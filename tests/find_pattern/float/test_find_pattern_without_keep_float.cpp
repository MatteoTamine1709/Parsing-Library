#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "header.h"
#include "test_header.h"

using namespace std;

TestSuite(find_pattern_float_without_keep_suite);

Test(find_pattern_float_without_keep_suite, simple_f)
{
    Parser p;
    int error = -1;
    const string str = "42";
    const string pattern = "%f";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, false);
    vector<vector<pType_v>> correct = {{42.0f}};

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

Test(find_pattern_float_without_keep_suite, single_complex_f)
{
    Parser p;
    int error = -1;
    const string str = "42.3";
    const string pattern = "%f";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, false);
    vector<vector<pType_v>> correct = {{42.3f}};

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

Test(find_pattern_float_without_keep_suite, multiple_f)
{
    Parser p;
    int error = -1;
    const string str = "42 52";
    const string pattern = "%f %f";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, false);
    vector<vector<pType_v>> correct = {{42.0f, 52.0f}};

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

Test(find_pattern_float_without_keep_suite, multiple_complex_f)
{
    Parser p;
    int error = -1;
    const string str = "42.68 52.64";
    const string pattern = "%f %f";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, false);
    vector<vector<pType_v>> correct = {{42.68f, 52.64f}};

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

Test(find_pattern_float_without_keep_suite, simple_f_multiple_pattern)
{
    Parser p;
    int error = -1;
    const string str = "42 52";
    const string pattern = "%f";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, false);
    vector<vector<pType_v>> correct = {{42.0f}, {52.0f}};

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

Test(find_pattern_float_without_keep_suite, complex_f_multiple_pattern)
{
    Parser p;
    int error = -1;
    const string str = "42.65 52.84";
    const string pattern = "%f";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, false);
    vector<vector<pType_v>> correct = {{42.65f}, {52.84f}};

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

Test(find_pattern_float_without_keep_suite, multiple_f_multiple_pattern)
{
    Parser p;
    int error = -1;
    const string str = "42 52 69 87";
    const string pattern = "%f %f";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, false);
    vector<vector<pType_v>> correct = {{42.0f, 52.0f}, {69.0f, 87.0f}};

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

Test(find_pattern_float_without_keep_suite, multiple_complex_f_multiple_pattern)
{
    Parser p;
    int error = -1;
    const string str = "42.2548 52.689 69.154 87.358";
    const string pattern = "%f %f";
    vector<vector<pType_v>> ret = p.find_pattern(str, pattern, false);
    vector<vector<pType_v>> correct = {{42.2548f, 52.689f}, {69.154f, 87.358f}};

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