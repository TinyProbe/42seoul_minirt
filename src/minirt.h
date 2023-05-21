/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:31:26 by tkong             #+#    #+#             */
/*   Updated: 2023/05/21 17:54:58 by tkong            ###   ########.fr       */
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
# define PI		3.1416f

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
	AMB_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
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
	ERROR_AMBIENT,
	ERROR_CAMERA,
	ERROR_MAX,
}	t_error;

typedef t_bdll	t_list;
typedef struct s_v3
{
	t_f32	x;
	t_f32	y;
	t_f32	z;
}	t_v3;
typedef struct s_mat4
{
	t_f32	_[4][4];
}	t_mat4;
typedef struct s_obj
{
	t_form	form;
	t_i32	color;
	t_f32	rto_rng;
	t_f32	fov;
	t_v3	transform;
	t_v3	rotation;
	t_v3	scale;
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
	t_obj		*ambient;
	t_i8		*file;
	const t_i8	*msg[ERROR_MAX];
}	t_a;

void	mlx_pixel_put2(t_data *dat, t_i32 x, t_i32 y, t_i32 color);
t_u8	mlx_get_rgb(t_i32 *color, t_argb part);
void	mlx_set_rgb(t_i32 *color, t_argb part, t_u8 to);

void	error(const t_i8 **msg, t_error err);
t_i32	quit(void);
t_i32	count_string(t_i8 **strs);
t_i32	extract_color(t_a *a, t_i8 *color);
t_f32	to_degree(t_f32 radian);
t_f32	to_radian(t_f32 degree);
void	mat4cpy(t_mat4 *dst, t_mat4 *src);

t_v3	extract_v3(t_a *a, t_i8 *val);
t_v3	make_v3(t_f32 x, t_f32 y, t_f32 z);
t_v3	neg_v3(t_v3 *v);
t_v3	sum_v3(t_v3 *v, t_v3 *v2);
t_v3	sub_v3(t_v3 *v, t_v3 *v2);
t_v3	mlt_v3(t_v3 *v, t_v3 *v2);
t_v3	div_v3(t_v3 *v, t_v3 *v2);
t_v3	_mlt_v3(t_f32 t, t_v3 *v);
t_v3	mlt_v3_(t_v3 *v, t_f32 t);
t_v3	div_v3_(t_v3 *v, t_f32 t);
t_f32	dot(t_v3 *v, t_v3 *v2);
t_v3	cross(t_v3 *v, t_v3 *v2);
t_f32	length_squared(t_v3 *v);
t_f32	length(t_v3 *v);
t_v3	normalize(t_v3 *v);

void	init_mat4(t_mat4 *m);
void	mlt_mat4(t_mat4 *m, t_mat4 *m2, t_mat4 *res);
t_v3	mlt_v3mat(t_v3 *v, t_mat4 *m);

void	x_rtt_mat4(t_mat4 *m, t_f32 degree);
void	y_rtt_mat4(t_mat4 *m, t_f32 degree);
void	z_rtt_mat4(t_mat4 *m, t_f32 degree);
void	x_rtt_mat4_apply(t_mat4 *m, t_f32 degree);
void	y_rtt_mat4_apply(t_mat4 *m, t_f32 degree);
void	z_rtt_mat4_apply(t_mat4 *m, t_f32 degree);

void	render(t_a *a);

t_i32	key_down(t_i32 key, t_a *a);
t_i32	mouse_down(t_i32 butten, t_i32 x, t_i32 y, t_a *a);

void	scan_file(t_a *a);

void	amb_light(t_a *a, t_i8 **strs);
void	camera(t_a *a, t_i8 **strs);
void	light(t_a *a, t_i8 **strs);
void	sphere(t_a *a, t_i8 **strs);
void	plane(t_a *a, t_i8 **strs);
void	cylinder(t_a *a, t_i8 **strs);

#endif
