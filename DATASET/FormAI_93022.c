//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
#include <stdio.h>

int rand_array[1000];

int search(int key, int start_index, int end_index) 
{
   if(start_index > end_index) {
      return -1;
   }
   int mid_index = start_index + (end_index - start_index)/2;
   if(rand_array[mid_index] == key) {
      return mid_index;
   } else if(rand_array[mid_index] > key) {
      return search(key, start_index, mid_index-1);
   } else {
      return search(key, mid_index+1, end_index);
   }
}

int main()
{
   int i, n, key, result;
   printf("Enter the size of array: ");
   scanf("%d", &n);

   srand(time(NULL));
   printf("The array is:\n");
   for(i = 0; i < n; i++) {
      rand_array[i] = rand()%1000;
      printf("%d ", rand_array[i]);
   }
   printf("\n\nEnter the key you want to search: ");
   scanf("%d", &key);

   result = search(key, 0, n-1);
   if(result == -1) {
      printf("\nOops! The key %d is not found in the array.\n", key);
   } else {
      printf("\nHurray! The key %d is found at index %d of the array.\n", key, result);
   }

   return 0;
}