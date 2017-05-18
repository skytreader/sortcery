#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

define_max(int)
define_max(float)
define_max(double)

/**
Returns the index of the greatest element in the array. In case of ties, the
first occurrence of the greatest element is returned.

@param arr
@param limit
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

/**
Returns the index of the least element in the array. In case of ties, the
first occurrence of the least element is returned.

@param arr
@param limit
@return The index of the least element or a negative value if, for some
    reason "least element" is undefined.
*/
int min(int arr[], int limit){
    if(limit == 0){
        return -1;
    }

    int i;
    int min_i = 0;
    for(i = 1; i < limit; i++){
        if(arr[i] < arr[min_i]){
            min_i = i;
        }
    }
    return min_i;
}

int maxint(int arr[], int limit){
    return max_int(arr, limit);
}

int maxfloat(float arr[], int limit){
    return max_float(arr, limit);
}

int maxdouble(double arr[], int limit){
    return max_double(arr, limit);
}

/**
Swap the values at i and j of `arr`. Automagic assumption that i and j are
within bounds.

WARNING: This method is not safe. Swapping large integer values might cause an
overflow condition. The only reason to use this, if at all, is that it is
lighter on memory ever-so-slightly.

@param arr
@param i
@param j
*/
void swap(int arr[], int i, int j){
    if(i == j){
        return;
    }
    arr[i] += arr[j];
    arr[j] = arr[i] - arr[j];
    arr[i] -= arr[j];
}

/**
The safest swap method to use. Does not try to be clever and just gets the job
done (TM).

@param arr
@param i
@param j
@param limit
*/
void safe_swap(int arr[], int i, int j, int limit){
    int max_index = limit - 1;
    if(i > max_index || j > max_index){
        exit(INVALID_STATE_EXT);
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/**
Shifts all elements in the subarray [i, shift_limit) by shift_count. The vacated
cells will contain the misplaced elements.

@param arr
@param limit
    The length of the array.
@param i
    The index of the first element of the subarray to be shifted.
@param shift_limit
    Let j be the index of the last element to be shifted. Then shift_limit will
    be j + 1.
@param shift_count
    The number of places to shift the elements. Hence after the operation, the
    element at index i will be found at index i + shift_count.
*/
void shift(int arr[], int limit, int i, int shift_limit, int shift_count){
    if(limit == shift_limit){
        shift_limit = limit - shift_count;
    }

    int displacement_temp[shift_count];
    int shiftlength = shift_limit - i;
    int shift_temp[shiftlength];
    int j;

    // Copy the elements that will be displaced unintentionally.
    for(j = 0; j < shift_count; j++){
        int translation = shift_limit + j;
        if(translation < limit){
            displacement_temp[j] = arr[shift_limit + j];
        } else{
            printf("out of bounds memory access!\n");
            exit(OUT_OF_BOUNDS_MEM_EXT);
        }
    }

    // Copy the elements to be shifted intentionally.
    for(j = 0; j < shiftlength; j++){
        int translation = i + j;
        if(translation < limit){
            shift_temp[j] = arr[i + j];
        } else{
            printf("out of bounds memory access!\n");
            exit(OUT_OF_BOUNDS_MEM_EXT);
        }
    }

    // Shift the elements.
    for(j = 0; j < shiftlength; j++){
        int translation = j + i + shift_count;
        if(translation < limit){
            arr[j + i + shift_count] = shift_temp[j];
        } else{
            printf("out of bounds memory access!\n");
            exit(OUT_OF_BOUNDS_MEM_EXT);
        }
    }

    // Fill in the "blanked" cells.
    for(j = 0; j < shift_count; j++){
        int translation = i + j;
        if(translation < limit){
            arr[i + j] = displacement_temp[j];
        } else{
            printf("out of bounds memory access!\n");
            exit(OUT_OF_BOUNDS_MEM_EXT);
        }
    }
}

void printarr(int arr[], int limit){
    int i;
    for(i = 0; i < limit; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void init_stack(stack *s, int size){
    (*s).stack = (int*) malloc(sizeof(int) * size);
    (*s).size = size;
    s->head = 0;
}

/**
This does not delete the item in memory (i.e., an item that is "popped" can
still be accessed via s->stack[s->head + 1] outside of the stack functions. This
is a possible issue!

However (this does not matter much while we are returning primitives), this
ensures that the data returned is _the_ object, not some copy. If we overwrite
the stack data immediately, we would corrupt objects that are passed to the
stack.
*/
int pop(stack *s){
    if(s->head == 0){
        printf("popping from an empty stack.\n");
        exit(INVALID_STATE_EXT);
    }
    s->head--;
    return s->stack[s->head];
}

void push(stack *s, int d){
    if(s->head == (s->size - 1)){
        printf("pushing to a full stack.\n");
        exit(OUT_OF_BOUNDS_MEM_EXT);
    }
    s->stack[s->head] = d;
    s->head++;
}
