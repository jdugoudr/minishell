/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:59:26 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/15 14:32:16 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_c(int sig)
{
	if (sig != 2)
		return ;
	if (g_child)
		kill(g_child, SIGQUIT);
	else
	{
		ft_printf("\n");
		do_prompt(getcwd(NULL, 0));
	}
}
