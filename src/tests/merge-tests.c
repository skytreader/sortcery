#include <criterion/criterion.h>
#include "../utils.h"
#include "../merge.h"

Test(merge_tests, small_boundary){
    int test[] = {3, 1, 4, 1};
    int expected[] = {1, 3, 4, 1};
    int testlimit = arrsize(test);
    int testlimit_bytes = sizeof(test);

    cr_assert_eq(arrsize(test), arrsize(expected), "Sanity check");
    cr_assert_neq(memcmp(test, expected, testlimit_bytes), 0, "Pre-call check");
    merge(test, testlimit, 0, 1, 2);
    cr_assert_eq(memcmp(test, expected, testlimit_bytes), 0, "Post-call check");
}

Test(merge_tests, large_merge){
    int test[] = {1, 2, 4, 7, 11, 2, 3, 6, 10};
    int expected[] = {1, 2, 2, 3, 4, 6, 7, 10, 11};
    int testlimit = arrsize(test);
    int testlimit_bytes = sizeof(test);

    cr_assert_eq(arrsize(test), arrsize(expected), "Sanity check");
    cr_assert_neq(memcmp(test, expected, testlimit_bytes), 0, "Pre-call check");
    merge(test, testlimit, 0, 5, testlimit);
    cr_assert_eq(memcmp(test, expected, testlimit_bytes), 0, "Post-call check");
}
