//FormAI DATASET v1.0 Category: Error handling ; Style: careful
#include<stdio.h>
#include<stdlib.h>

void throwError(char *msg) {
  fprintf(stderr, "Error: %s\n", msg);
  exit(1);
}

int main() {
  int x, y;

  printf("Enter two numbers: ");
  if(scanf("%d %d", &x, &y) != 2) {
    throwError("Invalid input. Expected two integers.");
  }

  int z = x + y;
  if(z < 0) {
    throwError("Addition result is negative.");
  }

  int *arr = malloc(z * sizeof(int));
  if(arr == NULL) {
    throwError("Memory allocation error.");
  }

  for(int i=0; i<z; i++) {
    arr[i] = i;
  }

  if(z > 10) {
    fprintf(stderr, "Warning: Sum is quite large.\n");
  }

  printf("Array contents: ");
  for(int i=0; i<z; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}