/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_unclose_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:26:13 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/21 17:30:40 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_up(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[0][i])
	{
		if (vars->map[0][i] != '1')
		{
			ft_printf("ERROR : INVALID MAP");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_wall_left(t_vars *vars)
{
	int	j;

	j = 0;
	while (vars->map[j])
	{
		if (vars->map[j][0] != '1')
		{
			ft_printf("ERROR : INVALID MAP");
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_wall_right(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[j])
	{
		while (vars->map[j][i])
		{
			i++;
		}
		i--;
		if (vars->map[j][i] != '1')
		{
			ft_printf("ERROR : INVALID MAP");
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_wall_down(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[j])
		j++;
	j--;
	while (vars->map[j][i])
	{
		if (vars->map[j][i] != '1')
		{
			ft_printf("ERROR : INVALID MAP");
			return (1);
		}
		i++;
	}
	return (0);
}
