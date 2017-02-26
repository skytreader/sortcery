#include "utils.h"

/**
Returns the index of the greatest element in the array. In case of ties, the
first occurrence of the greatest element is returned.

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
