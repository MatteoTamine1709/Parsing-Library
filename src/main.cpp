#include <string>
#include <iostream>
#include "header.h"

using namespace std;

int main(int argc, char const *argv[])
{
    const string test = "thisisiss olis a simple test of llloisooollllisi";

    const vector<string> o = {"isiss ol"};
    Parser p;
    vector<string> lol = p.split_word(test, o);
    for (int i = 0; i < lol.size(); i++)
        cout << lol[i] << "\n";
    return 0;
}