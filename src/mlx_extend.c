/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:10:18 by tkong             #+#    #+#             */
/*   Updated: 2023/05/20 09:16:02 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_pixel_put2(t_data *data, t_i32 x, t_i32 y, t_i32 color)
{
	*(t_u32 *)(data->addr + (y * data->llen + x * (data->bpp / 8))) = color;
}

t_u8	mlx_get_rgb(t_i32 color, t_argb part)
{
	return (((t_u8 *) &color)[part]);
}

void	mlx_set_rgb(t_i32 *color, t_argb part, t_u8 to)
{
	((t_u8 *) color)[part] = to;
}
