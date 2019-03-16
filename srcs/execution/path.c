/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:22:41 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/14 10:43:35 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

static int	check_file(char **tab, char **env)
{
	if (access(tab[0], F_OK))
		return (minishell_error(tab[0], NO_FILE));
	else if (access(tab[0], X_OK))
		return (minishell_error(tab[0], NO_PERM));
	return (exec_bin(tab[0], tab, env));
}

static char	*do_path(char *path, char *name)
{
	char	*tmp;
	char	*com_path;

	if ((tmp = ft_strjoin(path, "/")) == NULL)
		return (NULL);
	com_path = ft_strjoin(tmp, name);
	free(tmp);
	return (com_path);
}

static int	check_path(char **path_tab, char **tab, char **env)
{
	char	*path;
	int		i;
	int		ret;

	i = 0;
	while (path_tab[i])
	{
		if ((path = do_path(path_tab[i], tab[0])) == NULL)
			return (minishell_error(APP_NAME, INTERN));
		if (access(path, F_OK) == 0)
		{
			ret = exec_bin(path, tab, env);
			free(path);
			return (ret);
		}
		free(path);
		i++;
	}
	return (minishell_error(tab[0], NO_CMD));
}

int			path(char **tab, char **env)
{
	int		ret;
	char	*path;
	char	**path_tab;

	ret = 0;
	if (strchr(tab[0], '/'))
		ret = check_file(tab, env);
	else
	{
		if ((path = get_env(PATH, env)) == NULL)
			return (minishell_error(APP_NAME, INTERN));
		if ((path_tab = ft_strsplit(path, ':')) == NULL)
			return (minishell_error(APP_NAME, INTERN));
		ret = check_path(path_tab, tab, env);
		ft_tabstrdel(&path_tab, 0);
	}
	return (ret);
}
