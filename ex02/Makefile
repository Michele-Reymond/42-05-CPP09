SRCS	= 	main.cpp \
			RPN.cpp 
CFLAGS	= -Wall -Werror -Wextra -std=c++98 -pedantic
CC		= g++-12
NAME	= PmergeMe
OBJS	= ${SRCS:.cpp=.o}
RM		= rm -f

all:	${NAME}

.cpp.o:
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

run:
	./${NAME} 3 5 9 7 4
#	./${NAME} `jot -r 3000 1 100000 | tr '\n' ' '`

# https://www.dcode.fr/notation-polonaise-inverse

mrun: all run

.PHONY: all clean fclean re run mrun