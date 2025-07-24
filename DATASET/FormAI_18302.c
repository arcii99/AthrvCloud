//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>

int fibonacci(int n)
{
  if(n == 0 || n == 1)
    return n;
  
  return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
  int n;
  printf("Enter the number of terms: ");
  scanf("%d", &n);

  printf("Fibonacci Sequence for %d terms:\n", n);

  for(int i = 0; i < n; i++)
  {
    int result = fibonacci(i);
    for(int j = 0; j < result; j++)
      printf("*");
    printf("\n");
  }
  return 0;
}