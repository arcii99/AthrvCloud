//FormAI DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define pi as a constant
const double pi = 3.14159;

// Define a struct to hold the position and orientation of the robot
struct robot {
  double x, y; // Cartesian coordinates of the robot
  double heading; // Robot's orientation, in radians
};

// Define a function to move the robot forward by a distance
void move_forward(struct robot *r, double distance) {
  // Update the robot's position based on its orientation and distance
  r->x += distance * cos(r->heading);
  r->y += distance * sin(r->heading);
}

// Define a function to turn the robot by an angle
void turn(struct robot *r, double angle) {
  // Update the robot's orientation based on the given angle
  r->heading += angle;

  // Normalize the orientation to be within the range [0, 2*pi]
  while (r->heading >= 2*pi) {
    r->heading -= 2*pi;
  }
  while (r->heading < 0) {
    r->heading += 2*pi;
  }
}

int main() {
  // Create a new robot at position (0,0) and initial orientation of pi/4
  struct robot r = {0, 0, pi/4.0};

  // Move the robot forward by 10 units
  move_forward(&r, 10);

  // Turn the robot by an angle of pi/2
  turn(&r, pi/2.0);

  // Move the robot forward by 10 units
  move_forward(&r, 10);

  // Print the final position and orientation of the robot
  printf("Robot is at position (%f,%f) with heading %f radians\n", r.x, r.y, r.heading);

  return 0;
}