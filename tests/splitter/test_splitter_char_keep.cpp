#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header.h"
#include "test_header.h"

TestSuite(splitter_char_keep_suite);

Test(splitter_char_keep_suite, simple_char)
{
    Parser p;
    int error = -1;
    vector<string> ret = p.split_char("Salut comment tu vas", " ", true);
    vector<string> correct = {"Salut", " ", "comment", " ", "tu", " ", "vas"};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_char_keep_suite, simple_char_no_input)
{
    Parser p;
    int error = -1;
    vector<string> ret = p.split_char("", " ", true);
    vector<string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_char_keep_suite, simple_char_only_split)
{
    Parser p;
    int error = -1;
    vector<string> ret = p.split_char("     ", " ", true);
    vector<string> correct = {"     "};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_char_keep_suite, multiple_char)
{
    Parser p;
    int error = -1;
    vector<string> ret = p.split_char("Salut comment tu vas", " t", true);
    vector<string> correct = {"Salu", "t ", "commen", "t t", "u", " ", "vas"};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());
    
    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_char_keep_suite, multiple_char_no_input)
{
    Parser p;
    int error = -1;
    vector<string> ret = p.split_char("", " t", true);
    vector<string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_char_keep_suite, multiple_char_only_split)
{
    Parser p;
    int error = -1;
    vector<string> ret = p.split_char("     ttt", " t", true);
    vector<string> correct = {"     ttt"};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}