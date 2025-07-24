//FormAI DATASET v1.0 Category: Smart home automation ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
   char command[50];
   int lightsOn = 0;
   int temp = 70;

   printf("Welcome to Smart Home Automation System\n");

   while(1) {
      printf("\nCurrent Temperature: %d\n", temp);
      printf("Lights are currently %s\n", lightsOn ? "on" : "off");

      printf("Enter a command (turn_on_lights, turn_off_lights, set_temperature, exit): ");
      scanf("%s", command);

      if(strcmp(command, "turn_on_lights") == 0) {
         lightsOn = 1;
         printf("Turning on lights...\n");
      } 
      else if(strcmp(command, "turn_off_lights") == 0) {
         lightsOn = 0;
         printf("Turning off lights...\n");
      }
      else if(strcmp(command, "set_temperature") == 0) {
         printf("Enter desired temperature: ");
         scanf("%d", &temp);
         printf("Setting temperature to %d...\n", temp);
      }
      else if(strcmp(command, "exit") == 0) {
         printf("Goodbye!\n");
         break;
      }
      else {
         printf("Invalid command, please try again.\n");
      }
   }

   return 0;
}