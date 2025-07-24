//FormAI DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for light control system
struct Light {
   int lightOn; // 1 if light is on, 0 if light is off
   int intensity; // 0 if light is off, 1-10 for intensity level
   char color[20]; // string value for light color
} livingRoomLight, bedroomLight, kitchenLight;

int main() {
   // Initialize living room light
   livingRoomLight.lightOn = 0;
   livingRoomLight.intensity = 0;
   strcpy(livingRoomLight.color, "white");

   // Initialize bedroom light
   bedroomLight.lightOn = 0;
   bedroomLight.intensity = 0;
   strcpy(bedroomLight.color, "white");

   // Initialize kitchen light
   kitchenLight.lightOn = 0;
   kitchenLight.intensity = 0;
   strcpy(kitchenLight.color, "white");

   // Print welcome message and available commands
   printf("Welcome to the Smart Home Light Control System!\n");
   printf("Available commands:\n");
   printf("- turn on/off {living room/bedroom/kitchen} light\n");
   printf("- set {living room/bedroom/kitchen} light intensity {1-10}\n");
   printf("- set {living room/bedroom/kitchen} light color {white/red/blue/green}\n");
   printf("- exit\n");

   // Start loop for user input
   while (1) {
      char command[50];
      char item[50];
      char value[50];

      // Read user input
      printf("Enter command: ");
      scanf("%s %s %s", command, item, value);

      // Process user input
      if (strcmp(command, "turn") == 0 && strcmp(item, "on/off") == 0) {
         // Turn light on/off
         if (strcmp(value, "living") == 0) {
            printf("Living room light turned %s!\n", livingRoomLight.lightOn ? "off" : "on");
            livingRoomLight.lightOn = !livingRoomLight.lightOn;
         } else if (strcmp(value, "bedroom") == 0) {
            printf("Bedroom light turned %s!\n", bedroomLight.lightOn ? "off" : "on");
            bedroomLight.lightOn = !bedroomLight.lightOn;
         } else if (strcmp(value, "kitchen") == 0) {
            printf("Kitchen light turned %s!\n", kitchenLight.lightOn ? "off" : "on");
            kitchenLight.lightOn = !kitchenLight.lightOn;
         } else {
            printf("Invalid item!\n");
         }
      } else if (strcmp(command, "set") == 0 && strcmp(item, "light") == 0 && strcmp(value, "intensity") == 0) {
         // Set light intensity
         int intensity;
         if (strcmp(item, "living") == 0) {
            intensity = atoi(value);
            if (intensity >= 0 && intensity <= 10) {
               printf("Living room light intensity set to %d!\n", intensity);
               livingRoomLight.intensity = intensity;
            } else {
               printf("Invalid intensity level!\n");
            }
         } else if (strcmp(value, "bedroom") == 0) {
            intensity = atoi(value);
            if (intensity >= 0 && intensity <= 10) {
               printf("Bedroom light intensity set to %d!\n", intensity);
               bedroomLight.intensity = intensity;
            } else {
               printf("Invalid intensity level!\n");
            }
         } else if (strcmp(value, "kitchen") == 0) {
            intensity = atoi(value);
            if (intensity >= 0 && intensity <= 10) {
               printf("Kitchen light intensity set to %d!\n", intensity);
               kitchenLight.intensity = intensity;
            } else {
               printf("Invalid intensity level!\n");
            }
         } else {
            printf("Invalid item!\n");
         }
      } else if (strcmp(command, "set") == 0 && strcmp(item, "light") == 0 && strcmp(value, "color") == 0) {
         // Set light color
         if (strcmp(item, "living") == 0) {
            if (strcmp(value, "white") == 0 || strcmp(value, "red") == 0 || strcmp(value, "blue") == 0 || strcmp(value, "green") == 0) {
               printf("Living room light color set to %s!\n", value);
               strcpy(livingRoomLight.color, value);
            } else {
               printf("Invalid color!\n");
            }
         } else if (strcmp(value, "bedroom") == 0) {
            if (strcmp(value, "white") == 0 || strcmp(value, "red") == 0 || strcmp(value, "blue") == 0 || strcmp(value, "green") == 0) {
               printf("Bedroom light color set to %s!\n", value);
               strcpy(bedroomLight.color, value);
            } else {
               printf("Invalid color!\n");
            }
         } else if (strcmp(value, "kitchen") == 0) {
            if (strcmp(value, "white") == 0 || strcmp(value, "red") == 0 || strcmp(value, "blue") == 0 || strcmp(value, "green") == 0) {
               printf("Kitchen light color set to %s!\n", value);
               strcpy(kitchenLight.color, value);
            } else {
               printf("Invalid color!\n");
            }
         } else {
            printf("Invalid item!\n");
         }
      } else if (strcmp(command, "exit") == 0) {
         // Exit program
         printf("Exiting Smart Home Light Control System...\n");
         break;
      } else {
         printf("Invalid command!\n");
      }
   }

   return 0;
}