# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 15:57:08 by lsaumon           #+#    #+#              #
#    Updated: 2024/07/06 04:25:36 by lsaumon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
LIBLIBA		:= libft/libft.a
SRC			:= ./srcs

# =================================== SOURCES ==================================

SRCS		:=  $(addprefix $(SRC)/, main.c) \
				$(addprefix $(SRC)/, map_definition.c) \
				$(addprefix $(SRC)/, parsing.c) \
				$(addprefix $(SRC)/, init.c) \
				$(addprefix $(SRC)/, flood_fill.c) \
				$(addprefix $(SRC)/, so_utils.c) \
				
OBJ_DIR		:= .objs
OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# =================================== FLAGS ====================================

CC			:=	cc
FLAGS		:=	-Wall -Wextra -Werror #-g3 -fsanitize=address
FLAGS		+=	-I libft -I includes
RM			:=	rm -rf

ifeq ($(DEBUG),1)
	FLAGS +=  -g3 -fsanitize=address
endif

$(OBJ_DIR)/%.o :%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(FLAGS) -c $< -o $@

# =================================== COLORS ===================================

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN		:=	\033[1;36m

# =================================== COMPILATION ==============================

all:		$(NAME)

$(LIBLIBA):
	@make -s -C libft
	
$(NAME): $(LIBLIBA) $(OBJS) $(MLXBUILD)
	@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	@ $(CC) $(SRCS) $(LIBLIBA) -o $(NAME) $(FLAGS) ./MLX42/build/libmlx42.a -Iinclude -I ./MLX42/include/MLX42 -lglfw -lm
	@ echo "$(YELLOW)$(NAME) $(GREEN)created $(CLR_RMV)✔️"

$(MLXBUILD):
	echo toto
	cd MLX42/ && cmake -B build && cmake --build build -j4
	echo tata

# =================================== RULES ====================================

clean:

	@ $(RM) $(OBJ_DIR)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
	@make -s -C libft clean

fclean:		clean

	@ $(RM) $(NAME) $(RM)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
	@make -s -C libft fclean

re:		fclean all

.PHONY:		all bonus clean fclean re