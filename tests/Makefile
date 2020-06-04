CRIT_NAME 	= 	unit_tests

CRIT_FLAG	= 	--coverage --verbose -lcriterion

CRIT_SRC 	= 	splitter/test_splitter_char_without_keep.cpp 		\
				splitter/test_splitter_char_keep.cpp

LIB 		= 	-L../lib -lparsing

INCLUDE		=	-I../include/

compil_crit: fclean
	g++ -o ${CRIT_NAME} ${CRIT_SRC} ${CRIT_FLAG} ${INCLUDE} ${LIB}
	
fclean:
	rm -rf *.gcda
	rm -rf *.gcno
gcov:
	gcov *