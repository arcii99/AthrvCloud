//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include<stdio.h>

// Divide and conquer algorithm
int binarySearch(int arr[], int left, int right, int target) {
   if (right >= left) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target)
         return mid;
      if (arr[mid] > target)
         return binarySearch(arr, left, mid - 1, target);
      return binarySearch(arr, mid + 1, right, target);
   }
   return -1;
}

int main() {
   int arr[] = {2, 3, 4, 10, 40};
   int target = 10;
   int n = sizeof(arr)/ sizeof(arr[0]);
   int result = binarySearch(arr, 0, n - 1, target);
   if(result == -1){
      printf("Element is not found in the array");
   } else {
      printf("Element is found at index: %d", result);
   }
   return 0;    
}