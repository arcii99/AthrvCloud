//FormAI DATASET v1.0 Category: Smart home automation ; Style: introspective
#include <stdio.h>

int main() {
  printf("Welcome to my smart home automation system!\n");
  
  int lights = 0;
  int temperature = 25;
  
  while (1) {
    printf("Current temperature: %d\n", temperature);
    printf("Lights: ");
    if (lights) {
      printf("ON\n");
    } else {
      printf("OFF\n");
    }
    
    printf("Enter a command (1: turn on lights, 2: turn off lights, 3: increase temperature, 4: decrease temperature): ");
    int command;
    scanf("%d", &command);
    
    switch (command) {
      case 1:
        lights = 1;
        break;
      case 2:
        lights = 0;
        break;
      case 3:
        temperature += 1;
        break;
      case 4:
        temperature -= 1;
        break;
      default:
        printf("Invalid command!\n");
        continue;
    }
  }
  
  return 0;
}