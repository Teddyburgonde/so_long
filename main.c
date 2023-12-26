/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:43:20 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/26 18:22:22 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include "so_long.h"
#include "libftprintf.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;
	int		i;

	if (argc == 1)
	{
		ft_putstr_fd("ERROR\n you didn't load the map\n", 2);
		return (1);
	}
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		return (0);
	i = ft_strlen(argv[1]) - 1;
	
	if (i < 3)
	{
		free(vars);
		ft_printf("ERROR MAP EXTENTION\n");
		return (1);	
	}
	if ((i >= 4 && ft_strncmp(&argv[1][i - 3], ".ber", 4))
		|| (struct_init(vars, argv[1]) == 1))
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