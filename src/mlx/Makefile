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

MLX = $(LIBRARIES_DIR)libmlx.a

CC = gcc
AR = ar rc
CC_FLAGS = -O2 -DSTRINGPUTX11

LIBRARIES_DIR = ../../libraries/
INCLUDES = -I ../../includes/ -I ../../includes/mlx/
OBJ_DIR	=	../../objs/mlx/
# add to match string put with X11 in size and position
SRC_C = $(addprefix $(SRC_DIR_C), $(addsuffix .c, $(SRC_FILES_C)))
OBJ_C = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_C)))

SRC_M = $(addprefix $(SRC_DIR_M), $(addsuffix .m, $(SRC_FILES_M)))
OBJ_M = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_M)))

all: $(MLX)

$(MLX) : $(OBJF) $(OBJ_C) $(OBJ_M)
	@$(AR) $(MLX) $(OBJ_C) $(OBJ_M)
	@ranlib $(MLX)

$(OBJ_DIR)%.o: $(SRC_DIR_C)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR_M)%.m
	@$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(MLX) $(OBJ_C) $(OBJ_M)
	@rm -rf $(OBJ_DIR)
	@rm -f mlx_app

re: clean all
