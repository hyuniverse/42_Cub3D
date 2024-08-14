/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:32:53 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/14 16:50:33 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static int	cub3d_split_count(char const *s, char c);
static int	cub3d_make_result2(char const *s, char **result, int i, int j);
static int	cub3d_make_result(char const *s, char c, char **result, int flag);

static int	cub3d_split_count(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (cnt);
}

static int	cub3d_make_result2(char const *s, char **result, int i, int j)
{
	*result = (char *)malloc(sizeof(char) * (i - j + 1));
	if (*result == NULL)
		return (1);
	ft_strlcpy(*result, s + j, i - j + 1);
	return (0);
}

static int	cub3d_make_result(char const *s, char c, char **result, int flag)
{
	int	i;
	int	j;
	int	cnt;

	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (s[i] != c && flag == 0)
		{
			j = i;
			flag = 1;
			cnt++;
		}
		else if (s[i] == c && flag == 1)
		{
			if (cub3d_make_result2(s, result++, i, j) != 0)
				return (cnt);
			flag = 0;
		}
	}
	if (flag == 1)
		if (cub3d_make_result2(s, result, i, j) != 0)
			return (cnt);
	return (0);
}

char	**cub3d_split(char const *s, char c)
{
	char	**result;
	int		arr_cnt;
	int		idx;
	int		cnt;

	idx = -1;
	arr_cnt = cub3d_split_count(s, c);
	if (arr_cnt > 2)
		print_error("Error");
	result = (char **)malloc(sizeof(char *) * (arr_cnt + 1));
	if (result == NULL)
		return (NULL);
	cnt = cub3d_make_result(s, c, result, 0);
	if (cnt > 0)
	{
		while (--cnt > 0)
			free(result[++idx]);
		free(result);
		return (NULL);
	}
	result[arr_cnt] = NULL;
	return (result);
}
