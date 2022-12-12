NAME			=	cub3d
42LIB			=	libraries/42lib.a
UNAME			=	$(shell uname)
MLX				=	libraries/mlx.a

## COMPILING AND LINKING RELATED VARIABLES ##
AR				=	ar rc
CC 				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
SANITIZE 		=	-fsanitize=address -g3
LIBFLAGS		=	$(LIBRARIES)/*
INCFLAG			=	-I $(INCDIR)/
RM				=	rm -rf
MKDIR			=	mkdir -p
#############################################

INCLUDES 		=	-I includes/	\

##########EXCEPTIONS###########
EXCEPT_FILES	=
EXCEPT_DIRS		=	mlx_darwin mlx_linux
#########DIRECTORY DECLARATION###
INCDIR			=	includes
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
DEP				:=	$(subst $(INCDIR), $(DEPDIR), $(SRCDEP:.h=.d))
##############PROJECT DIRS#############
42LIB_DIR		=	42lib
PROJECT_DIR		=	cub3d

##############PROJECT OBJS#############
42LIB_OBJS		:=	$(wildcard $(OBJDIR)/$(42LIB_DIR)/*.o)
PROJECT_OBJS	:=	$(wildcard $(OBJDIR)/$(PROJECT_DIR)/*.o)

#############MLX VARS COMPILATION#######################
MLXOS			?=
MLXDIR			?=
MLXOSRCS		?=
MLXOBJS			?=

#$(addprefix $(OBJDIR)/, $(OBJDIRS),
$(info DEP=$(DEP))
$(info DEPDIR=$(DEPDIR))
$(info SRCDEP=$(SRCDEP))
#$(info PROJECT_OBJS=$(PROJECT_OBJS))
#$(info MLXOS=$(MLXOS))
#$(info MLXDIR=$(MLXDIR))
#$(info MLXSRCS=$(MLXSRCS))
#$(info MLXSOBJS=$(MLXOBJS))
#$(info PROJECT_OBJS=$(PROJECT_OBJS))

#$(info EXECPT_DIRS=$(EXCEPT_DIRS))
#$(info EXCEPT_FILES=$(EXCEPT_FILES))
#$(info SRCS= $(SRCS))
#$(info OBJS= $(OBJS))
test:
all: $(NAME)

$(NAME): $(42LIB) $(MLX) $(OBJS) $(DEP)
	$(CC) $(CFLAGS) $(PROJECT_OBJS) $(INCFLAG) $(LIBFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(call mk_dir)
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@

$(DEP): $(SRCDEP)
	$(MKDIR) $(OBJDIR)/$(DEPDIR)/
	$(CC) -c $< -o $@

$(42LIB): $(OBJS)
	$(MKDIR) $(LIBRARIES)
	$(AR) $(42LIB) $(42LIB_OBJS)

$(MLX):
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
