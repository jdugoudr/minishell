/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:13:21 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/15 16:30:53 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char		*get_env(char *name, char **env)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	j = 0;
	if (!env)
		return (NULL);
	if (name[0] != '$')
		return ("");
	while (env[++i])
	{
		while (env[i][j] != '=' && env[i][j] != '\0')
			j++;
		c = env[i][j];
		env[i][j] = '\0';
		if (!ft_strcmp(env[i], name + 1))
			break ;
		env[i][j] = c;
		j = 0;
	}
	if (!env[i])
		return ("");
	env[i][j] = c;
	return (env[i] + j + 1);
}

static int	set_new_name(char *name, char *value, char ***env)
{
	int		len;
	char	*tmp;
	char	**add_val;
	int		i;

	i = -1;
	len = (int)ft_tablen((const char **)(*env));
	if ((add_val = malloc((len + 2) * sizeof(char *))))
	{
		while (++i < len)
			add_val[i] = (*env)[i];
		if ((tmp = ft_strjoin(name, "=")) == NULL
				|| (add_val[len] = ft_strjoinfree(&tmp, value)) == NULL)
		{
			free(tmp);
			return (1);
		}
	}
	else
		return (1);
	add_val[len + 1] = NULL;
	free(*env);
	*env = add_val;
	return (0);
}

int			set_env(char *name, char *value, char ***env)
{
	char	*tmp_value;
	char	c;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while ((*env)[++i])
	{
		while ((*env)[i][j] != '=' && (*env)[i][j] != '\0')
			j++;
		if (!ft_strncmp((*env)[i], name, j))
		{
			c = (*env)[i][j + 1];
			(*env)[i][j + 1] = '\0';
			tmp_value = ft_strjoin((*env)[i], value);
			tmp_value == NULL ? (*env)[i][j + 1] = c : free((*env)[i]);
			if (!tmp_value)
				return (1);
			(*env)[i] = tmp_value;
			return (0);
		}
		j = 0;
	}
	return (set_new_name(name, value, env));
}
