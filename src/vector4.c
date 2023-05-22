/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:19:18 by tkong             #+#    #+#             */
/*   Updated: 2023/05/22 19:19:04 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3	to_spherical(t_v3 *v)
{
	t_v3	v2;

	v2 = normalize(v);
	return (make_v3(\
		length(v), \
		acosf(v2.z), \
		atan2f(v2.y, v2.x)));
}

t_v3	to_cartesian(t_v3 *v)
{
	return (make_v3(\
		cosf(v->z) * sinf(v->y) * v->x, \
		sinf(v->z) * sinf(v->y) * v->x, \
		cosf(v->y) * v->x));
}
