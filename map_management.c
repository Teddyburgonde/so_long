/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:27:20 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/26 11:32:42 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **tab_copy)
{
 	int		k;
 	k = 0;
 	while (tab_copy[k])
	{
		ft_printf("%s\n", tab_copy[k]);
 		k++;
	}
	//ft_free(tab_copy);
}
char	**pathfinder(int x, int y, char **map)
{
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'T')
	{
		map[y - 1][x] = 'T';
		pathfinder(x, y - 1, map);
	}
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'T')
	{
		map[y + 1][x] = 'T';
		pathfinder(x, y + 1, map);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'T')
	{
		map[y][x - 1] = 'T';
		pathfinder(x - 1, y, map);
	}
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'T')
	{
		map[y][x + 1] = 'T';
		pathfinder(x + 1, y, map);
	}
	else if ((map[y - 1][x] == '1') && (map[y][x + 1] == '1') 
		&& (map[y][x - 1] == '1') && (map[y][x + 1] == '1'))
	{
		ft_printf("ERROR the game cannot be completed");
		ft_free(map);
		exit(EXIT_FAILURE);
	}
	
	return (map);
}

int	is_valid(t_vars *vars)
{
	char	**tab_copy;
	int		i;
	int		j;

	find_player(vars);
	i = vars->x;
	j = vars->y;
	tab_copy = copy_map(vars);
	print_map(vars->map);
	if (!tab_copy)
	{
		free_struct(vars);
		exit(EXIT_FAILURE);
	}
	ft_printf("\n");
	print_map(pathfinder(i, j, tab_copy));
	
	//print_map(vars->map);
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
