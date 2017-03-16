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
*/
void insert(int arr[], int sorted_limit, int limit){
    // These cases make no sense.
    if(limit < 0 || sorted_limit > limit){
        exit(1);
    }

    if(sorted_limit >= (limit - 1)){
        return;
    }
    
    int i;
    for(i = sorted_limit; i >= 0; i--){
        int move_candidate = arr[i + 1];
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
void insertion_sort(int arr[], int limit){
    int i;
    for(i = 1; i < limit; i++){
        insert(arr, i, limit);
    }
}
