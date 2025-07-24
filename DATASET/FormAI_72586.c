//FormAI DATASET v1.0 Category: Smart home automation ; Style: introspective
#include <stdio.h>
#include <stdbool.h>

int main() {
   bool isKitchenLightOn = false;  // initializing boolean variable
   bool isACOn = true;
   int temperature = 25;
   
   printf("Welcome to the Smart Home Automation system!\n");

   while(1) {  // infinite loop to keep the program running
      printf("\nEnter 1 to turn on/off the kitchen light.\n");
      printf("Enter 2 to adjust the temperature of the AC.\n");
      printf("Enter 3 to check the status of all devices.\n");
      printf("Enter 4 to exit the program.\n");
      int choice;
      scanf("%d", &choice);

      switch(choice) {
         case 1: 
            if(isKitchenLightOn) {
               printf("Turning off kitchen light.\n");
               isKitchenLightOn = false;
            } else {
               printf("Turning on kitchen light.\n");
               isKitchenLightOn = true;
            }
            break;
         case 2:
            printf("Enter the temperature you'd like to set the AC to: ");
            scanf("%d", &temperature);
            break;
         case 3:
            printf("Kitchen light is currently %s.\n", isKitchenLightOn ? "ON" : "OFF");
            printf("AC is currently %s and set to %d degrees Celsius.\n", isACOn ? "ON" : "OFF", temperature);
            break;
         case 4:
            printf("Exiting program. Goodbye!\n");
            return 0;
         default:
            printf("Invalid input. Please try again.\n");
      }
   }
   return 0;
}