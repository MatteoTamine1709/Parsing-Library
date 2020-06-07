#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "header.h"
#include "test_header.h"

using namespace std;

TestSuite(find_pattern_string_keep_suite);

Test(find_pattern_string_keep_suite, simple_s)
{
    Parser p;
    int error = -1;
    const string str = "Hello";
    const string pattern = "%s";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct = {{"Hello"}};

    cr_assert(ret.size() == correct.size(), "Not the same amount of recognition: ret:%d correct:%d",
        ret.size(), correct.size());

    for (int i = 0; i < ret.size(); i++) {
        if (ret[i].size() != correct[i].size()) {
            error = i;
            break;
        }
    }
    cr_assert(error == -1, "Not the same amout of arg for pattern nb[%d]: \
ret:%d correct:%d", error, ret[error].size(), correct[error].size());

    error = compare_ret_correct_variant(ret, correct);
    if (error != -1) {
        cout << "Current : " << endl;
        display_vector_variant(ret[error]);
        cout << "==========" << endl;
        cout << "Expected : " << endl;
        display_vector_variant(correct[error]);
    }
    cr_assert(error == -1, "Error on comparing variant: %d",
        error);
}

Test(find_pattern_string_keep_suite, multiple_s)
{
    Parser p;
    int error = -1;
    const string str = "Hello you";
    const string pattern = "%s %s";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct = {{"Hello", " ", "you"}};

    cr_assert(ret.size() == correct.size(), "Not the same amount of recognition: ret:%d correct:%d",
        ret.size(), correct.size());

    for (int i = 0; i < ret.size(); i++) {
        if (ret[i].size() != correct[i].size()) {
            error = i;
            break;
        }
    }
    cr_assert(error == -1, "Not the same amout of arg for pattern nb[%d]: \
ret:%d correct:%d", error, ret[error].size(), correct[error].size());

    error = compare_ret_correct_variant(ret, correct);
    if (error != -1) {
        cout << "Current : " << endl;
        display_vector_variant(ret[error]);
        cout << "==========" << endl;
        cout << "Expected : " << endl;
        display_vector_variant(correct[error]);
    }
    cr_assert(error == -1, "Error on comparing variant: %d",
        error);
}

Test(find_pattern_string_keep_suite, simple_s_multiple_pattern)
{
    Parser p;
    int error = -1;
    const string str = "Test:Bla";
    const string pattern = "%s";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct = {{"Test"}, {"Bla"}};

    cr_assert(ret.size() == correct.size(), "Not the same amount of recognition: ret:%d correct:%d",
        ret.size(), correct.size());

    for (int i = 0; i < ret.size(); i++) {
        if (ret[i].size() != correct[i].size()) {
            error = i;
            break;
        }
    }
    cr_assert(error == -1, "Not the same amout of arg for pattern nb[%d]: \
ret:%d correct:%d", error, ret[error].size(), correct[error].size());

    error = compare_ret_correct_variant(ret, correct);
    if (error != -1) {
        cout << "Current : " << endl;
        display_vector_variant(ret[error]);
        cout << "==========" << endl;
        cout << "Expected : " << endl;
        display_vector_variant(correct[error]);
    }
    cr_assert(error == -1, "Error on comparing variant: %d",
        error);
}

Test(find_pattern_string_keep_suite, multiple_s_multiple_pattern)
{
    Parser p;
    int error = -1;
    const string str = "Helloa Testa:Hellob Testb";
    const string pattern = "%s %s";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct = {{"Helloa", " ", "Testa"}, {"Hellob", " ", "Testb"}};

    cr_assert(ret.size() == correct.size(), "Not the same amount of recognition: ret:%d correct:%d",
        ret.size(), correct.size());

    for (int i = 0; i < ret.size(); i++) {
        if (ret[i].size() != correct[i].size()) {
            error = i;
            break;
        }
    }
    cr_assert(error == -1, "Not the same amout of arg for pattern nb[%d]: \
ret:%d correct:%d", error, ret[error].size(), correct[error].size());

    error = compare_ret_correct_variant(ret, correct);
    if (error != -1) {
        cout << "Current : " << endl;
        display_vector_variant(ret[error]);
        cout << "==========" << endl;
        cout << "Expected : " << endl;
        display_vector_variant(correct[error]);
    }
    cr_assert(error == -1, "Error on comparing variant: %d",
        error);
}