//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int prev = 0;
  int current = 1;
  int next;
  int max_num = 20;

  printf("\nFibonacci Sequence Visualizer\n\n");

  for(int i = 0; i < max_num; i++) {
    next = prev + current;
    prev = current;
    current = next;

    srand(time(NULL));

    int random_num = rand() % 10 + 1;

    printf("%d: \t", i+1);

    for(int j = 0; j < current; j++) {
      if(j%2 == 0 && j%3 == 0) {
        printf("*");
      } else if(j%2 == 0) {
        printf("+");
      } else if(j%3 == 0) {
        printf("-");
      } else {
        int random_prop = rand() % 10 + 1;
        if(random_prop < 5) {
          printf("^");
        } else {
          printf("~");
        }
      }
    }

    printf("\n\n");

  }

  printf("End of Fibonacci Sequence\n");

  return 0;
}