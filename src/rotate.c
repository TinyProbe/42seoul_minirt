/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:14:06 by tkong             #+#    #+#             */
/*   Updated: 2023/05/21 16:54:44 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	x_rtt_mat4(t_mat4 *m, t_f32 degree)
{
	init_mat4(m);
	m->_[1][1] = cosf(to_radian(degree));
	m->_[1][2] = sinf(to_radian(degree));
	m->_[2][1] = -sinf(to_radian(degree));
	m->_[2][2] = cosf(to_radian(degree));
}

void	y_rtt_mat4(t_mat4 *m, t_f32 degree)
{
	init_mat4(m);
	m->_[0][0] = cosf(to_radian(degree));
	m->_[0][2] = -sinf(to_radian(degree));
	m->_[2][0] = sinf(to_radian(degree));
	m->_[2][2] = cosf(to_radian(degree));
}

void	z_rtt_mat4(t_mat4 *m, t_f32 degree)
{
	init_mat4(m);
	m->_[0][0] = cosf(to_radian(degree));
	m->_[0][1] = sinf(to_radian(degree));
	m->_[1][0] = -sinf(to_radian(degree));
	m->_[1][1] = cosf(to_radian(degree));
}
