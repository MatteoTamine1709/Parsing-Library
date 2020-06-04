#include <string>
#include <iostream>
#include "header.h"

using namespace std;

int main(int argc, char const *argv[])
{
    const string test = "this olis a simple test of llloisooollllisi";

    const string o = "is ol";
    Parser p;
    vector<string> lol = p.split_char(test, o);
    for (int i = 0; i < lol.size(); i++)
        cout << lol[i] << "\n";
    return 0;
}