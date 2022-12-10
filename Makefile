NAME		=	cub3d
INC			=	-I includes/ -I mlx/

#.SILENT:
all: $(NAME)

$(NAME):$(MLX)
	mkdir -p libraries
	make -C mlx/ 2> mlx_logs
	rm mlx_logs
	$(CC) $(CFLAGS) src/main.c -L libraries/ $(INC)

clean:
	make clean -C mlx

#colors
BLK	=	\e[0;30m
RED	=	\e[0;31m
GRN	=	\e[0;32m
YEL	=	\e[0;33m
BLU	=	\e[0;34m
MAG	=	\e[0;35m
CYN	=	\e[0;36m
WHT	=	\e[0;37m

B_BLK	=	\e[1;30m
B_RED	=	\e[1;31m
B_GRN	=	\e[1;32m
B_YEL	=	\e[1;33m
B_BLU	=	\e[1;34m
B_MAG	=	\e[1;35m
B_CYN	=	\e[1;36m
B_WHT	=	\e[1;37m
NC	=	\e[0m
