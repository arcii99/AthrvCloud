//FormAI DATASET v1.0 Category: Smart home light control ; Style: creative
#include <stdio.h>
#include <stdlib.h>

/* Smart home light control example program */

int main() {

   /* Welcome message */
   printf("Welcome to the smart home light control program!\n\n");

   /* Initialize light status */
   int lightsOn = 0;

   /* User input loop */
   while (1) {
      /* Print current status */
      if (lightsOn) {
         printf("The lights are currently on.\n");
      } else {
         printf("The lights are currently off.\n");
      }
      
      /* Get user input */
      printf("Do you want to turn the lights on or off? (enter 'on' or 'off')\n");
      char input[10];
      fgets(input, 10, stdin);

      /* Process user input */
      if (strcmp(input, "on\n") == 0) {
         if (!lightsOn) {
            printf("Turning the lights on...\n");
            /* Code to turn the lights on goes here */
            lightsOn = 1;
         } else {
            printf("The lights are already on.\n");
         }
      } else if (strcmp(input, "off\n") == 0) {
         if (lightsOn) {
            printf("Turning the lights off...\n");
            /* Code to turn the lights off goes here */
            lightsOn = 0;
         } else {
            printf("The lights are already off.\n");
         }
      } else {
         printf("Invalid input. Please enter 'on' or 'off'.\n");
      }
      
      printf("\n");
   }
   
   return 0;
}