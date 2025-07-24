//FormAI DATASET v1.0 Category: Smart home automation ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main() {
  char command[20];
  printf("Welcome to Smart Home Automation!\n");
  
  while(1) {
    printf("Enter command (e.g. turn on lights, lock door): ");
    scanf("%[^\n]%*c", &command);
    
    if (strstr(command, "turn on lights")) {
      printf("Turning on lights...\n");
      // code to turn on lights
    } else if (strstr(command, "turn off lights")) {
      printf("Turning off lights...\n");
      // code to turn off lights
    } else if (strstr(command, "lock door")) {
      printf("Locking door...\n");
      // code to lock door
    } else if (strstr(command, "unlock door")) {
      printf("Unlocking door...\n");
      // code to unlock door
    } else if (strstr(command, "play music")) {
      printf("Playing music...\n");
      // code to play music
    } else {
      printf("Command not recognized!\n");
    }
  }
  
  return 0;
}