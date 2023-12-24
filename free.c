/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:32:40 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/24 10:12:11 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_texture(t_vars *vars)
{
	mlx_delete_texture(vars->texture_knight);
	mlx_delete_texture(vars->texture_gate);
	mlx_delete_texture(vars->texture_wall);
	mlx_delete_texture(vars->texture_ground);
	mlx_delete_texture(vars->texture_apple);
	mlx_delete_texture(vars->texture_open_gate);
}

void	free_struct(t_vars *vars)
{
	free_texture(vars);
	mlx_terminate(vars->mlx);
	ft_free(vars->map);
	free(vars);
}
void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}