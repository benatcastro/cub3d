NAME	=	cub3d
42LIB	=	libraries/42lib.a
TEST	=	test
TEST2	=	test

## COMPILING AND LINKING RELATED VARIABLES ##
AR = ar rc
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SANITIZE = -fsanitize=address -g3
RM = rm -f
#############################################

INCLUDES =	-I includes/	\
			-I	mlx

EXECPT_DIRS	=	mlx
OBJDIR		=	objs
SRCDIR		=	src

SRCDIRS		:=	$(shell find $(SRCDIR) -name '*.c' -exec dirname {} \; | uniq)
OBJDIRS		:=	$(shell find . -name '*.c' -exec dirname {} \; | uniq | sed 's/\/$(SRCDIR)//g' | sed 's/^\.\(.\)//g' | sed 's/$(EXECPT_DIRS)//g')
OBJDIRS		:=	$(addprefix $(OBJDIR)/, $(OBJDIRS))
SRCS		:=	$(shell find $(SRCDIR) -name '*.c')
OBJS		:=	$(patsubst %.c, $(OBJDIR)%.o, $(shell echo $(SRCS) | sed 's/$(SRCDIR)//g'))
#$(patsubst %.c,$(OBJDIR)/%.o,
#############################################
DIRS = .dir
#.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(call mk_dir)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

re: clean all

define mk_dir
	mkdir -p $(OBJDIRS)/;
endef

.PHONY: all clean fclean re bonus ext
