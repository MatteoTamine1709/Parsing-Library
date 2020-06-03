#ifndef PARSING_H_
#define PARSING_H_

#include "splitter.h"
#include <string>
#include <vector> 
using namespace std;

class Parser
{
private:
public:
    vector<string> split(const string &str, const string &symb, bool save_split = false);
    
};

static int perrno = 0;

#define PE_VAL 1

void str_perrno(void);

#endif