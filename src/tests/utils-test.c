#include <criterion/criterion.h>
#include "../utils.h"

Test(max_tests, all) {
    int test1[] = {1};
    cr_assert(max(test1, 1) == 0, "Singleton max");

    int test_none[0];
    cr_assert(max(test_none, arrsize(test_none)) < 0, "Zero length array");

    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    cr_assert(max(usual_case, arrsize(usual_case)) == 4, "Usual case");
}

Test(arrsize_tests, all) {
    int size3[] = {1, 2, 3};
    cr_assert(arrsize(size3) == 3, "Happy arrsize");

    int size0[0];
    cr_assert(arrsize(size0) == 0, "Zero length array");
}

Test(min_tests, all) {
    int test1[] = {1};
    cr_assert(min(test1, 1) == 0, "Singleton min");

    int test_none[0];
    cr_assert(min(test_none, arrsize(test_none)) < 0, "Zero length array");

    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    cr_assert(min(usual_case, arrsize(usual_case)) == 0, "Usual case");
}
