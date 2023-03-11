/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:31:26 by tkong             #+#    #+#             */
/*   Updated: 2023/03/07 03:00:10 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../ft/ft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WID	800
# define HEI	800

typedef enum e_event
{
	KEYDOWN		= 2,
	KEYUP		= 3,
	MOUSEDOWN	= 4,
	MOUSEUP		= 5,
	MOUSEMOVE	= 6,
	EXPOSE		= 12,
	DESTROY		= 17,
}	t_event;
typedef enum e_key
{
	KEY_ESC		= 0x35,
	KEY_SPACE	= 0x31,
	KEY_0		= 0x1D,
	KEY_MINUS	= 0x1B,
	KEY_EQUAL	= 0x18,
	KEY_UP		= 0x7E,
	KEY_DOWN	= 0x7D,
	KEY_LEFT	= 0x7B,
	KEY_RIGHT	= 0x7C,
	KEY_SHIFT	= 0x101,
	KEY_REST	= 0x2B,
	KEY_FSTOP	= 0x2F,
}	t_key;

typedef enum e_mouse
{
	LEFT_CLICK	= 0x01,
	RIGHT_CLICK	= 0x02,
	MID_CLICK	= 0x03,
	SCROLL_UP	= 0x04,
	SCROLL_DOWN	= 0x05,
}	t_mouse;
typedef enum e_form
{
	AMBIENT_LIGHTING,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	HYPERBOLOID,
	PARABOLOID,
}	t_form;
typedef enum e_argb
{
	ALPHA,
	RED,
	GREEN,
	BLUE,
}	t_argb;
typedef enum e_error
{
	ERROR_ARGUMENT = 1,
	ERROR_FILENAME,
	ERROR_FILEOPEN,
	ERROR_FILEFORMAT,
	ERROR_INITFAIL,
	ERROR_MAX,
}	t_error;

typedef t_bdll	t_list;
typedef struct s_vec
{
	t_f32	x;
	t_f32	y;
	t_f32	z;
}	t_vec;
typedef struct s_obj
{
	t_form	form;
	t_i8	*texture;
	t_i32	color;
	t_f32	ratio_in_range;
	t_f32	fov;
	t_vec	transform;
	t_vec	rotation;
	t_vec	scale;
	t_f32	radius;
}	t_obj;
typedef struct s_data
{
	void	*img;
	t_i8	*addr;
	t_i32	bpp;
	t_i32	llen;
	t_i32	endian;
}	t_data; 
typedef struct s_mlx
{
	void	*_;
	void	*win;
	t_data	data;
}	t_mlx;
typedef struct s_a
{
	t_mlx		mlx;
	t_list		obj;
	t_i8		*filename;
	const t_i8	*msg[ERROR_MAX];
}	t_a;

void	mlx_pixel_put2(t_data *data, t_i32 x, t_i32 y, t_i32 color);
t_i8	mlx_get_rgb(t_i32 color, t_argb part);
void	mlx_set_rgb(t_i32 *color, t_argb part, t_i8 to);

#endif
