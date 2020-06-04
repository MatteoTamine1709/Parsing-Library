#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header.h"
#include "test_header.h"

TestSuite(splitter_char_without_keep_suite);

Test(splitter_char_without_keep_suite, simple_char)
{
    Parser p;
    int error = -1;
    std::vector<std::string> ret = p.split_char("Salut comment tu vas", " ", false);
    std::vector<std::string> correct = {"Salut", "comment", "tu", "vas"};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_char_without_keep_suite, simple_char_no_input)
{
    Parser p;
    int error = -1;
    std::vector<std::string> ret = p.split_char("", " ", false);
    std::vector<std::string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_char_without_keep_suite, simple_char_only_split)
{
    Parser p;
    int error = -1;
    std::vector<std::string> ret = p.split_char("     ", " ", false);
    std::vector<std::string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_char_without_keep_suite, multiple_char)
{
    Parser p;
    int error = -1;
    std::vector<std::string> ret = p.split_char("Salut comment tu vas", " t", false);
    std::vector<std::string> correct = {"Salu", "commen", "u", "vas"};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_char_without_keep_suite, multiple_char_no_input)
{
    Parser p;
    int error = -1;
    std::vector<std::string> ret = p.split_char("", " t", false);
    std::vector<std::string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_char_without_keep_suite, multiple_char_only_split)
{
    Parser p;
    int error = -1;
    std::vector<std::string> ret = p.split_char("     ttt", " t", false);
    std::vector<std::string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}