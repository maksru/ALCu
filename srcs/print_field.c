/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:13:28 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/18 17:05:23 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void		print_field(t_list *const rows)
{
	int		matches;
	t_list	*tmp;
	int		nrow;

	tmp = rows;
	nrow = 0;
	ft_putstr(BOLD_GREEN);
	ft_putendl("Field:");
	ft_putstr(BOLD_CYAN);
	while (tmp)
	{
		matches = *(int *)tmp->content;
		ft_putnbr(++nrow);
		ft_putstr(":  ");
		while (matches--)
			ft_putchar('|');
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putstr(NORMAL_WHITE);
}

void		print_field_with_effects(t_list *const rows)
{
	print_field(rows);
	ft_putstr(BOLD_WHITE);
	ft_putendl("Input number of matches from 1 to 3:");
	ft_putstr(NORMAL_WHITE);
}
