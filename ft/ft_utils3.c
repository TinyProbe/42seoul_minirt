/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:57:27 by tkong             #+#    #+#             */
/*   Updated: 2023/04/25 17:55:51 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void	ft_swap_half(void *a, void *b, size_t siz);

void	ft_swap(void *a, void *b, size_t siz)
{
	if (a == b)
		return ;
	if (siz == sizeof(t_u8))
	{
		*(t_u8 *) a ^= *(t_u8 *) b;
		*(t_u8 *) b ^= *(t_u8 *) a;
		*(t_u8 *) a ^= *(t_u8 *) b;
	}
	else if (siz == sizeof(t_u16))
	{
		*(t_u16 *) a ^= *(t_u16 *) b;
		*(t_u16 *) b ^= *(t_u16 *) a;
		*(t_u16 *) a ^= *(t_u16 *) b;
	}
	else
		ft_swap_half(a, b, siz);
}

static void	ft_swap_half(void *a, void *b, size_t siz)
{
	if (siz == sizeof(t_u32))
	{
		*(t_u32 *) a ^= *(t_u32 *) b;
		*(t_u32 *) b ^= *(t_u32 *) a;
		*(t_u32 *) a ^= *(t_u32 *) b;
	}
	else if (siz == sizeof(t_u64))
	{
		*(t_u64 *) a ^= *(t_u64 *) b;
		*(t_u64 *) b ^= *(t_u64 *) a;
		*(t_u64 *) a ^= *(t_u64 *) b;
	}
}

void	ft_reverse(void *begin, void *end, size_t siz)
{
	t_i32	i;
	t_i32	j;

	i = 0;
	j = 0;
	if (siz == sizeof(t_u8))
		while ((t_u8 *) begin + i < (t_u8 *) end - ++j)
			ft_swap((t_u8 *) begin + i++, (t_u8 *) end - j, siz);
	else if (siz == sizeof(t_u16))
		while ((t_u16 *) begin + i < (t_u16 *) end - ++j)
			ft_swap((t_u16 *) begin + i++, (t_u16 *) end - j, siz);
	else if (siz == sizeof(t_u32))
		while ((t_u32 *) begin + i < (t_u32 *) end - ++j)
			ft_swap((t_u32 *) begin + i++, (t_u32 *) end - j, siz);
	else if (siz == sizeof(t_u64))
		while ((t_u64 *) begin + i < (t_u64 *) end - ++j)
			ft_swap((t_u64 *) begin + i++, (t_u64 *) end - j, siz);
}

t_bool	*ft_make_code(const char *set)
{
	static char	code[CODE_SIZE];

	ft_bzero(code, CODE_SIZE);
	while (*set)
		code[(t_i32) *set++] = TRUE;
	return (code);
}
