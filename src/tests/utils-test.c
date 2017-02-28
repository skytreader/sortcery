#include <criterion/criterion.h>
#include "../utils.h"

Test(suite_name, test_name) {
    int test1[] = {1};
    cr_assert(max(test1, 1) == 0, "Singleton max");
    int size3[] = {1, 2, 3};
    cr_assert(arrsize(size3) == 3, "Happy arrzie");
}
