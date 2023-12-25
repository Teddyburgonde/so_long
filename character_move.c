/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:41:02 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/25 16:41:14 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up_down(t_vars *vars, int movement)
{
	mlx_delete_image(vars->mlx, vars->images.img_knight);
	vars->images.img_knight = mlx_new_image(vars->mlx,
			vars->height, vars->width);
	vars->images.img_knight = mlx_texture_to_image(vars->mlx,
			vars->textures.texture_knight);
	mlx_image_to_window(vars->mlx, vars->images.img_knight, vars->x,
		vars->y + movement);
	vars->y += movement;
	vars->move_count++;
	ft_printf("%d\n", vars->move_count);
}

void	move_left_right(t_vars *vars, int movement)
{
	mlx_delete_image(vars->mlx, vars->images.img_knight);
	vars->images.img_knight = mlx_new_image(vars->mlx,
			vars->height, vars->width);
	vars->images.img_knight = mlx_texture_to_image(vars->mlx,
			vars->textures.texture_knight);
	mlx_image_to_window(vars->mlx, vars->images.img_knight,
		vars->x + movement, vars->y);
	vars->x += movement;
	vars->move_count++;
	ft_printf("%d\n", vars->move_count);
}
