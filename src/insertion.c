#include <stdlib.h>

#include "insertion.h"
#include "utils.h"

/**
Move the element in `sorted_limit + 1` to a sorted position in `arr`. `arr` will
be modified accordingly.

@param arr
@param sorted_limit
    The last index of the sorted part of the array.
@param limit
    The length of the array.
@param comparator
*/
void insert(void *arr, size_t sorted_limit, size_t limit, size_t item_size, int (*comparator)(const void *, const void *)){
    // These cases make no sense.
    if(sorted_limit > limit){
        exit(1);
    }

    if(sorted_limit >= (limit - 1)){
        return;
    }
    
    int i;
    unsigned char buffer[item_size];
    for(i = sorted_limit; i >= 0; i--){
        // int move_candidate = arr[i + 1];
        memcpy(buffer, arr + item_size * (i + 1), item_size);
        if(move_candidate < arr[i]){
            safe_swap(arr, i, i + 1, limit);
        } else{
            break;
        }
    }
}

/**
Sorts the given array from indices [0, limit).

@param arr
@param limit
    Hopefully, the length of the array.
*/
void insertion_sort(
    void *arr, size_t limit, size_t item_size,
    int (*comparator)(const void *, const void *)
){
    unsigned int i;
    for(i = 1; i < limit; i++){
        insert(arr, i, limit, item_size, comparator);
    }
}
