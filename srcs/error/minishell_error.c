/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 14:03:11 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/12 16:59:29 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_error.h"

int		minishell_error(char *func, char *type)
{
	ft_fprintf(STD_ERR, "Error: %s: %s\n", func, type);
	return (1);
}

void	mn_exit(char **tab, char **env, int ret)
{
	if (tab)
		ft_tabstrdel(&tab, 0);
	if (env)
		ft_tabstrdel(&env, 0);
	exit(ret);
}
