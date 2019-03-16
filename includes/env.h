/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:32:33 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/14 13:40:29 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"

# define HOME	"$HOME"
# define OLDPWD	"$OLDPWD"
# define PWD	"$PWD"
# define PATH	"$PATH"

void	print_env(char **env);
char	**init_env(void);
char	*get_env(char *name, char **env);
int		set_env(char *name, char *value, char ***env);
int		unset_env(char *name, char ***env);

#endif
