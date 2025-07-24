//FormAI DATASET v1.0 Category: Benchmarking ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

   int i,j,k;
   int size = 10000;
   int matrix[size][size];
   double time_spent;

   //Generating random elements
   srand(time(0));
   for(i=0;i<size;i++) {
      for(j=0;j<size;j++) {
         matrix[i][j] = rand();
      }
   }

   clock_t begin = clock();
   
   //Benchmarking add operation
   for(k=0;k<10000;k++) {
      for(i=0;i<size;i++) {
         for(j=0;j<size;j++) {
            matrix[i][j] += 5;
         }
      }
   }

   clock_t end = clock();
   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   printf("The time spent on add operation is %f seconds\n", time_spent);

   //Benchmarking multiplication operation
   begin = clock();
   for(k=0;k<10000;k++) {
      for(i=0;i<size;i++) {
         for(j=0;j<size;j++) {
            matrix[i][j] *= 2;
         }
      }
   }
   end = clock();
   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   printf("The time spent on multiplication operation is %f seconds\n", time_spent);

   return 0;
}