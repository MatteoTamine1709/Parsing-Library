SRC  =  src/perrno.cpp

INCLUDE = ./include/

NAME   =  libparsing.a

OBJ  =  $(SRC:.cpp=.o)

all:  $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re:  fclean all
