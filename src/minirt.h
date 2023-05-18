/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:31:26 by tkong             #+#    #+#             */
/*   Updated: 2023/03/16 07:16:27 by tkong            ###   ########.fr       */
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
	DESTROY		= 17,
}	t_event;
typedef enum e_key
{
	KEY_ESC		= 0x35,
}	t_key;
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
	BLUE,
	GREEN,
	RED,
	ALPHA,
}	t_argb;
typedef enum e_error
{
	ERROR_ARGUMENT = 1,
	ERROR_FILENAME,
	ERROR_FILEOPEN,
	ERROR_FILEFORMAT,
	ERROR_INITFAIL,
	ERROR_CAMERA,
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
	t_data	dat;
}	t_mlx;
typedef struct s_a
{
	t_mlx		mlx;
	t_list		obj;
	t_obj		*camera;
	t_i8		*filename;
	const t_i8	*msg[ERROR_MAX];
}	t_a;

void	mlx_pixel_put2(t_data *dat, t_i32 x, t_i32 y, t_i32 color);
t_i8	mlx_get_rgb(t_i32 color, t_argb part);
void	mlx_set_rgb(t_i32 *color, t_argb part, t_i8 to);

void	error(const t_i8 **msg, t_error err);
t_i32	quit(void);
t_i32	count_string(t_i8 **strs);
t_i32	extract_color(t_a *a, t_i8 *color);

// t_vec	make_vec_randomly(float, float)
t_vec	extract_vec(t_a *a, t_i8 *vec);
t_vec	make_vec(t_f32 x, t_f32 y, t_f32 z);
t_vec	neg_vec(t_vec *v);
t_vec	sum_vec(t_vec *v, t_vec *v2);
t_vec	sub_vec(t_vec *v, t_vec *v2);
t_vec	mlt_vec(t_vec *v, t_vec *v2);
t_vec	div_vec(t_vec *v, t_vec *v2);
t_vec	_mlt_vec(t_f32 t, t_vec *v);
t_vec	mlt_vec_(t_vec *v, t_f32 t);
t_vec	div_vec_(t_vec *v, t_f32 t);
t_vec	cross(t_vec *v, t_vec *v2);
t_f32	dot(t_vec *v, t_vec *v2);
t_f32	length_squared(t_vec *v);
t_f32	length(t_vec *v);
t_vec	unt_vec(t_vec *v);

void	render(t_a *a);

t_i32	key_down(t_i32 key, t_a *a);
t_i32	mouse_down(t_i32 butten, t_i32 x, t_i32 y, t_a *a);

void	scan_file(t_a *a);

void	ambient_lighting(t_a *a, t_i8 **strs);
void	camera(t_a *a, t_i8 **strs);
void	light(t_a *a, t_i8 **strs);
void	sphere(t_a *a, t_i8 **strs);
void	plane(t_a *a, t_i8 **strs);
void	cylinder(t_a *a, t_i8 **strs);

#endif
