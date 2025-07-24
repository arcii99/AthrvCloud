//FormAI DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
   int data[5] = {4, 7, 2, 9, 1};
   int min = data[0];
   int max = data[0];
   
   for (int i = 1; i < 5; i++) {
       if (data[i] < min) {
           min = data[i];
       }
       
       if (data[i] > max) {
           max = data[i];
       }
   }
   
   printf("Minimum value in the dataset: %d\n", min);
   printf("Maximum value in the dataset: %d\n", max);

   return 0;
}