#include <math.h>
#include <stdio.h>

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
void merge(int arr[], unsigned int limit, unsigned int p1_origin, unsigned int p2_origin, unsigned int p2_limit){
    unsigned int i = p1_origin;
    unsigned int j = p2_origin;
    
    while(i < p2_limit && j < p2_limit){
        if(arr[i] <= arr[j]){
            i++;
        } else if(arr[i] > arr[j]){
            shift(arr, limit, i, j, 1);
            j++;
        }
    }
}

void mergesort(int arr[], unsigned int limit){
    unsigned int skip_limit = ceil(logb(limit, 2)) + 1;
    unsigned int skip = 1;

    while(skip <= skip_limit){
        unsigned int i;
        unsigned int last_p1 = limit - skip + 1;
        for(i = 0; i < last_p1;){
            unsigned int p2_origin = i + skip;
            unsigned int p2_limit = p2_origin + skip;
            
            if(p2_limit > limit){
                p2_limit = limit;
            }

            merge(arr, limit, i, p2_origin, p2_limit);
            i = p2_limit;
        }
        skip *= 2;
    }
}
