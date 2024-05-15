# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 02:23:35 by lsaumon           #+#    #+#              #
#    Updated: 2024/05/15 03:55:00 by lsaumon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	So_long

# =================================== SOURCES ==================================

SRCS =		main.c \
			checker_map_1.c 
			

OBJ_DIR		:= .objs
OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# =================================== FLAGS ====================================

CC =	cc
FLAGS =	-Wall -Wextra -g3 -fsanitize=address -Werror
RM =	rm -rf
AR =	ar rcs

$(OBJ_DIR)/%.o :%.c
	@mkdir -p $(dir $@)
	@ $(CC) $(FLAGS) -c $< -o $@

# =================================== COLORS ===================================

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN		:=	\033[1;36m

# =================================== COMPILATION ==============================

all:	${NAME}

$(NAME):	$(OBJS) 
	@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	@ $(AR) $(NAME) $(OBJS)
	@ echo "$(YELLOW)$(NAME) $(GREEN)created $(CLR_RMV)✔️"

# =================================== RULES ====================================

clean:

	@ $(RM) $(OBJ_DIR)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean

	@ $(RM) $(NAME) $(RM)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all bonus clean fclean re