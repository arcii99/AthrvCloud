//FormAI DATASET v1.0 Category: Sorting ; Style: Claude Shannon
/*The following program implements the Bubble Sort algorithm to sort an array of integers.*/

#include <stdio.h>

int main()
{
  int n, i, j, temp;
  int array[100];

  printf("Enter number of elements: ");
  scanf("%d", &n);

  for(i = 0; i < n; i++)
  {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &array[i]);
  }

  for(i = 0; i < n-1; i++)
  {
    for(j = 0; j < n-i-1; j++)
    {
      if(array[j] > array[j+1])
      {
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }

  printf("\nSorted array in ascending order:\n");

  for(i = 0; i < n; i++)
  {
    printf("%d\n", array[i]);
  }
  return 0;
}