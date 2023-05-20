/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:17:20 by tkong             #+#    #+#             */
/*   Updated: 2023/05/20 09:12:04 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3	extract_v3(t_a *a, t_i8 *val)
{
	t_i8	**xyz;
	t_v3	v;

	xyz = ft_split(val, ',');
	if (count_string(xyz) != 3)
		error(a->msg, ERROR_FILEFORMAT);
	v = make_v3(ft_stof(xyz[0]), ft_stof(xyz[1]), ft_stof(xyz[2]));
	ft_delete_split(xyz);
	return (v);
}

t_v3	make_v3(t_f32 x, t_f32 y, t_f32 z)
{
	t_v3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_v3	neg_v3(t_v3 *v)
{
	t_v3	v2;

	v2.x = -(v->x);
	v2.y = -(v->y);
	v2.z = -(v->z);
	return (v2);
}

t_v3	sum_v3(t_v3 *v, t_v3 *v2)
{
	t_v3	v3;

	v3.x = v->x + v2->x;
	v3.y = v->y + v2->y;
	v3.z = v->z + v2->z;
	return (v3);
}

t_v3	sub_v3(t_v3 *v, t_v3 *v2)
{
	t_v3	v3;

	v3.x = v->x - v2->x;
	v3.y = v->y - v2->y;
	v3.z = v->z - v2->z;
	return (v3);
}
