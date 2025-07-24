//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>

int search(int arr[], int start, int end, int key) {
   if(start <= end) {
      int mid = (start + end) / 2; // finding the middle index of the array
      if(arr[mid] == key) { //checking if middle index has the key
         return mid;
      }
      else if(arr[mid] < key) { //checking if key is present in the right sub array
         return search(arr, mid + 1, end, key);
      }
      else { //key is present in the left sub array
         return search(arr, start, mid - 1, key);
      }
   }
   return -1;
}

int main() {
   int n, key;
   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);
   int arr[n];
   printf("Enter %d integers: ", n);
   for(int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
   printf("Enter the element to be searched: ");
   scanf("%d", &key);
   int index = search(arr, 0, n - 1, key);
   if(index == -1) {
      printf("%d not found in the array.", key);
   }
   else {
      printf("%d found at index %d.", key, index);
   }
   return 0;
}