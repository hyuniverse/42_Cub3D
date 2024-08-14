/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:24:24 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/14 20:32:27 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"

void	rotate()
{

}

int	key_hook(int keycode)
{
	if (keycode == W) //전
	{

	}
	else if (keycode == S)  //후
	{

	}
	else if (keycode == A)  //좌
	{ //회전 후 이동

	}
	else if (keycode == D)  //우
	{ //회전 후 이동

	}
	else if (keycode == ESC)
		exit(0);//자원...괜찮은지 확인
	return (0);
}

int	exit_hook(void)
{
	exit(0); //자원 괜찮은지 확인. 아닐 경우 exit 메소드 따로 만들어야. 
}
