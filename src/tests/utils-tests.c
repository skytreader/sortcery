#include <criterion/criterion.h>
#include <stdio.h>

#include "../utils.h"

Test(max_tests, all){
    int test1[] = {1};
    cr_assert(max(test1, 1) == 0, "Singleton max");

    int test_none[0];
    cr_assert(max(test_none, arrsize(test_none)) < 0, "Zero length array");

    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    cr_assert(max(usual_case, arrsize(usual_case)) == 4, "Usual case");
}

Test(arrsize_tests, all){
    int size3[] = {1, 2, 3};
    cr_assert(arrsize(size3) == 3, "Happy arrsize");

    int size0[0];
    cr_assert(arrsize(size0) == 0, "Zero length array");
}

Test(min_tests, all){
    int test1[] = {1};
    cr_assert(min(test1, 1) == 0, "Singleton min");

    int test_none[0];
    cr_assert(min(test_none, arrsize(test_none)) < 0, "Zero length array");

    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    cr_assert(min(usual_case, arrsize(usual_case)) == 0, "Usual case");
}

Test(swap_test, all){
    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int swap_3_4[] = {1, 4, 1, 9, 5, 2, 6};
    
    cr_assert(memcmp(usual_case, swap_3_4, sizeof(usual_case)) != 0, "Pre-swap");
    swap(usual_case, 3, 4);
    cr_assert(memcmp(usual_case, swap_3_4, sizeof(usual_case)) == 0, "Swap 3, 4");
}

Test(swap_test_commutative, all){
    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int swap_3_4[] = {1, 4, 1, 9, 5, 2, 6};
    
    cr_assert(memcmp(usual_case, swap_3_4, sizeof(usual_case)) != 0, "Pre-swap");
    swap(usual_case, 4, 3);
    cr_assert(memcmp(usual_case, swap_3_4, sizeof(usual_case)) == 0, "Swap 4, 3");
}

Test(swap_test_same, all){
    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int usual_case_clone[] = {1, 4, 1, 5, 9, 2, 6};

    cr_assert(memcmp(usual_case, usual_case_clone, sizeof(usual_case)) == 0, "Pre-swap");
    swap(usual_case, 0, 0);
    cr_assert(memcmp(usual_case, usual_case_clone, sizeof(usual_case)) == 0, "Swap same index");
}

Test(smart_swap, all){
    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int swap_3_4[] = {1, 4, 1, 9, 5, 2, 6};
    
    cr_assert(memcmp(usual_case, swap_3_4, sizeof(usual_case)) != 0, "Pre-swap");
    safe_swap(usual_case, 4, 3, arrsize(usual_case));
    cr_assert(memcmp(usual_case, swap_3_4, sizeof(usual_case)) == 0, "Swap 4, 3");
}

Test(shift_limit, all){
    int indices[] = {0, 1, 2, 3, 4, 5, 6};
    int shift2limit[] = {0, 5, 6, 1, 2, 3, 4};
    int caselimit = sizeof(indices);

    cr_assert(sizeof(indices) == sizeof(shift2limit), "Sanity check");
    cr_assert(memcmp(indices, shift2limit, caselimit) != 0, "Pre shift");
    shift(indices, arrsize(indices), 1, 5, 2);
    cr_assert(memcmp(indices, shift2limit, caselimit) == 0, "Post shift");
}

Test(shift_subarray, all){
    int indices[] = {0, 1, 2, 3, 4, 5, 7};
    int subshift[] = {0, 4, 5, 1, 2, 3, 7};
    int caselimit = sizeof(indices);

    cr_assert(sizeof(indices) == sizeof(subshift), "Sanity check");
    cr_assert(memcmp(indices, subshift, caselimit) != 0, "Pre shift");
    shift(indices, arrsize(indices), 1, 4, 2);
    cr_assert(memcmp(indices, subshift, caselimit) == 0, "Post shift");
}

Test(shift_beginning, all){
    int indices[] = {0, 1, 2, 3, 4, 5, 8};
    int startshift[] = {3, 4, 0, 1, 2, 5, 8};
    int caselimit_bytes = sizeof(indices);

    cr_assert(sizeof(indices) == sizeof(startshift), "Sanity check");
    cr_assert(memcmp(indices, startshift, caselimit_bytes) != 0, "Pre shift");
    shift(indices, arrsize(indices), 0, 3, 2);
    cr_assert(memcmp(indices, startshift, caselimit_bytes) != 0, "Post shift");
}
