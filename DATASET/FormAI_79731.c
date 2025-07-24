//FormAI DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>

int search(int arr[], int n, int key) {
   int i;
   for (i = 0; i < n; i++) {
      if (arr[i] == key)
         return i;
   }
   return -1;
}

int main() {
   int arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
   int n = sizeof(arr)/sizeof(arr[0]);
   int key, index;

   printf("Enter key element: ");
   scanf("%d", &key);

   index = search(arr, n, key);

   if (index != -1) {
      printf("Element %d found at index %d", key, index);
   }
   else {
      printf("Element not found");
   }

   return 0;
}