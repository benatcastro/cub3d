NAME	=	cub3d
42LIB	=	libraries/42lib.a

## COMPILING AND LINKING RELATED VARIABLES ##
AR = ar rc
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SANITIZE = -fsanitize=address -g3
RM = rm -f
#############################################

INCLUDES =	-I includes/	\
			-I	mlx

OBJDIR		=	objs
SRCDIR		=	src

SRCDIRS		:=	$(shell find $(SRCDIR) -name '*.c' -exec dirname {} \; | uniq)
SRCS		:=	$(shell find $(SRCDIR) -name '*.c')
OBJS		:=	$(patsubst %.c,$(OBJDIR)/%.o, $(shell echo $(SRCS) | cut -f2))

#############################################

#.SILENT:

all:
	echo $(SRCDIRS)
test: $(NAME)

$(NAME) : buildtree $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) libraries/*

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	rm -rf $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

buildtree:
	@$(call mk_dir)

define mk_dir
	mkdir -p $(OBJDIR)/;		\
	for dir in $(SRCDIRS);	\
	do	\
		mkdir -p $(OBJDIR)/$$dir;	\
	done
endef

.PHONY: all clean fclean re bonus ext
