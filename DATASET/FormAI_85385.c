//FormAI DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int linear_search(int [], int, int);

int main()
{
   int array[100], search_element, size, position;
   printf("Enter the number of elements: ");
   scanf("%d", &size);
   printf("Enter %d integers: ", size);

   for (int i=0; i<size; i++)
      scanf("%d", &array[i]);

   printf("Enter the element to search: ");
   scanf("%d", &search_element);

   position = linear_search(array, size, search_element);

   if (position == -1)
      printf("\nElement not found!\n");
   else
      printf("\nElement found at position %d\n", position+1);

   return 0;
}

int linear_search(int arr[], int n, int x)
{
   for(int i=0; i<n; i++)
   {
      if (arr[i] == x)
         return i;
   }
   return -1;
}