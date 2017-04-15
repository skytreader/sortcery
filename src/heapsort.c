#include "heapsort.h"
#include "utils.h"

/**
Remember:
The left and right sons of node i (if any) is at node 2i + 1 and 2i + 2,
respectively.
*/

void heapify(int n[], int limit){
    // Get the father of the lastnode.
    int i = limit / 2;

    while(i >= 0){
        int minson = (2 * i) + 1;
        int rson = (2 * i) + 2;
        if(rson < limit && n[minson] < n[(2 * i) + 2]){
            minson = (2 * i) + 2;
        }

        if(n[minson] < n[i]){
            safe_swap(n, minson, i, limit);
        }

        i--;
    }
}

void heapsort(int n[], int limit){
}
