//FormAI DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>
#include <stdbool.h>

bool isLightOn = false;

int main() {
  printf("Welcome to Smart Home Light Control Program!\n");
  
  while (true) {
    printf("Enter 'on' to turn the light on or 'off' to turn the light off: ");
    char userChoice[4];
    scanf("%s", userChoice);
    
    if (strcmp(userChoice, "on") == 0) {
      if (isLightOn) {
        printf("The light is already on!\n");
      } else {
        isLightOn = true;
        printf("***Turning the light on***\n");
      }
    } else if (strcmp(userChoice, "off") == 0) {
      if (!isLightOn) {
        printf("The light is already off!\n");
      } else {
        isLightOn = false;
        printf("***Turning the light off***\n");
      }
    } else {
      printf("Invalid choice!\n");
    }
  }
  
  return 0;
}