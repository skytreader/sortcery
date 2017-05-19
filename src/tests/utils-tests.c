#include <criterion/criterion.h>

#include "../utils.h"

Test(max_tests, all){
    int test1[] = {1};
    cr_assert(max(test1, 1) == 0, "Singleton max");

    int test_none[0];
    cr_assert(max(test_none, arrsize(test_none)) < 0, "Zero length array");

    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    cr_assert(max(usual_case, arrsize(usual_case)) == 4, "Usual case");
}

Test(define_max_tests, ints){
    int itest[] = {1, 4, 1, 5, 9, 2, 6};
    cr_assert_eq(maxint(itest, arrsize(itest)), 4, "maxint works");
}

Test(define_max_tests, floats){
    float itest[] = {1.0f, 4.0f, 1.0f, 5.0f, 9.0f, 2.0f, 6.0f};
    cr_assert_eq(maxfloat(itest, arrsize(itest)), 4, "maxfloat works");
}

Test(define_max_tests, doubles){
    double itest[] = {1.0, 4.0, 1.0, 5.0, 9.0, 2.0, 6.0};
    cr_assert_eq(maxdouble(itest, arrsize(itest)), 4, "maxdouble works");
}

Test(define_min_tests, ints){
    int itest[] = {1, 4, 1, 5, 0, 9, 2, 6};
    cr_assert_eq(minint(itest, arrsize(itest)), 4, "minint works");
}

Test(define_min_tests, floats){
    float itest[] = {1.0f, 4.0f, 1.0f, 5.0f, 0.0f, 9.0f, 2.0f, 6.0f};
    cr_assert_eq(minfloat(itest, arrsize(itest)), 4, "minfloat works");
}

Test(define_min_tests, doubles){
    double itest[] = {1.0, 4.0, 1.0, 5.0, 0.0, 9.0, 2.0, 6.0};
    cr_assert_eq(mindouble(itest, arrsize(itest)), 4, "mindouble works");
}

Test(arrsize_tests, all){
    int size3[] = {1, 2, 3};
    cr_assert(arrsize(size3) == 3, "Happy arrsize");

    int size0[0];
    cr_assert(arrsize(size0) == 0, "Zero length array");
}

Test(logb_tests, all){
    // With thanks to Python 3
    cr_assert_float_eq(logb(6, 2), 2.584962500721156, 0.0000001, "log test");
}

Test(min_tests, all){
    int test1[] = {1};
    cr_assert(min(test1, 1) == 0, "Singleton min");

    int test_none[0];
    cr_assert(min(test_none, arrsize(test_none)) < 0, "Zero length array");

    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    cr_assert(min(usual_case, arrsize(usual_case)) == 0, "Usual case");
}

Test(swap_tests, common){
    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int swap_3_4[] = {1, 4, 1, 9, 5, 2, 6};
    
    cr_assert(memcmp(usual_case, swap_3_4, sizeof(usual_case)) != 0, "Pre-swap");
    swap(usual_case, 3, 4);
    cr_assert(memcmp(usual_case, swap_3_4, sizeof(usual_case)) == 0, "Swap 3, 4");
}

Test(swap_tests, commutative){
    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int swap_3_4[] = {1, 4, 1, 9, 5, 2, 6};
    
    cr_assert(memcmp(usual_case, swap_3_4, sizeof(usual_case)) != 0, "Pre-swap");
    swap(usual_case, 4, 3);
    cr_assert(memcmp(usual_case, swap_3_4, sizeof(usual_case)) == 0, "Swap 4, 3");
}

Test(swap_tests, sameval){
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

Test(shift_tests, limit){
    int indices[] = {0, 1, 2, 3, 4, 5, 6};
    int shift2limit[] = {0, 5, 6, 1, 2, 3, 4};
    int caselimit = sizeof(indices);

    cr_assert(sizeof(indices) == sizeof(shift2limit), "Sanity check");
    cr_assert(memcmp(indices, shift2limit, caselimit) != 0, "Pre shift");
    shift(indices, arrsize(indices), 1, 5, 2);
    cr_assert(memcmp(indices, shift2limit, caselimit) == 0, "Post shift");
}

Test(shift_tests, subarray){
    int indices[] = {0, 1, 2, 3, 4, 5, 7};
    int subshift[] = {0, 4, 5, 1, 2, 3, 7};
    int caselimit = sizeof(indices);

    cr_assert(sizeof(indices) == sizeof(subshift), "Sanity check");
    cr_assert(memcmp(indices, subshift, caselimit) != 0, "Pre shift");
    shift(indices, arrsize(indices), 1, 4, 2);
    cr_assert(memcmp(indices, subshift, caselimit) == 0, "Post shift");
}

Test(shift_tests, beginning){
    int indices[] = {0, 1, 2, 3, 4, 5, 8};
    int startshift[] = {3, 4, 0, 1, 2, 5, 8};
    int caselimit_bytes = sizeof(indices);

    cr_assert(sizeof(indices) == sizeof(startshift), "Sanity check");
    cr_assert(memcmp(indices, startshift, caselimit_bytes) != 0, "Pre shift");
    shift(indices, arrsize(indices), 0, 3, 2);
    cr_assert(memcmp(indices, startshift, caselimit_bytes) == 0, "Post shift");
}

Test(shift_tests, whole_array){
    int indices[] = {0, 1, 2, 3, 4, 5, 9};
    int wholeshift[] = {4, 5, 9, 0, 1, 2, 3};
    int caselimit_bytes = sizeof(indices);
    int caselimit_len = arrsize(indices);

    cr_assert(sizeof(indices) == sizeof(wholeshift), "Sanity check");
    cr_assert(memcmp(indices, wholeshift, caselimit_bytes) != 0, "Pre shift");
    shift(indices, caselimit_len, 0, caselimit_len, 3);
    cr_assert(memcmp(indices, wholeshift, caselimit_bytes) == 0, "Post shift");
}

Test(shift_tests, whole_array_equivalent){
    int indices[] = {0, 1, 2, 3, 4, 5, 9};
    int wholeshift[] = {4, 5, 9, 0, 1, 2, 3};
    int caselimit_bytes = sizeof(indices);
    int caselimit_len = arrsize(indices);

    cr_assert_eq(sizeof(indices), sizeof(wholeshift), "Sanity check");
    cr_assert_neq(memcmp(indices, wholeshift, caselimit_bytes), 0, "Pre shift");
    shift(indices, caselimit_len, 0, 4, 3);
    cr_assert_eq(memcmp(indices, wholeshift, caselimit_bytes), 0, "Post shift");
}

Test(stack_tests, init){
    int stack_size = 3;
    stack s;
    cr_assert_neq(s.size, stack_size, "Initial declaration of stack is sizeless.");
    init_stack(&s, stack_size);
    cr_assert_eq(s.size, stack_size, "Post init, s has size.");
}

Test(stack_tests, pushpop_happy){
    int stack_size = 3;
    stack s;
    cr_assert_neq(s.size, stack_size, "Initial declaration of stack is sizeless.");
    init_stack(&s, stack_size);
    cr_assert_eq(s.size, stack_size, "Post init, s has size.");
    cr_assert_eq(s.head, 0, "Pre-push check.");
    push(&s, 8);
    cr_assert_eq(s.head, 1, "Post-push check.");
    int karl_popper = pop(&s);
    cr_assert_eq(s.head, 0, "Post-pop check.");
}
