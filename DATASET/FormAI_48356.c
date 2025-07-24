//FormAI DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>

int sequentialSearch(int arr[], int n, int searchValue){
   int i;
   for (i=0;i<n;i++){
      if (arr[i] == searchValue){
         return i;
      }
   }
   return -1;
}

int binarySearch(int arr[], int left, int right, int searchValue){
   if (right>=left){
      int mid = left + (right - left)/2;
      if (arr[mid] == searchValue){
         return mid;
      }
      if (arr[mid] > searchValue){
         return binarySearch(arr, left, mid-1, searchValue);
      }
      return binarySearch(arr, mid+1, right, searchValue);
   }
   return -1;
}

int main(){

   int arr[] = {2, 7, 11, 21, 23, 29, 31, 37, 41, 43, 47, 53};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int searchValue = 31;
   
   int searchResult = sequentialSearch(arr, n, searchValue);
   if (searchResult >= 0){
      printf("Using sequential search, %d found at index %d.\n", searchValue, searchResult);
   } else {
      printf("Using sequential search, %d not found.\n", searchValue);
   }

   searchResult = binarySearch(arr, 0, n-1, searchValue);
   if (searchResult >= 0){
      printf("Using binary search, %d found at index %d.\n", searchValue, searchResult);
   } else {
      printf("Using binary search, %d not found.\n", searchValue);
   }
   
   return 0;
}