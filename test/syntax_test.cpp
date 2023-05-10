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
