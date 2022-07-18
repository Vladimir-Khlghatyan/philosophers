
SRCS 			= ${wildcard ./*.c}

OBJS 			= ${SRCS:.c=.o}

CC				= cc
RM				= rm -f
CFLAGS			= -pthread -Wall -Wextra -Werror

NAME			= philo_bonus

all:			${NAME}

$(NAME):		$(OBJS)
				${CC}  ${CFLAGS} -o ${NAME} ${OBJS}
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
				${RM} ${OBJS}
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				${RM} ${NAME}
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:			all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
