
SRCS 			= ${wildcard ./philos/*.c}

SRCS_BONUS		= ${wildcard ./philo_bonus/*.c}

OBJS 			= ${SRCS:.c=.o}

OBJS_BONUS		= ${SRCS_BONUS:.c=.o}

CC				= cc
RM				= rm -f
CFLAGS			= -pthread -Wall -Wextra -Werror

NAME			= philo
NAME_BONUS		= philo_bonus

all:			${NAME}

$(NAME):		$(OBJS)
				${CC}  ${CFLAGS} -o ${NAME} ${OBJS}
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
				${RM} ${OBJS}
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				${RM} ${NAME} ${NAME_BONUS}
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

bonus:			${NAME_BONUS}
				@echo -e "$(GREEN)$(NAME_BONUS) created!$(DEFAULT)"			

$(NAME_BONUS):	${BONUS_OBJS}
				${CC}  ${CFLAGS} -o ${NAME_BONUS} ${BONUS_OBJS}

.PHONY:			all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
