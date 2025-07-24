//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Ada Lovelace
#include <stdio.h>
int search(int arr[], int n, int x) {
   for (int i = 0; i < n; i++) {
      if (arr[i] == x)
         return i;
   }
   return -1;
}
int main() {
   int arr[] = {23, 24, 25, 26, 27, 28, 29};
   int x = 27; // search for value 27
   int n = sizeof(arr)/sizeof(arr[0]);
   int result = search(arr, n, x);
   if (result == -1)
      printf("Element not found.\n");
   else
      printf("Element found at index %d.\n", result);
   return 0;
}