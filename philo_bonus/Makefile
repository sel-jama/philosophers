# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 07:46:18 by sel-jama          #+#    #+#              #
#    Updated: 2023/06/23 12:21:21 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_BONUS = init_open.c philo_bonus.c children_philos.c utils_bonus.c check_args.c

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread

NAME = philo_bonus

all: ${NAME}

${NAME} : ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} -o ${NAME}

clean:
	@rm -f ${OBJS_BONUS}

fclean: clean
	@rm -f ${NAME}

re: fclean all