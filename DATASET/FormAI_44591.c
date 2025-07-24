//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fib(n-1) + fib(n-2);
}

void drawLine(int width, char symbol) {
  for (int i=1; i<=width; i++) {
    printf("%c", symbol);
  }
  printf("\n");
}

void drawFibonacci(int n, int width, char symbol) {
  int fibArr[n];
  fibArr[0] = 0;
  fibArr[1] = 1;
  for (int i=2; i<n; i++) {
    fibArr[i] = fibArr[i-1] + fibArr[i-2];
  }
  for (int i=n-1; i>=0; i--) {
    drawLine(width-fibArr[i], ' ');
    drawLine(fibArr[i], symbol);
  }
}

int main(int argc, char** argv) {
  if (argc != 4) {
    printf("Usage: ./fibonacci n width symbol\n");
    printf("n = number of Fibonacci numbers to display\n");
    printf("width = width of the symbol lines\n");
    printf("symbol = symbol to use for drawing the lines\n");
    return 1;
  }
  int n = atoi(argv[1]);
  int width = atoi(argv[2]);
  char* symbol = argv[3];
  drawFibonacci(n, width, symbol[0]);
  return 0;
}