/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:04:58 by tkong             #+#    #+#             */
/*   Updated: 2023/04/25 17:11:59 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	line_analyze(t_a *a, t_i8 *line);

void	scan_file(t_a *a)
{
	t_i32	fd;
	t_i8	*line;

	fd = open(a->filename, O_RDONLY);
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
			ambient_lighting(a, strs);
		else if (!ft_strcmp(strs[0], "C"))
			camera(a, strs);
		else if (!ft_strcmp(strs[0], "L"))
			light(a, strs);
		else if (!ft_strcmp(strs[0], "sp"))
			sphere(a, strs);
		else if (!ft_strcmp(strs[0], "pl"))
			plane(a, strs);
		else if (!ft_strcmp(strs[0], "cy"))
			cylinder(a, strs);
		else
			error(a->msg, ERROR_FILEFORMAT);
	}
	ft_delete_split(strs);
}
