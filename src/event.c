/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:04:33 by tkong             #+#    #+#             */
/*   Updated: 2023/03/16 01:09:17 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_i32	key_down(t_i32 key, t_a *a)
{
	(void) a;
	if (key == KEY_ESC)
		quit();
	return (0);
}