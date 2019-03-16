/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:18:57 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/15 14:06:35 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_BIN_H
# define EXEC_BIN_H

# include "minishell.h"
# include "minishell_error.h"

int	exec_bin(char *cmd, char **arg, char **env);

#endif
