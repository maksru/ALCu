/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:29:31 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/18 20:07:43 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static inline int		define_fd(const char *const filename)
{
	int					fd;

	if (!filename)
		fd = 0;
	else
	{
		if ((fd = open(filename, O_RDONLY)) == -1 ||
				read(fd, NULL, 0) == -1)
			return (-1);
	}
	return (fd);
}

static inline int		read_from_file(const char *const filename,
		t_list **const rows,
		char *line,
		int row_count)
{
	int					fd;

	if ((fd = define_fd(filename)) == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		if ((!*line && fd && *rows) || !ft_aredigits(line))
			return (0);
		if (!*line && !fd && *rows)
		{
			free(line);
			break ;
		}
		if ((row_count = ft_atoi(line)) > 0 && row_count <= MAX)
			ft_lstadd(rows, ft_lstnew((void *)&row_count, sizeof(int)));
		else
			return (0);
		free(line);
	}
	if (fd)
		if (close(fd) == -1)
			return (0);
	if (!*rows)
		return (0);
	return (1);
}

static inline void		intro_input(void)
{
	ft_putstr(BOLD_WHITE);
	ft_putendl("Input a number of matches in a row and press ENTER.");
	ft_putendl("At the end just press ENTER in the empty field.");
	ft_putendl("Incorrect data input cases an ERROR");
	ft_putstr(NORMAL_WHITE);
}

int						main(int ac, char **av)
{
	t_list				*rows;
	char				*line;

	ft_putstr(CLEAR);
	rows = NULL;
	if (ac >= 2)
	{
		if (!read_from_file(av[1], &rows, (line = NULL), 0))
		{
			ft_putendl("ERROR");
			return (0);
		}
	}
	else
	{
		intro_input();
		if (!read_from_file(NULL, &rows, (line = NULL), 0))
		{
			ft_putendl("ERROR");
			return (0);
		}
	}
	ft_lstrev(&rows);
	turn(&rows);
	return (0);
}
