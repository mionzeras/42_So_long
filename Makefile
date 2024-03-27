# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 15:17:35 by gcampos-          #+#    #+#              #
#    Updated: 2024/03/14 19:41:41 by gcampos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I includes

#FILES
SRCS = src/clean.c src/create_map.c src/graphics.c src/main.c \
		src/parsing.c src/utils.c
OBJS = ${SRCS:.c=.o}
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -Llibft -lft
MLX_PATH = mlx
MLX = -Lmlx -lmlx -Ilmlx -lXext -lX11

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME): ${OBJS}
		@echo "Compiling libft..."
		@${MAKE} ${LIBFT_PATH}
		@echo "libft compiled!"
		@echo "Compiling mlx..."
		@${MAKE} ${MLX_PATH}
		@echo "mlx compiled!"
		@echo "Compiling ${NAME}..."
		${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}
		@echo "so_long compiled!"

clean:
		${MAKE} ${LIBFT_PATH} clean
		${MAKE} ${MLX_PATH} clean
		@${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re