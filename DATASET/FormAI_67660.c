//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: synchronous
#include <stdio.h>

int fibonacci(int n) 
{
  if (n == 0 || n == 1) 
  {
    return n;
  }
  
  return (fibonacci(n-1) + fibonacci(n-2));
}

void visualizer(int n) 
{
  int i, j;

  for(i = 0; i < n; i++) 
  {
    for(j = 0; j <= i; j++) 
    {
      printf("%d ", fibonacci(j));
    }

    printf("\n");
  }
}

int main() 
{
  int n;

  printf("Enter the number of terms (n): ");
  scanf("%d", &n);

  visualizer(n);

  return 0;
}