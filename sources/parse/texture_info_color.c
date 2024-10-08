/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_info_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:04:43 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/28 16:22:39 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void	is_valid_color_line(char *line, int i, int comma_cnt, int num_cnt)
{
	if (is_num(line[0]) == FALSE)
		print_error("Error");
	while (line[i] && line[i] != '\n')
	{
		if (is_num(line[i]) == TRUE)
			num_cnt++;
		else if (line[i] == ',')
		{
			num_cnt = 0;
			comma_cnt++;
			if (line[i - 1] == ',')
				print_error("Error");
		}
		else
			print_error("Error");
		if (num_cnt > 3 || comma_cnt > 2)
			print_error("Error");
		i++;
	}
	if (num_cnt == 0)
		print_error("Error");
}

unsigned int	str_to_rgb(char *str)
{
	int				i;
	int				num_idx;
	unsigned int	rgb[2];

	i = 0;
	num_idx = 0;
	rgb[0] = 0;
	rgb[1] = 0;
	is_valid_color_line(str, 1, 0, 0);
	while (str[i])
	{
		if (str[i] == ',')
		{
			str_to_color(str, num_idx, i, rgb);
			num_idx = i + 1;
			rgb[0]++;
		}
		i++;
	}
	str_to_color(str, num_idx, i - 1, rgb);
	return (rgb[1]);
}

void	str_to_color(char *str, int num_idx, int i, unsigned int *rgb)
{
	int	result;

	result = 0;
	while (num_idx < i)
	{
		result = result * 10 + (str[num_idx] - '0');
		num_idx++;
	}
	if (result > 255)
		print_error("Error");
	if (rgb[0] == 0)
		rgb[1] = rgb[1] | (result << 16);
	else if (rgb[0] == 1)
		rgb[1] = rgb[1] | (result << 8);
	else if (rgb[0] == 2)
		rgb[1] = rgb[1] | result;
}
