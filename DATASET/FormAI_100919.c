//FormAI DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>

int main() {
  int* iPtr;

  iPtr = (int*)malloc(sizeof(int));

  if (iPtr == NULL) {
    printf("OMG! Out of memory!\n");
    exit(1);
  }

  printf("HOLY COW! Memory allocated!\n");

  *iPtr = 42;

  printf("The value of the integer is %d\n", *iPtr);

  free(iPtr);

  printf("WOW! Memory has been freed!\n");

  return 0;
}