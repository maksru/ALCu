/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:38:58 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/18 17:35:42 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int			correct_number(const int input_digit)
{
	if (input_digit == 1 ||
			input_digit == 2 ||
			input_digit == 3)
		return (1);
	return (0);
}

void		repeat_msg(const int msg_id)
{
	char	*c;

	ft_putstr(BOLD_RED);
	if (msg_id == WRONG_SYMBOL_MSG)
		ft_putendl("Wrong character in input. Press ONLY enter.");
	else if (msg_id == WRONG_NUMBER_MSG)
		ft_putendl("Wrong number of matches in a row. Press ONLY enter.");
	else if (msg_id == WRONG_COUNT_MSG)
		ft_putendl("Input is bigger then count in a row. Press ONLY enter.");
	c = NULL;
	while (get_next_line(0, &c))
	{
		if (*c == 0)
		{
			free(c);
			break ;
		}
		else
			ft_putendl("O, God, I told you... Press enter at last...");
		free(c);
	}
	ft_putstr(NORMAL_WHITE);
}

int			is_computer_first(void)
{
	char	*answer;

	ft_putstr(BOLD_WHITE);
	ft_putstr("Type 1 for computer first turn and press ENTER. ");
	ft_putendl("Otherwise just press ENTER.");
	ft_putstr(NORMAL_WHITE);
	while (get_next_line(0, &answer))
	{
		if (ft_aredigits(answer) &&
				ft_strlen(answer) == 1)
		{
			if (ft_atoi(answer) == 1)
			{
				free(answer);
				return (1);
			}
			else
				free(answer);
		}
		else
			free(answer);
		return (2);
	}
	return (0);
}
