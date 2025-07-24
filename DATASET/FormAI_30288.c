//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Linus Torvalds
#include <stdio.h>

int main(void)
{
  int n, a = 0, b = 1, c;

  printf("Enter the number of terms: ");
  scanf("%d", &n);

  printf("\nLinus Torvalds presents Fibonacci Series:\n");
  printf("%d\n%d\n", a, b);

  for(int i = 2; i < n; i++)
  {
    c = a + b;
    printf("%d\n", c);
    a = b;
    b = c;
  }

  return 0;
}