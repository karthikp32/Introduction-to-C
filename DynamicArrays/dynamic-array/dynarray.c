#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STARTING_CAPACITY 8

// If the problem is a bit too hard to solve, solve a simpler problem by implementing a dynamic array that only supports int
// Then you can generalize/modify it to work with other types like floats, longs, etc.

typedef struct DynamicArray {
  // TODO define our struct
  int underlyingArray[1];

} DynamicArray;


DynamicArray* DA_new (void) {
  // TODO allocate and return a new dynamic array
  struct DynamicArray* dynamicArray;
  (*dynamicArray).underlyingArray[0] = '\0';
  return dynamicArray;
}

int DA_size(DynamicArray *da) {
  // TODO return the number of items in the dynamic array
  //keep iterating until you reach an element of a different data
  if (sizeof((*da).underlyingArray) > 0 && (*da).underlyingArray[0] != '\0') {
      return (sizeof((*da).underlyingArray)) / (sizeof((*da).underlyingArray[0]));
  }
  return 0;
}

void DA_push (DynamicArray* da, void* x) {
  // TODO push to the end
  int size = DA_size(da);
}

void *DA_pop(DynamicArray *da) {
  // TODO pop from the end
}

void DA_set(DynamicArray *da, void *x, int i) {
  // TODO set at a given index, if possible
}

void *DA_get(DynamicArray *da, int i) {
  // TODO get from a given index, if possible
}


void DA_free(DynamicArray *da) {
  // TODO deallocate anything on the heap
}

int main() {
    DynamicArray* da = DA_new();

    assert(DA_size(da) == 0);

    // basic push and pop test
    int x = 5;
    float y = 12.4;
    DA_push(da, &x);
    DA_push(da, &y);
    assert(DA_size(da) == 2);
    printf("OK\n");

    assert(DA_pop(da) == &y);
    assert(DA_size(da) == 1);

    assert(DA_pop(da) == &x);
    assert(DA_size(da) == 0);
    assert(DA_pop(da) == NULL);

    // basic set/get test
    DA_push(da, &x);
    DA_set(da, &y, 0);
    assert(DA_get(da, 0) == &y);
    DA_pop(da);
    assert(DA_size(da) == 0);

    // expansion test
    DynamicArray *da2 = DA_new(); // use another DynamicArray to show it doesn't get overriden
    DA_push(da2, &x);
    int i, n = 100 * STARTING_CAPACITY, arr[n];
    for (i = 0; i < n; i++) {
      arr[i] = i;
      DA_push(da, &arr[i]);
    }
    assert(DA_size(da) == n);
    for (i = 0; i < n; i++) {
      assert(DA_get(da, i) == &arr[i]);
    }
    for (; n; n--)
      DA_pop(da);
    assert(DA_size(da) == 0);
    assert(DA_pop(da2) == &x); // this will fail if da doesn't expand

    DA_free(da);
    DA_free(da2);
    printf("OK\n");
}
