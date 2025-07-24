//FormAI DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p = malloc(sizeof(int));

  if (p == NULL) {
    printf("Memory allocation error!.\n");
    return 1;
  }

  *p = 42;

  printf("The value of p is: %d\n", *p);

  free(p);

  return 0;
}