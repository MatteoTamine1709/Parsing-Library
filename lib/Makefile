SRC  =  src/perrno.cpp 						\
		src/splitter/splitter_char.cpp 		\
		src/splitter/splitter_word.cpp 		\
		src/look_for/look_for.cpp 			\
		src/look_for/flag_manager.cpp 		\
		src/look_for/get_flag_num.cpp 		\
		src/look_for/get_flag_string.cpp 	\
		src/look_for/get_flag.cpp

CSRC  =  src/perrno.cpp 					\
		src/splitter/splitter_char.cpp 		\
		src/splitter/splitter_word.cpp		\
		src/look_for/look_for.cpp			\
		src/splitter/c_interface.cpp

NAME   	=  libparsing.a

CNAME	=  libcparsing.a

CXXFLAGS = -std=c++17 -g

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
