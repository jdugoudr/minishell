/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:35:20 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/13 15:55:51 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	unset_loop(int i, char ***env, char **new)
{
	int		r;
	int		j;

	j = 0;
	r = 0;
	while ((*env)[j])
	{
		if (j != i)
			new[j - r] = (*env)[j];
		else
			r = 1;
		j++;
	}
	new[j - 1] = NULL;
}

static int	key_match(char *name, char **env)
{
	int		j;
	int		i;
	char	c;

	j = 0;
	i = 0;
	while (env[i])
	{
		while (env[i][j] != '=' && env[i][j] != '\0')
			j++;
		c = env[i][j];
		env[i][j] = '\0';
		if (!ft_strcmp(env[i], name))
			break ;
		env[i][j] = c;
		j = 0;
		i++;
	}
	return (i);
}

int			unset_env(char *name, char ***env)
{
	int		i;
	char	**new;

	if (!env || !(*env))
		return (1);
	i = key_match(name, *env);
	if ((*env)[i])
	{
		if (!(new = malloc(ft_tablen((const char **)*env) * sizeof(char *))))
			return (1);
		free((*env)[i]);
		unset_loop(i, env, new);
		free(*env);
		*env = new;
	}
	return (0);
}
