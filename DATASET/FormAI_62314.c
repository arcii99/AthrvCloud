//FormAI DATASET v1.0 Category: Smart home automation ; Style: surprised
#include <stdio.h>

int main() {
   // Variables to store sensor readings
   int temperature = 25; 
   int humidity = 50;
   int light = 1;

   // Control variables for smart home features
   int ac_on = 0;
   int humidifier_on = 0;
   int light_on = 0;

   printf("Welcome to your Smart Home Automation System!\n");

   // Check temperature and activate AC when temperature is too high
   if (temperature > 30) {
      ac_on = 1;
      printf("It's getting hot in here! AC is now on.\n");
   } else {
      printf("Temperature is comfortable.\n");
   }

   // Check humidity and activate humidifier when humidity is too low
   if (humidity < 40) {
      humidifier_on = 1;
      printf("It's dry in here! Humidifier is now on.\n");
   } else {
      printf("Humidity is good.\n");
   }

   // Check light level and activate light when it's too dark
   if (light == 0) {
      light_on = 1;
      printf("It's dark in here! Light is now on.\n");
   } else {
      printf("Light is already on.\n");
   }

   // Display the status of all smart home features
   printf("AC is %s\n", ac_on ? "on" : "off");
   printf("Humidifier is %s\n", humidifier_on ? "on" : "off");
   printf("Light is %s\n", light_on ? "on" : "off");

   return 0;
}