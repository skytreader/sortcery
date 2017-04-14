#include "heapsort.h"
#include "utils.h"

/**
Remember:
The left and right sons of node i (if any) is at node 2i + 1 and 2i + 2,
respectively.
*/

void heapify(int n[], int limit){
    int lastnode = limit - 1;
    int is_rson = (lastnode % 2) == 0;
    int i = lastnode;

    while(i >= 0){
        i -= 1;
    }
}
