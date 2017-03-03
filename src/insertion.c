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
    if(limit < 0){
        exit(1);
    }

    if(sorted_limit == limit){
        return;
    }
    
    int i;
    for(i = sorted_limit; i >= 0; i--){
        int move_candidate = arr[i + 1];
        printarr(arr, limit);
        if(move_candidate < arr[i]){
            swap(arr, i, i + 1);
        } else{
            break;
        }
    }
}
