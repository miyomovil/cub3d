NAME 				= cub3d
LIBFT_PATH 			= ./libft
MINILIBX_PATH 		= ./minilibx-linux
SRCS 				= 	./srcs/read_map.c \
						./srcs/get_res.c \


OBJS 				= ${SRCS:.c=.o}
INCLUDE 			= cub3d.h
LIBFT 				= libft
MINILIBX 			= minilibX
CC					= gcc -g -Wall -Wextra -Werror
RM 					= rm -f
MLXFLAGS			= -I ./minilibx-linux -L ./minilibx-linux -lmlx -lm -lbsd -lX11 -lXext
LIBFLAGS			= -I ./libft -L ./libft  -l ft

all:				libft_all minilibx_all ${NAME}

$(NAME):			${OBJS}
					$(CC) ${OBJS} ${MLXFLAGS} ${LIBFLAGS} -o cub3d

.c.o:
					@$(CC) -c $< $(MLXFLAGS) -o $@
clean:				libft_clean minilibx_clean
						@${RM} ${OBJS}
fclean: 			libft_fclean clean
						@${RM} ${NAME}
re: fclean all

libft_all:
	make -C $(LIBFT_PATH) all
	cp ./libft/libft.a libft.a

libft_clean:
	make -C $(LIBFT_PATH) clean

libft_fclean:
	make -C $(LIBFT_PATH) fclean
	$(RM) libft.a

minilibx_all:
	make -C $(MINILIBX_PATH) all
	cp ./minilibx-linux/libmlx.a libmlx.a

minilibx_clean:
	make -C $(MINILIBX_PATH) clean
	$(RM) libmlx.a

.PHONY: all re clean fclean