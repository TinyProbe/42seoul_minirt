# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 21:09:17 by tkong             #+#    #+#              #
#    Updated: 2023/03/13 05:26:52 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT

CPL		= cc
OPT		= -Wall -Wextra -Werror -O2 -o $(NAME)
LIB		= $(FT) $(MLX) -framework OpenGL -framework AppKit
RM		= rm -f

FT_DIR	= ./ft/
FT_HDR	= $(FT_DIR)ft.h
FT		= $(FT_DIR)libft.a

MLX_DIR	= ./mlx/
MLX_HDR	= $(MLX_DIR)mlx.h
MLX		= $(MLX_DIR)libmlx.a

SRC_DIR	= ./src/
SRC_LST	= main.c\
		  mlx_extend.c\
		  utility.c\
		  utility2.c\
		  render.c\
		  event.c\
		  scan.c\
		  object.c\
		  object2.c
SRC		= $(addprefix $(SRC_DIR), $(SRC_LST))
INC		= $(addprefix $(SRC_DIR), minirt.h)

ifdef B
	SRC_DIR	= ./src_bonus/
	SRC_LST	= main_bonus.c
	SRC		= $(addprefix $(SRC_DIR), $(SRC_LST))
	INC		= $(addprefix $(SRC_DIR), minirt_bonus.h)
endif

$(NAME): $(FT) $(MLX) $(INC) $(SRC) Makefile
	$(CPL) $(OPT) $(SRC) $(LIB)

$(FT):
	make -sC $(FT_DIR)

$(MLX):
	make -sC $(MLX_DIR)

all: $(NAME)

bonus:
	make B=1 all

clean:
	make -sC $(FT_DIR) clean
	make -sC $(MLX_DIR) clean

fclean: clean
	$(RM) $(FT) $(MLX) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
