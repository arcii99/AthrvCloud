//FormAI DATASET v1.0 Category: Smart home automation ; Style: innovative
#include <stdio.h>

int main() {
   int temp, light;
   char door;

   printf("Welcome to our Smart Home Automation System!\n");

   printf("What is the current temperature in your home? (in Celsius)\n");
   scanf("%d", &temp);
   if (temp > 25) {
      printf("The temperature is too high! Turning on the air conditioner...\n");
      // Code to turn on the air conditioner
   } else if (temp < 18) {
      printf("The temperature is too low! Turning on the heater...\n");
      // Code to turn on the heater
   } else {
      printf("The temperature is just right. No action needed.\n");
   }

   printf("How bright is the light in your living room? (in lumens)\n");
   scanf("%d", &light);
   if (light < 500) {
      printf("It's too dark. Turning on the lights...\n");
      // Code to turn on the lights
   } else if (light > 1000) {
      printf("It's too bright. Dimming the lights...\n");
      // Code to dim the lights
   } else {
      printf("The lighting is just right. No action needed.\n");
   }

   printf("Is your front door locked? (y/n)\n");
   scanf(" %c", &door);
   if (door == 'n' || door == 'N') {
      printf("The door is unlocked. Locking the door...\n");
      // Code to lock the door
   } else {
      printf("The door is already locked. No action needed.\n");
   }

   printf("Thank you for using our Smart Home Automation System.\n");
   return 0;
}