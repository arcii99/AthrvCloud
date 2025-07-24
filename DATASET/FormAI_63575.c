//FormAI DATASET v1.0 Category: Smart home automation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() { 
  int temp = 0;
  int light = 0;
  int doorLock = 0;
  
  while(1) {
    printf("Enter command: ");
    char command[50];
    
    fgets(command, 50, stdin);
    
    if (strstr(command, "setTemperature")) {
      int newTemp = atoi(strstr(command, " "));
      if (newTemp >= 60 && newTemp <= 80) {
        temp = newTemp;
        printf("Temperature set to %d\n", temp);
      } else {
        printf("Temperature must be between 60 and 80\n");
      }
    } else if (strstr(command, "setLightStatus")) {
      int newLight = atoi(strstr(command, " "));
      if (newLight == 0 || newLight == 1) {
        light = newLight;
        printf("Light status set to %d\n", light);
      } else {
        printf("Light status must be 0 or 1\n");
      }
    } else if (strstr(command, "setDoorLock")) {
      int newLock = atoi(strstr(command, " "));
      if (newLock == 0 || newLock == 1) {
        doorLock = newLock;
        printf("Door lock set to %d\n", doorLock);
      } else {
        printf("Door lock status must be 0 or 1\n");
      }
    } else if (strstr(command, "checkTemperature")) {
      printf("Current temperature is %d\n", temp);
    } else if (strstr(command, "checkLightStatus")) {
      printf("Current light status is %d\n", light);
    } else if (strstr(command, "checkDoorLock")) {
      printf("Current door lock status is %d\n", doorLock);
    } else if (strstr(command, "exit")) {
      break;
    } else {
      printf("Invalid command\n");
    }
  }
  return 0;
}