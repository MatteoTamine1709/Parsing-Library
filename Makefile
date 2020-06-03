SRC	=	src/main.cpp

CFLAGS = 	-W -Wall -Wextra

LIB = -L./lib -lparsing

INCLUDE = 	-I./include

NAME 	=	parser

all:	build_lib $(NAME)

$(NAME):
	g++ -o $(NAME) $(SRC) $(LIB) $(INCLUDE)

clean:
	make clean -C lib

fclean: clean
	rm -rf $(NAME)
	rm -rf $(OBJ)

re: fclean all

build_lib:
	make re -C lib/

debug: CFLAGS += -g fclean all

unit_test: re
	make compil_crit -C tests/
