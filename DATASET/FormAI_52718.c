//FormAI DATASET v1.0 Category: Smart home light control ; Style: grateful
#include <stdio.h>

// Function to turn on the lights
void turnOnLights() {
  // Code to send a signal to the smart home system to turn on the lights
  printf("Lights turned on!\n");
}

// Function to turn off the lights
void turnOffLights() {
  // Code to send a signal to the smart home system to turn off the lights
  printf("Lights turned off!\n");
}

// Main function
int main() {
  int choice;
  
  printf("Welcome to Smart Home Light Control!\n");
  printf("Please choose an option:\n");
  printf("1. Turn on lights\n");
  printf("2. Turn off lights\n");
  scanf("%d", &choice);
  
  if (choice == 1) {
    turnOnLights();
  }
  else if (choice == 2) {
    turnOffLights();
  }
  else {
    printf("Invalid choice!\n");
  }
  
  return 0;
}