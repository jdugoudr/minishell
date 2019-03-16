/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:22:47 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/14 12:21:38 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	to_print_env(char **env, char **tab)
{
	if (tab[1] != NULL)
		return (minishell_error(ENV, MANY_ARG));
	if (env)
	{
		print_env(env);
		return (0);
	}
	return (1);
}

static int	to_set_env(char ***env, char **tab)
{
	size_t	len;
	int		i;

	len = ft_tablen((const char **)tab);
	i = 0;
	if (len > 3)
		return (minishell_error(SETENV, MANY_ARG));
	else if (len < 3)
		return (minishell_error(SETENV, FEW_ARG));
	while (tab[1][i])
	{
		if (ft_isalnum(tab[1][i]) == 0)
			return (minishell_error(SETENV, NOT_ALNU));
		i++;
	}
	if ((set_env(tab[1], tab[2], env)) == 1)
		return (minishell_error(SETENV, INTERN));
	return (0);
}

static int	to_unset_env(char ***env, char **tab)
{
	int	i;

	i = 1;
	if (!tab[1])
		return (minishell_error(UNENV, FEW_ARG));
	while (tab[i] && unset_env(tab[i], env) == 0)
		i++;
	if (tab[i])
		return (minishell_error(UNENV, INTERN));
	return (0);
}

int			parse_distribute(char **tabline, char ***env)
{
	if ((ft_strcmp(tabline[0], ENV)) == 0)
		return (to_print_env(*env, tabline));
	else if ((ft_strcmp(tabline[0], SETENV)) == 0)
		return (to_set_env(env, tabline));
	else if ((ft_strcmp(tabline[0], UNENV)) == 0)
		return (to_unset_env(env, tabline));
	else if ((ft_strcmp(tabline[0], ECHO)) == 0)
		return (do_echo(tabline));
	else if ((ft_strcmp(tabline[0], CD)) == 0)
		return (cd(tabline[1], ft_tablen((const char **)tabline), env));
	else
		return (path(tabline, *env));
	return (0);
}
