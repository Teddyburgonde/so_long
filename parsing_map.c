/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:51:27 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/25 16:58:50 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_vars *vars, char *tmp, char *tab, int fd)
{
	while (tmp)
	{
		tab = ft_strjoin(tab, tmp);
		if (tab == NULL)
		{
			free(vars);
			exit(EXIT_FAILURE);
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	vars->map = ft_split(tab, '\n');
	if (vars->map == NULL)
	{
		free(vars);
		exit(EXIT_FAILURE);
	}
	free(tab);
	close(fd);
}

int	parse_map(char *file, t_vars *vars)
{
	char	*tab;
	char	*tmp;
	int		fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
		return (-1);
	tab = get_next_line(fd);
	if (tab == NULL)
	{
		free(tab);
		close(fd);
		return (-1);
	}
	tmp = get_next_line(fd);
	init_map(vars, tmp, tab, fd);
	return (0);
}