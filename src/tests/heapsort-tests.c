#include <criterion/criterion.h>
#include <stdio.h>
#include "../utils.h"
#include "../heapsort.h"

Test(heapify, small){
    int simple_heap[] = {2, 1, 0};
    int simple_heap_count = arrsize(simple_heap);
    heapify(simple_heap, simple_heap_count);
    cr_assert_eq(simple_heap[0], 0, "root is 0");
}

Test(heapify, even){
    int numlist[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 4};
    int numlist_count = arrsize(numlist);
    printf("pre-heapify ");
    printarr(numlist, numlist_count);
    heapify(numlist, numlist_count);
    printf("post-heapify ");
    printarr(numlist, numlist_count);

    int limit = numlist_count / 2;
    int i;
    for(i = 0; i < limit; i++){
        int lson = (2 * i) + 1;
        if(lson < limit){
            printf("numlist[i] %d vs numlist[lson] %d\n", numlist[i], numlist[lson]);
            cr_assert(numlist[i] <= numlist[lson], "parent is less than or equal to lson");
        }

        int rson = (2 * i) + 2;
        if(rson < limit){
            cr_assert(numlist[i] <= numlist[rson], "parent is less than or equal to rson");
        }
    }
}
