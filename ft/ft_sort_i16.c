/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_i16.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:56:48 by tkong             #+#    #+#             */
/*   Updated: 2023/03/19 12:53:56 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void		unit_merge_sort(t_i16 **buf, t_i32 seq, size_t len);
static t_i32	replace_buf(t_i16 **buf, t_i32 seq, size_t len, t_i32 *i);

void	ft_sort_i16(t_i16 *begin, t_i16 *end)
{
	t_i32	seq;
	t_i32	len;
	t_i16	*buf[2];

	seq = 0;
	len = end - begin;
	buf[0] = (t_i16 *) malloc(sizeof(t_i16) * len);
	buf[1] = (t_i16 *) malloc(sizeof(t_i16) * len);
	ft_memcpy(buf[0], begin, sizeof(t_i16) * len);
	while ((1 << seq) < len)
		unit_merge_sort(buf, seq++, len);
	ft_memcpy(begin, buf[seq & 1], sizeof(t_i16) * len);
	free(buf[0]);
	free(buf[1]);
}

static void	unit_merge_sort(t_i16 **buf, t_i32 seq, size_t len)
{
	t_i32	i[4];

	i[2] = 0;
	i[3] = 0;
	while (i[2] < (t_i32) len)
	{
		i[0] = i[2];
		i[1] = i[2] + (1 << seq);
		while (1)
			if (replace_buf(buf, seq, len, i))
				break ;
		i[2] += (1 << seq) * 2;
	}
}

static t_i32	replace_buf(t_i16 **buf, t_i32 seq, size_t len, t_i32 *i)
{
	if (i[0] < ft_min(i[2] + (1 << seq), (t_i32) len)
		&& i[1] < ft_min(i[2] + (1 << seq) * 2, (t_i32) len))
	{
		if (buf[seq & 1][i[0]] < buf[seq & 1][i[1]])
			buf[!(seq & 1)][i[3]++] = buf[seq & 1][i[0]++];
		else
			buf[!(seq & 1)][i[3]++] = buf[seq & 1][i[1]++];
	}
	else if (i[0] < ft_min(i[2] + (1 << seq), (t_i32) len))
		buf[!(seq & 1)][i[3]++] = buf[seq & 1][i[0]++];
	else if (i[1] < ft_min(i[2] + (1 << seq) * 2, (t_i32) len))
		buf[!(seq & 1)][i[3]++] = buf[seq & 1][i[1]++];
	else
		return (-1);
	return (0);
}
