SRC  =  src/perrno.cpp 						\
		src/splitter/splitter_char.cpp 		\
		src/splitter/splitter_word.cpp		\
		src/splitter/c_interface.cpp

NAME   =  libparsing.a

CXXFLAGS = -std=c++17 -g

OBJ  =  $(SRC:.cpp=.o)

all:  $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re:  fclean all
