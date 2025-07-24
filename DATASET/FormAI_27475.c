//FormAI DATASET v1.0 Category: Digital signal processing ; Style: recursive
#include <stdio.h>

// Declare recursive function
int dspRecursive(int n)
{
  if(n == 0 || n == 1) // Base case
    return n;
  else // Recursive case
    return dspRecursive(n-1) + dspRecursive(n-2);
}

int main()
{
  int n, i;

  printf("Enter the number of terms: ");
  scanf("%d", &n);

  printf("DSP Series: ");
  for(i = 0; i < n; i++)
    printf("%d ", dspRecursive(i));

  printf("\n");

  return 0;
}