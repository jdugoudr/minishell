/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:46:25 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/15 14:33:12 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_error.h"
#include "parse.h"
#include "env.h"
#include "unistd.h"

static void	del_blank(char *line, int nb_blank)
{
	int	i;

	i = 0;
	if (nb_blank == 0)
		return ;
	while (line[i + nb_blank])
	{
		line[i] = line[i + nb_blank];
		i++;
	}
	line[i] = '\0';
}

/*
** here we skip the blank and let just one
** if you want to enable " " you have t add here
*/

static void	normalise(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
			i++;
		while (line[i + j] == ' ' || line[i + j] == '\t')
		{
			if (line[i + j] == '\t')
				line[i + j] = ' ';
			j++;
		}
		if (j > 0)
		{
			if (line[i + j] != '\0' && i > 0)
				j--;
			del_blank(line + i, j);
			i++;
		}
		j = 0;
	}
}

static int	mn_gnl(char **line)
{
	char	buff[BUFF + 1];
	char	*tmp;
	int		rd;

	if ((*line = ft_strnew(BUFF + 1)) == NULL)
		return (1);
	while ((tmp = ft_strchr(*line, '\n')) == NULL)
	{
		if ((rd = read(STDIN_FILENO, buff, BUFF)) == -1)
		{
			free(*line);
			return (1);
		}
		buff[rd] = '\0';
		if ((*line = ft_strjoinfree(line, buff)) == NULL)
			return (1);
	}
	*(*line + (tmp - *line)) = '\0';
	return (0);
}

static void	init(void)
{
	g_child = 0;
	do_prompt(getcwd(NULL, 0));
	signal(SIGINT, &signal_c);
}

int			main(void)
{
	char	*line;
	int		ret;
	char	**multicmd;

	ret = 0;
	if ((g_env = init_env()) == NULL)
		return (1);
	init();
	while (mn_gnl(&line) == 0)
	{
		normalise(line);
		multicmd = ft_strsplit((const char *)line, ';');
		free(line);
		if (!multicmd)
			minishell_error(APP_NAME, INTERN);
		else
		{
			if (multicmd[0])
				ret = parse(multicmd, &g_env, ret);
			ft_tabstrdel(&multicmd, 0);
		}
		do_prompt(getcwd(NULL, 0));
	}
	return (1);
}
