# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharris <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 12:08:20 by sharris           #+#    #+#              #
#    Updated: 2018/10/17 12:11:40 by sharris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# Sources and objects
SRC_RAW = 	main \
			fdf \
			err \
			maputil \
			vector

SRC = $(SRC_RAW:%=$(SRC_DIR)%.c)
SRC_DIR = src/
OBJ = $(SRC_RAW:%=$(OBJ_DIR)%.o)
OBJ_DIR = obj/
INC = includes/
INC_FLAG = -I $(INC)

# LIB
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_FLAG = $(LIBFT_DIR)src/* -I $(LIBFT_DIR)includes
# TODO: Keep this -> LIBFT_FLAG = -L $(LIBFT_DIR) -l ft -I $(LIBFT_DIR)includes

# minilibx
MLX_DIR = minilibx/
MLX_LIB = $(MLX_DIR)libmlx.a
MLX_FLAG = -L $(MLX_DIR) -l mlx

# X11
X11_INC = -I /opt/X11/includes/X11
X11_FLAG = -L /opt/X11/lib -l X11 -l Xext

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

mkdir : $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir obj

# ! -########################  Replace SRC_RAW with OBJ equivalent
$(NAME): $(LIBFT) $(MLX_LIB)
	$(CC) -g $(LIBFT_FLAG) $(MLX_FLAG) $(X11_FLAG) $(INC_FLAG) $(SRC) -o $(NAME)

$(OBJ): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_FLAG): $(LIBFT)

# ! --############## Be sure to eventually switch to .o files (.c for now in debugging.)
clean:
# !	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
