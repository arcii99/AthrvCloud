//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
   int temperature = 25; // default temperature
   int isLightOn = 0; // 0 means light is off
   
   printf("Welcome to the Smart Home Automation System!\n");
   
   while(1) {
       int option;
       printf("\nWhat would you like to do?\n");
       printf("1. Adjust Temperature\n");
       printf("2. Turn On/Off Light\n");
       printf("3. Quit\n");
       printf("Enter option number: ");
       scanf("%d", &option);
       
       switch(option) {
           case 1:
               printf("Enter new temperature: ");
               scanf("%d", &temperature);
               printf("Temperature set to %d degrees Celsius.\n", temperature);
               break;
           case 2:
               if(isLightOn == 0) {
                   printf("Turning on light.\n");
                   isLightOn = 1;
               }
               else {
                   printf("Turning off light.\n");
                   isLightOn = 0;
               }
               break;
           case 3:
               printf("Exiting Smart Home Automation System. Goodbye!\n");
               exit(0);
           default:
               printf("Invalid option selected. Please try again.\n");
               break;
       }
   }
   
   return 0;
}