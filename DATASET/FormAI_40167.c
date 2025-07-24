//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);
  
  int *fibonacciSequence = malloc(sizeof(int) * num);
  
  fibonacciSequence[0] = 0;
  fibonacciSequence[1] = 1;

  for (int i = 2; i < num; i++) {
    fibonacciSequence[i] = fibonacciSequence[i-1] + fibonacciSequence[i-2];
  }

  printf("Fibonacci Sequence up to %d:\n", num);
  for (int i = 0; i < num; i++) {
    printf("%d  ", fibonacciSequence[i]);
    if ((i+1) % 10 == 0) {
      printf("\n");
    }
  }
  
  free(fibonacciSequence);
  return 0;
}