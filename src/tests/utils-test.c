#include <criterion/criterion.h>
#include "../utils.h"

Test(max_tests, all) {
    int test1[] = {1};
    cr_assert(max(test1, 1) == 0, "Singleton max");
}

Test(arrsize_tests, all) {
    int size3[] = {1, 2, 3};
    cr_assert(arrsize(size3) == 3, "Happy arrzie");
}
