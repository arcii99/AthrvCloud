//FormAI DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>

int main() {
   int n = 10;
   int fibo[n];
   fibo[0] = 0;
   fibo[1] = 1;
   for (int i = 2; i < n; i++) {
      fibo[i] = fibo[i-1] + fibo[i-2];
   }
   printf("The first %d Fibonacci numbers are:\n", n);
   for (int i = 0; i < n; i++) {
      printf("%d ", fibo[i]);
   }
   printf("\n");
   
   int a = 10;
   int b = 5;
   printf("Original values: a = %d, b = %d\n", a, b);
   a = a + b; // a = 15
   b = a - b; // b = 10
   a = a - b; // a = 5
   printf("Swapped values: a = %d, b = %d\n", a, b);
   
   int arr[5][5] = {
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 10},
      {11, 12, 13, 14, 15},
      {16, 17, 18, 19, 20},
      {21, 22, 23, 24, 25}
   };
   printf("The original 5x5 array is:\n");
   for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
         printf("%d ", arr[i][j]);
      }
      printf("\n");
   }
   printf("\n");
   printf("The diagonal elements are:\n");
   for (int i = 0; i < 5; i++) {
      printf("%d ", arr[i][i]);
   }
   printf("\n");

   return 0;
}