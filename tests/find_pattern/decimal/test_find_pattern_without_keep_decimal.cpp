#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "header.h"
#include "test_header.h"

using namespace std;

TestSuite(find_pattern_decimal_without_keep_suite);

Test(find_pattern_decimal_without_keep_suite, simple_d)
{
    Parser p;
    int error = -1;
    const string str = "42";
    const string pattern = "%d";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, false);
    vector<vector<pType_v>> correct = {{42}};

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

Test(find_pattern_decimal_without_keep_suite, multiple_d)
{
    Parser p;
    int error = -1;
    const string str = "42 52";
    const string pattern = "%d %d";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, false);
    vector<vector<pType_v>> correct = {{42, 52}};

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

Test(find_pattern_decimal_without_keep_suite, simple_d_multiple_pattern)
{
    Parser p;
    int error = -1;
    const string str = "42 52";
    const string pattern = "%d";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, false);
    vector<vector<pType_v>> correct = {{42}, {52}};

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

Test(find_pattern_decimal_without_keep_suite, multiple_d_multiple_pattern)
{
    Parser p;
    int error = -1;
    const string str = "42 52 69 87";
    const string pattern = "%d %d";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, false);
    vector<vector<pType_v>> correct = {{42, 52}, {69, 87}};

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