/*
This used to contain a definition for `insert`--the actual function that does
all the heavy lifting for insertion sort. However, it was made `static` because
it makes sense to hide helper functions from external users. A consequence of
this is that I could not unit test the `insert` function.

Which goes to show how convenient OO could be (with Java specifically in mind).
Unit testing the `insert` function might be debatable to unit testing purists
but at least in Java I could come to some kind of compromise and declare the
helper function as `protected` (or even `protected final`).
*/
void insertion_sort(void *arr, size_t limit, size_t item_size, int (*comparator)(const void *, const void *));
