#include <criterion/criterion.h>
#include "../insertion.h"
#include "../utils.h"

Test(insert_tests, all) {
    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int inserted[] = {1, 1, 4, 5, 9, 2, 6};
    int usual_case_size = arrsize(usual_case);

    insert(usual_case, 1, usual_case_size);

    cr_assert(memcmp(usual_case, inserted, usual_case_size) == 0, "Insert works");
}
