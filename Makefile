SRC	=	src/main.cpp

CSRC	=	src/c_interface.c

CFLAGS = 	-W -Wall -Wextra

LIB = -L./lib -lparsing

INCLUDE = 	-I./include

NAME 	=	parser

CNAME 	=	cparser

all:	build_lib $(NAME)

$(NAME):
	g++ -g -o $(NAME) $(SRC) $(LIB) $(INCLUDE)

clean:
	rm -rf $(NAME)
	rm -rf $(CNAME)

fclean: clean
	rm -rf $(OBJ)
	rm -rf vg*

re: fclean all

cre: fclean build_lib
	g++ -g -o $(CNAME) $(CSRC) $(LIB) $(INCLUDE)

build_lib:
	make re -C lib/

debug: CFLAGS += -g fclean all

unit_test: re
	make compil_crit -C tests/
