#include <string>
#include <iostream>
#include "header.h"

using namespace std;

int main(int argc, char const *argv[])
{
    const string test = "this olis a simple test of llloisooollllisi";
    /*const vector<string> o = {"ol","is"};
    vector<string> lol = p.split(test, o, true);*/

    const string o = "i";
    Parser p;
    vector<string> lol = p.split(test, o, true);
    for (int i = 0; i < lol.size(); i++)
        cout << lol[i] << "\n";
    return 0;
}