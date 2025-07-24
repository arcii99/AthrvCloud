//FormAI DATASET v1.0 Category: Smart home automation ; Style: real-life
#include <stdio.h>

int main() {
  // Smart Home Automation example program
  // Simulating a smart home with temperature, lights, and door control
  
  // Initialize variables
  int temperature = 70;
  int lights = 0; // 0 = off, 1 = on
  int door_status = 0; // 0 = closed, 1 = open
  
  // Print initial status
  printf("Smart Home Status:\nTemperature: %dF\nLights: %s\nDoor: %s\n", temperature, lights ? "On" : "Off", door_status ? "Open" : "Closed");
  
  // Adjust temperature 
  temperature -= 10;
  printf("Adjusting temperature to %dF...\n", temperature);
  
  // Turn on lights
  lights = 1;
  printf("Turning on lights...\n");
  
  // Open door
  door_status = 1;
  printf("Opening door...\n");
  
  // Print updated status
  printf("Smart Home Status:\nTemperature: %dF\nLights: %s\nDoor: %s\n", temperature, lights ? "On" : "Off", door_status ? "Open" : "Closed");
  
  // Wait 5 minutes
  printf("Waiting 5 minutes...\n");
  for(int i = 0; i < 300; i++) {
    printf("%d seconds...\n", 300 - i);
  }
  
  // Close door
  door_status = 0;
  printf("Closing door...\n");
  
  // Print final status
  printf("Smart Home Status:\nTemperature: %dF\nLights: %s\nDoor: %s\n", temperature, lights ? "On" : "Off", door_status ? "Open" : "Closed");
  
  return 0;
}