#include <string>
#include <variant>
#include <iostream>
#include <typeinfo>
#include "header.h"

using namespace std;

void test(void)
{
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
}

void look_for(void)
{
    Parser p;
    //const string test = "to:9xxx98p12pour\nlol:9aaa4p3aa";

    //const string o = "%s:%d%s%dp%d%s";
    //const string test2 = "5-2-6\n##start\n3-4-5\n";
    //const string pattern = "##%s\n%d-%d-%d\n";
    //const string test3 = "34a     oui";
    //const string pattern2 = "%da    %s";
    const string test4 = "opl-98.olp-44";
    const string pattern3 = "l%f.%s%u";
    p.look_for(test4, pattern3, true);
}

void splitter(void)
{
    const string test = "thisisiss olis a simple test of llloisooollllisi";

    const vector<string> o = {"isiss ol"};
    Parser p;
    vector<string> lol = p.split_word(test, o);
    for (int i = 0; i < lol.size(); i++)
        cout << lol[i] << "\n";
}

int main(int argc, char const *argv[])
{
    //splitter();
    look_for();
    //test();
    return 0;
}