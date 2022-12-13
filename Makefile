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
CFLAGS			=	-Wall -Werror -Wextra
SANITIZE 		=	-fsanitize=address -g3
LIBFLAG			=	$(LIBRARIES)/*
INCFLAG			=	-I includes/ -I src/mlx_darwin/
MLXFlAG			=	-lglfw

##########EXCEPTIONS###########
EXCEPT_FILES	=	test.c
EXCEPT_DIRS		=	parsing
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
PROJECT_OBJS	:=	$(wildcard $(OBJDIR)/$(PROJECT_DIR)/*.o)
DANAE_OBJS		:=	$(wildcard $(OBJDIR)/$(DANAE_DIR)/*.o)
#############MLX VARS COMPILATION#######################
MLXOS			?=
MLXDIR			?=
MLXOSRCS		?=
MLXOBJS			?=

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
$(info dane_objS=$(DANAE_OBJS))
#$(info EXECPT_DIRS=$(EXCEPT_DIRS))
#$(info EXCEPT_FILES=$(EXCEPT_FILES))
#$(info SRCS= $(SRCS))
#$(info OBJS= $(OBJS))
all: $(NAME)


$(NAME): $(PROJECT_OBJS) $(MLX) $(DANAE) $(42LIB) $(OBJS)
	$(CC) $(CFLAGS) $(PROJECT_OBJS) $(INCFLAG) $(LIBFLAG) $(MLXFlAG) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@

$(42LIB): $(42LIB_OBJS) $(OBJS)
	$(MKDIR) $(LIBRARIES)
	$(AR) $(42LIB) $(42LIB_OBJS)

$(DANAE): $(DANAE_OBJS) $(OBJS)
	$(MKDIR) $(LIBRARIES)
	$(AR) $(DANAE) $(DANAE_OBJS)

$(MLX):
	$(MKDIR) libraries/
	make -C src/mlx_darwin


$(MLXOS):
ifeq ($(UNAME), Darwin)
	echo Darwin mlx
else
ifeq ($(UNAME), Linux)
	$(eval MLXOS = LINUX)
	$(eval MLXDIR = $(SRCDIR)/mlx_linux)
	$(eval MLXSRCS = $(wildcard $(MLXDIR)/*c))
	$(eval MLXSOBJS = $(eval MLXOBJS = $(patsubst %.c, %.o, MLXSRCS)))

	$(info MLXOS=$(MLXOS))
	$(info MLXDIR=$(MLXDIR))
	$(info MLXSRCS=$(MLXSRCS))
	$(info MLXSOBJS=$(MLXOBJS))
else
	printf "Your OS is not compatible with this program";
endif
endif
	@$(call mlx_compiler)

clean:
	$(RM) $(OBJDIR)
	make clean -C src/mlx_darwin
fclean: clean
	$(RM) $(LIBRARIES)

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
