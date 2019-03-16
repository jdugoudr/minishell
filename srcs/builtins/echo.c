/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:37:15 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/14 12:19:50 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"
#include "env.h"
#include "minishell_error.h"

int			do_echo(char **tab)
{
	int		i;
	int		r;

	i = 1;
	r = 0;
	while (tab[i])
	{
		if (i != 1)
			ft_putchar(' ');
		ft_putstr(tab[i]);
		i++;
	}
	if (r != 1)
		ft_putchar('\n');
	return (r);
}
