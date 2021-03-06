#include "utils.h"
#include "bubble.h"

void bubble_sort(int arr[], unsigned int limit){
    unsigned int i;
    for(i = limit - 1; i > 0; i--){
        unsigned int max_index = maxint(arr, i + 1);
        swap(arr, i, max_index);
    }
}
