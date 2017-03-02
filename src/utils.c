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

@param arr
@param i
@param j
*/
void swap(int arr[], int i, int j){
    arr[i] += arr[j];
    arr[j] = arr[i] - arr[j];
}
