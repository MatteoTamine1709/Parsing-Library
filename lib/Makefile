SRC  =  src/perrno.cpp 						\
		src/splitter/splitter_char.cpp 		\
		src/splitter/splitter_word.cpp		\
		src/splitter/c_interface.cpp

INCLUDE = ./include/

NAME   =  libparsing.a

CFLAGS = -g --coverage

OBJ  =  $(SRC:.cpp=.o)

all:  $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re:  fclean all
