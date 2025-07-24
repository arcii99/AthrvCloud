//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include<stdio.h>

int binarySearch(int array[], int left, int right, int target) {
   while (left <= right) {
      int middle = left + (right-left)/2;

      if (array[middle] == target)
         return middle;

      if (array[middle] < target)
         left = middle + 1;

      else
         right = middle - 1;
   }

   return -1;
}

int main() {
   int array[] = {2, 3, 4, 10, 40};
   int arrayLength = sizeof(array)/sizeof(array[0]);
   int target = 10;
   int result = binarySearch(array, 0, arrayLength - 1, target);

   if(result == -1)
      printf("Element not found in array.");
   else
      printf("Element found at index: %d", result);

   return 0;
}