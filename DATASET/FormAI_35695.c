//FormAI DATASET v1.0 Category: Smart home light control ; Style: visionary
#include <stdio.h>
#include <stdbool.h>

int main() {
  int lightIntensity = 0;
  bool isLightOn = false;

  printf("Welcome to the Smart Home Light Control System!\n");
  
  while (true) {
    printf("Current light intensity: %d\n", lightIntensity);
    printf("Is the light on? %s\n", isLightOn ? "Yes" : "No");
    printf("Enter a command (turn on, turn off, adjust [number]): ");

    char command[10];
    scanf("%s", command);

    if (strcmp(command, "turn on") == 0) {
      isLightOn = true;
      lightIntensity = 100;
      printf("Light turned on!\n");
    } else if (strcmp(command, "turn off") == 0) {
      isLightOn = false;
      lightIntensity = 0;
      printf("Light turned off!\n");
    } else if (strncmp(command, "adjust", 6) == 0) {
      int intensity = atoi(command + 7);

      if (intensity >= 0 && intensity <= 100) {
        lightIntensity = intensity;
        printf("Light intensity adjusted to %d!\n", intensity);
      } else {
        printf("Please enter a number between 0 and 100.\n");
      }
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}