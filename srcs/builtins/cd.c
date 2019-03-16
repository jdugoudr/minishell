/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:02:29 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/14 12:18:45 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

static int	check_path(char *path, char **final_path, char **env)
{
	if (path == NULL)
	{
		*final_path = ft_strdup(get_env(HOME, env));
		if (!*final_path)
			return (minishell_error(CD, INTERN));
		if ((*final_path)[0] == '\0')
			return (minishell_error(HOME + 1, UNKNOW));
	}
	else if (ft_strcmp(path, "-") == 0)
		*final_path = ft_strdup(get_env(OLDPWD, env));
	else
		*final_path = ft_strdup(path);
	if (!*final_path)
		return (minishell_error(CD, INTERN));
	else if (access(*final_path, F_OK))
		return (minishell_error(*final_path, NO_FILE));
	else if (access(*final_path, X_OK))
		return (minishell_error(*final_path, NO_PERM));
	return (0);
}

static int	set_dir_env(char *old, char ***env)
{
	char	*new;

	new = getcwd(NULL, 0);
	if (new == NULL)
		return (minishell_error(CD, INTERN));
	set_env(OLDPWD + 1, old, env);
	set_env(PWD + 1, new, env);
	free(new);
	return (0);
}

int			cd(char *path, size_t len_arg, char ***env)
{
	char	*dest_dir;
	char	*curr_dir;
	int		r;

	r = 0;
	dest_dir = NULL;
	curr_dir = getcwd(NULL, 0);
	if (!curr_dir)
		return (minishell_error(CD, INTERN));
	if (len_arg > 2)
		r = minishell_error(CD, MANY_ARG);
	else if (check_path(path, &dest_dir, *env))
		r = 1;
	else if (ft_strcmp(curr_dir, dest_dir) == 0)
		r = 0;
	else if (chdir(dest_dir) == -1)
		r = minishell_error(CD, INTERN);
	else
		r = set_dir_env(curr_dir, env);
	free(curr_dir);
	free(dest_dir);
	return (r);
}
