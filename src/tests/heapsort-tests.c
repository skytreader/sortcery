#include <criterion/criterion.h>
#include "../utils.h"
#include "../heapsort.h"

Test(heapify, small){
    int simple_heap[] = {2, 1, 0};
    int simple_heap_count = arrsize(simple_heap);
    heapify(simple_heap, simple_heap_count);
    cr_assert_eq(simple_heap[0], 0);
}
