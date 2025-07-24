//FormAI DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>
#include <stdbool.h>

int main() {
   bool lightOn = false;
   int brightnessLevel = 0;

   printf("Welcome to the Smart Home Light Control System\n");

   while(true) {
      char userInput;

      printf("\nPlease choose an option:\n");
      printf("(a) Turn on/off the light\n");
      printf("(b) Adjust brightness level\n");
      printf("(c) Exit program\n");

      scanf(" %c", &userInput);

      if(userInput == 'a') {
         if(lightOn) {
            printf("Light turned off\n");
            lightOn = false;
         } else {
            printf("Light turned on\n");
            lightOn = true;
         }
      } else if(userInput == 'b') {
         printf("Enter brightness level (0-100): ");
         scanf("%d", &brightnessLevel);

         if(brightnessLevel < 0) {
            brightnessLevel = 0;
         } else if(brightnessLevel > 100) {
            brightnessLevel = 100;
         }

         printf("Brightness level set to %d\n", brightnessLevel);
      } else if(userInput == 'c') {
         printf("Exiting program...\n");
         break;
      } else {
         printf("Invalid input. Please try again.\n");
      }
   }

   return 0;
}