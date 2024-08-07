MAKEFLAGS += -s
NAME= so_long
LIBFT_A= libft/libft.a
CC= cc
FLAGS= -Wall -Wextra -Werror
RM= rm -rf
OBJ= $(SRC:.c=.o)
PATH_LIBFT= libft/
MLX_PATH= mlx/
MLX_FLAGS= -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_LIB= $(MLX_PATH)/libmlx_Linux.a
MLX_INCLUDE= -I/usr/include -Imlx
SRC= so_long.c map_checker.c

all: $(MLX_LIB) $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT_A) $(MLX_FLAGS)

$(MLX_LIB):
	make -C $(MLX_PATH)

$(LIBFT_A):
	$(MAKE) -C $(PATH_LIBFT)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC) $(MLX_INCLUDE)
	

clean:
	$(RM) $(OBJ)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all
