//FormAI DATASET v1.0 Category: Smart home light control ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// This is a function to turn on the lights
void turnOnLights(bool *lightsOn) {
  *lightsOn = true;
  printf("Lights are now turned on.\n");
}

// This is a function to turn off the lights
void turnOffLights(bool *lightsOn) {
  *lightsOn = false;
  printf("Lights are now turned off.\n");
}

// This is the main function that will run the program
int main() {
  // Initialize a boolean variable to check if the lights are on
  bool lightsOn = false;
  
  // Print out the initial state of the lights
  printf("The lights are currently %s.\n", lightsOn ? "on" : "off");
  
  // Ask the user if they want to turn on or off the lights
  printf("Do you want to turn on or off the lights?\n");
  
  // Create a char array to store the user's input
  char userInput[10];
  
  // Get the user's input and remove newline character
  fgets(userInput, 10, stdin);
  userInput[strcspn(userInput, "\n")] = 0;
  
  // Check if the user wants to turn on the lights
  if (strcmp(userInput, "on") == 0) {
    turnOnLights(&lightsOn);
  } 
  // Check if the user wants to turn off the lights
  else if (strcmp(userInput, "off") == 0) {
    turnOffLights(&lightsOn);
  } 
  // If the user's input is invalid, print out an error message
  else {
    printf("Invalid input. Please enter 'on' or 'off'.\n");
  }
  
  // Print out the state of the lights after the user's input has been processed
  printf("The lights are now %s.\n", lightsOn ? "on" : "off");
  
  return 0;
}