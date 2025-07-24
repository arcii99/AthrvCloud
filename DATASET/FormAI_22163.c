//FormAI DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int c_search(int arr[], int length, int key) {
   int start = 0, end = length - 1;
   while (start <= end && key >= arr[start] && key <= arr[end]) {
      int pos = start + ((double)(end - start) / (arr[end] - arr[start])) * (key - arr[start]);
      if (arr[pos] == key)
         return pos;
      if (arr[pos] < key)
         start = pos + 1;
      else
         end = pos - 1;
   }
   return -1;
}

int main() {
   int length, key, i, res;
   printf("Enter the length of the array: ");
   scanf("%d", &length);
   int arr[length];
   printf("Enter the array elements: ");
   for (i = 0; i < length; i++) {
      scanf("%d", &arr[i]);
   }
   printf("Enter the key element to search: ");
   scanf("%d", &key);
   res = c_search(arr, length, key);
   if(res == -1){
      printf("Element is not found in the array");
   }else{
      printf("Element is found at index %d", res);
   }
   return 0;
}