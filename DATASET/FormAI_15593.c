//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: recursive
#include <stdio.h>
// Recursive function to calculate Fibonacci sequence
int fibRec(int n)
{
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return (fibRec(n-1) + fibRec(n-2));
}
// Main function to test the Fibonacci sequence
int main()
{
  int numTerms, i;
  printf("Enter the number of terms to find the Fibonacci sequence: ");
  scanf("%d",&numTerms);
  printf("Fibonacci sequence: ");
  for (i = 0; i < numTerms; i++)
  {
    printf("%d ",fibRec(i));
  }
  printf("\n");
  return 0;
}