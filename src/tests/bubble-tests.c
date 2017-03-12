#include <criterion/criterion.h>

#include "../bubble.h"
#include "../utils.h"

Test(sorting, all) {
    int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
    int sorted_usual_case[] = {1, 1, 2, 4, 5, 6, 9};
    int usual_case_size = sizeof(usual_case);

    cr_assert(usual_case_size == sizeof(sorted_usual_case), "Preliminary set-up test");
    cr_assert(memcmp(usual_case, sorted_usual_case, usual_case_size) != 0, "Preliminary state test");
    sort(usual_case, arrsize(usual_case));
    cr_assert(memcmp(usual_case, sorted_usual_case, usual_case_size) == 0, "Sorted test");
}
