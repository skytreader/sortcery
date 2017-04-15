#include <stdio.h>
#include "heapsort.h"
#include "utils.h"

/**
Remember:
The left and right sons of node i (if any) is at node 2i + 1 and 2i + 2,
respectively.
*/

void heapify(int n[], int limit){
    int i;

    for(i = 0; i < limit; i++){
        int minson = (2 * i) + 1;
        int rson = (2 * i) + 2;
        if(rson < limit && n[minson] > n[rson]){
            minson = rson;
        }

        if(minson < limit && n[minson] < n[i]){
            safe_swap(n, minson, i, limit);
        }
    }
}

/**
This function is the key to making the heap and the queue co-exist in the same
space of allocated memory. Every call to this function will take the root of the
heap and put it at the tail of the queue.

@param n
@param limit
    The actual number of elements inthe allocated memory (size of the array n).
*/
void heapsort_shift(int n[], int limit){
    int root_holder = n[0];
    int i;

    for(i = 1; i < limit; i++){
        safe_swap(n, i, i - 1, limit);
    }

    n[limit - 1] = root_holder;
}

void heapsort(int n[], int limit){
    int i;

    for(i = 0; i < limit; i++){
        heapify(n, limit - i);
        heapsort_shift(n, limit);
    }
}
