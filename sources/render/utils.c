/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:46:19 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/17 18:56:06 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"

void	set_doub_vector(t_doub_vector *vec, double x, double y)
{
	vec->x = x;
	vec->y = y;
}

void	set_int_vector(t_int_vector *vec, int x, int y)
{
	vec->x = x;
	vec->y = y;
}

double	get_time(void)
{
	struct timeval	time;
	double			result;

	time.tv_sec = 0;
	time.tv_usec = 0;
	gettimeofday(&time, 0);
	result = (double)(time.tv_usec);
	return (result);
}

double	get_delta(double ray_dir)
{
	double	delta_dist;

	if (ray_dir == 0)
		delta_dist = 1e30;
	else
	{
		delta_dist = 1 / ray_dir;
		if (delta_dist < 0)
			delta_dist = -delta_dist;
	}
	return (delta_dist);
}

int	get_dir(double component_value, char component, int sign)
{
	if (component == 'y')
	{
		if (sign * component_value > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
	else
	{
		if (sign * component_value > 0)
			return (WEST);
		else
			return (EAST);
	}
}
