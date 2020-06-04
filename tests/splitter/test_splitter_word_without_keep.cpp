#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header.h"
#include "test_header.h"

TestSuite(splitter_word_without_keep_suite);

Test(splitter_word_without_keep_suite, simple_word)
{
    Parser p;
    int error = -1;
    vector<string> ret = p.split_word("Salut comment tu vas", {"comment"}, false);
    vector<string> correct = {"Salut ", " tu vas"};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_word_without_keep_suite, simple_word_no_input)
{
    Parser p;
    int error = -1;
    vector<string> ret = p.split_word("", {" "}, false);
    vector<string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_word_without_keep_suite, simple_word_only_split)
{
    Parser p;
    int error = -1;
    vector<string> ret = p.split_word("     ", {" "}, false);
    vector<string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_word_without_keep_suite, multiple_word)
{
    Parser p;
    int error = -1;
    vector<string> ret = p.split_word("Salut comment tu vas", {" t", "mm"}, false);
    vector<string> correct = {"Salut co", "ent", "u vas"};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_word_without_keep_suite, multiple_word_no_input)
{
    Parser p;
    int error = -1;
    vector<string> ret = p.split_word("", {" t", "mm"}, false);
    vector<string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}

Test(splitter_word_without_keep_suite, multiple_word_only_split)
{
    Parser p;
    int error = -1;
    vector<string> ret = p.split_word(" tmm tmm tmm", {" t", "mm"}, false);
    vector<string> correct = {""};

    cr_assert(ret.size() == correct.size(), "Not the same amount of words: ret:%d correct:%d",
        ret.size(), correct.size());

    error = compare_ret_correct(ret, correct);
    cr_assert(error == -1, "Error on comparing string: ret[%d]:\"%s\" correct[%d]:\"%s\"",
        error, ret[error].c_str(), error, correct[error].c_str());
}