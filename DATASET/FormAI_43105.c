//FormAI DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include<stdio.h>

// function to perform searching
int binarySearch(int array[], int size, int key) {
   int low = 0, high = size - 1, mid;
   while(low <= high) {
      mid = (low + high) / 2;
      if(array[mid] == key)
         return mid;
      if(array[mid] > key)
         high = mid - 1;
      else
         low = mid + 1;
   }
   return -1;
}

int main() {
   int i, size, key, index;
   int array[100];

   // read the array size from user
   printf("Enter array size : ");
   scanf("%d", &size);

   // read the array from user
   printf("Enter array elements : ");
   for(i=0; i<size; i++)
      scanf("%d", &array[i]);

   // read the key to be searched
   printf("Enter key : ");
   scanf("%d", &key);

   // perform binary search
   index = binarySearch(array, size, key);

   // display the result
   if(index != -1)
      printf("Element found at index %d", index);
   else
      printf("Element not found in array");

   return 0;
}