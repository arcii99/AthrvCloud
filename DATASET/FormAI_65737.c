//FormAI DATASET v1.0 Category: Digital signal processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

   int signal[10] = {2, 4, 3, 5, 6, 7, 4, 3, 1, -2};
   int filtered[10] = {0}; 
   
   printf("Starting DSP (Dancing Signal Processing) Program!\n");

   printf("Applying Filter...");

   for (int i = 1; i < 9; i++) { // Applying butter filter 
       filtered[i] = (signal[i-1]+ 2*signal[i] + signal[i+1])/4;
   }

   printf("DONE!\n");
   printf("Testing Filtered Signal...\n");
   for(int i = 0; i < 10; i++) {
       printf("%d, ", filtered[i]); // Displaying filtered signal 
   }
   
   printf("Filtering again but this time with some rhythm...\n");

   int rhythm[10] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0}; // Defining the rhythm pattern 
   int index = 0;

   for(int i = 0; i < 10; i++) {
       filtered[i] = rhythm[index%10] * filtered[i]; // Filtering with rhythm
       index++;
   }

   printf("DONE! Rhythm filter has gone wild on our signal!!!\n");

   printf("Displaying the funky signal...\n");
   
   for(int i = 0; i < 10; i++) {
       printf("%d, ", filtered[i]); // Displaying the funky signal
   }
   
   printf("Exiting DSP Program... Cheers!!!\n");

   return 0; 

}