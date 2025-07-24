//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>

void fibonacci(int n) {
  int f1 = 0, f2 = 1, next_term, i;
  printf("%d %d ", f1, f2);
  for (i = 3; i <= n; i++) {
    next_term = f1 + f2;
    printf("%d ", next_term);
    f1 = f2;
    f2 = next_term;
  }
}

void printVisual(int n) {
  int f1 = 0, f2 = 1, next_term, i, j;
  printf("\n\n\tThe Fibonacci Sequence:\n");
  printf("\t----------------------\n\n");
  printf("\t0\n\t1\n");
  for (i = 3; i <= n; i++) {
    next_term = f1 + f2;
    f1 = f2;
    f2 = next_term;
    for (j = 1; j <= next_term; j++) {
        if (j == 1) {
            printf("\t%d", next_term);
        }
        else if (j == next_term){
            printf("*\n");
        }
        else{
            printf("*");
        }
    }
  }
}

int main() {
  int n;
  printf("\nEnter the number of terms: ");
  scanf("%d", &n);
  printf("\n\tSequence computation:\n\t----------------------\n");
  fibonacci(n);
  printf("\n");
  printVisual(n);
  return 0;
}