/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:16:09 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/15 14:32:39 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_prompt(char *prompt)
{
	char	*home;
	char	*tmp;
	size_t	len;

	home = get_env(HOME, g_env);
	if (prompt && home)
	{
		len = ft_strlen(home);
		if (home[0] != '\0' && (home = ft_strstr(prompt, home))
				&& (tmp = ft_strnew(ft_strlen(prompt) - len + 1)))
		{
			ft_strncat(tmp, prompt, home - prompt);
			ft_strcat(tmp, "~");
			ft_strcat(tmp, prompt + len);
			ft_printf("%s : ", tmp);
			free(tmp);
			free(prompt);
			return ;
		}
		ft_printf("%s : ", prompt);
	}
	else
		ft_putstr("prompt : ");
	free(prompt);
}
