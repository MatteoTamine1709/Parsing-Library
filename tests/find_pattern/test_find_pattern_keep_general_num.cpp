#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "header.h"
#include "test_header.h"

using namespace std;

TestSuite(find_pattern_general_num_keep_suite);

Test(find_pattern_general_num_keep_suite, no_str)
{
    Parser p;
    int error = -1;
    const string str = "";
    const string pattern = "%d";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct;

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
    cr_assert(error == -1, "Error on comparing variant: %d", error);
}

Test(find_pattern_general_num_keep_suite, no_pattern)
{
    Parser p;
    int error = -1;
    const string str = "42";
    const string pattern = "";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct;

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
    cr_assert(error == -1, "Error on comparing variant: %d", error);
}

Test(find_pattern_general_num_keep_suite, no_input)
{
    Parser p;
    int error = -1;
    const string str = "";
    const string pattern = "";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct;

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
    cr_assert(error == -1, "Error on comparing variant: %d", error);
}

Test(find_pattern_general_num_keep_suite, no_pattern_in_str)
{
    Parser p;
    int error = -1;
    const string str = "iubkbkj";
    const string pattern = "%d";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct;

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
    cr_assert(error == -1, "Error on comparing variant: %d", error);
}

Test(find_pattern_general_num_keep_suite, only_split_pattern)
{
    Parser p;
    int error = -1;
    const string str = "iubkbkj";
    const string pattern = "iubkbkj";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct = {{"iubkbkj"}};

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
    cr_assert(error == -1, "Error on comparing variant: %d", error);
}