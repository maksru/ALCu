/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:43:01 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/18 19:51:57 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define MAX 10000
# define HUMAN 1
# define MACHINE 0
# define WRONG_SYMBOL_MSG 0
# define WRONG_NUMBER_MSG 1
# define WRONG_COUNT_MSG 2
# define BOLD_RED "\033[1;31m"
# define NORMAL_WHITE "\033[0;39m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_CYAN "\033[1;36m"
# define BOLD_WHITE "\033[1;39m"
# define CLEAR "\033[1J\033[;H"

void			print_field(t_list *const rows);
void			print_field_with_effects(t_list *const rows);
void			print_sort_field(int *const rows);
void			turn(t_list **rows);
void			pop_one(t_list **lst);
void			repeat_msg(const int msg_id);
int				correct_number(const int input_digit);
int				is_computer_first(void);
int				calculate_turn(t_list **rows);
void			lstdelall(t_list **rows);
#endif
