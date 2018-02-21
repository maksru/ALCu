/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dellist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:10:06 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/18 19:11:50 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void		pop_one(t_list **lst)
{
	t_list	*next;

	next = (*lst)->next;
	free((*lst)->content);
	free(*lst);
	*lst = next;
}

void		lstdelall(t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free((int *)(*lst)->content);
		free(*lst);
		*lst = next;
	}
}
