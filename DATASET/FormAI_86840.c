//FormAI DATASET v1.0 Category: Smart home automation ; Style: scientific
/* Smart Home Automation Program */
/* Written by: [Your Name] */
/* Date: [Date] */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
   /* Declare variables */
   int temperature = 0;
   bool motion_detected = false;

   /* Welcome message */
   printf("Welcome to Smart Home Automation!\n");

   /* Ask for temperature */
   printf("Enter current temperature in Celsius: ");
   scanf("%d", &temperature);

   /* Ask for motion detection */
   printf("Is there any motion detected? (0 for no, 1 for yes): ");
   scanf("%d", &motion_detected);

   /* Check if temperature is too high */
   if (temperature > 30) {
      printf("Temperature is too high, turning on air conditioner...\n");
      /* Code to turn on air conditioner */
   }
   else {
      printf("Temperature is within range.\n");
   }

   /* Check if motion is detected */
   if (motion_detected) {
      printf("Motion detected, turning on lights...\n");
      /* Code to turn on lights */
   }
   else {
      printf("No motion detected.\n");
   }

   return 0;
}