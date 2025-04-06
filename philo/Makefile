# Color
RESET	=	\033[0m
RED	=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m


# Standard
NAME	= philo

# Compiler and Flags
CC		= 	cc
CFLAGS 	= 	-Wall -Wextra -Werror -pthread -g -I
RM 		= 	rm -f

# Directories
INC			= 	includes/
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/

# Source Files

#	srcs/
#	|-second/
#	|-third/

INIT_DIR	=	init/

UTILS_DIR	=	$(SRCS_DIR)utils/ft_atoi.c\
				$(SRCS_DIR)utils/write_error.c

PROGRAM_DIR	=	$(SRCS_DIR)program/check_input.c\
				$(SRCS_DIR)program/main.c\
				$(SRCS_DIR)program/$(INIT_DIR)program_init.c\
				$(SRCS_DIR)program/$(INIT_DIR)forks_init.c\
				$(SRCS_DIR)program/$(INIT_DIR)philos_init.c\

SRCS	=	$(UTILS_DIR) $(PROGRAM_DIR)

OBJS	=	$(patsubst $(SRCS_DIR)%.c,$(OBJS_DIR)%.o,$(SRCS))


# Build Rules
# start:
# 	make all

all: $(NAME) $(LIBFT)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(INC) $(OBJS)  -o $(NAME)
	@echo "\n[ $(YELLOW)$(NAME) $(RESET)] $(GREEN)has been created!$(RESET)\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@echo "Creating $(YELLOW)$(@D)$(RESET)/ $(GREEN)$(@F)$(RESET)"
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)
	@echo "\n$(BLUE)Obj files cleaned.$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\n$(BLUE)Binary files cleaned.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
