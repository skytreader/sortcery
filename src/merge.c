#include "merge.h"
#include "utils.h"

/**
Assuming that the subarrays described by the index ranges
    
    [p1_origin, p2_origin)
    [p2_origin, p2_limit)

are sorted, this method merges them into one sorted array spanning [p1_origin,
p2_limit) in the provided array.

@param arr
@param limit
    The length of the array.
@param p1_origin
@param p2_origin
@param p2_limit
*/
void merge(int arr[], int limit, int p1_origin, int p2_origin, int p2_limit){
    int i = p1_origin;
    int j = p2_origin;
    
    while(i < p2_limit && j < p2_limit){
        if(arr[i] <= arr[j]){
            i++;
        } else if(arr[i] > arr[j]){
            shift(arr, limit, i, j, 1);
            j++;
        }
    }
}
