//FormAI DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // Seed the random number generator with the current time
   float temp = (rand() % 11) + 20; // Generate initial "room" temperature between 20 and 30 degrees Celsius
   printf("Current room temperature: %.1fC\n", temp);
   int time_elapsed = 0; // Initialize time elapsed to 0

   while (time_elapsed <= 600) { // Continue monitoring room temperature for 10 minutes
       float temp_change = (rand() % 5) - 2; // Generate random temperature change between -2C and 2C
       temp += temp_change;
       if (temp < 15 || temp > 35) { // Check if temperature is outside acceptable range
           printf("Warning: Room temperature is outside acceptable range. Shutting down monitor.\n");
           break; // Exit the loop and end the program
       }
       printf("Current room temperature: %.1fC\n", temp);
       time_elapsed += 5; // Increment time elapsed by 5 minutes
       sleep(5); // Wait 5 seconds before repeating loop
   }

   if (time_elapsed > 600) { // If loop completes without finding unacceptable temperature, print message and end program
       printf("Monitoring complete. Room temperature stayed within acceptable range for 10 minutes.\n");
   }

   return 0;
}