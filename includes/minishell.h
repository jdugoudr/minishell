/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:48:13 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/15 15:05:53 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "env.h"
# include "signal.h"

# define STD_IN		0

# define EXIT		"exit"
# define BUFF		50

pid_t	g_child;
char	**g_env;

void	signal_c(int sig);
void	do_prompt(char *prompt);

#endif
