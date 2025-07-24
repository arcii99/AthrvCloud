//FormAI DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>
#define MAXSIZE 100

int search(int arr[], int n, int x) {
   // Initialize starting and ending indexes
   int left = 0, right = n-1;
 
   // Traverse the array until both pointers meet or cross
   while (left <= right) {
      int mid = (left + right)/2;
 
      // If element is present at middle
      if (arr[mid] == x)
         return mid;
 
      // If element is smaller than mid
      else if (arr[mid] > x)
         right = mid - 1;
 
      // Else, element is in right subarray
      else
         left = mid + 1;
   }
 
   // If element is not present in array
   return -1;
}
 
int main() {
   int arr[MAXSIZE], n, x, result;
   printf("Enter size of array: ");
   scanf("%d", &n);
 
   printf("Enter elements of array in sorted order:\n");
   for(int i = 0; i < n; i++)
      scanf("%d", &arr[i]);
 
   printf("Enter element to search: ");
   scanf("%d", &x);
 
   result = search(arr, n, x);
   if(result == -1)
      printf("Element is not present in array");
   else
      printf("Element is present at index %d", result);
   return 0;
}