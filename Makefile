SRC	=	src/main.cpp

CSRC	=	src/c_interface.c

CFLAGS = 	-W -Wall -Wextra

LIB = -L./lib -lparsing

INCLUDE = 	-I./include

NAME 	=	parser

CNAME 	=	cparser

CRIT_NAME 	= 	unit_tests

CRIT_FLAG	= 	--coverage --verbose -lcriterion

CRIT_TEST = 	tests/compare_string_vector.cpp 						\
				tests/splitter/test_splitter_char_without_keep.cpp 		\
				tests/splitter/test_splitter_char_keep.cpp 				\
				tests/splitter/test_splitter_word_without_keep.cpp 		\
				tests/splitter/test_splitter_word_keep.cpp

CRIT_SRC 	= 	lib/src/perrno.cpp 						\
				lib/src/splitter/splitter_char.cpp 		\
				lib/src/splitter/splitter_word.cpp		\
				lib/src/splitter/c_interface.cpp

all:	build_lib $(NAME)

$(NAME):
	g++ -o $(NAME) $(SRC) $(LIB) $(INCLUDE)

clean:
	rm -rf $(NAME)
	rm -rf $(CNAME)
	rm -rf $(CRIT_NAME)

crit_clean:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.gcov

fclean: clean crit_clean
	rm -rf vg*

re: fclean all

cre: re build_lib
	g++ -g -o $(CNAME) $(CSRC) $(LIB) $(INCLUDE)

build_lib:
	make re -C lib/

debug: CFLAGS += -g fclean all

unit_test: re
	g++ -o ${CRIT_NAME} ${CRIT_SRC} ${CRIT_FLAG} $(CRIT_TEST) ${INCLUDE} ${LIB}
	clear
	./$(CRIT_NAME)

branch: unit_test
	gcovr --exclude tests/ --exclude lib/src/splitter/c_interface.cpp --branches

coverage: unit_test
	gcovr --exclude tests/ --exclude lib/src/splitter/c_interface.cpp
