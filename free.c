/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:32:40 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/24 15:21:52 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_texture(t_vars *vars)
{
	mlx_delete_texture(vars->textures.texture_knight);
	mlx_delete_texture(vars->textures.texture_gate);
	mlx_delete_texture(vars->textures.texture_wall);
	mlx_delete_texture(vars->textures.texture_ground);
	mlx_delete_texture(vars->textures.texture_apple);
	mlx_delete_texture(vars->textures.texture_open_gate);
}

void	free_struct(t_vars *vars)
{
	free_texture(vars);
	mlx_terminate(vars->mlx);
	if (vars->map != NULL)
		ft_free(vars->map);
	free(vars);
}
