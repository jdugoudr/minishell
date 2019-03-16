/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:27:33 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/15 09:44:05 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "echo.h"
# include "minishell.h"
# include "minishell_error.h"
# include "env.h"
# include "cd.h"
# include "libft.h"
# include "path.h"

# define ENV		"env"
# define SETENV		"setenv"
# define UNENV		"unsetenv"
# define ECHO		"echo"
# define CD			"cd"
# define EXIT		"exit"
# define APP_NAME	"minishell"

int	parse(char **multicmd, char ***env, int ret);

int	parse_distribute(char **tabline, char ***env);

int	lex_var(char **tab, char **env, int ret);

int	do_simple_dolls(char **line, int *i, int ret);
int	ask_env(char **line, char **env, int *i);

#endif
