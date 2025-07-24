//FormAI DATASET v1.0 Category: Digital signal processing ; Style: happy
#include<stdio.h>
#include<stdlib.h>

int main() {

   printf("Hooray, we are starting the DSP Happy code!\n\n");

   int signal[8] = {1,3,5,7,9,11,13,15};
   int sum = 0;

   printf("Here is our signal:\n");

   for(int i = 0; i < 8; i++){
      printf("%d ", signal[i]);
   }

   printf("\n\nLet's sum up the values in the signal:\n");

   for(int i = 0; i < 8; i++){
      sum += signal[i];
      printf("The current sum is %d\n", sum);
   }

   printf("\nAnd the final sum of our signal is: %d\n", sum);

   printf("\nYay! Our DSP Happy code has successfully executed!");

   return 0;
}