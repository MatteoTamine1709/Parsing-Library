#include <criterion/criterion.h>
#include <criterion/redirect.h>

TestSuite(splitter_suite);

Test(splitter_suite, sample)
{
    char test[] = "Salut";
    cr_assert_str_eq(test, "Salut", "Error on comparing string");
}

Test(splitter_suite, sample2)
{
    //cr_assert(test() == 2, "error");
}