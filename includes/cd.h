/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:04:04 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/14 13:43:22 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include "libft.h"
# include "minishell_error.h"
# include "parse.h"
# include "env.h"
# include <unistd.h>
# include <pwd.h>

int	cd(char *path, size_t len_arg, char ***env);

#endif
