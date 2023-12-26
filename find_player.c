/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:44:03 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/26 15:08:33 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map[j])
	{
		i = 0;
		while (vars->map[j][i])
		{
			if (vars->map[j][i] == 'P')
			{
				vars->y = j;
				vars->x = i;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	find_gate(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map[j])
	{
		i = 0;
		while (vars->map[j][i])
		{
			if (vars->map[j][i] == 'E')
			{
				vars->b = j;
				vars->a = i;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	find_collectibles(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map[j])
	{
		i = 0;
		while (vars->map[j][i])
		{
			if (vars->map[j][i] == 'C')
			{
				vars->d = j;
				vars->c = i;
				return ;
			}
			i++;
		}
		j++;
	}
}
