//FormAI DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include <stdio.h>

int main() {
   int temperature = 25;
   int isLightsOn = 0;
   int isACOn = 0;
   int isSecuritySystemEnabled = 0;
   
   printf("Welcome to Smart Home Automation\n");
   printf("Temperature: %d°C\n", temperature);
   printf("Lights: %s\n", isLightsOn ? "On" : "Off");
   printf("AC: %s\n", isACOn ? "On" : "Off");
   printf("Security System: %s\n", isSecuritySystemEnabled ? "Enabled" : "Disabled");
   
   while (1) {
      printf("\nMenu:\n");
      printf("1. Turn on/off lights\n");
      printf("2. Turn on/off AC\n");
      printf("3. Enable/disable security system\n");
      printf("4. Exit\n");
      
      int choice;
      scanf("%d", &choice);
      
      switch (choice) {
         case 1:
            isLightsOn = !isLightsOn;
            printf("Lights turned %s\n", isLightsOn ? "On" : "Off");
            break;
         case 2:
            isACOn = !isACOn;
            printf("AC turned %s\n", isACOn ? "On" : "Off");
            break;
         case 3:
            isSecuritySystemEnabled = !isSecuritySystemEnabled;
            printf("Security System %s\n", isSecuritySystemEnabled ? "Enabled" : "Disabled");
            break;
         case 4:
            printf("Exiting program\n");
            return 0;
         default:
            printf("Invalid choice, try again\n");
            break;
      }
   }
   
   return 0;
}