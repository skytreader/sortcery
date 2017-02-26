#include <criterion/criterion.h>
#include "../utils.h"

Test(suite_name, test_name) {
    int test1[] = {1};
    cr_assert(max(test1, 1) == 0, "Singleton max");
}
