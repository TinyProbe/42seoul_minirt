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

t_i32	extract_color(t_a *a, t_i8 *color)
{
	t_i8	**rgb;
	t_i32	rtn;

	rgb = ft_split(color, ',');
	if (count_string(rgb) != 3)
		error(a->msg, ERROR_FILEFORMAT);
	mlx_set_rgb(&rtn, ALPHA, (t_i8) 0);
	mlx_set_rgb(&rtn, RED, (t_i8) ft_stoi(rgb[0]));
	mlx_set_rgb(&rtn, GREEN, (t_i8) ft_stoi(rgb[1]));
	mlx_set_rgb(&rtn, BLUE, (t_i8) ft_stoi(rgb[2]));
	ft_delete_split(rgb);
	return (rtn);
}
