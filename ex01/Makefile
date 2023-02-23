SRCS	= 	main.cpp \
			RPN.cpp 
CFLAGS	= -Wall -Werror -Wextra -std=c++98 -pedantic
CC		= g++-12
NAME	= RPN
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
	./${NAME} "89 * 9 - 9 - 9 - 4 - 1 +"
#	./${NAME} "82 / 2 + 4 * 2 +"
#	./${NAME} "77 * 7 -"
#	./${NAME} "734*+"
#	./${NAME} "3 4 1 2 + * +"
#	./${NAME} "0 4 1 2 + * +"
#	./${NAME} "92/"
#	./${NAME} "92/5*3/"
#	./${NAME} "60/"

#	errors
#	./${NAME} "82"
#	./${NAME} "82 7 4 22"
#	./${NAME} "8 + 2"
#	./${NAME} "8"
#	./${NAME} "+"
#	./${NAME} "62+*"
#	./${NAME} "82 /* 2 + 4 * 2 +"
#	./${NAME} "3 4 1 2 + × +"
#	./${NAME} "* 1 2 + 4 × 3 +"
#	./${NAME} 89 * 9 
#	./${NAME} "(1 + 1)" 

# https://www.dcode.fr/notation-polonaise-inverse

mrun: all run

.PHONY: all clean fclean re run mrun