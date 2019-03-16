/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:10:42 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/15 13:06:02 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <unistd.h>
#include <sys/types.h>

static int	bltin_exit(char **multicmd, char **cmd, char **env)
{
	if (ft_tablen((const char **)cmd) > 1)
		return (minishell_error(EXIT, MANY_ARG));
	if (multicmd)
		ft_tabstrdel(&multicmd, 0);
	if (cmd)
		ft_tabstrdel(&cmd, 0);
	if (env)
		ft_tabstrdel(&env, 0);
	exit(0);
	return (0);
}

int			parse(char **multicmd, char ***env, int ret)
{
	int		i;
	char	**cmd;

	i = 0;
	while (multicmd[i])
	{
		if ((cmd = ft_strsplit((const char *)(multicmd[i]), ' ')) == NULL)
			return (minishell_error(APP_NAME, INTERN));
		if ((*cmd) && lex_var(cmd, *env, ret))
		{
			ft_tabstrdel(&cmd, 0);
			return (1);
		}
		else if ((*cmd) && !ft_strcmp(cmd[0], EXIT))
			ret = bltin_exit(multicmd, cmd, *env);
		else if ((*cmd))
			ret = parse_distribute(cmd, env);
		ft_tabstrdel(&cmd, 0);
		i++;
	}
	return (ret);
}
