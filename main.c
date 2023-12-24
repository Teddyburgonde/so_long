/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:43:20 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/24 15:55:21 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include "so_long.h"
#include "libftprintf.h"

int	is_valid(t_vars *vars)
{
	char	**tab_copy;
	int		i;
	int		j;

	find_player(vars);
	i = vars->x;
	j = vars->y;
	tab_copy = copy_map(vars);
	if (!tab_copy)
	{
		free_struct(vars);
		exit(EXIT_FAILURE);
	}
	pathfinder(i, j, tab_copy);
	ft_free(tab_copy);
	return (1);
}

void	initialize_value(int *have_apples,
int *have_many_doors, int *have_character)
{
	*have_apples = 0;
	*have_many_doors = 0;
	*have_character = 0;
}

void	calcul_height(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		if (vars->height < ft_strlen(vars->map[i]))
			vars->height = ft_strlen(vars->map[i]);
		i++;
	}
	i = 0;
	while (vars->map[vars->width])
		vars->width++;
}

int	check_errors(t_vars *vars)
{
	int	have_apples;
	int	have_many_doors;
	int	have_character;

	initialize_value(&have_apples, &have_many_doors, &have_character);
	if (error_collectibles(vars, have_apples) == 1
		|| error_too_many_doors(vars, have_many_doors) == 1
		|| error_no_character(vars, have_character) == 1
		|| error_too_many_characters(vars, have_character) == 1)
		return (1);
	return (0);
}

int	struct_init(t_vars *vars, char *file)
{
	int	i;
	int	j;
	int	have_apples;
	int	have_many_doors;
	int	have_character;

	i = 0;
	j = 0;
	initialize_value(&have_apples, &have_many_doors, &have_character);
	vars->move_count = 0;
	vars->height = 0;
	vars->width = 0;
	vars->map = NULL;
	if (parse_map(file, vars) == -1)
		return (1);
	if (check_wall_up(vars) == 1 || check_wall_left(vars) == 1
		|| check_wall_right(vars) == 1 || check_wall_down(vars) == 1)
		return (1);
	if (check_errors(vars) == 1)
		return (1);
	// if (error_collectibles(vars, have_apples) == 1
	// 	|| error_too_many_doors(vars, have_many_doors) == 1
	// 	|| error_no_character(vars, have_character) == 1
	// 	|| error_too_many_characters(vars, have_character) == 1)
		//return (1);
	calcul_height(vars);
	if (!is_valid(vars))
		return (1);
	init_display(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	int		i;

	if (argc == 1)
	{
		ft_printf("ERROR you have not loaded the map\n");
		return (1);
	}
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		return (0);
	i = ft_strlen(argv[1]) - 1;
	if ((argv[1][i] != 'r' || argv[1][i - 1] != 'e' || argv[1][i - 2] != 'b'
		|| argv[1][i - 3] != '.') || struct_init(vars, argv[1]) == 1)
	{
		free(vars);
		ft_printf("ERROR MAP EXTENTION\n");
		return (1);
	}
	display_map_elements(vars);
	mlx_key_hook(vars->mlx, key_press, vars);
	mlx_loop(vars->mlx);
	free_struct(vars);
	return (0);
}
