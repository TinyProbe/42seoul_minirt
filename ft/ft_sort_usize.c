/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_usize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:54:37 by tkong             #+#    #+#             */
/*   Updated: 2023/03/19 12:55:30 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void		unit_merge_sort(t_usize **buf, t_i32 seq, size_t len);
static t_i32	replace_buf(t_usize **buf, t_i32 seq, size_t len, t_i32 *i);

void	ft_sort_usize(t_usize *begin, t_usize *end)
{
	t_i32	seq;
	t_i32	len;
	t_usize	*buf[2];

	seq = 0;
	len = end - begin;
	buf[0] = (t_usize *) malloc(sizeof(t_usize) * len);
	buf[1] = (t_usize *) malloc(sizeof(t_usize) * len);
	ft_memcpy(buf[0], begin, sizeof(t_usize) * len);
	while ((1 << seq) < len)
		unit_merge_sort(buf, seq++, len);
	ft_memcpy(begin, buf[seq & 1], sizeof(t_usize) * len);
	free(buf[0]);
	free(buf[1]);
}

static void	unit_merge_sort(t_usize **buf, t_i32 seq, size_t len)
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

static t_i32	replace_buf(t_usize **buf, t_i32 seq, size_t len, t_i32 *i)
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
