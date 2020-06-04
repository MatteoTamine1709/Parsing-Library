#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/header.h"

TestSuite(splitter_char_without_keep_suite);

Test(splitter_char_without_keep_suite, simple_char)
{
    Parser p;
    bool assert = true;
    vector<string> ret = p.split_char("Salut comment tu vas", " ", false);
    vector<string> correct = {"Salut", "comment", "tu", "vas"};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words");

    for (int i = 0; i < ret.size(); i++)
        if (ret[i].compare(correct[i]) != 0) {
            assert = false;
            break;
        }
    cr_assert(assert, "Error on comparing string");
}

Test(splitter_char_without_keep_suite, simple_char_no_input)
{
    Parser p;
    bool assert = true;
    vector<string> ret = p.split_char("", " ", false);
    vector<string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words");

    for (int i = 0; i < ret.size(); i++)
        if (ret[i].compare(correct[i]) != 0) {
            assert = false;
            break;
        }
    cr_assert(assert, "Error on comparing string");
}

Test(splitter_char_without_keep_suite, simple_char_only_split)
{
    Parser p;
    bool assert = true;
    vector<string> ret = p.split_char("     ", " ", false);
    vector<string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words");

    for (int i = 0; i < ret.size(); i++)
        if (ret[i].compare(correct[i]) != 0) {
            assert = false;
            break;
        }
    cr_assert(assert, "Error on comparing string");
}

Test(splitter_char_without_keep_suite, multiple_char)
{
    Parser p;
    bool assert = true;
    vector<string> ret = p.split_char("Salut comment tu vas", " t", false);
    vector<string> correct = {"Salu", "commen", "u", "vas"};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words");

    for (int i = 0; i < ret.size(); i++)
        if (ret[i].compare(correct[i]) != 0) {
            assert = false;
            break;
        }
    cr_assert(assert, "Error on comparing string");
}

Test(splitter_char_without_keep_suite, multiple_char_no_input)
{
    Parser p;
    bool assert = true;
    vector<string> ret = p.split_char("", " t", false);
    vector<string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words");

    for (int i = 0; i < ret.size(); i++)
        if (ret[i].compare(correct[i]) != 0) {
            assert = false;
            break;
        }
    cr_assert(assert, "Error on comparing string");
}

Test(splitter_char_without_keep_suite, multiple_char_only_split)
{
    Parser p;
    bool assert = true;
    vector<string> ret = p.split_char("     ttt", " t", false);
    vector<string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words");

    for (int i = 0; i < ret.size(); i++)
        if (ret[i].compare(correct[i]) != 0) {
            assert = false;
            break;
        }
    cr_assert(assert, "Error on comparing string");
}