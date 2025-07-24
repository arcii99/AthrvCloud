//FormAI DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>

int main()
{
   int array[100], n, key, i;
   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);
   printf("Enter the elements of the array: ");
   for (i = 0; i < n; i++)
      scanf("%d", &array[i]);
   printf("Enter the element to be searched: ");
   scanf("%d", &key);
   for (i = 0; i < n; i++)
   {
      if (array[i] == key)
      {
         printf("%d is present at location %d.\n", key, i + 1);
         break;
      }
   }
   if (i == n)
      printf("%d is not present in the array.\n", key);
   return 0;
}