//FormAI DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdbool.h>

int main() {
   // Set initial variables to false
   bool isDaytime = false;
   bool isLightOn = false;

   // Check if it is daytime or nighttime
   if (isDaytime == true) {
      // If it is daytime, turn the light off
      isLightOn = false;
      printf("The sun is out, turning off the lights!\n");

   } else {
      // If it is nighttime, turn the light on
      isLightOn = true;
      printf("It's dark outside, time to turn on the lights!\n");
   }

   // Check if the light is on or off
   if (isLightOn == true) {
      // If the light is on, turn it off
      isLightOn = false;
      printf("The light is currently on, turning it off!\n");

   } else {
      // If the light is off, turn it on
      isLightOn = true;
      printf("The light is currently off, turning it on!\n");
   }

   // Final check to make sure the light is on or off
   if (isLightOn == true) {
      printf("The light is on.\n");
   } else {
      printf("The light is off.\n");
   }

   return 0;
}