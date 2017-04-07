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

void mergesort(int arr[], int limit){
    int skip_limit = ceil(logb(limit, 2)) + 1;
    printf("skip limit is %d\n", skip_limit);
    int skip = 1;

    while(skip <= skip_limit){
        int i;
        int last_p1 = limit - skip + 1;
        printf("skip is %d\n", skip);
        for(i = 0; i < last_p1;){
            int p2_origin = i + skip;
            int p2_limit = p2_origin + skip;
            
            if(p2_limit > limit){
                p2_limit = limit;
            }

            printf("i %d p2o %d p2l %d\n", i, p2_origin, p2_limit);
            merge(arr, limit, i, p2_origin, p2_limit);
            i = p2_limit;
        }
        printarr(arr, limit);
        skip *= 2;
    }
}
