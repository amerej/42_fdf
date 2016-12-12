NAME	=	fdf

SRC		=	main.c map.c key.c draw.c matrice.c transform.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc
#CFLAGS	=	-Werror -Wextra -Wall

LIBLINK	=	-L./libft -lft
MLX		=	./minilibx_osx/mlx.a
MLXLINK	=	-L./minilibx_osx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./libft
		$(CC) $(CFLAGS) $(LIBLINK) $(MLXLINK) -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)
		make -C ./libft clean
		rm -f ./minilibx_osx/$(OBJ)

fclean:	clean
		rm -rf $(NAME)
		make -C ./libft fclean
		rm -f ./minilibx_osx/$(NAME)

re:		fclean all

.PHONY: clean
