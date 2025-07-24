//FormAI DATASET v1.0 Category: Smart home light control ; Style: energetic
#include <stdio.h>

int main() {
   int light = 0; // initialize light to OFF
   int input; // for user input

   printf("Welcome to Smart Home Light Control!\n");
   printf("Press 1 to turn the light on, or 0 to turn it off.\n");
   printf("Press 2 to exit the program.\n");

   while(1) { // loop until user chooses to exit
      printf("Light Status: %s\n", (light == 0) ? "OFF" : "ON"); // display current light status
      scanf("%d", &input); // get user input

      if(input == 1 && light == 0) { // turn light on
         light = 1;
         printf("Light turned ON!\n");
      }
      else if(input == 0 && light == 1) { // turn light off
         light = 0;
         printf("Light turned OFF!\n");
      }
      else if(input == 2) { // exit program
         printf("Exiting Smart Home Light Control.\n");
         break;
      }
      else {
         printf("Invalid input. Please try again.\n");
      }
   }

   return 0;
}