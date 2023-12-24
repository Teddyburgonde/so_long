/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:35:57 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/24 08:36:40 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_vars *vars, int element, int movement)
{
	if ((element == MLX_KEY_W
			&& vars->map[(vars->y / SPRITE_PIXEL) - 1][vars->x / SPRITE_PIXEL] != '1')
	|| (element == MLX_KEY_S
			&& vars->map[(vars->y / SPRITE_PIXEL) + 1][vars->x / SPRITE_PIXEL] != '1'))
	{
		move_up_down(vars, movement);
	}
	if ((element == MLX_KEY_A && vars->map[vars->y / SPRITE_PIXEL][vars->x / SPRITE_PIXEL -1] != '1')
	|| (element == MLX_KEY_D && vars->map[vars->y / SPRITE_PIXEL][vars->x / SPRITE_PIXEL +1] != '1'))
	{
		move_left_right(vars, movement);
	}
	if (vars->map[(vars->y / SPRITE_PIXEL)][vars->x / SPRITE_PIXEL] == 'C')
		collectible_capture(vars);
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;

	(void) keydata;
	vars = param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
		move(vars, MLX_KEY_W, - SPRITE_PIXEL);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
		move(vars, MLX_KEY_A, - SPRITE_PIXEL);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
		move(vars, MLX_KEY_S, SPRITE_PIXEL);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
		move(vars, MLX_KEY_D, SPRITE_PIXEL);
	if (vars->apple_count == 0)
	{
		mlx_image_to_window(vars->mlx, vars->img_ground,
			vars->x_gate, vars->y_gate);
		mlx_image_to_window(vars->mlx, vars->img_open_gate,
			vars->x_gate, vars->y_gate);
		if (vars->map[(vars->y / SPRITE_PIXEL)][vars->x / SPRITE_PIXEL] == 'E')
			mlx_close_window(vars->mlx);
	}
}
