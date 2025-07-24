//FormAI DATASET v1.0 Category: Robot movement control ; Style: automated
#include <stdio.h>

/* Function prototypes */
void move_forward(int steps);
void move_backward(int steps);
void turn_left(int degrees);
void turn_right(int degrees);

int main() {
   move_forward(5);   // Move 5 steps forward
   turn_left(90);     // Turn left 90 degrees
   move_backward(3);  // Move 3 steps backward
   turn_right(45);    // Turn right 45 degrees
   
   return 0;
}

/* Move the robot forward a given number of steps */
void move_forward(int steps) {
   printf("Moving robot forward %d steps.\n", steps);
   // Code to control movement
}

/* Move the robot backward a given number of steps */
void move_backward(int steps) {
   printf("Moving robot backward %d steps.\n", steps);
   // Code to control movement
}

/* Turn the robot left a given number of degrees */
void turn_left(int degrees) {
   printf("Turning robot left %d degrees.\n", degrees);
   // Code to control movement
}

/* Turn the robot right a given number of degrees */
void turn_right(int degrees) {
   printf("Turning robot right %d degrees.\n", degrees);
   // Code to control movement
}