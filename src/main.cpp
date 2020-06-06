#include <string>
#include <variant>
#include <iostream>
#include <typeinfo>
#include "header.h"

using namespace std;

void find_pattern(void)
{
    Parser p;
    //const string test = "to:9xxx98p12pour\nlol:9aaa4p3aa";

    //const string o = "%s:%d%s%dp%d%s";
    //const string test2 = "5-2-6\n##start\n3-4-5\n";
    //const string pattern = "##%s\n%d-%d-%d\n";
    //const string test3 = "34a     oui";
    //const string pattern2 = "%da    %s";
    const string test4 = "lol";
    const string pattern3 = "%c";
    vector<vector<pType_v>> ret = p.find_pattern(test4, pattern3, false);
}

void splitter(void)
{
    const string test = "this : 42";

    const vector<string> o = {" : "};
    Parser p;
    vector<string> lol = p.split_word(test, o);
    for (int i = 0; i < lol.size(); i++)
        cout << lol[i] << "\n";
}

void lemin_find_pattern(void)
{
    Parser p;
    string str = "15\n##end\n1 23 3\n2 16 7\n#comment\n3 16 3\n4 16 5\n5 9 3\n6 1 0\n7 4 8\n##start\n0 9 5\n0-4\n0-6\n1-3\n4-3\n5-2\n3-5\n#another comment\n4-2\n2-1\n7-6\n7-2\n7-4\n6-5";
    
    printf("end start\n");
    string pattern = "##%s\n%d %d %d";
    p.find_pattern(str,pattern);

    printf("rooms\n");
    pattern = "\n%d %d %d";
    p.find_pattern(str,pattern);

    printf("tunnels\n");
    pattern = "\n%d-%d";
    p.find_pattern(str,pattern);
}

int main(int argc, char const *argv[])
{
    splitter();
    //lemin_find_pattern();
    //find_pattern();
    return 0;
}