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

void heapsort(int n[], int limit){
}
