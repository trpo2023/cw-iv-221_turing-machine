#include <ctest.h>
#include <iostream>

#include "libturing/file_validation_check.hpp"

CTEST(syntax_suite, check_arrow_true)
{
    std::string str = "->";
    int index = 0;
    ASSERT_FALSE(check_arrow(str, &index));
}

CTEST(syntax_suite, check_arrow_false)
{
    std::string str1 = "--";
    int index1 = 0;

    std::string str2 = ">";
    int index2 = 0;

    ASSERT_TRUE(check_arrow(str1, &index1));
    ASSERT_EQUAL(1, index1);

    ASSERT_TRUE(check_arrow(str2, &index2));
    ASSERT_EQUAL(0, index2);
}

CTEST(syntax_suite, check_shift_true)
{
    std::string s1 = "  R  ";
    std::string s2 = "  r  ";
    std::string s3 = "  L  ";
    std::string s4 = "  l  ";
    std::string s5 = "  N  ";
    std::string s6 = "  n  ";

    int index = 0;
    ASSERT_FALSE(check_shift(s1, &index));

    index = 0;
    ASSERT_FALSE(check_shift(s2, &index));

    index = 0;
    ASSERT_FALSE(check_shift(s3, &index));

    index = 0;
    ASSERT_FALSE(check_shift(s4, &index));

    index = 0;
    ASSERT_FALSE(check_shift(s5, &index));

    index = 0;
    ASSERT_FALSE(check_shift(s6, &index));
}

CTEST(syntax_suite, check_shift_false)
{
    std::string s1 = "A";
    int index = 0;

    ASSERT_TRUE(check_shift(s1, &index));
}
