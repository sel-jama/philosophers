# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 07:46:18 by sel-jama          #+#    #+#              #
#    Updated: 2023/06/09 22:53:43 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = init.c philo.c treads.c utils.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

NAME = philo

all: ${NAME}

${NAME} : ${OBJS}
	${CC} -fsanitize=address ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all