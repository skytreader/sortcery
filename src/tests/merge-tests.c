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

Test(merge_tests, large_submerge){
    int test[] = {1, 2, 4, 7, 11, 2, 3, 6, 10, 1, 2, 3, 4};
    int expected[] = {1, 2, 2, 3, 4, 6, 7, 10, 11, 1, 2, 3, 4};
    int testlimit = arrsize(test);
    int testlimit_bytes = sizeof(test);

    cr_assert_eq(arrsize(test), arrsize(expected), "Sanity check");
    cr_assert_neq(memcmp(test, expected, testlimit_bytes), 0, "Pre-call check");
    merge(test, testlimit, 0, 5, 9);
    cr_assert_eq(memcmp(test, expected, testlimit_bytes), 0, "Post-call check");
}

Test(merge_tests, same_elements_no_movement){
    int test[] = {1, 1, 1, 2, 2, 2, 1, 2, 3};
    int expected[] = {1, 1, 1, 2, 2, 2, 1, 2, 3};
    int testlimit = arrsize(test);
    int testlimit_bytes = sizeof(test);

    cr_assert_eq(arrsize(test), arrsize(expected), "Sanity check");
    merge(test, testlimit, 0, 3, 6);
    cr_assert_eq(memcmp(test, expected, testlimit_bytes), 0, "Post-call check");
}

Test(merge_tests, uneven_bounds){
    int test[] = {1, 1, 4, 5, 2, 9};
    int expected[] = {1, 1, 2, 4, 5, 9};
    int testlimit = arrsize(test);
    int testlimit_bytes = sizeof(test);

    cr_assert_eq(arrsize(test), arrsize(expected), "Sanity check");
    cr_assert_neq(memcmp(test, expected, testlimit_bytes), 0, "Pre-call check");
    merge(test, testlimit, 0, 4, testlimit);
    cr_assert_eq(memcmp(test, expected, testlimit_bytes), 0, "Post-call check");
}

Test(mergesort_tests, even){
    int test[] = {1, 4, 1, 5, 9, 2};
    int expected[] = {1, 1, 2, 4, 5, 9};
    int testlimit = arrsize(test);
    int testlimit_bytes = sizeof(test);

    cr_assert_eq(arrsize(test), arrsize(expected), "Sanity check");
    cr_assert_neq(memcmp(test, expected, testlimit_bytes), 0, "Pre-call check");
    mergesort(test, testlimit);
    cr_assert_eq(memcmp(test, expected, testlimit_bytes), 0, "Post-call check");
}

Test(mergesort_tests, odd){
    int test[] = {1, 4, 1, 9, 2};
    int expected[] = {1, 1, 2, 4, 9};
    int testlimit = arrsize(test);
    int testlimit_bytes = sizeof(test);

    cr_assert_eq(arrsize(test), arrsize(expected), "Sanity check");
    cr_assert_neq(memcmp(test, expected, testlimit_bytes), 0, "Pre-call check");
    mergesort(test, testlimit);
    cr_assert_eq(memcmp(test, expected, testlimit_bytes), 0, "Post-call check");
}

Test(mergesort_tests, power_two){
    int test[] = {1, 4, 1, 9};
    int expected[] = {1, 1, 4, 9};
    int testlimit = arrsize(test);
    int testlimit_bytes = sizeof(test);

    cr_assert_eq(arrsize(test), arrsize(expected), "Sanity check");
    cr_assert_neq(memcmp(test, expected, testlimit_bytes), 0, "Pre-call check");
    mergesort(test, testlimit);
    cr_assert_eq(memcmp(test, expected, testlimit_bytes), 0, "Post-call check");
}
