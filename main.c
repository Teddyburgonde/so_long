/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:43:20 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/27 10:09:01 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include "so_long.h"
#include "libftprintf.h"

static void	error_message_extention(t_vars *vars, int i, char **argv)
{
	if (i < 3)
	{
		free(vars);
		ft_putstr_fd("ERROR\nMAP EXTENTION !\n", 2);
		exit(EXIT_FAILURE);
	}
	if ((i >= 4 && ft_strncmp(&argv[1][i - 3], ".ber", 4))
		|| (struct_init(vars, argv[1]) == 1))
	{
		free(vars);
		ft_putstr_fd("ERROR\nMAP EXTENTION !\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	int		i;

	if (argc == 1)
	{
		ft_putstr_fd("ERROR\nYou didn't load the map !\n", 2);
		return (1);
	}
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		return (0);
	i = ft_strlen(argv[1]) - 1;
	error_message_extention(vars, i, argv);
	display_map_elements(vars);
	mlx_key_hook(vars->mlx, key_press, vars);
	mlx_loop(vars->mlx);
	free_struct(vars);
	return (0);
}
