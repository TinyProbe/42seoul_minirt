/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:27:11 by tkong             #+#    #+#             */
/*   Updated: 2023/04/25 16:51:16 by tkong            ###   ########.fr       */
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
	a->msg[ERROR_CAMERA] = "error: Need only one camera.\n";
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
	a->mlx.dat.img = mlx_new_image(a->mlx._, WID, HEI);
	if (a->mlx.dat.img == NULL)
		error(a->msg, ERROR_INITFAIL);
	a->mlx.dat.addr = mlx_get_data_addr(a->mlx.dat.img,
			&(a->mlx.dat.bpp),
			&(a->mlx.dat.llen),
			&(a->mlx.dat.endian));
	if (a->mlx.dat.addr == NULL)
		error(a->msg, ERROR_INITFAIL);
}

static void	regist_callback(t_a *a)
{
	mlx_hook(a->mlx.win, DESTROY, 0, quit, NULL);
	mlx_hook(a->mlx.win, KEYDOWN, 0, key_down, a);
}
