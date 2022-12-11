NAME			=	cub3d
42LIB			=	libraries/42lib.a

## COMPILING AND LINKING RELATED VARIABLES ##
AR				=	ar rc
CC 				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
SANITIZE 		=	-fsanitize=address -g3
LIBFLAGS		=	-L $(LIBRARIES)/
INCFLAG			=	-I $(INCLUDES)/
RM				=	rm -rf
#############################################

INCLUDES =	-I includes/	\
			-I	src/mlx

##########EXCEPTIONS###########
EXCEPT_FILES	=	test.c
EXCEPT_DIRS		=	mlx
#########DIRECTORY DECLARATION###
INCLUDES		=	includes
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
SRCS			:=	$(foreach dir, $(SRCDIRS), $(shell find $(dir) -name '*.c'))
SRCS			:=	$(filter-out $(EXCEPT_FILES),$(SRCS))
OBJS			:=	$(patsubst %.c, $(OBJDIR)%.o, $(shell echo $(SRCS) | sed 's/$(SRCDIR)//g'))
##############PROJECT DIR#############
42LIB_DIR		=	42lib
PROJECT_DIR		=	cub3d

##############PROJECT OBJS#############
42LIB_OBJS		:=	$(wildcard  $(OBJDIR)/$(42LIB_DIR)/*.o)
PROJECT_OBJS	:=	$(wildcard $(OBJDIR)/$(PROJECT_DIR)/*.o)

#$(addprefix $(OBJDIR)/, $(OBJDIRS),

#$(info OBJDIRS=$(OBJDIRS))
#$(info EXECPT_DIRS=$(EXCEPT_DIRS))
#$(info EXCEPT_FILES=$(EXCEPT_FILES))
#$(info SRCS= $(SRCS))
#$(info OBJS= $(OBJS))
#42lib: $(42LIB) $(OBJS)
$(MLX):
	make -C src/mlx
$(42LIB): $(OBJS)
	mkdir -p $(LIBRARIES)
	$(AR) $(42LIB) $(42LIB_OBJS)
all: $(NAME)

$(NAME): $(42LIB) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(PROJECT_OBJS) $(INCFLAG) $(LIBFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(call mk_dir)
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(LIBRARIES)
re: fclean all

define mk_dir
	mkdir -p $(OBJDIRS);
endef

.PHONY: all clean fclean re bonus ext
