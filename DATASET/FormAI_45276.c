//FormAI DATASET v1.0 Category: Sorting ; Style: visionary
#include <stdio.h>

int main()
{
 int array[100], n, c, d,s;
  printf("Enter the number of elements you want in the array: \n");
  scanf("%d", &n);

  printf("Enter the elements of the array: \n");
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  // Sorting the array using Bubble sort
   for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For descending order use < */
      {
        s       = array[d];
        array[d]   = array[d+1];
        array[d+1] = s;
      }
    }
  }

  printf("Sorted array in ascending order: \n");
  for (c = 0; c < n; c++)
     printf("%d  ", array[c]);

  return 0;
}