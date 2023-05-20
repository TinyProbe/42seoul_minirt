/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:17:25 by tkong             #+#    #+#             */
/*   Updated: 2023/05/20 09:12:30 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3	mlt_v3(t_v3 *v, t_v3 *v2)
{
	t_v3	v3;

	v3.x = v->x * v2->x;
	v3.y = v->y * v2->y;
	v3.z = v->z * v2->z;
	return (v3);
}

t_v3	div_v3(t_v3 *v, t_v3 *v2)
{
	t_v3	v3;

	v3.x = v->x / v2->x;
	v3.x = v->y / v2->y;
	v3.x = v->z / v2->z;
	return (v3);
}

t_v3	_mlt_v3(t_f32 t, t_v3 *v)
{
	t_v3	v2;

	v2.x = v->x * t;
	v2.y = v->y * t;
	v2.z = v->z * t;
	return (v2);
}

t_v3	mlt_v3_(t_v3 *v, t_f32 t)
{
	return (_mlt_v3(t, v));
}

t_v3	div_v3_(t_v3 *v, t_f32 t)
{
	t_v3	v2;

	v2.x = v->x / t;
	v2.y = v->y / t;
	v2.z = v->z / t;
	return (v2);
}
