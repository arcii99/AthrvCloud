//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// function for calculating fibonacci sequence
int fibonacci(int n)
{
  if(n == 0 || n == 1)
    return n;
  else
    return fibonacci(n-1) + fibonacci(n-2);
}

// function for visualizing fibonacci sequence
void visualizeFibonacci(int n)
{
  int fib[MAX];
  int i, j, k = 0;

  printf("\nVisualizing Fibonacci Sequence\n");

  for(i = 0; i < n; i++)
  {
    fib[i] = fibonacci(i);
    for(k = 0; k < i; k++)
      printf("%c", fib[k] % 2 == 0 ? '|' : ' ');
    printf("%d\n", fib[i]);
  }

  for(i = n-2; i >= 0; i--)
  {
    for(k = 0; k < i; k++)
      printf("%c", fib[k] % 2 == 0 ? '|' : ' ');
    printf("%d\n", fib[i]);
  }
}

int main()
{
  int n;

  printf("Enter the number of terms in Fibonacci Sequence: ");
  scanf("%d", &n);

  visualizeFibonacci(n);

  return 0;
}