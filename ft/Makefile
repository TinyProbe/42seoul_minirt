# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 12:24:20 by tkong             #+#    #+#              #
#    Updated: 2023/03/19 12:57:41 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc
CFLAG	= -Wall -Wextra -Werror -O2 -c
AR		= ar
ARFLAG	= rcs
SRC		= ft_fput.c\
		  ft_gnl.c\
		  ft_iswhat1.c\
		  ft_iswhat2.c\
		  ft_memory1.c\
		  ft_memory2.c\
		  ft_sort_f32.c\
		  ft_sort_f64.c\
		  ft_sort_i16.c\
		  ft_sort_i32.c\
		  ft_sort_i64.c\
		  ft_sort_i8.c\
		  ft_sort_isize.c\
		  ft_sort_u16.c\
		  ft_sort_u32.c\
		  ft_sort_u64.c\
		  ft_sort_u8.c\
		  ft_sort_usize.c\
		  ft_string1.c\
		  ft_string2.c\
		  ft_string3.c\
		  ft_string4.c\
		  ft_utils1.c\
		  ft_utils2.c\
		  ft_utils3.c\
		  ft_utils4.c\
		  ft_utils5.c\
		  printf/ft_printf.c\
		  printf/ft_vfprintf.c\
		  printf/ft_validation.c\
		  printf/ft_vali_mix.c\
		  printf/ft_form.c\
		  printf/ft_iswhat1.c\
		  printf/ft_iswhat2.c\
		  printf/ft_setarg.c\
		  printf/ft_conversion.c\
		  printf/ft_apply.c\
		  ft_list1_bonus.c\
		  ft_list2_bonus.c\
		  ft_bdll.c\
		  ft_bdll2.c\

OBJ		= $(SRC:.c=.o)
INC		= libft.h
RM		= rm -f

%.o: %.c
	$(CC) $(CFLAG) $? -o $@

$(NAME): $(OBJ)
	$(AR) $(ARFLAG) $@ $?

all: $(NAME)

bonus: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
