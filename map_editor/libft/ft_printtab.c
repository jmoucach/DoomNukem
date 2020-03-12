/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:39:12 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/01/02 12:40:04 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = -1;
	if (!(tab && tab[0]))
		return ;
	while (tab[++i][0])
		ft_putendl(tab[i]);
}
