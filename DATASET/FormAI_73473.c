//FormAI DATASET v1.0 Category: Smart home automation ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Variables to store the state of different devices
  int bedroom_lamp = 0;
  int living_room_lamp = 0;
  int audio_system = 0;
  int tv = 0;
  int temperature = 25;

  printf("Welcome to Smart Home Automation\n\n");
  
  while (1) {
    // Display the current state of all devices
    printf("Current State\n");
    printf("--------------\n");
    printf("Bedroom Lamp: %s\n", bedroom_lamp ? "ON" : "OFF");
    printf("Living Room Lamp: %s\n", living_room_lamp ? "ON" : "OFF");
    printf("Audio System: %s\n", audio_system ? "ON" : "OFF");
    printf("TV: %s\n", tv ? "ON" : "OFF");
    printf("Temperature: %d\n\n", temperature);
    
    // Prompt the user for input
    printf("Enter your command:\n");
    char command[50];
    fgets(command, 50, stdin);

    // Parse the command
    if (strcmp(command, "bedroom_lamp on\n") == 0) {
      bedroom_lamp = 1;
      printf("Bedroom Lamp is now ON.\n");
    } else if (strcmp(command, "bedroom_lamp off\n") == 0) {
      bedroom_lamp = 0;
      printf("Bedroom Lamp is now OFF.\n");
    } else if (strcmp(command, "living_room_lamp on\n") == 0) {
      living_room_lamp = 1;
      printf("Living Room Lamp is now ON.\n");
    } else if (strcmp(command, "living_room_lamp off\n") == 0) {
      living_room_lamp = 0;
      printf("Living Room Lamp is now OFF.\n");
    } else if (strcmp(command, "audio_system on\n") == 0) {
      audio_system = 1;
      printf("Audio System is now ON.\n");
    } else if (strcmp(command, "audio_system off\n") == 0) {
      audio_system = 0;
      printf("Audio System is now OFF.\n");
    } else if (strcmp(command, "tv on\n") == 0) {
      tv = 1;
      printf("TV is now ON.\n");
    } else if (strcmp(command, "tv off\n") == 0) {
      tv = 0;
      printf("TV is now OFF.\n");
    } else if (strcmp(command, "increase temperature\n") == 0) {
      temperature += 1;
      printf("Temperature increased by 1 degree.\n");
    } else if (strcmp(command, "decrease temperature\n") == 0) {
      temperature -= 1;
      printf("Temperature decreased by 1 degree.\n");
    } else if (strcmp(command, "exit\n") == 0) {
      break;
    } else {
      printf("Unknown command.\n");
    }
  }

  return 0;
}