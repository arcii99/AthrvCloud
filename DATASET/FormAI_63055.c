//FormAI DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   float temp;
   time_t t;
   // Intialize random number generator
   srand((unsigned) time(&t)); 

   // Generate random temperature readings between 20 to 40 degrees centigrade
   temp = (rand() % 21) + 20; 

   // Display the current temperature reading
   printf("Current Temperature: %.2f degrees Celsius\n", temp);

   // Check if temperature exceeds a specified threshold and alert if necessary
   if (temp > 30.0)
   {
       printf("WARNING: Temperature is higher than 30 degrees Celsius!\n");
   }

   return 0;
}