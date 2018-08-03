#include <criterion/criterion.h>
#include "../insertion.h"
#include "../utils.h"

Test(insertion_sort_int, all){
    int i;
    
    for(i = 0; i < 100; i++){
        int usual_case[] = {1, 4, 1, 5, 9, 2, 6};
        int sorted_usual_case[] = {1, 1, 2, 4, 5, 6, 9};
        int usual_case_size = sizeof(usual_case);

        cr_assert(usual_case_size == sizeof(sorted_usual_case), "Preliminary set-up test");
        cr_assert(memcmp(usual_case, sorted_usual_case, usual_case_size) != 0, "Preliminary state test");
        insertion_sort(usual_case, arrsize(usual_case), sizeof(int), cmp_int);
        cr_assert(memcmp(usual_case, sorted_usual_case, usual_case_size) == 0, "Sorted test");
    }
}

Test(insertion_sort_float, all){
    int i;
    
    for(i = 0; i < 100; i++){
        float usual_case[] = {1.0f, 4.0f, 1.0f, 5.0f, 9.0f, 2.0f, 6.0f};
        float sorted_usual_case[] = {1.0f, 1.0f, 2.0f, 4.0f, 5.0f, 6.0f, 9.0f};
        int usual_case_size = sizeof(usual_case);

        cr_assert(usual_case_size == sizeof(sorted_usual_case), "Preliminary set-up test");
        cr_assert(memcmp(usual_case, sorted_usual_case, usual_case_size) != 0, "Preliminary state test");
        insertion_sort(usual_case, arrsize(usual_case), sizeof(float), cmp_int);
        cr_assert(memcmp(usual_case, sorted_usual_case, usual_case_size) == 0, "Sorted test");
    }
}
