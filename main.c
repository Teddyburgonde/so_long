/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:43:20 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/23 15:15:53 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include "so_long.h"
#include "libftprintf.h"

int    is_valid(t_vars *vars)
{
	char **tab_copy;
	int i;
	int j;
	//int len;

	find_player(vars);
    i = vars->x;
    j = vars->y;
	tab_copy = copy_map(vars);
	//print_map(vars);
    pathfinder(i, j, tab_copy);
	//print_map(vars);
    return (1);
}

int   struct_init(t_vars *vars, char *file)
{
    int i;
    int j;
    int have_apples;
    int have_many_doors;
    int have_character;

    have_many_doors = 0;
    have_character = 0;
    vars->move_count = 0;
    vars->height = 0;
    vars->width = 0;
    have_apples = 0;
    j = 0;
    i = 0;

    parse_map(file, vars);
    if (check_wall_up(vars) == 1)
        return (1);
    if (check_wall_left(vars) == 1)
        return (1);
    if (check_wall_right(vars) == 1)
        return (1);
    if (check_wall_down(vars) == 1)
        return (1);
    if (error_collectibles(vars, have_apples) == 1)
        return (1);
    if (error_too_many_doors(vars, have_many_doors) == 1)
        return (1);
    if (error_no_character(vars, have_character) == 1)
        return (1);
    if (error_too_many_characters(vars, have_character) == 1)
        return (1);
    while (vars->map[i])
    {
        if (vars->height < ft_strlen(vars->map[i]))
            vars->height = ft_strlen(vars->map[i]);
        i++;
    }
    while (vars->map[vars->width])
        vars->width++;
    if (!is_valid(vars))
        return (1);
    init_display(vars);
    return (0);
}

int main(int argc, char **argv)
{ 
    t_vars *vars;
    vars = malloc(sizeof(t_vars));
	ft_bzero(vars, sizeof(t_vars));
    int i;

	if (argc == 1)
	{
		ft_printf("ERROR error you have not loaded the card");
		return (1);
	}
    i = ft_strlen(argv[1]) - 1;
    if (argv[1][i] != 'r' || argv[1][i - 1] != 'e' || argv[1][i - 2] != 'b' || argv[1][i - 3] != '.')
    {
        ft_printf("ERROR MAP EXTENTION");
        return (1);
    }
    if (struct_init(vars, argv[1]) == 1)
        return (1);
    display_map_elements(vars);
    mlx_key_hook(vars->mlx, key_press, vars);
    mlx_loop(vars->mlx);
    return (0);
}
