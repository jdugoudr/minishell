/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:10:24 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/15 16:30:52 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	remove_from_line(char **line, char *add, int *i, int len_rem)
{
	char	*new;
	size_t	len_add;

	len_add = ft_strlen(add);
	if (!(new = ft_strnew((ft_strlen(*line) - len_rem + len_add))))
		return (minishell_error(APP_NAME, INTERN));
	(*line)[*i] = '\0';
	ft_strcat(new, *line);
	ft_strcat(new, add);
	ft_strcat(new, (*line) + *i + len_rem);
	free(*line);
	*line = new;
	*i += len_add - 1;
	return (0);
}

int			do_simple_dolls(char **line, int *i, int ret)
{
	char	*tmp;
	int		len_rem;
	int		r;

	tmp = NULL;
	len_rem = 1;
	if ((*line)[*i + 1] == '?')
	{
		len_rem++;
		tmp = ft_itoa(ret);
	}
	else if ((*line)[*i + 1] == '$')
	{
		len_rem++;
		tmp = ft_itoa(getpid());
	}
	else if ((*line)[*i + 1] == '\0')
		tmp = ft_strdup("$");
	if (!tmp)
		return (minishell_error(APP_NAME, INTERN));
	r = remove_from_line(line, tmp, i, len_rem);
	free(tmp);
	return (r);
}

int			ask_env(char **line, char **env, int *i)
{
	int		j;
	char	c;
	char	*tmp;

	j = *i + 1;
	while ((*line)[j] && (*line)[j] != '$' && (*line)[j] != '~')
		j += 1;
	c = (*line)[j];
	(*line)[j] = '\0';
	if ((tmp = ft_strdup(get_env((*line) + *i, env))) == NULL)
		return (minishell_error(APP_NAME, INTERN));
	if (tmp[0] == '\0')
	{
		free(tmp);
		return (minishell_error((*line) + 1, UNKNOW));
	}
	(*line)[j] = c;
	j = remove_from_line(line, tmp, i, j - *i);
	free(tmp);
	return (j);
}
