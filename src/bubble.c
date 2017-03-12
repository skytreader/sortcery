#include "utils.h"
#include "bubble.h"

void bubble_sort(int arr[], int limit){
    int i;
    for(i = limit - 1; i >= 0; i--){
        int max_index = max(arr, i);
        swap(arr, i, max_index);
    }
}
