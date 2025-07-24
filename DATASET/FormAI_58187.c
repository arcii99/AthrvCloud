//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Drone Remote Control Example Program!\n");
  printf("Initializing...\n");
  printf("Press 1 to take off and 0 to land\n");

  int isFlying = 0;

  while(1) {
    int userInput;
    printf("Enter a command: ");
    scanf("%d", &userInput);

    if(userInput == 1 && !isFlying) {
      isFlying = 1;
      printf("Taking off...\n");
    } else if(userInput == 0 && isFlying) {
      isFlying = 0;
      printf("Landing...\n");
    } else if(userInput == 3) {
      printf("Depth: %d meters\n", rand() % 101);
      printf("Temperature: %d Celsius\n", rand() % 50);
    } else if(userInput == 4) {
      printf("Battery Level: %d%%\n", rand() % 101);
    } else if(userInput == 5) {
      printf("Distance from Home: %d meters\n", rand() % 501);
    } else if(userInput == 6) {
      printf("Turning left...\n");
    } else if(userInput == 7) {
      printf("Turning right...\n");
    } else if(userInput == 8) {
      printf("Going forward...\n");
    } else if(userInput == 9) {
      printf("Going backward...\n");
    } else {
      printf("Invalid command. Please try again.\n");
    }
  }
  
  return 0;
}