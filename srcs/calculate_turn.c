/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_turn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:43:25 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/18 17:44:59 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static inline int	last_row_turn(t_list **rows,
		int current,
		int *decrease)
{
	if (current == 1)
	{
		pop_one(rows);
		return (0);
	}
	else if (current == 2)
		*decrease = 1;
	else if (current == 3)
		*decrease = 2;
	else if (current == 4)
		*decrease = 3;
	else if (current >= 6)
		*decrease = 3;
	else
		*decrease = 1;
	return (1);
}

static inline int	usual_computer_turn(t_list **rows,
		int current,
		int next,
		int *decrease)
{
	if (correct_number(current))
	{
		if (next >= 5 || next == 1 || current == 1)
		{
			pop_one(rows);
			return (0);
		}
		else if (next == 3 || next == 2)
			*decrease = current - 1;
	}
	else
	{
		if (current >= 9)
			*decrease = 3;
		else if (current >= 6)
			*decrease = 2;
		else
			*decrease = 1;
	}
	return (1);
}

static inline int	final_turn_check(t_list **rows, int decrease,
		int current)
{
	if (!decrease)
	{
		decrease = 1;
		if (current == 1)
		{
			pop_one(rows);
			return (current);
		}
	}
	*(int *)(*rows)->content -= decrease;
	return (decrease);
}

int					calculate_turn(t_list **rows)
{
	int				current;
	int				decrease;
	int				next;

	decrease = 0;
	current = *(int *)(*rows)->content;
	if (!(*rows)->next)
	{
		if (!last_row_turn(rows, current, &decrease))
			return (1);
	}
	else
	{
		next = *(int *)(*rows)->next->content;
		if (!usual_computer_turn(rows, current, next,
					&decrease))
			return (1);
	}
	return (final_turn_check(rows, decrease, current));
}
