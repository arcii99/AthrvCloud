//FormAI DATASET v1.0 Category: Smart home light control ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
  char response[20];
  int lightStatus = 0; // 0 means off, 1 means on

  while(1) {
    printf("Enter a command (on/off/quit): ");
    scanf("%s", response);
    
    if(strcmp(response, "on") == 0) {
      if(lightStatus == 0) { // If the light is off
        lightStatus = 1; // Turn the light on
        printf("The light is now on.\n");
      } else {
        printf("The light is already on.\n");
      }
    } else if(strcmp(response, "off") == 0) {
      if(lightStatus == 1) { // If the light is on
        lightStatus = 0; // Turn the light off
        printf("The light is now off.\n");
      } else {
        printf("The light is already off.\n");
      }
    } else if(strcmp(response, "quit") == 0) {
      printf("Goodbye!\n");
      break; // Exit the loop
    } else {
      printf("Invalid command. Please try again.\n");
    }
  }

  return 0;
}