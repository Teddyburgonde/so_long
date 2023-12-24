/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_capture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:03:28 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/24 08:38:30 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_capture(t_vars *vars)
{
	mlx_image_to_window(vars->mlx, vars->img_ground, vars->x, vars->y);
	mlx_image_to_window(vars->mlx, vars->img_knight, vars->x, vars->y);
	vars->map[(vars->y / SPRITE_PIXEL)][vars->x / SPRITE_PIXEL] = '0';
	vars->apple_count--;
}
