//FormAI DATASET v1.0 Category: Smart home automation ; Style: funny
#include <stdio.h>
#include <stdbool.h>

int main() {
  bool living_room_light = false;
  bool kitchen_light = false;
  bool bathroom_light = false;
  bool bedroom_light = false;
  
  printf("Welcome to the Smart Home Automation program!\n\n");
  printf("Please enter the command to turn on/off your lights (living_room, kitchen, bathroom, bedroom): ");
  
  char command[20];
  scanf("%s", command);
  
  if (strcmp(command, "living_room") == 0) {
    if (living_room_light) {
      printf("Turning off the living room light.\n");
      living_room_light = false;
    } else {
      printf("Turning on the living room light.\n");
      living_room_light = true;
    }
  } else if (strcmp(command, "kitchen") == 0) {
    if (kitchen_light) {
      printf("Turning off the kitchen light.\n");
      kitchen_light = false;
    } else {
      printf("Turning on the kitchen light.\n");
      kitchen_light = true;
    }
  } else if (strcmp(command, "bathroom") == 0) {
    if (bathroom_light) {
      printf("Turning off the bathroom light.\n");
      bathroom_light = false;
    } else {
      printf("Turning on the bathroom light.\n");
      bathroom_light = true;
    }
  } else if (strcmp(command, "bedroom") == 0) {
    if (bedroom_light) {
      printf("Turning off the bedroom light.\n");
      bedroom_light = false;
    } else {
      printf("Turning on the bedroom light.\n");
      bedroom_light = true;
    }
  } else {
    printf("Invalid command. Please enter a valid command.\n");
  }
  
  return 0;
}