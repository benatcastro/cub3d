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

EXECPT_DIRS	=	cub3d 42lib
OBJDIR		=	objs
SRCDIR		=	src


EXECPT_DIRS	:=	$(foreach dir, $(EXECPT_DIRS), $(shell find $(SRCDIR) -type d -name '$(dir)'))
SRCDIRS		:=	$(filter-out $(EXECPT_DIRS), $(SRCDIRS), $(shell find $(SRCDIR) -name '*.c' -exec dirname {} \; | uniq))
OBJDIRS		:=	$(addprefix $(OBJDIR), $(shell echo $(SRCDIRS) | sed 's/$(SRCDIR)//g'))
SRCS		:=	$(shell find $(SRCDIR) -name '*.c')
OBJS		:=	$(patsubst %.c, $(OBJDIR)%.o, $(shell echo $(SRCS) | sed 's/$(SRCDIR)//g'))
#$(addprefix $(OBJDIR)/, $(OBJDIRS),
#.SILENT:


$(info SRCDIRS=$(SRCDIRS))
$(info OBJDIRS=$(OBJDIRS))
$(info TEST=$(EXECPT_DIRS))
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
