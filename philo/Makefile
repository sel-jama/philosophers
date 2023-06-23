# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 07:46:18 by sel-jama          #+#    #+#              #
#    Updated: 2023/06/23 19:53:05 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = init.c philo.c threads.c utils.c check_args.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

NAME = philo

all: ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all