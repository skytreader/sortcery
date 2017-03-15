#include <stdio.h>

#include "utils.h"

/**
Returns the index of the greatest element in the array. In case of ties, the
first occurrence of the greatest element is returned.

@param arr
@param limit
@return The index of the greatest element or a negative value if, for some
    reason "greatest element" is undefined.
*/
int max(int arr[], int limit){
    if(limit == 0){
        return -1;
    }

    int i;
    int max_i = 0;
    for(i = 1; i < limit; i++){
        if(arr[i] > arr[max_i]){
            max_i = i;
        }
    }
    return max_i;
}

/**
Returns the index of the least element in the array. In case of ties, the
first occurrence of the least element is returned.

@param arr
@param limit
@return The index of the least element or a negative value if, for some
    reason "least element" is undefined.
*/
int min(int arr[], int limit){
    if(limit == 0){
        return -1;
    }

    int i;
    int min_i = 0;
    for(i = 1; i < limit; i++){
        if(arr[i] < arr[min_i]){
            min_i = i;
        }
    }
    return min_i;
}

/**
Swap the values at i and j of `arr`. Automagic assumption that i and j are
within bounds.

WARNING: This method is not safe. Swapping large integer values might cause an
overflow condition. The only reason to use this, if at all, is that it is
lighter on memory ever-so-slightly.

@param arr
@param i
@param j
*/
void swap(int arr[], int i, int j){
    arr[i] += arr[j];
    arr[j] = arr[i] - arr[j];
    arr[i] -= arr[j];
}

/**
The safest swap method to use. Does not try to be clever and just gets the job
done (TM).

@param arr
@param i
@param j
*/
void safe_swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/**
Shifts all elements in the subarray [i, shift_limit) by shift_count. The vacated
cells will contain the misplaced elements.

@param arr
@param limit
    The length of the array.
@param i
    The index of the first element of the subarray to be shifted.
@param shift_limit
@param shift_count
*/
void shift(int arr[], int limit, int i, int shift_limit, int shift_count){
    int displacement_count = limit - shift_limit;
}

void printarr(int arr[], int limit){
    int i;
    for(i = 0; i < limit; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
