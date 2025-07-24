//FormAI DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int findMax(int* arr, int size, int* max) {
   if (size == 1) {
      *max = *arr;
      return 1;
   }

   int submax;
   int count = findMax(arr + 1, size - 1, &submax);
   if (*arr > submax) {
      *max = *arr;
      return 1 + count;
   } else {
      *max = submax;
      return count;
   }
}

int main() {
   int size;
   printf("Enter the size of the array: ");
   scanf("%d", &size);

   int* arr = malloc(sizeof(int) * size);
   for (int i = 0; i < size; i++) {
      scanf("%d", &arr[i]);
   }

   int max;
   int count = findMax(arr, size, &max);
   printf("The maximum value in the array is %d\n", max);
   printf("It occurs %d times in the array.\n", count);

   free(arr);
   return 0;
}