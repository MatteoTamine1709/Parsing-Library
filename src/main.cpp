#include <string>
#include <iostream>
#include "header.h"

using namespace std;

int main(int argc, char const *argv[])
{
    const string test = "test of looool";
    const string o = "l";
    Parser p;
    vector<string> lol = p.split(test, o, true);
    for (int i = 0; i < lol.size(); i++)
        cout << lol[i] << "\n";
    return 0;
}