#include <criterion/criterion.h>
#include "../insertion.h"
#include "../utils.h"

Test(insert_tests_happy, all) {
    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int inserted[] = {1, 1, 4, 5, 9, 2, 6};
    int usual_case_size = sizeof(usual_case);

    cr_assert(memcmp(usual_case, inserted, usual_case_size) != 0, "Pre-check");
    insert(usual_case, 1, usual_case_size);
    cr_assert(memcmp(usual_case, inserted, usual_case_size) == 0, "insert works");
}

Test(limit_edge_tests1, all) {
    /*
    I know this is not sorted but this also tests that the function treats its
    assumptions seriously.
    */
    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int cp_usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int usual_case_size = sizeof(usual_case);
    
    cr_assert(memcmp(usual_case, cp_usual_case, usual_case_size) == 0, "Pre-check");
    insert(usual_case, usual_case_size, usual_case_size);
    cr_assert(memcmp(usual_case, cp_usual_case, usual_case_size) == 0, "insert respects assumptions");
}

Test(limit_edge_tests2, all) {
    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int cp_usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int usual_case_size = sizeof(usual_case);

    cr_assert(memcmp(usual_case, cp_usual_case, usual_case_size) == 0, "Pre-check");
    insert(usual_case, 0, 0);
    cr_assert(memcmp(usual_case, cp_usual_case, usual_case_size) == 0, "insert respects assumptions");
}
