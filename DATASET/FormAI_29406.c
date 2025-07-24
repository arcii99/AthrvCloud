//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ultraprecise
#include <stdio.h>

void fibonacci_visualizer(int n);

int main() {
  int n;

  printf("Enter the number of terms to display: ");
  scanf("%d", &n);

  fibonacci_visualizer(n);

  return 0;
}

void fibonacci_visualizer(int n) {
  int i, j, current_term, last_term = 0, current_num = 1;

  for (i = 1; i <= n; i++) {
    current_term = last_term + current_num;
    last_term = current_num;
    current_num = current_term;

    for (j = 1; j <= current_term; j++) {
      printf("*");
    }

    printf("\n");
  }
}