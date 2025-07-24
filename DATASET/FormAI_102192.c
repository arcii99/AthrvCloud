//FormAI DATASET v1.0 Category: Smart home light control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int lightStatus = 0;
  int time = 0;

  printf("Welcome to the Smart Home Light Control Program!\n");

  while(1) {
    printf("Current Status: %s\n", lightStatus ? "ON":"OFF");
    printf("Current Time: %d\n", time);

    printf("Enter 1 to turn ON and 0 to turn OFF the light: ");
    scanf("%d", &lightStatus);

    printf("Enter the time in seconds to keep the light: ");
    scanf("%d", &time);

    if(lightStatus == 1) {
      printf("Light is turned ON for %d seconds!\n", time);
      // Code to turn ON the Light
      // For example (We can use any LED in embedded context)
      // digitalWrite(LED_BUILTIN, HIGH); // Turn the LED on (Note that HIGH is the voltage level.
      // delay(time*1000);
      // digitalWrite(LED_BUILTIN, LOW); // Turn the LED off by making the voltage LOW

    } else {
      printf("Light is turned OFF!\n");
      // Code to turn OFF the Light
      // For example (We can use any LED in embedded context)
      // digitalWrite(LED_BUILTIN, LOW); // Turn the LED off (Note that LOW is the voltage level.
    }
  }

  return 0;
}