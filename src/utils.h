#define arrsize(arr) sizeof(arr) / sizeof(arr[0])

int max(int arr[], int limit);
int min(int arr[], int limit);
void swap(int arr[], int i, int j);
void safe_swap(int arr[], int i, int j);
// TODO Make this return/operate on a char*
void printarr(int arr[], int limit);
