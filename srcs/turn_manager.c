/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:35:44 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/18 18:25:46 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static inline void		computer_turn(t_list **rows,
		int *const is_end)
{
	ft_putendl("Computer turns.");
	ft_putstr("He brings ");
	ft_putstr(BOLD_WHITE);
	ft_putnbr(calculate_turn(rows));
	ft_putstr(NORMAL_WHITE);
	ft_putendl(" matches.");
	if (!*rows)
	{
		*is_end = 1;
		ft_putstr(BOLD_GREEN);
		ft_putendl("Player wins.");
	}
}

static inline int		init_turn(t_list **rows, int *is_end)
{
	int					kt;

	kt = 0;
	if ((kt = is_computer_first()) == 1)
		computer_turn(rows, is_end);
	else if (kt == 0)
	{
		ft_putstr(CLEAR);
		ft_putendl("ERROR");
		return (0);
	}
	return (1);
}

static inline int		wrong_input(char *input)
{
	if (!ft_aredigits(input))
	{
		free(input);
		repeat_msg(WRONG_SYMBOL_MSG);
		return (1);
	}
	return (0);
}

static inline int		human_turn(t_list **rows,
		int input_digit,
		int *is_end)
{
	if (!correct_number(input_digit))
	{
		repeat_msg(WRONG_NUMBER_MSG);
		return (0);
	}
	else if (*(int *)(*rows)->content < input_digit)
	{
		repeat_msg(WRONG_COUNT_MSG);
		return (0);
	}
	else
	{
		if (!(*(int *)(*rows)->content -= input_digit))
		{
			pop_one(rows);
			if (!*rows)
			{
				*is_end = 1;
				ft_putstr(BOLD_RED);
				ft_putendl("Computer wins.");
				return (0);
			}
		}
	}
	return (1);
}

void					turn(t_list **rows)
{
	char				*input;
	int					input_digit;
	int					is_end;

	is_end = 0;
	input_digit = 0;
	if (!init_turn(rows, &is_end))
		return ;
	while (!is_end)
	{
		print_field_with_effects(*rows);
		get_next_line(0, &input);
		ft_putstr(CLEAR);
		if (wrong_input(input))
			continue ;
		else
		{
			input_digit = ft_atoi(input);
			free(input);
			if (!human_turn(rows, input_digit, &is_end))
				continue ;
		}
		computer_turn(rows, &is_end);
	}
	ft_putstr(NORMAL_WHITE);
}
