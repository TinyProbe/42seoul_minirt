/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:04:05 by tkong             #+#    #+#             */
/*   Updated: 2023/03/19 13:41:51 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_i32	calc_pixel(t_a *a, t_i32 x, t_i32 y);

void	render(t_a *a)
{
	t_i32	i;
	t_i32	j;

	i = HEI;
	while (i--)
	{
		j = WID;
		while (j--)
			mlx_pixel_put2(&(a->mlx.dat), j, i, calc_pixel(a, j, i));
	}
	mlx_put_image_to_window(a->mlx._, a->mlx.win, a->mlx.dat.img, 0, 0);
}

static t_i32	calc_pixel(t_a *a, t_i32 x, t_i32 y)
{
	(void) a;
	(void) x;
	(void) y;
	return (0x00ff00ff);
}
