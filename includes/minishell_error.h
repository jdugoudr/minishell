/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 14:05:09 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/14 13:39:12 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ERROR_H
# define MINISHELL_ERROR_H

# include "libft.h"

# define STD_ERR	2

# define MANY_ARG	"Too many arguments."
# define FEW_ARG	"Too few arguments."
# define NOT_ALNU	"Variable name must contain alphanumeric characters."
# define INTERN		"Sorry a intern problem happend. You must try again."
# define UNKNOW		"Undefined variable."
# define NO_FILE	"No such file or directory."
# define NO_PERM	"Permission denied."
# define NO_CMD		"Command not found."

int		minishell_error(char *func, char *type);
void	mn_exit(char **tab, char **env, int ret);

#endif
