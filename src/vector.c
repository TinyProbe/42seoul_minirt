/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:17:20 by tkong             #+#    #+#             */
/*   Updated: 2023/05/22 11:50:57 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	return (make_v3(-(v->x), -(v->y), -(v->z)));
}

t_v3	sum_v3(t_v3 *v, t_v3 *v2)
{
	return (make_v3(\
		v->x + v2->x, \
		v->y + v2->y, \
		v->z + v2->z));
}

t_v3	sub_v3(t_v3 *v, t_v3 *v2)
{
	return (make_v3(\
		v->x - v2->x, \
		v->y - v2->y, \
		v->z - v2->z));
}
