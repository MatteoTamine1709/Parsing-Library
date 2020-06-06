SRC	=	src/main.cpp

CSRC	=	src/c_interface.c

CFLAGS = 	-W -Wall -Wextra

LIB = -L./lib -lparsing

CLIB = -L./lib -lcparsing

INCLUDE = 	-I./include

NAME 	=	parser

CNAME 	=	cparser

CRIT_NAME 	= 	unit_tests

CRIT_FLAG	= 	--coverage --verbose -lcriterion

CRIT_TEST = 	tests/compare_string_vector.cpp 						\
				tests/find_pattern/display_vector_variant.cpp 			\
				tests/splitter/test_splitter_char_without_keep.cpp 		\
				tests/splitter/test_splitter_char_keep.cpp 				\
				tests/splitter/test_splitter_word_without_keep.cpp 		\
				tests/splitter/test_splitter_word_keep.cpp 				\
				tests/find_pattern/test_find_pattern_without_keep_decimal.cpp \
				tests/find_pattern/test_find_pattern_without_keep_general.cpp \
				tests/find_pattern/test_find_pattern_keep_general.cpp

CRIT_SRC 	= 	lib/src/splitter/splitter_char.cpp 		\
				lib/src/splitter/splitter_word.cpp 		\
				lib/src/find_pattern/find_pattern.cpp 		\
				lib/src/find_pattern/flag_manager.cpp 		\
				lib/src/find_pattern/get_flag_num.cpp 		\
				lib/src/find_pattern/get_flag_string.cpp 	\
				lib/src/find_pattern/get_flag.cpp

all:	build_lib $(NAME)

$(NAME):
	g++ -std=c++17 -o $(NAME) $(SRC) $(LIB) $(INCLUDE)

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
	make fclean -C lib/

re: fclean all

cre: fclean build_clib
	g++ -std=c++17 -g -o $(CNAME) $(CSRC) $(CLIB) $(INCLUDE)

build_lib:
	make cpplib -C lib/

build_clib:
	make clib -C lib/

debug: CFLAGS += -g fclean all

unit_test: fclean build_clib
	g++ -std=c++17 -o ${CRIT_NAME} ${CRIT_SRC} ${CRIT_FLAG} $(CRIT_TEST) ${INCLUDE} ${CLIB}
	clear
	./$(CRIT_NAME)

branch: unit_test
	gcovr --exclude tests/ --branches

coverage: unit_test
	gcovr --exclude tests/
