/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:10:18 by tkong             #+#    #+#             */
/*   Updated: 2023/03/02 20:16:32 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_pixel_put2(t_data *data, t_i32 x, t_i32 y, t_i32 color)
{
	*(t_u32 *)(data->addr + (y * data->llen + x * (data->bpp / 8))) = color;
}

t_i8	mlx_get_rgb(t_i32 color, t_argb part)
{
	return (((t_i8 *) &color)[part]);
}

void	mlx_set_rgb(t_i32 *color, t_argb part, t_i8 to)
{
	((t_i8 *) color)[part] = to;
}
