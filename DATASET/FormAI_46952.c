//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, j, k, x;
   int arr1[1000][1000], arr2[1000][1000], arr3[1000][1000];
   clock_t start, end;
   double time_taken;

   // initialize arrays with random values between 0 and 99
   for(i=0;i<1000;i++) {
       for(j=0;j<1000;j++) {
           arr1[i][j] = rand() % 100;
           arr2[i][j] = rand() % 100;
           arr3[i][j] = 0;
       }
   }

   // perform matrix multiplication and time it
   start = clock();
   for(i=0;i<1000;i++) {
       for(j=0;j<1000;j++) {
           for(k=0;k<1000;k++) {
               arr3[i][j] += arr1[i][k] * arr2[k][j];
           }
       }
   }
   end = clock();
   time_taken = (double)(end - start) / CLOCKS_PER_SEC;

   printf("Matrix multiplication took %f seconds\n",time_taken);

   // perform sorting and time it
   start = clock();
   for(i=0;i<1000;i++) {
       for(j=0;j<999;j++) {
           for(k=j+1;k<1000;k++) {
               if(arr1[i][k] < arr1[i][j]) {
                   x = arr1[i][j];
                   arr1[i][j] = arr1[i][k];
                   arr1[i][k] = x;
               }
           }
       }
   }
   end = clock();
   time_taken = (double)(end - start) / CLOCKS_PER_SEC;

   printf("Sorting took %f seconds\n",time_taken);

   return 0;
}