# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 18:25:39 by ahusic            #+#    #+#              #
#    Updated: 2024/05/15 17:34:01 by ahusic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fractol
CFLAGS	:= -Wextra -Wall -Werror
LDFLAGS	:= -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit
LIBMLX	:= ./lib/MLX42


HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= fractol.c extra.c julia.c mandelbrot.c moving.c utils.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(LIB) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

init:
	git submodule update --init --recursive

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(LIB):
	@make -sC $(LIBMLX)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIB) -o $(NAME)

clean:
	@echo "cleaning up..."
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build


fclean: clean
	@echo "fully cleaned up."
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
