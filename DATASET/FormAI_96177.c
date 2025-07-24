//FormAI DATASET v1.0 Category: Smart home light control ; Style: future-proof
#include <stdio.h>

// Function to turn on the light
void turnOnLight() {
  printf("Light is turned on\n");
}

// Function to turn off the light
void turnOffLight() {
  printf("Light is turned off\n");
}

// Function to control the light based on input
void controlLight(int input) {
  if(input == 0) {
    turnOffLight();
  } else {
    turnOnLight();
  }
}

int main() {
  int input;
  
  printf("Welcome to Smart Home Light Control\n");
  
  while(1) {
    printf("Select an option:\n");
    printf("1. Turn on the light\n");
    printf("0. Turn off the light\n");
    printf("-1. Exit\n");
    
    scanf("%d", &input);
    
    if(input == -1) {
      printf("Thanks for using Smart Home Light Control!\n");
      break;
    } else if(input == 0 || input == 1) {
      controlLight(input);
    } else {
      printf("Invalid input. Please try again.\n");
    }
  }
  
  return 0;
}