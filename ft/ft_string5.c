/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:20:13 by tkong             #+#    #+#             */
/*   Updated: 2023/01/12 17:37:01 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

size_t	ft_strcpy(t_i8 *dst, const t_i8 *src)
{
	size_t	idx;

	idx = 0;
	while (*src)
		dst[idx++] = *src++;
	dst[idx] = '\0';
	return (idx);
}

t_i8	*ft_strslice(const t_i8 *s1, t_i32 begin, t_i32 end)
{
	t_isize	n;
	void	*res;

	n = end - begin;
	res = malloc(n + 1);
	if (res)
		((char *) ft_memcpy(res, s1 + begin, n))[n] = '\0';
	return (res);
}
