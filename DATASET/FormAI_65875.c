//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>

#define MAX_VALUE 1000
#define MIN_VALUE 0

void bucket_sort(int arr[], int n) {
   int count[MAX_VALUE + 1] = {0};

   for (int i = 0; i < n; i++) {
      count[arr[i]]++;
   }

   for (int i = MIN_VALUE; i <= MAX_VALUE; i++) {
      for (int j = 0; j < count[i]; j++) {
         printf("%d ", i);
      }
   }
}

int main() {
   int arr[] = {5, 2, 8, 3, 10, 2, 1};
   int n = sizeof(arr)/sizeof(arr[0]);

   printf("Before sorting:\n");
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");

   bucket_sort(arr, n);

   printf("\nAfter sorting:\n");
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");

   return 0;
}