SRCS	= 	main.cpp \
			PmergeMe.cpp 
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
	./${NAME} 5 2 56 12 4 6 7 13 14 67 3 8 15
#	if doubles possibles 
#	./${NAME} `jot -r 3000 1 100000 | tr '\n' ' '`

#	if not
#	./PmergeMe `jot -r 3000 1 2000000 | tr '\n' ' '`

# https://www.dcode.fr/notation-polonaise-inverse

mrun: all run

.PHONY: all clean fclean re run mrun