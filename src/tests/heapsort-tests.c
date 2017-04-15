#include <criterion/criterion.h>
#include "../utils.h"
#include "../heapsort.h"

Test(heapify, small_odd){
    int simple_heap[] = {2, 1, 0};
    int simple_heap_count = arrsize(simple_heap);
    heapify(simple_heap, simple_heap_count);
    cr_assert_eq(simple_heap[0], 0, "root is 0");
}

Test(heapify, small_even){
    int simple_heap[] = {2, 1};
    int simple_heap_count = arrsize(simple_heap);
    heapify(simple_heap, simple_heap_count);
    cr_assert_eq(simple_heap[0], 1, "root is 1");
}

Test(heapify, even){
    int numlist[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 4};
    int numlist_count = arrsize(numlist);
    heapify(numlist, numlist_count);

    int limit = numlist_count / 2;
    int i;
    for(i = 0; i < limit; i++){
        int lson = (2 * i) + 1;
        if(lson < limit){
            cr_assert(numlist[i] <= numlist[lson], "parent is less than or equal to lson");
        }

        int rson = (2 * i) + 2;
        if(rson < limit){
            cr_assert(numlist[i] <= numlist[rson], "parent is less than or equal to rson");
        }
    }
}

Test(heapify, odd){
    int numlist[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int numlist_count = arrsize(numlist);
    heapify(numlist, numlist_count);

    int limit = numlist_count / 2;
    int i;
    for(i = 0; i < limit; i++){
        int lson = (2 * i) + 1;
        if(lson < limit){
            cr_assert(numlist[i] <= numlist[lson], "parent is less than or equal to lson");
        }

        int rson = (2 * i) + 2;
        if(rson < limit){
            cr_assert(numlist[i] <= numlist[rson], "parent is less than or equal to rson");
        }
    }
}

Test(heapsort, pi){
    int test[] = {1, 4, 1, 5, 9, 2};
    int expected[] = {1, 1, 2, 4, 5, 9};
    int testlimit = arrsize(test);
    int testlimit_bytes = sizeof(test);

    cr_assert_eq(arrsize(test), arrsize(expected), "Sanity check");
    cr_assert_neq(memcmp(test, expected, testlimit_bytes), 0, "Pre-call check");
    heapsort(test, testlimit);
    cr_assert_eq(memcmp(test, expected, testlimit_bytes), 0, "Post-call check");
}
