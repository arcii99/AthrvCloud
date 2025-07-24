//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int signal_time[3] = {10, 5, 15}; // array to hold the time for each signal, 0-indexed as Red, Yellow, Green
   int current_signal = 0; // starting signal is Red (0-indexed)
   
   printf("Starting Traffic Light Controller program...\n\n");
   
   while (1) // infinite loop to keep the program running until interrupted
   {
      printf("Signal for %d seconds: ", signal_time[current_signal]);
      
      for (int i = signal_time[current_signal]; i > 0; i--) // loop to countdown the signal time
      {
         printf("%d ", i); // print the remaining time
         sleep(1); // wait for 1 second
      }
      
      printf("\n");
      
      current_signal = (current_signal + 1) % 3; // move to the next signal (circular array)
   }
   
   return 0;
}