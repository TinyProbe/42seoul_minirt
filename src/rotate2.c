/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:12:05 by tkong             #+#    #+#             */
/*   Updated: 2023/05/21 17:55:17 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	x_rtt_mat4_apply(t_mat4 *m, t_f32 degree)
{
	t_mat4	tmp;
	t_mat4	tmp2;

	x_rtt_mat4(&tmp, degree);
	mlt_mat4(m, &tmp, &tmp2);
	mat4cpy(m, &tmp2);
}

void	y_rtt_mat4_apply(t_mat4 *m, t_f32 degree)
{
	t_mat4	tmp;
	t_mat4	tmp2;

	y_rtt_mat4(&tmp, degree);
	mlt_mat4(m, &tmp, &tmp2);
	mat4cpy(m, &tmp2);
}

void	z_rtt_mat4_apply(t_mat4 *m, t_f32 degree)
{
	t_mat4	tmp;
	t_mat4	tmp2;

	z_rtt_mat4(&tmp, degree);
	mlt_mat4(m, &tmp, &tmp2);
	mat4cpy(m, &tmp2);
}
