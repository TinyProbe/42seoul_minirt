/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:17:25 by tkong             #+#    #+#             */
/*   Updated: 2023/05/21 17:34:52 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3	mlt_v3(t_v3 *v, t_v3 *v2)
{
	return (make_v3(\
		v->x * v2->x,\
		v->y * v2->y,\
		v->z * v2->z));
}

t_v3	div_v3(t_v3 *v, t_v3 *v2)
{
	return (make_v3(\
		v->x / v2->x,\
		v->y / v2->y,\
		v->z / v2->z));
}

t_v3	_mlt_v3(t_f32 t, t_v3 *v)
{
	return (mlt_v3_(v, t));
}

t_v3	mlt_v3_(t_v3 *v, t_f32 t)
{
	return (make_v3(\
		v->x * t,\
		v->y * t,\
		v->z * t));
}

t_v3	div_v3_(t_v3 *v, t_f32 t)
{
	return (make_v3(\
		v->x / t,\
		v->y / t,\
		v->z / t));
}
