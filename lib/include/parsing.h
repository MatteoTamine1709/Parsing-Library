#ifndef PARSING_H_
#define PARSING_H_

#include <string>
#include <string.h>
#include <vector>
#include <variant>
#include "c_interface.h"

class Parser
{
private:
public:
    std::vector<std::string> split_char(const std::string &str, const std::string &symb, bool save_split = false);
    std::vector<std::string> split_word(const std::string &str, const std::vector<std::string> words, bool save_split = false);
    std::vector<std::variant<std::string, char, int, float>> look_for(const std::string &str, const std::string &pattern, bool save_split = false);
    
};

static int perrno = 0;

#define PE_VAL 1

void str_perrno(void);

#endif