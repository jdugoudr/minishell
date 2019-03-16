/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:17:14 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/14 13:41:43 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "minishell_error.h"
# include "exec_bin.h"
# include "env.h"
# include "parse.h"
# include <unistd.h>

int	path(char **tab, char **env);
#endif
