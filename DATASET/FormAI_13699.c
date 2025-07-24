//FormAI DATASET v1.0 Category: Smart home automation ; Style: mathematical
#include <stdio.h>

int main() {
   int temperature = 25;
   int lightIntensity = 80;
   int humidity = 65;
   int windowStatus = 0;
   int fanStatus = 0;
   int acStatus = 0;
   int lightStatus = 0;

   /* Smart Home Automation System */

   printf("Current Temperature: %d°C\n", temperature);
   printf("Current Light Intensity: %d%%\n", lightIntensity);
   printf("Current Humidity: %d%%\n", humidity);
   printf("\n");

   /* Check Room Temperature */
   if(temperature > 30) {
      acStatus = 1; /* Turn on AC */
   } else if (temperature < 20) {
      acStatus = 0; /* Turn off AC */
   }

   /* Check Room Light Intensity */
   if(lightIntensity > 75) {
      lightStatus = 0; /* Turn off Lights */
   } else if (lightIntensity < 25) {
      lightStatus = 1; /* Turn on Lights */
   }

   /* Check Room Humidity */
   if(humidity > 70) {
      fanStatus = 1; /* Turn on Fan */
   } else if (humidity < 50) {
      fanStatus = 0; /* Turn off Fan */
   }

   /* Check Window Status */
   if(windowStatus == 1) {
      acStatus = 0; /* Close Window */
   }

   /* Control Room Devices */
   printf("AC Status: %d\n", acStatus);
   printf("Fan Status: %d\n", fanStatus);
   printf("Light Status: %d\n", lightStatus);
   printf("\n");

   return 0;
}