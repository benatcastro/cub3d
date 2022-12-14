#
#

SRC_FILES_C=	mlx_shaders\
				mlx_png\
				mlx_xpm\
				mlx_int_str_to_wordtab\

SRC_FILES_M =	mlx_new_window\
				mlx_init_loop\
				mlx_new_image\
				mlx_mouse\

UNAME = $(shell uname)
MLX = $(LIBRARIES_DIR)mlx_$(UNAME).a

CC = gcc
AR = ar rc
CC_FLAGS = -O2 -DSTRINGPUTX11

LIBRARIES_DIR = ../../libraries/
INCLUDES = -I ../../includes/ -I ../../includes/mlx/
OBJ_DIR	=	../../objs/mlx_Darwin/
# add to match string put with X11 in size and position
SRC_C = $(addprefix $(SRC_DIR_C), $(addsuffix .c, $(SRC_FILES_C)))
OBJ_C = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_C)))

SRC_M = $(addprefix $(SRC_DIR_M), $(addsuffix .m, $(SRC_FILES_M)))
OBJ_M = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_M)))

.SILENT:
all: $(MLX)

$(MLX) : $(OBJF) $(OBJ_C) $(OBJ_M)
	@$(AR) $(MLX) $(OBJ_C) $(OBJ_M)
	printf "$(B_MAG)CREATING LIBRARY$(NC) $(B_WHT)%s$(NC)\n" MLX_DARWIN
	@ranlib $(MLX)

$(OBJ_DIR)%.o: $(SRC_DIR_C)%.c
	@mkdir -p $(OBJ_DIR)
	printf "$(B_CYN)Compling: $(NC)$(B_WHT)%s$(NC)\n" $(shell basename $@)
	$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@ 2>log
	rm log

$(OBJ_DIR)%.o: $(SRC_DIR_M)%.m
	printf "$(B_CYN)Compling: $(NC)$(B_WHT)%s$(NC)\n" $(shell basename $@)
	$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@ 2>log
	rm log

clean:
	@rm -f $(MLX) $(OBJ_C) $(OBJ_M)
	@rm -rf $(OBJ_DIR)
	@rm -f mlx_app

re: clean all

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
