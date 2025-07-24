//FormAI DATASET v1.0 Category: Robot movement control ; Style: modular
// This is a sample program to demonstrate modular control of a robot movement using C
// These are the header files required for this program
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// These are the function prototypes used in this program
void moveForward(int distance);
void moveBackward(int distance);
void turnRight(int angle);
void turnLeft(int angle);

// This is the main function
int main()
{
   moveForward(5); // Move 5 meters forward
   turnRight(90); // Turn right 90 degrees
   moveBackward(3); // Move 3 meters backward
   turnLeft(45); // Turn left 45 degrees
   
   return 0;
}

// This function moves the robot forward a certain distance
void moveForward(int distance)
{
   printf("Moving forward %d m\n", distance);
   // Insert code to move robot forward
}

// This function moves the robot backward a certain distance
void moveBackward(int distance)
{
   printf("Moving backward %d m\n", distance);
   // Insert code to move robot backward
}

// This function turns the robot right a certain angle
void turnRight(int angle)
{
   printf("Turning right %d degrees\n", angle);
   // Insert code to turn robot right
}

// This function turns the robot left a certain angle
void turnLeft(int angle)
{
   printf("Turning left %d degrees\n", angle);
   // Insert code to turn robot left
}