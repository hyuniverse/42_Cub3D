/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:46:19 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/14 20:31:51 by sehyupar         ###   ########.fr       */
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
