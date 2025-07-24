//FormAI DATASET v1.0 Category: Robot movement control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
   int x = 0, y = 0; // Initialize x and y to 0

   // Loop until the user wants to quit
   while (1) {
      char input; // Variable to store the user input
      
      // Print the current position of the robot
      printf("Current position (x, y): (%d, %d)\n", x, y);
      
      // Ask the user to enter a movement command
      printf("Enter a movement command (u/d/l/r, q to quit): ");
      scanf(" %c", &input); // Read user input
     
      // Process the user input
      switch(input) {
         case 'u':   // Move up
            y++;
            break;
         
         case 'd':   // Move down
            y--;
            break;
         
         case 'l':   // Move left
            x--;
            break;
         
         case 'r':   // Move right
            x++;
            break;
      
         case 'q':   // Quit the program
            printf("Goodbye!\n");
            exit(0); // Exit the program
      
         default:    // Invalid input
            printf("Invalid input, please try again.\n");
            break;
      }
   }
   
   return 0;
}