/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:05:53 by tkong             #+#    #+#             */
/*   Updated: 2023/05/20 09:22:44 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cylinder(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 6)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = CYLINDER;
	obj->color = extract_color(a, strs[5]);
	obj->rto_rng = 0;
	obj->fov = 0;
	obj->transform = extract_v3(a, strs[1]);
	obj->rotation = extract_v3(a, strs[2]);
	obj->scale = make_v3(0, ft_stof(strs[4]), 0);
	obj->radius = ft_stof(strs[3]) / 2;
	ft_pushb(&(a->obj), obj);
}
