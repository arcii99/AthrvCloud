//FormAI DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>

int main() {
   int array[100], search, c, n;
 
   printf("Enter number of elements in the array:\n");
   scanf("%d",&n);
 
   printf("Enter %d integers:\n",n);
 
   for (c = 0; c < n; c++)
      scanf("%d",&array[c]);
 
   printf("Enter the number to search:\n");
   scanf("%d", &search);
 
   // Using Linear Search Algorithm
   for (c = 0; c < n; c++) {
      if (array[c] == search) {
         printf("%d is present at location %d.\n", search, c+1);
         break;
      }
   }
   
   if (c == n) // If element not found in the array
      printf("%d is not present in the array.\n", search);
 
   return 0;
}