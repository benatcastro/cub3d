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
CFLAGS			:=	-Wall -Werror -Wextra# $(SANITIZE)
SANITIZE 		:=	-fsanitize=address -g3
LIBDIR			=	libraries
LIBFLAG			:=	$(LIBDIR)/*
INCFLAG			:=	-I includes/ -I src/mlx/include/
MLXFlAG			:=

##########EXCEPTIONS###########
EXCEPT_DIRS		=	mlx_linux mlx_darwin
EXCEPT_FILES	=
#########DIRECTORY DECLARATION###
OBJDIR			=	objs
SRCDIR			=	src

############EXPAND EXCEPTIONS##########
EXCEPT_DIRS		:=	$(foreach dir, $(EXCEPT_DIRS), $(shell find $(SRCDIR) -name $(dir)))
EXCEPT_FILES	+=	$(foreach dir, $(EXCEPT_DIRS), $(shell find $(dir) -name '*.c'))


############CREATING ALL OBJS##############
SRCDIRS			:=	$(shell find $(SRCDIR) -name '*.c' -exec dirname {} \; | uniq)
SRCDIRS			:=	$(filter-out $(EXCEPT_DIRS), $(SRCDIRS))
OBJDIRS			:=	$(addprefix $(OBJDIR), $(shell echo $(SRCDIRS) | sed 's/$(SRCDIR)//g'))
SRCS			:=	$(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*c))
SRCS			:=	$(filter-out $(EXCEPT_FILES),$(SRCS))
OBJS			:=	$(patsubst %.c, $(OBJDIR)%.o, $(shell echo $(SRCS) | sed 's/$(SRCDIR)//g'))
##############PROJECT DIRS#############
42LIB_DIR		=	42lib
DANAE_DIR		=	danae
PROJECT_DIR		=	cub3d

##############PROJECT OBJS#############
PROJECT_OBJS	:=	$(wildcard $(OBJDIR)/$(PROJECT_DIR)/*.o) $(wildcard $(OBJDIR)/$(PROJECT_DIR)/init/*.o)
DANAE_OBJS		:=	$(wildcard $(OBJDIR)/$(DANAE_DIR)/*.o) $(wildcard $(OBJDIR)/$(DANAE_DIR)/raycasting/*.o)
#############MLX VARS COMPILATION#######################
42LIB_SRC		:=	$(wildcard $(SRCDIR)/$(42LIB_DIR)/*.c)
42LIB_OBJS		:=	$(subst src, objs, $(42LIB_SRC:.c=.o))


#$(addprefix $(OBJDIR)/, $(OBJDIRS),
$(info LIBFLAG=$(LIBFLAG))
#$(info 42OBJS=$(42LIB_OBJS))
#$(info DEPDIR=$(DEPDIR))
#$(info SRCDEP=$(SRCDEP))
#$(info PROJECT_OBJS=$(PROJECT_OBJS))
#$(info MLXOS=$(MLXOS))
#$(info MLXDIR=$(MLXDIR))
#$(info MLXSRCS=$(MLXSRCS))
#$(info MLXSOBJS=$(MLXOBJS))
#$(info PROJECT_OBJS=$(PROJECT_OBJS))
#$(info dane_objS=$(DANAE_OBJS))
$(info EXECPT_DIRS=$(EXCEPT_DIRS))
$(info EXCEPT_FILES=$(EXCEPT_FILES))
$(info SRCS= $(SRCS))
#$(info OBJS= $(OBJS))


all: $(NAME)


$(NAME): $(OBJS) $(42LIB) $(DANAE) $(UNAME)
	$(CC) $(CFLAGS) $(PROJECT_OBJS) $(INCFLAG) $(LIBFLAG) $(MLXFlAG) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@

$(DANAE): $(DANAE_OBJS) $(OBJS)
	$(MKDIR) $(LIBDIR)
	$(AR) $(DANAE) $(DANAE_OBJS)

$(42LIB): $(42LIB_OBJS) $(OBJS)
	$(MKDIR) $(LIBDIR)
	$(AR) $(42LIB) $(42LIB_OBJS)



Linux:
	$(eval MLXFlAG := -L.. -L%%/../lib -lXext -lX11 -lm -lbsd)
	make -C src/mlx_linux

Darwin:
	$(eval MLXFlAG := -framework OpenGL -framework AppKit)
	make -C src/mlx_darwin

clean:
	$(RM) $(OBJDIR)
	make clean -C src/mlx_darwin
	make clean -C src/mlx_linux

fclean: clean
	$(RM) $(LIBDIR)

re: fclean all

run: all
	./$(NAME)


.PHONY: all clean fclean re bonus ext
