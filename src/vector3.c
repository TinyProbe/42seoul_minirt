/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:17:27 by tkong             #+#    #+#             */
/*   Updated: 2023/05/20 09:12:50 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3	cross(t_v3 *v, t_v3 *v2)
{
	return (make_v3(\
		v->y * v2->z - v->z * v2->y,\
		v->z * v2->x - v->x * v2->z,\
		v->x * v2->y - v->y * v2->x));
}

t_f32	dot(t_v3 *v, t_v3 *v2)
{
	return (v->x * v2->x\
		+ v->y * v2->y\
		+ v->z * v2->z);
}

t_f32	length_squared(t_v3 *v)
{
	return (v->x * v->x\
		+ v->y * v->y\
		+ v->z * v->z);
}

t_f32	length(t_v3 *v)
{
	return (sqrt(length_squared(v)));
}

t_v3	unt_v3(t_v3 *v)
{
	return (div_v3_(v, length(v)));
}
