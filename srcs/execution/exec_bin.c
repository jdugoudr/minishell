/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:20:09 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/15 14:33:35 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_bin.h"

int	exec_bin(char *cmd, char **arg, char **env)
{
	int		ret;

	ret = 0;
	g_child = fork();
	if (g_child == 0)
	{
		signal(SIGINT, SIG_IGN);
		execve(cmd, arg, env);
	}
	else
	{
		waitpid(g_child, &ret, 0);
		g_child = 0;
	}
	return (ret);
}
