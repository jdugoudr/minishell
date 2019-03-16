/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 11:10:30 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/10 12:15:35 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		ft_printf("%s\n", env[i++]);
}

char		**init_env(void)
{
	extern char	**environ;
	char		**env;
	size_t		len;
	size_t		i;

	len = ft_tablen((const char **)environ);
	if ((env = (char **)malloc((len + 1) * sizeof(char *))) == NULL)
		return (NULL);
	env[len] = NULL;
	i = 0;
	while (i < len)
	{
		if ((env[i] = ft_strdup(environ[i])) == NULL)
		{
			ft_tabstrdel(&env, 0);
			return (NULL);
		}
		i++;
	}
	return (env);
}
