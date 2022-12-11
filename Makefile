NAME			=	cub3d
42LIB			=	libraries/42lib.a

## COMPILING AND LINKING RELATED VARIABLES ##
AR = ar rc
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SANITIZE = -fsanitize=address -g3
RM = rm -f
#############################################

INCLUDES =	-I includes/	\
			-I	src/mlx

##########EXCEPTIONS###########
EXCEPT_FILES	=
EXCEPT_DIRS		=	mlx
#########DIRECTORY DECLARATION###
OBJDIR			=	objs
SRCDIR			=	src

############EXPAND EXCEPTIONS##########
EXCEPT_DIRS		:=	$(foreach dir, $(EXCEPT_DIRS), $(shell find $(SRCDIR) -type d -name '$(dir)'))
EXCEPT_FILES	:=	$(foreach file, $(EXCEPT_FILES), $(shell find $(SRCDIR) -name '$(file)'))

###########
SRCDIRS			:=	$(shell find $(SRCDIR) -name '*.c' -exec dirname {} \; | uniq)
SRCDIRS			:=	$(filter-out $(EXCEPT_DIRS), $(SRCDIRS))
OBJDIRS			:=	$(addprefix $(OBJDIR), $(shell echo $(SRCDIRS) | sed 's/$(SRCDIR)//g'))
SRCS			:=	$(foreach dir, $(SRCDIRS), $(shell find $(dir) -name '*.c'))
SRCS			:=	$(filter-out $(EXCEPT_FILES),$(SRCS))
OBJS			:=	$(patsubst %.c, $(OBJDIR)%.o, $(shell echo $(SRCS) | sed 's/$(SRCDIR)//g'))
#$(addprefix $(OBJDIR)/, $(OBJDIRS),

#$(info SRCDIRS=$(SRCDIRS))
#$(info OBJDIRS=$(OBJDIRS))
#$(info EXECPT_DIRS=$(EXCEPT_DIRS))
#$(info EXCEPT_FILES=$(EXCEPT_FILES))
#$(info SRCS= $(SRCS))
#$(info OBJS= $(OBJS))
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)%$^ -o $(NAME)

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
