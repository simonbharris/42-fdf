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
# ! DEBUG: LIBFT_FLAG = $(LIBFT_DIR)src/* -I $(LIBFT_DIR)includes
LIBFT_INC_FLAG = -I $(LIBFT_DIR)includes
LIBFT_FLAG = -L $(LIBFT_DIR) -l ft $(LIBFT_INC_FLAG)

# minilibx
MLX_DIR = minilibx/
MLX_LIB = $(MLX_DIR)libmlx.a
MLX_FLAG = -L $(MLX_DIR) -l mlx

# X11
X11_INC = -I /opt/X11/includes/X11
X11_FLAG = -L /opt/X11/lib -l X11 -l Xext

# Compiler
CC = gcc
# TODO: KEEP: CFLAGS = -Wall -Wextra -Werror -c
CFLAGS = -c

all: $(NAME)

mkdir : $(OBJ_DIR)

# ! -########################  Replace SRC_RAW with OBJ equivalent
$(NAME): $(OBJ_DIR) $(LIBFT) $(MLX_LIB) $(OBJ)
	$(CC) -g $(LIBFT_FLAG) $(MLX_FLAG) $(X11_FLAG) $(INC_FLAG) $(OBJ) -o $(NAME)

$(OBJ): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC_FLAG) $(LIBFT_INC_FLAG) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_FLAG): $(LIBFT)

# ! --############## Be sure to eventually switch to .o files (.c for now in debugging.)
clean:
# !	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)
	rm -Rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
