/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:48:20 by tkong             #+#    #+#             */
/*   Updated: 2023/05/22 14:52:34 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_f32	to_degree(t_f32 radian)
{
	return (radian * 180 / PI);
}

t_f32	to_radian(t_f32 degree)
{
	return (degree * PI / 180);
}

void	m4cpy(t_mat4 *dst, t_mat4 *src)
{
	ft_memcpy(dst->_[0], src->_[0], sizeof(t_f32) * 4);
	ft_memcpy(dst->_[1], src->_[1], sizeof(t_f32) * 4);
	ft_memcpy(dst->_[2], src->_[2], sizeof(t_f32) * 4);
	ft_memcpy(dst->_[3], src->_[3], sizeof(t_f32) * 4);
}
