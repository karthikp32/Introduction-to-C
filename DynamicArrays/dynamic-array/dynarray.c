#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STARTING_CAPACITY 8

// If the problem is a bit too hard to solve, solve a simpler problem by implementing a dynamic array that only supports int
// Then you can generalize/modify it to work with other types like floats, longs, etc.

typedef struct DynamicArray {
  // TODO define our struct
  int* underlyingArray;
  int lastFilledIndex; 
  int size;
} DynamicArray;


DynamicArray* DA_new (void) {
  // TODO allocate and return a new dynamic array
  struct DynamicArray* dynamicArray;
  int first = '\0';
  (*dynamicArray).underlyingArray = &first;
  (*dynamicArray).lastFilledIndex = -1;
  (*dynamicArray).size = 0;
  return dynamicArray;
}

int DA_size(DynamicArray *da) {
  // TODO return the number of items in the dynamic array
  //keep iterating until you reach an element of a different data
  return (*da).size;
}

void DA_push (DynamicArray* da, void* x) {
  // TODO push to the end
  //Approach 1:
  // Get lastFilledIndex
  // if lastFilledIndex == -1
  //    underlyingArray[0] = x
  // if lastFilledIndex == size of underlyingArray - 1
  //  initialize new array doubledArray[size of underlyingArray * 2]
  // iterate from 0 to lastFilledIndex
  //  set doubledArray[i] = underlyingArray[i]
  // set doubledArray[lastFilledIndex + 1] = x
  // free the memory allocated to underlyingArray
  // set underlying array to doubledArray
  // else 
  //set underlyingArray[lastFilledIndex + 1] = x
  int lastFilledIndex = (*da).lastFilledIndex;
  int sizeOfDa = DA_size(da);
  if (lastFilledIndex == -1) {
    (*da).underlyingArray[0] = x;
    (*da).size++;
  }

  if (lastFilledIndex == sizeOfDa - 1) {
    int sizeOfInt = sizeof(int);
    int* doubledArray = malloc(sizeOfDa * sizeOfInt * 2);

    //set all values in doubledArray to '\0'
    for (int i=0; i < sizeOfDa * 2; i++) {
      *(doubledArray + i) =  '\0';
    }

    for (int j=0; j <= lastFilledIndex; j++) {
      *(doubledArray + j) = ((*da).underlyingArray + j);
    }

    //free memory allocated to underlyingArray
    free(da->underlyingArray);

    //reassign underlyingArray to point to doubledArray, the first memory address of the sequence of elements
    *(doubledArray + lastFilledIndex + 1) = x;
    da->underlyingArray = doubledArray;



  } else {
    *(da->underlyingArray + lastFilledIndex + 1) = x;
  }


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
