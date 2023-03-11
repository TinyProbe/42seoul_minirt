/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:27:11 by tkong             #+#    #+#             */
/*   Updated: 2023/03/07 03:17:59 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	error_message(t_a *a);
static void	error_check(t_a *a, t_i32 ac, t_i8 **av);
static void	create_mlx(t_a *a);
static void	regist_callback(t_a *a);

t_i32	main(t_i32 ac, t_i8 **av)
{
	t_a	a;

	ft_bzero(&a, sizeof(a));
	error_message(&a);
	error_check(&a, ac, av);
	create_mlx(&a);
	regist_callback(&a);
	render(&a);
	mlx_loop(a.mlx._);
	exit(0);
}

static void	error_message(t_a *a)
{
	a->msg[ERROR_ARGUMENT] = "error: Too little/many arguments.\n";
	a->msg[ERROR_FILENAME] = "error: Invalid file name.\n";
	a->msg[ERROR_FILEOPEN] = "error: File open failed.\n";
	a->msg[ERROR_FILEFORMAT] = "error: The file format is invalid.\n";
	a->msg[ERROR_INITFAIL] = "error: Device create failed.\n";
}

static void	error_check(t_a *a, t_i32 ac, t_i8 **av)
{
	t_u32	len;

	if (ac != 2)
		error(a->msg, ERROR_ARGUMENT);
	len = ft_strlen(av[1]);
	if (len < 3
			|| av[1][len - 3] != '.'
			|| av[1][len - 2] != 'r'
			|| av[1][len - 1] != 't')
		error(a->msg, ERROR_FILENAME);
	a->filename = av[1];
	scan_file(a);
}

static void	create_mlx(t_a *a)
{
	a->mlx._ = mlx_init();
	if (a->mlx._ == NULL)
		error(a->msg, ERROR_INITFAIL);
	a->mlx.win = mlx_new_window(a->mlx._, WID, HEI, "miniRT");
	if (a->mlx.win == NULL)
		error(a->msg, ERROR_INITFAIL);
	a->mlx.data.img = mlx_new_image(a->mlx._, WID, HEI);
	if (a->mlx.data.img == NULL)
		error(a->msg, ERROR_INITFAIL);
	a->mlx.data.addr = mlx_get_data_addr(a->mlx.data.img,
			&(a->mlx.data.bpp),
			&(a->mlx.data.llen),
			&(a->mlx.data.endian));
	if (a->mlx.data.addr == NULL)
		error(a->msg, ERROR_INITFAIL);
}

static void	regist_callback(t_a *a)
{
	mlx_hook(a->mlx.win, DESTROY, 0, quit, NULL);
	mlx_hook(a->mlx.win, KEYDOWN, 0, key_down, a);
	mlx_hook(a->mlx.win, MOUSEDOWN, 0, mouse_down, a);
}

// 
// utility.c
//
void	error(const t_i8 **msg, t_error err)
{
	write(STDERR__, msg[err], ft_strlen(msg[err]));
	exit(err);
}

void	quit(void)
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
	t_vec	rtn;
	t_i8	**xyz;

	xyz = ft_split(vec, ',');
	if (count_string(xyz) != 3) 
		error(a->msg, ERROR_FILEFORMAT);
	rtn = make_vec(ft_stof(xyz[0]), ft_stof(xyz[1]), ft_stof(xyz[2]));
	ft_delete_split(xyz);
	return (rtn);
}

//
// utility2.c
//
t_i32	extract_color(t_a *a, t_i8 *color)
{
	t_i32	rtn;
	t_i8	**rgb;

	rtn = 0;
	rgb = ft_split(color, ',');
	if (count_string(rgb) != 3) 
		error(a->msg, ERROR_FILEFORMAT);
	mlx_set_rgb(&rtn, RED, (t_i8) ft_stoi(rgb[0]));
	mlx_set_rgb(&rtn, GREEN, (t_i8) ft_stoi(rgb[1]));
	mlx_set_rgb(&rtn, BLUE, (t_i8) ft_stoi(rgb[2]));
	ft_delete_split(rgb);
	return (rtn);
}

//
// render.c
//
void	render(t_a *a)
{

}

//
// event.c
//
t_i32	key_down(t_i32 key, t_a *a)
{
	if (key == KEY_ESC)
		quit();
}

t_i32	mouse_down(t_i32 butten, t_f32 x, t_f32 y, t_a *a)
{

}

//
// scan.c
//
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
	close(fd);
}

static void	line_analyze(t_a *a, t_i8 *line)
{
	t_i8	**strs;

	strs = ft_split2(line, " \t\n\v\f\r");
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
	ft_delete_split(strs);
}

//
// object.c
//
void	ambient_lighting(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 3)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = AMBIENT_LIGHTING;
	obj->texture = NULL;
	obj->color = extract_color(a, strs[2]);
	obj->ratio_in_range = ft_stof(strs[1]);
	obj->fov = 0;
	obj->transform = make_vec(0, 0, 0);
	obj->rotation = make_vec(0, 0, 0);
	obj->scale = make_vec(0, 0, 0);
	obj->radius = 0;
	ft_pushb(&(a->obj), obj);
}

void	camera(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 4)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = CAMERA;
	obj->texture = NULL;
	obj->color = 0;
	obj->ratio_in_range = 0;
	obj->fov = ft_stof(strs[3]);
	obj->transform = extract_vec(a, strs[1]);
	obj->rotation = extract_vec(a, strs[2]);
	obj->scale = make_vec(0, 0, 0);
	obj->radius = 0;
	ft_pushb(&(a->obj), obj);
}

void	light(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 4)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = LIGHT;
	obj->texture = NULL;
	obj->color = extract_color(a, strs[3]);
	obj->ratio_in_range = ft_stof(strs[2]);
	obj->fov = 0;
	obj->transform = extract_vec(a, strs[1]);
	obj->rotation = make_vec(0, 0, 0);
	obj->scale = make_vec(0, 0, 0);
	obj->radius = 0;
	ft_pushb(&(a->obj), obj);
}

void	sphere(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 4)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = SPHERE;
	obj->texture = NULL;
	obj->color = extract_color(a, strs[3]);
	obj->ratio_in_range = 0;
	obj->fov = 0;
	obj->transform = extract_vec(a, strs[1]);
	obj->rotation = make_vec(0, 0, 0);
	obj->scale = make_vec(0, 0, 0);
	obj->radius = ft_stof(strs[2]) / 2;
	ft_pushb(&(a->obj), obj);
}

void	plane(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 4)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = PLANE;
	obj->texture = NULL;
	obj->color = extract_color(a, strs[3]);
	obj->ratio_in_range = 0;
	obj->fov = 0;
	obj->transform = extract_vec(a, strs[1]);
	obj->rotation = extract_vec(a, strs[2]);
	obj->scale = make_vec(0, 0, 0);
	obj->radius = 0;
	ft_pushb(&(a->obj), obj);
}

//
// object2.c
//
void	cylinder(t_a *a, t_i8 **strs)
{
	t_obj	*obj;

	if (count_string(strs) != 5)
		error(a->msg, ERROR_FILEFORMAT);
	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->form = CYLINDER;
	obj->texture = NULL;
	obj->color = extract_color(a, strs[5]);
	obj->ratio_in_range = 0;
	obj->fov = 0;
	obj->transform = extract_vec(a, strs[1]);
	obj->rotation = extract_vec(a, strs[2]);
	obj->scale = make_vec(0, ft_stof(strs[4]), 0);
	obj->radius = ft_stof(strs[3]) / 2;
	ft_pushb(&(a->obj), obj);
}
