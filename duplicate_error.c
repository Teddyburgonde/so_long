/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:24:28 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/25 08:28:17 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_errors(t_vars *vars)
{
	int	have_apples;
	int	have_many_doors;
	int	have_character;

	have_apples = 0;
	have_many_doors = 0;
	have_character = 0;
	if (error_collectibles(vars, have_apples) == 1
		|| error_too_many_doors(vars, have_many_doors) == 1
		|| error_no_character(vars, have_character) == 1
		|| error_too_many_characters(vars, have_character) == 1)
		return (1);
	return (0);
}
