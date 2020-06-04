#include <string>
#include <variant>
#include <iostream>
#include <typeinfo>
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

    vector<variant<string, char, int, float>> var;
    int val = stoi(" \t3");
    var.push_back(val);
    var.push_back("yes");
    var.push_back(3.5f);
    var.push_back('E');

    for (int i = 0; i < var.size(); i++) {
        if (var[i].index() == 0)
            cout << "string " << get<0>(var[i]) << endl;
        if (var[i].index() == 1)
           cout << "char " << get<1>(var[i]) << endl;
        if (var[i].index() == 2)
           cout << "int " << get<2>(var[i]) << endl;
        if (var[i].index() == 3)
           cout << "float " << get<3>(var[i]) << endl;
    }
    return 0;
}