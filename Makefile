NAME			=	cub3d
42LIB			=	$(LIBDIR)/42lib.a
DANAE			=	$(LIBDIR)/danae.a
UNAME			=	$(shell uname)
MLX				=	$(LIBDIR)/mlx_$(UNAME).a

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
MLXFlAG 		:=

##########EXCEPTIONS###########
EXCEPT_DIRS		=	mlx_linux mlx_darwin

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
PROJECT_SRC		:=	$(wildcard $(SRCDIR)/$(PROJECT_DIR)/*.c) $(wildcard $(SRCDIR)/$(PROJECT_DIR)/init/*.c)
PROJECT_OBJS	:=	$(subst src, objs, $(PROJECT_SRC:.c=.o))

#############LIB COMPILATION#######################
42LIB_SRC		:=	$(wildcard $(SRCDIR)/$(42LIB_DIR)/*.c)
42LIB_OBJS		:=	$(subst src, objs, $(42LIB_SRC:.c=.o))

DANAE_SRC		:=	$(wildcard $(SRCDIR)/$(DANAE_DIR)/*.c) $(wildcard $(SRCDIR)/$(DANAE_DIR)/raycasting/*.c)
DANAE_OBJS		:=	$(subst src, objs, $(DANAE_SRC:.c=.o))

#$(info LIBFLAG=$(LIBFLAG))
#$(info MLX=$(MLX))
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
#$(info EXECPT_DIRS=$(EXCEPT_DIRS))
#$(info EXCEPT_FILES=$(EXCEPT_FILES))
#$(info SRCS= $(SRCS))
#$(info OBJS= $(OBJS))

.SILENT:
all: $(NAME)

$(NAME): $(OBJS) $(42LIB) $(DANAE) $(DANAE_OBJS) $(MLX)
	printf "$(B_BLU)CREATING $(NC)$(B_WHT)%s$(NC) $(B_BLU)EXECUTABLE$(NC)\n" CUB3D
	$(CC) $(CFLAGS) $(PROJECT_OBJS) $(INCFLAG) $(LIBFLAG) $(MLXFlAG) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(MKDIR) $(@D)
	printf "$(B_CYN)Compling: $(NC)$(B_WHT)%s$(NC)\n" $(shell basename $@)
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@

$(42LIB): $(42LIB_OBJS) $(OBJS)
	$(MKDIR) $(LIBDIR)
	printf "$(B_MAG)CREATING LIBRARY$(NC) $(B_WHT)%s$(NC)\n" 42LIB
	$(AR) $(42LIB) $(42LIB_OBJS)

$(DANAE): $(DANAE_OBJS) $(OBJS)
	$(MKDIR) $(LIBDIR)
	printf "$(B_MAG)CREATING LIBRARY$(NC) $(B_WHT)%s$(NC)\n" DANAE
	$(AR) $(DANAE) $(DANAE_OBJS)

$(MLX):
ifeq ($(UNAME), Darwin)
	printf "$(B_BLU)CREATING MLX FOR$(NC) $(B_WHT)%s OS$(NC) $(B_WHT)$(NC)\n" $(UNAME)
	$(eval MLXFlAG := -framework OpenGL -framework AppKit)
	make -C src/mlx_darwin
else
	ifeq ($(UNAME), Linux)
		$(eval MLXFlAG := -L.. -L%%/../lib -lXext -lX11 -lm -lbsd)
		make -C src/mlx_linux
	else
		@echo Your OS is not compatible
	endif
endif

#Linux:
#Darwin:

clean:
	$(RM) $(OBJDIR)
	make clean -C src/mlx_darwin
	make clean -C src/mlx_linux

fclean: clean
	$(RM) $(LIBDIR)

re: fclean all

run: all
	./$(NAME)


.PHONY: all clean fclean re bonus

BLK		=	\e[0;30m
RED		=	\e[0;31m
GRN		=	\e[0;32m
YEL		=	\e[0;33m
BLU		=	\e[0;34m
MAG		=	\e[0;35m
CYN		=	\e[0;36m
WHT		=	\e[0;37m

B_BLK	=	\e[1;30m
B_RED	=	\e[1;31m
B_GRN	=	\e[1;32m
B_YEL	=	\e[1;33m
B_BLU	=	\e[1;34m
B_MAG	=	\e[1;35m
B_CYN	=	\e[1;36m
B_WHT	=	\e[1;37m
NC	=	\e[0m
