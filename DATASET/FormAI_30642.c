//FormAI DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include<stdio.h>

int main() {
   int arr[50], search_item, n, i, flag = 0;
   
   // Getting the input from user
   printf("\nEnter the number of elements: ");
   scanf("%d", &n);
   
   for (i = 0; i < n; i++) {
      printf("\nEnter element %d: ", i+1);
      scanf("%d", &arr[i]);
   }
   
   printf("\nEnter the item to be searched: ");
   scanf("%d", &search_item);
   
   // Searching Algorithm Implementation
   for (i = 0; i < n; i++) {
      if (arr[i] == search_item) {
         printf("\nThe item %d found at position %d", search_item, i+1);
         flag = 1;
         break;
      }
   }
   
   if (flag == 0) {
      printf("\nThe item %d is not present in the array", search_item);
   }
   
   return 0;
}