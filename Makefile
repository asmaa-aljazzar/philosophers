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

# Directories ---> paths
INC			= 	includes/
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/
PROG		=	$(SRCS_DIR)program/
INIT		=	$(PROG)init/
THREAD		=	$(PROG)threads/
UTIL		=	$(SRCS_DIR)utils/
PHILO_ROUTINE	=	$(THREAD)philo_routine/
MONITOR	=	$(THREAD)monitoring/
ACT	=	$(PHILO_ROUTINE)actions/

# Source Files

#	srcs/
#	|- program/
#		|- init/
#		|- threads/
#			|- philo_routine
#				|- actions
#	|- utils/

ACTIONS_DIR	=	$(ACT)eating.c\
				$(ACT)sleeping.c\
				$(ACT)thinking.c

PHILO_ROUTINE_DIR	= 	$(ACTIONS_DIR)\
						$(PHILO_ROUTINE)philo_routine.c

MONITORING_DIR	=	$(MONITOR)monitoring.c\

THREADS_DIR	=	$(PHILO_ROUTINE_DIR)\
				$(THREAD)monitoring.c\
				$(THREAD)thread_create.c

INIT_DIR	=	$(INIT)forks_init.c\
				$(INIT)input_init.c\
				$(INIT)philos_init.c\
				$(INIT)program_init.c

PROGRAM_DIR	=	$(INIT_DIR)\
				$(THREADS_DIR)\
				$(PROG)check_input.c\
				$(PROG)destroy_all.c\
				$(PROG)main.c
				
UTILS_DIR	=	$(UTIL)ft_atoi.c\
				$(UTIL)write_error.c\
				$(UTIL)ft_current_time.c\
				$(UTIL)print_msg.c

SRCS	=	$(UTILS_DIR) $(PROGRAM_DIR)

OBJS	=	$(patsubst $(SRCS_DIR)%.c,$(OBJS_DIR)%.o,$(SRCS))


# Build Rules
# start:
# 	make all

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)
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
