/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:57:20 by tkong             #+#    #+#             */
/*   Updated: 2023/03/13 12:24:49 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_i8	**ft_split(t_i8 const *s, t_i8 c)
{
	t_i8	*buf[100000];
	t_i32	len;
	t_i32	l;
	t_i32	r;

	len = 0;
	l = 0;
	r = -1;
	while (s[++r])
	{
		if (s[r] == c)
		{
			if (l < r)
				buf[len++] = ft_strndup(s + l, r - l);
			l = r + 1;
		}
	}
	if (l < r)
		buf[len++] = ft_strndup(s + l, r - l);
	buf[len++] = NULL;
	return (ft_memcpy(malloc(sizeof(t_i8 *) * len), buf, sizeof(t_i8 *) * len));
}

t_i8	**ft_split2(t_i8 const *s, const t_i8 *set)
{
	t_u8	code[CODE_SIZE];
	t_i8	*buf[100000];
	t_i32	len;
	t_i32	l;
	t_i32	r;

	l = -1;
	while (set[++l])
		code[(t_i32) set[l]] = TRUE;
	len = 0;
	l = 0;
	r = -1;
	while (s[++r])
	{
		if (code[(t_i32) s[r]])
		{
			if (l < r)
				buf[len++] = ft_strndup(s + l, r - l);
			l = r + 1;
		}
	}
	if (l < r)
		buf[len++] = ft_strndup(s + l, r - l);
	buf[len++] = NULL;
	return (ft_memcpy(malloc(sizeof(t_i8 *) * len), buf, sizeof(t_i8 *) * len));
}

void	ft_delete_split(t_i8 **strs)
{
	t_i32	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

size_t	ft_strcpy(t_i8 *dst, const t_i8 *src)
{
	size_t	i;

	i = ft_strlen(src);
	ft_memcpy(dst, src, i + 1);
	return (i);
}

t_i32	ft_strdel(t_i8 *dst, const t_i8 *set)
{
	t_u8	code[CODE_SIZE];
	t_i32	i;
	t_i32	j;

	ft_bzero(code, CODE_SIZE);
	i = -1;
	while (set[++i])
		code[(t_i32) set[i]] = TRUE;
	i = 0;
	j = -1;
	while (dst[++j])
		if (!code[(t_i32) dst[j]])
			dst[i++] = dst[j];
	dst[i] = '\0';
	return (i);
}
