//FormAI DATASET v1.0 Category: Searching algorithm ; Style: genious
#include <stdio.h>

int main() {
   int array[100], search, counter, count=0;

   printf("Enter number of elements: ");
   scanf("%d", &count);

   printf("Enter %d integers:\n", count);

   for(counter=0; counter<count; counter++)
      scanf("%d", &array[counter]);

   printf("Enter a number to search: ");
   scanf("%d", &search);

   for(counter=0;counter<count;counter++){
      if(array[counter]==search){
         printf("%d is present at location %d.\n", search, counter+1);
         break;
      }
   }
   if(counter==count)
      printf("%d is not present in the array.\n", search);

   return 0;
}