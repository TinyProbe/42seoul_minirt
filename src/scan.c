/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:04:58 by tkong             #+#    #+#             */
/*   Updated: 2023/05/22 14:43:07 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	line_analyze(t_a *a, t_i8 *line);

void	scan_file(t_a *a)
{
	t_i32	fd;
	t_i8	*line;

	fd = open(a->file, O_RDONLY);
	if (fd == -1)
		error(a->msg, ERROR_FILEOPEN);
	while (TRUE)
	{
		line = ft_gnl(fd);
		if (line == NULL)
			break ;
		if (line[0] != '\0')
			line_analyze(a, line);
		free(line);
	}
	if (a->ambient == NULL)
		error(a->msg, ERROR_AMBIENT);
	if (a->camera == NULL)
		error(a->msg, ERROR_CAMERA);
	close(fd);
}

static void	line_analyze(t_a *a, t_i8 *line)
{
	t_i8	**strs;

	strs = ft_split2(line, " \t\n\v\f\r");
	if (count_string(strs) > 0)
	{
		if (!ft_strcmp(strs[0], "A"))
			ext_ambient(a, strs);
		else if (!ft_strcmp(strs[0], "C"))
			ext_camera(a, strs);
		else if (!ft_strcmp(strs[0], "L"))
			ext_light(a, strs);
		else if (!ft_strcmp(strs[0], "sp"))
			ext_sphere(a, strs);
		else if (!ft_strcmp(strs[0], "pl"))
			ext_plane(a, strs);
		else if (!ft_strcmp(strs[0], "cy"))
			ext_cylinder(a, strs);
		else
			error(a->msg, ERROR_FILEFORMAT);
	}
	ft_delete_split(strs);
}
