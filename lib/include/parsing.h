#ifndef PARSING_H_
#define PARSING_H_

#include <string>
#include <string.h>
#include <vector>
#include <variant>
#include "c_interface.h"

using pType_v = std::variant<std::string, char, int, unsigned int, float, long>;

typedef int (*get_pattern_t) (const std::string str, char stop, int index, std::vector<pType_v> *result);

class Parser
{
private:
public:
    std::vector<std::string> split_char(const std::string &str, const std::string &symb, bool save_split = false);
    std::vector<std::string> split_word(const std::string &str, const std::vector<std::string> words, bool save_split = false);
    std::vector<pType_v> look_for(const std::string &str, const std::string &pattern, bool save_split = false, bool ignore_space = true);
    std::vector<pType_v> look_for(const std::string &str, const std::vector<std::string> pattern, bool save_split = false, bool ignore_space = true);
};

/*
** ALL POSSIBLE FLAGS FOR PATTERN:
** %s       => will read only letters                                                           String
** %S[...]  => will read everything till hit someting in the bracket                            String
** %n       => will read number and return it as a string (error if no number found)            String
** %.       => will read everything till find a dot                                           String
** %c       => will read the next char                                                          Char
** %d       => will convert the following number into int (error if no number found)            int
** %u       => will convert the following number into unsigned int (error if no number found)   unsigned int
** %f       => will convert the following number into float (error if no number found)          float
** %l       => will convert the following number into long (error if no number found)           long
** *        => will read everything                                                             String
**
** All of them will stop once they find the next char in the pattern
** For example:
** %s: => read all the string till find ':'
*/

static int perrno = 0;

#define PE_VAL 1

void str_perrno(void);

//LOOK_FOR
bool is_flag(char c);
bool is_valid_string_char(char c);
bool is_valid_string_dot(char c);
bool is_valid_int_char(char c);
int get_string(const std::string str, char stop, int index, std::vector<pType_v> *result);
int get_int(const std::string str, char stop, int index, std::vector<pType_v> *result);
int get_int(const std::string str, char stop, int index, std::vector<pType_v> *result);
int get_uint(const std::string str, char stop, int index, std::vector<pType_v> *result);
int get_float(const std::string str, char stop, int index, std::vector<pType_v> *result);
int get_long(const std::string str, char stop, int index, std::vector<pType_v> *result);
int get_string(const std::string str, char stop, int index, std::vector<pType_v> *result);
int get_complex_string(const std::string str, char stop, int index, std::vector<pType_v> *result);
int get_number(const std::string str, char stop, int index, std::vector<pType_v> *result);
int get_dot(const std::string str, char stop, int index, std::vector<pType_v> *result);
int get_char(const std::string str, char stop, int index, std::vector<pType_v> *result);
int get_pattern(char flag, char stop, const std::string str, int index, std::vector<pType_v> *result);

#endif