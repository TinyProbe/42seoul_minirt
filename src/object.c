/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:05:29 by tkong             #+#    #+#             */
/*   Updated: 2023/04/25 16:48:59 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ambient_lighting(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 3)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = AMBIENT_LIGHTING;
	obj->texture = NULL;
	obj->color = extract_color(a, strs[2]);
	obj->ratio_in_range = ft_stof(strs[1]);
	obj->fov = 0;
	obj->transform = make_vec(0, 0, 0);
	obj->rotation = make_vec(0, 0, 0);
	obj->scale = make_vec(0, 0, 0);
	obj->radius = 0;
	ft_pushb(&(a->obj), obj);
}

void	camera(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 4)
		error(a->msg, ERROR_FILEFORMAT);
	if (a->camera)
		error(a->msg, ERROR_CAMERA);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = CAMERA;
	obj->texture = NULL;
	obj->color = 0;
	obj->ratio_in_range = 0;
	obj->fov = ft_stof(strs[3]);
	obj->transform = extract_vec(a, strs[1]);
	obj->rotation = extract_vec(a, strs[2]);
	obj->scale = make_vec(0, 0, 0);
	obj->radius = 0;
	a->camera = obj;
}

void	light(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 4)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = LIGHT;
	obj->texture = NULL;
	obj->color = extract_color(a, strs[3]);
	obj->ratio_in_range = ft_stof(strs[2]);
	obj->fov = 0;
	obj->transform = extract_vec(a, strs[1]);
	obj->rotation = make_vec(0, 0, 0);
	obj->scale = make_vec(0, 0, 0);
	obj->radius = 0;
	ft_pushb(&(a->obj), obj);
}

void	sphere(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 4)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = SPHERE;
	obj->texture = NULL;
	obj->color = extract_color(a, strs[3]);
	obj->ratio_in_range = 0;
	obj->fov = 0;
	obj->transform = extract_vec(a, strs[1]);
	obj->rotation = make_vec(0, 0, 0);
	obj->scale = make_vec(0, 0, 0);
	obj->radius = ft_stof(strs[2]) / 2;
	ft_pushb(&(a->obj), obj);
}

void	plane(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 4)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = PLANE;
	obj->texture = NULL;
	obj->color = extract_color(a, strs[3]);
	obj->ratio_in_range = 0;
	obj->fov = 0;
	obj->transform = extract_vec(a, strs[1]);
	obj->rotation = extract_vec(a, strs[2]);
	obj->scale = make_vec(0, 0, 0);
	obj->radius = 0;
	ft_pushb(&(a->obj), obj);
}
