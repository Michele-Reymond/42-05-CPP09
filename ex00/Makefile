SRCS	= 	main.cpp \
			BtcExchange.cpp 
CFLAGS	= -Wall -Werror -Wextra -std=c++98 -pedantic
CC		= g++-12
NAME	= btc
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
# ./${NAME} input.txt
# ./${NAME} input_empty.txt
	./${NAME} input_error.txt

mrun: all run

.PHONY: all clean fclean re run mrun