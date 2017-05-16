#include <math.h>

/*
Define exit codes here. Keep them sorted alphabetically.
*/
#define INVALID_STATE_EXT 5
#define OUT_OF_BOUNDS_MEM_EXT 1

#define arrsize(arr) sizeof(arr) / sizeof(arr[0])
#define logb(a, base) log(a) / log(base)

#define define_max(T) \
T chad_max_##T(T* arr, int limit){ \
    if(limit == 0){ \
        return -1; \
    } \
    int i; \
    int max_i = 0; \
    for(i = 1; i < limit; i++){ \
        if(arr[i] > arr[max_i]){ \
            max_i = i; \
        } \
    } \
    return max_i; \
}


int max(int arr[], int limit);
int min(int arr[], int limit);
void swap(int arr[], int i, int j);
void safe_swap(int arr[], int i, int j, int limit);
void shift(int arr[], int limit, int i, int shift_limit, int shift_count);
// TODO Make this return/operate on a char*
void printarr(int arr[], int limit);

typedef struct STACK {
    int *stack;
    int size;
    int head;
} stack;

void init_stack(stack *s, int size);
int pop(stack *s);
void push(stack *s, int d);
