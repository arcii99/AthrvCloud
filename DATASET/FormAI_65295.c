//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int num1 = 0, num2 = 1, count = 0, n = 0;
  printf("Enter the number of terms: ");
  scanf("%d", &n);
  printf("Generating Fibonacci sequence for the first %d terms...\n", n);
  sleep(1);

  // Fibonacci sequence visualizer
  printf("0, ");
  while(count < n-1) {
    sleep(1);
    printf("%d, ", num2);
    int temp = num2;
    num2 = num1 + num2;
    num1 = temp;
    count++;
  }

  printf("\nThe Fibonacci sequence has been successfully generated!");
  return 0;
}