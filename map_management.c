/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:27:20 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/26 16:47:54 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**pathfinder_exit(int a, int b, char **map)
{
	if (map[b - 1][a] != '1' && map[b - 1][a] != 'Z')
	{
		map[b - 1][a] = 'Z';
		pathfinder_exit(a, b - 1, map);
	}
	if (map[b + 1][a] != '1' && map[b + 1][a] != 'Z')
	{
		map[b + 1][a] = 'Z';
		pathfinder_exit(a, b + 1, map);
	}
	if (map[b][a - 1] != '1' && map[b][a - 1] != 'Z')
	{
		map[b][a - 1] = 'Z';
		pathfinder_exit(a - 1, b, map);
	}
	if (map[b][a + 1] != '1' && map[b][a + 1] != 'Z')
	{
		map[b][a + 1] = 'Z';
		pathfinder_exit(a + 1, b, map);
	}
	if ((map[b - 1][a] == '1') && (map[b][a + 1] == '1')
		&& (map[b][a - 1] == '1') && (map[b][a + 1] == '1'))
		message_exit_error(map);
	return (map);
}

char	**pathfinder_collectibles(int c, int d, char **map)
{
	if (map[d - 1][c] != '1' && map[d - 1][c] != 'W')
	{
		map[d - 1][c] = 'W';
		pathfinder_collectibles(c, d - 1, map);
	}
	if (map[d + 1][c] != '1' && map[d + 1][c] != 'W')
	{
		map[d + 1][c] = 'W';
		pathfinder_collectibles(c, d + 1, map);
	}
	if (map[d][c - 1] != '1' && map[d][c - 1] != 'W')
	{
		map[d][c - 1] = 'W';
		pathfinder_collectibles(c - 1, d, map);
	}
	if (map[d][c + 1] != '1' && map[d][c + 1] != 'W')
	{
		map[d][c + 1] = 'W';
		pathfinder_collectibles(c + 1, d, map);
	}
	if ((map[d - 1][c] == '1') && (map[d][c + 1] == '1')
		&& (map[d][c - 1] == '1') && (map[d][c + 1] == '1'))
		message_collectibles(map);
	return (map);
}

char	**pathfinder_character(int x, int y, char **map)
{
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'T')
	{
		map[y - 1][x] = 'T';
		pathfinder_character(x, y - 1, map);
	}
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'T')
	{
		map[y + 1][x] = 'T';
		pathfinder_character(x, y + 1, map);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'T')
	{
		map[y][x - 1] = 'T';
		pathfinder_character(x - 1, y, map);
	}
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'T')
	{
		map[y][x + 1] = 'T';
		pathfinder_character(x + 1, y, map);
	}
	//if 
	
	// if ((map[y - 1][x] == '1') && (map[y][x + 1] == '1')
	// 	&& (map[y][x - 1] == '1') && (map[y][x + 1] == '1'))
	// 	message_character(map);
	return (map);
}

int	is_valid(t_vars *vars, int i, int j, int k)
{
	char	**tab_copy;
	int		l;
	int		m;
	int		n;

	find_player(vars);
	find_gate(vars);
	find_collectibles(vars);
	i = vars->x;
	j = vars->y;
	k = vars->a;
	l = vars->b;
	m = vars->c;
	n = vars->d;
	tab_copy = copy_map(vars);
	if (!tab_copy)
	{
		free_struct(vars);
		exit(EXIT_FAILURE);
	}
	pathfinder_character(i, j, tab_copy);
	if ()
	pathfinder_exit(k, l, tab_copy);
	pathfinder_collectibles(m, n, tab_copy);
	ft_free(tab_copy);
	return (1);
}

char	**copy_map(t_vars *vars)
{
	char	**tab_copy;
	int		j;

	j = 0;
	while (vars->map[j])
		j++;
	tab_copy = malloc(sizeof(char *) * (j + 1));
	if (!tab_copy)
		return (NULL);
	j = 0;
	while (vars->map[j])
	{
		tab_copy[j] = ft_strdup(vars->map[j]);
		if (!tab_copy[j])
		{
			while (j > 0)
				free(tab_copy[j--]);
			free(tab_copy);
			return (NULL);
		}
		j++;
	}
	tab_copy[j] = NULL;
	return (tab_copy);
}
