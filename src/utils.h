#include <math.h>

/*
Define exit codes here. Keep them sorted alphabetically.
*/
#define INVALID_STATE_EXT 5
#define OUT_OF_BOUNDS_MEM_EXT 1

#define arrsize(arr) sizeof(arr) / sizeof(arr[0])
#define logb(a, base) log(a) / log(base)
#define ptrind(bp, item_size, index) bp + item_size * index

#define define_max(T) \
T template_max_##T(T* arr, int limit){ \
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

#define define_min(T) \
T template_min_##T(T* arr, int limit){ \
    if(limit == 0){ \
        return -1; \
    } \
    int i; \
    int min_i = 0; \
    for(i = 1; i < limit; i++){ \
        if(arr[i] < arr[min_i]){ \
            min_i = i; \
        } \
    } \
    return min_i; \
}


int maxint(int arr[], int limit);
int maxfloat(float arr[], int limit);
int maxdouble(double arr[], int limit);
int minint(int arr[], int limit);
int minfloat(float arr[], int limit);
int mindouble(double arr[], int limit);
void swap(int arr[], int i, int j);
void safe_swap(int arr[], int i, int j, int limit);
void shift(int arr[], int limit, int i, int shift_limit, int shift_count);
// TODO Make this return/operate on a char*
void printarr(int arr[], int limit);

/*
The following compare functions should return a value n subject to the following
conditions:

    n > 0 if a > b
    n == 0 if a == b
    n < 0 if a < b

Passed to a sorting function, they should sort in ascending order. Passed to
`find_extreme` they should return the maximum.
*/
int cmp_int(const void *a, const void *b);
int cmp_float(const void *a, const void *b);

typedef struct STACK {
    int *stack;
    int size;
    int head;
} stack;

void init_stack(stack *s, int size);
int pop(stack *s);
void push(stack *s, int d);
