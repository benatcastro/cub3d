NAME			=	cub3d
42LIB			=	libraries/42lib.a
DANAE			=	libraries/danae.a
UNAME			=	$(shell uname)
MLX				=	libraries/mlx.a

## COMPILING AND LINKING RELATED VARIABLES ##
AR				=	ar rc
CC 				=	gcc
RM				=	rm -rf
MKDIR			=	mkdir -p
################FLAGS##########################
CFLAGS			=	-Wall -Werror -Wextra# $(SANITIZE)
SANITIZE 		=	-fsanitize=address -g3
LIBFLAG			=	$(LIBRARIES)/*
INCFLAG			=	-I includes/ -I src/mlx/include/
MLXFlAG			=	-framework OpenGL -framework AppKit

##########EXCEPTIONS###########
EXCEPT_FILES	=	test.c
EXCEPT_DIRS		=	mlx
#########DIRECTORY DECLARATION###
LIBRARIES		=	libraries
OBJDIR			=	objs
SRCDIR			=	src

############EXPAND EXCEPTIONS##########
EXCEPT_DIRS		:=	$(foreach dir, $(EXCEPT_DIRS), $(shell find $(SRCDIR) -type d -name '$(dir)'))
EXCEPT_FILES	:=	$(foreach file, $(EXCEPT_FILES), $(shell find $(SRCDIR) -name '$(file)'))

############CREATING ALL OBJS##############
SRCDIRS			:=	$(shell find $(SRCDIR) -name '*.c' -exec dirname {} \; | uniq)
SRCDIRS			:=	$(filter-out $(EXCEPT_DIRS), $(SRCDIRS))
OBJDIRS			:=	$(addprefix $(OBJDIR), $(shell echo $(SRCDIRS) | sed 's/$(SRCDIR)//g'))
SRCDEP			:=	$(wildcard $(INCDIR)/*h)
DEPDIR			:=	$(OBJDIR)/dependencies
SRCS			:=	$(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*c))
SRCS			:=	$(filter-out $(EXCEPT_FILES),$(SRCS))
OBJS			:=	$(patsubst %.c, $(OBJDIR)%.o, $(shell echo $(SRCS) | sed 's/$(SRCDIR)//g'))
DEP				:=	$(subst $(OBJDIR), $(DEPDIR), $(OBJS:.o=.d))
##############PROJECT DIRS#############
42LIB_DIR		=	42lib
DANAE_DIR		=	danae
PROJECT_DIR		=	cub3d

##############PROJECT OBJS#############
42LIB_OBJS		:=	$(wildcard $(OBJDIR)/$(42LIB_DIR)/*.o)
PROJECT_OBJS	:=	$(wildcard $(OBJDIR)/$(PROJECT_DIR)/*.o) $(wildcard $(OBJDIR)/$(PROJECT_DIR)/init/*.o)
DANAE_OBJS		:=	$(wildcard $(OBJDIR)/$(DANAE_DIR)/*.o) $(wildcard $(OBJDIR)/$(DANAE_DIR)/raycasting/*.o)
#############MLX VARS COMPILATION#######################


#$(addprefix $(OBJDIR)/, $(OBJDIRS),
#$(info DEP=$(DEP))
#$(info DEPDIR=$(DEPDIR))
#$(info SRCDEP=$(SRCDEP))
#$(info PROJECT_OBJS=$(PROJECT_OBJS))
#$(info MLXOS=$(MLXOS))
#$(info MLXDIR=$(MLXDIR))
#$(info MLXSRCS=$(MLXSRCS))
#$(info MLXSOBJS=$(MLXOBJS))
#$(info PROJECT_OBJS=$(PROJECT_OBJS))
#$(info dane_objS=$(DANAE_OBJS))
#$(info EXECPT_DIRS=$(EXCEPT_DIRS))
#$(info EXCEPT_FILES=$(EXCEPT_FILES))
#$(info SRCS= $(SRCS))
#$(info OBJS= $(OBJS))
all: $(NAME)


$(NAME): $(OBJS) $(42LIB) $(DANAE)
	$(CC) $(CFLAGS) $(PROJECT_OBJS) $(INCFLAG) $(LIBFLAG) $(MLXFlAG) -o $(NAME)


$(DANAE): $(DANAE_OBJS) $(OBJS)
	$(MKDIR) $(LIBRARIES)
	$(AR) $(DANAE) $(DANAE_OBJS)
	make -C src/mlx

$(42LIB): $(42LIB_OBJS) $(OBJS)
	$(MKDIR) $(LIBRARIES)
	$(AR) $(42LIB) $(42LIB_OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@
clean:
	$(RM) $(OBJDIR)
	make clean -C src/mlx
fclean: clean
	$(RM) $(LIBRARIES)
	make clean -C src/mlx

re: fclean all

run: all
	./$(NAME)

define mk_dir
	$(MKDIR) $(OBJDIRS);
endef

define mlx_compiler
	echo mlx_compiler
endef


.PHONY: all clean fclean re bonus ext
