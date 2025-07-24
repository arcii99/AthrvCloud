//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_fibonacci(int n) {
  int i, j, k, fib;
  static char BUFFER[4096] = "";

  memset(BUFFER, ' ', sizeof(BUFFER));
  BUFFER[sizeof(BUFFER) - 1] = 0;
  i = j = 0;
  k = n - 1;
  while (k--) {
    fib = i + j;
    i = j;
    j = fib;

    printf("%4d%c", fib, k ? ',' : '\n');
    // Adjust buffer
    snprintf(BUFFER, sizeof(BUFFER), "%s%4d%c", BUFFER, fib,
             k ? ',' : '\n');
    usleep(50000);  // Sleep for 50ms
  }
  FILE *file;
  file = fopen("fibonacci.txt", "w");
  fprintf(file, "%s", BUFFER);
  fclose(file);
}

int main() {
  int n;

  printf("Enter the number of Fibonacci numbers you want to generate: ");
  scanf("%d", &n);

  printf("Generating Fibonacci numbers...\n");

  // Print the Fibonacci series
  print_fibonacci(n);

  printf("Done!\n");

  return 0;
}