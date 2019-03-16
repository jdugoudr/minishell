/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:01:05 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/15 16:30:54 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <unistd.h>
#include <sys/types.h>

static int	do_tild(char **line, int *i, char **env)
{
	char	*new;
	size_t	len;
	char	*tmp;

	tmp = get_env(HOME, env);
	if (tmp[0] == '\0')
		return (minishell_error(APP_NAME, "No home specified in environment."));
	len = ft_strlen(tmp);
	if ((new = ft_strnew(ft_strlen(*line) + len - 1)) == NULL)
		return (minishell_error(APP_NAME, INTERN));
	ft_strncat(new, *line, *i);
	ft_strcat(new, tmp);
	ft_strcat(new, *line + *i + 1);
	free(*line);
	*line = new;
	*i += len - 1;
	return (0);
}

static int	do_dolls(char **line, int *i, char **env, int ret)
{
	if ((*line)[*i + 1] == '?' || (*line)[*i + 1] == '$'
			|| (*line)[*i + 1] == '\0')
		return (do_simple_dolls(line, i, ret));
	else
		return (ask_env(line, env, i));
}

int			lex_var(char **tab, char **env, int ret)
{
	int		i;
	int		j;
	char	*line;
	int		r;

	i = 0;
	j = 0;
	r = 0;
	while (tab[i])
	{
		line = NULL;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '$')
				r = do_dolls(tab + i, &j, env, ret);
			else if (tab[i][j] == '~')
				r = do_tild(tab + i, &j, env);
			j++;
			if (r)
				break ;
		}
		i++;
		j = 0;
	}
	return (r);
}
