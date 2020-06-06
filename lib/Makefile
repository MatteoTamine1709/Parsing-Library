SRC  =  src/perrno.cpp 							\
		src/splitter/splitter_char.cpp 			\
		src/splitter/splitter_word.cpp 			\
		src/find_pattern/find_pattern.cpp 		\
		src/find_pattern/flag_manager.cpp 		\
		src/find_pattern/get_flag_num.cpp 		\
		src/find_pattern/get_flag_string.cpp 	\
		src/find_pattern/get_flag.cpp

CSRC  =  src/perrno.cpp 						\
		src/splitter/splitter_char.cpp 			\
		src/splitter/splitter_word.cpp			\
		src/find_pattern/find_pattern.cpp		\
		src/splitter/c_interface.cpp

NAME   	=  libparsing.a

CNAME	=  libcparsing.a

CXXFLAGS = -std=c++17

OBJ  =  $(SRC:.cpp=.o)

COBJ  =  $(CSRC:.cpp=.o)

all:  cpplib clib

cpplib:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clib:	$(COBJ)
	ar rc $(CNAME) $(COBJ)

clean:
	rm -f $(NAME)
	rm -f $(CNAME)

fclean: clean
	rm -f $(OBJ)
	rm -f $(COBJ)

re:  fclean all
