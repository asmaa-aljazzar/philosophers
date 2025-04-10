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
#	|- program/
#		|- init/
#		|- threads/ 
#	|- utils/

INIT_DIR	=	$(SRCS_DIR)program/init/input_init.c\
				$(SRCS_DIR)program/init/forks_init.c\
				$(SRCS_DIR)program/init/philos_init.c\
				$(SRCS_DIR)program/init/program_init.c\

UTILS_DIR	=	$(SRCS_DIR)utils/ft_atoi.c\
				$(SRCS_DIR)utils/write_error.c\
				$(SRCS_DIR)utils/ft_current_time.c\

PHILO_ROUTINE_DIR	=	$(SRCS_DIR)program/threads/philo_routine/philo_routine.c\
						$(SRCS_DIR)program/threads/philo_routine/actions.c

THREADS_DIR	=	$(SRCS_DIR)program/threads/monitoring.c\
				$(SRCS_DIR)program/threads/thread_create.c\
				$(PHILO_ROUTINE_DIR)

PROGRAM_DIR	=	$(INIT_DIR)\
				$(THREADS_DIR)\
				$(SRCS_DIR)program/main.c\
				$(SRCS_DIR)program/destroy_all.c\
				$(SRCS_DIR)program/check_input.c\

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
