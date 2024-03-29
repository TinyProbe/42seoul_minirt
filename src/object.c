/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:05:29 by tkong             #+#    #+#             */
/*   Updated: 2023/05/22 14:47:11 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ext_ambient(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 3)
		error(a->msg, ERROR_FILEFORMAT);
	if (a->ambient)
		error(a->msg, ERROR_AMBIENT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = AMBIENT;
	obj->color = ext_color(a, strs[2]);
	obj->rto_rng = ft_stof(strs[1]);
	obj->fov = 0;
	obj->transform = make_v3(0, 0, 0);
	obj->rotation = make_v3(0, 0, 0);
	obj->scale = make_v3(0, 0, 0);
	obj->radius = 0;
	a->ambient = obj;
}

void	ext_camera(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 4)
		error(a->msg, ERROR_FILEFORMAT);
	if (a->camera)
		error(a->msg, ERROR_CAMERA);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = CAMERA;
	obj->color = 0;
	obj->rto_rng = 0;
	obj->fov = ft_stof(strs[3]);
	obj->transform = ext_v3(a, strs[1]);
	obj->rotation = ext_v3(a, strs[2]);
	obj->scale = make_v3(0, 0, 0);
	obj->radius = 0;
	a->camera = obj;
}

void	ext_light(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 4)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = LIGHT;
	obj->color = ext_color(a, strs[3]);
	obj->rto_rng = ft_stof(strs[2]);
	obj->fov = 0;
	obj->transform = ext_v3(a, strs[1]);
	obj->rotation = make_v3(0, 0, 0);
	obj->scale = make_v3(0, 0, 0);
	obj->radius = 0;
	ft_pushb(&(a->obj), obj);
}

void	ext_sphere(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 4)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = SPHERE;
	obj->color = ext_color(a, strs[3]);
	obj->rto_rng = 0;
	obj->fov = 0;
	obj->transform = ext_v3(a, strs[1]);
	obj->rotation = make_v3(0, 0, 0);
	obj->scale = make_v3(0, 0, 0);
	obj->radius = ft_stof(strs[2]) / 2;
	ft_pushb(&(a->obj), obj);
}

void	ext_plane(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 4)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = PLANE;
	obj->color = ext_color(a, strs[3]);
	obj->rto_rng = 0;
	obj->fov = 0;
	obj->transform = ext_v3(a, strs[1]);
	obj->rotation = ext_v3(a, strs[2]);
	obj->scale = make_v3(0, 0, 0);
	obj->radius = 0;
	ft_pushb(&(a->obj), obj);
}
