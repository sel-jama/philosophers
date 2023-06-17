# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 07:46:18 by sel-jama          #+#    #+#              #
#    Updated: 2023/06/16 05:18:00 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_BONUS = init.c philo_bonus.c treads.c utils.c

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

NAME = philo_bonus

all: ${NAME}

${NAME} : ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} -o ${NAME}

clean:
	@rm -f ${OBJS_BONUS}

fclean: clean
	@rm -f ${NAME}

re: fclean all