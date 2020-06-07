#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "header.h"
#include "test_header.h"

using namespace std;

TestSuite(find_pattern_unsigned_keep_suite);

Test(find_pattern_unsigned_keep_suite, simple_u)
{
    Parser p;
    int error = -1;
    const string str = "42";
    const string pattern = "%u";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct = {{(unsigned int) 42}};

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

Test(find_pattern_unsigned_keep_suite, multiple_u)
{
    Parser p;
    int error = -1;
    const string str = "42 52";
    const string pattern = "%u %u";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct = {{(unsigned int) 42, " ", (unsigned int) 52}};

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

Test(find_pattern_unsigned_keep_suite, simple_u_multiple_pattern)
{
    Parser p;
    int error = -1;
    const string str = "42 52";
    const string pattern = "%u";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct = {{(unsigned int) 42}, {(unsigned int) 52}};

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

Test(find_pattern_unsigned_keep_suite, multiple_u_multiple_pattern)
{
    Parser p;
    int error = -1;
    const string str = "42 52 69 87";
    const string pattern = "%u %u";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct = {{(unsigned int) 42, " ", (unsigned int) 52}, {(unsigned int) 69, " ", (unsigned int) 87}};

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

Test(find_pattern_unsigned_keep_suite, simple_neg_u)
{
    Parser p;
    int error = -1;
    const string str = "-54";
    const string pattern = "%u";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, true);
    vector<vector<pType_v>> correct = {{(unsigned int) -54}};

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

Test(find_pattern_unsigned_keep_suite, too_big_u)
{
    Parser p;
    int error = -1;
    const string str = "42949672950000";
    const string pattern = "%u";
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
    cr_assert(error == -1, "Error on comparing variant: %d",
        error);
}