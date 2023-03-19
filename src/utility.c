/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:01:36 by tkong             #+#    #+#             */
/*   Updated: 2023/03/13 21:27:16 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error(const t_i8 **msg, t_error err)
{
	write(STDERR__, msg[err], ft_strlen(msg[err]));
	exit(err);
}

t_i32	quit(void)
{
	exit(0);
}

t_i32	count_string(t_i8 **strs)
{
	t_i32	i;

	i = -1;
	while (strs[++i])
		;
	return (i);
}

t_vec	make_vec(t_f32 x, t_f32 y, t_f32 z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	extract_vec(t_a *a, t_i8 *vec)
{
	t_i8	**xyz;
	t_vec	rtn;

	xyz = ft_split(vec, ',');
	if (count_string(xyz) != 3)
		error(a->msg, ERROR_FILEFORMAT);
	rtn = make_vec(ft_stof(xyz[0]), ft_stof(xyz[1]), ft_stof(xyz[2]));
	ft_delete_split(xyz);
	return (rtn);
}
