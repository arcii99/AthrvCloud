//FormAI DATASET v1.0 Category: Digital signal processing ; Style: minimalist
#include <stdio.h>
#define N 10

int main()
{
   int x[N] = {1,2,3,4,5,6,7,8,9,10};
   int y[N];
   int i;

   // Multiply by 2 and store in y
   for(i=0; i<N; i++){
      y[i] = x[i] * 2;
   }

   // Print the result
   for(i=0; i<N; i++){
      printf("%d ", y[i]);
   }
   
   return 0;
}