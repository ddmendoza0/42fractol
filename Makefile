# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 13:10:58 by dmendoza          #+#    #+#              #
#    Updated: 2025/05/30 19:48:17 by dmendoza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

HEADERS	=	-I ./include -I $(LIBMLX)/include -I$(LIBFT)

LIBMLX	=	./lib/MLX42
LIBFT	=	./lib/libft
LIBS	=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

SRC_DIR =	src/
SRCS	=	$(SRC_DIR)main.c $(SRC_DIR)init.c $(SRC_DIR)render.c \
		$(SRC_DIR)mandelbrot.c $(SRC_DIR)julia.c $(SRC_DIR)events.c \
		$(SRC_DIR)utils.c $(SRC_DIR)actions.c

OBJ_DIR =	obj/
OBJS	=	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

INCLUDE =	include/fractol.h Makefile

CC	=	cc
CFLAGS	=	-g -Wall -Wextra -Werror -Wunreachable-code -Ofast -I./libft \
		-I./include -I$(LIBMLX)/include -I$(LIBFT)
RM	=	rm -f

all:	libft libmlx $(NAME)

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:		$(LIBFT)/libft.a

$(LIBFT)/libft.a: FORCE 
	@$(MAKE) -C $(LIBFT)

$(NAME):	$(OBJS)
		@echo "Building fractol..."
		@$(CC) $(OBJS) $(LIBS) -o $(NAME) 
		@echo "...fractol built successfully."

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCLUDE)
		@mkdir -p $(dir $@)
		@echo "Compiling $<..."
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "...compilation completed"
clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT) clean
	@rm -rf $(LIBMLX)/build
	@echo "...object files cleansed."

fclean:	clean
	@echo "Cleaning all..."
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@echo "...all cleaned."

re:	fclean all

.PHONY:	all clean fclean re libft libmlx FORCE

