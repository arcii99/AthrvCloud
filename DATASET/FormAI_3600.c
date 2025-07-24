//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
   int red = 1, yellow = 0, green = 0;
   int timer = 0, limit = 20; // limit is the max time for each signal
   
   srand(time(0)); // Seeeding the random number generator
   
   while(1) 
   {
      // Print traffic light signals
      printf("-------Traffic Light Controller-------\n");
      printf("| Red: %d | Yellow: %d | Green: %d |\n", red, yellow, green);
      
      // Check if it's time to switch signal
      if(timer >= limit) 
      {
         timer = 0; // Reset the timer
         int next_signal = rand() % 3; // Randomly select the next signal
         
         // Set the new signal based on the randomly selected number
         switch(next_signal) 
         {
            case 0: // Red
               red = 1; yellow = 0; green = 0;
               printf("Signal changed to: Red\n");
               break;
            case 1: // Yellow
               red = 0; yellow = 1; green = 0;
               printf("Signal changed to: Yellow\n");
               break;
            case 2: // Green
               red = 0; yellow = 0; green = 1;
               printf("Signal changed to: Green\n");
               break;
         }
      }
      
      timer++; // Increment timer
      printf("Duration: %d s \n", timer);
      
      // Wait for 1 second before printing the signal again
      sleep(1);
   }
   
   return 0;
}