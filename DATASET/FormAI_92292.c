//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: enthusiastic
#include <stdio.h>

// Define the functions for each direction of the remote control vehicle
void moveForward() {
   printf("Moving forward!\n");
}

void moveBackward() {
   printf("Moving backward!\n");
}

void turnLeft() {
   printf("Turning left!\n");
}

void turnRight() {
   printf("Turning right!\n");
}

int main() {
   // Printing the welcome message
   printf("Welcome to the Remote Control Vehicle Simulation!\n");
   
   // Prompting the user for input
   printf("Please enter a direction (forward, backward, left, right): ");
   
   // Taking the user input
   char direction[10];
   scanf("%s", direction);
   
   // Applying the user input and call corresponding functions
   if (strcmp(direction, "forward") == 0) {
      moveForward();
   } else if (strcmp(direction, "backward") == 0) {
      moveBackward();
   } else if (strcmp(direction, "left") == 0) {
      turnLeft();
   } else if (strcmp(direction, "right") == 0) {
      turnRight();
   } else {
      // Handling unexpected input by printing an error message
      printf("Error: Invalid direction\n");
   }
   
   // Printing the goodbye message
   printf("Thank you for using the Remote Control Vehicle Simulation!\n");
   
   // End of program
   return 0;
}