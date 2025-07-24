//FormAI DATASET v1.0 Category: Robot movement control ; Style: Ada Lovelace
#include <stdio.h>

#define PI 3.141592653589793

// Define the motion parameters
double wheel_radius = 2.5;  // cm
double axle_length = 15.0;  // cm
double motor_speed = 40.0;  // rpm
double time_step = 0.1;     // s

// Define the robot state
double x = 0.0;   // cm
double y = 0.0;   // cm
double theta = 0.0;  // rad

// Define the movement functions
void forward(double distance) {
  int num_steps = (int)(distance / (2.0 * PI * wheel_radius) * 360.0);
  double step_distance = 2.0 * PI * wheel_radius / 360.0;
  for (int i = 0; i < num_steps; i++) {
    x += step_distance * cos(theta);
    y += step_distance * sin(theta);
    printf("Moving forward to (%f, %f)\n", x, y);
  }
}

void turn(double angle) {
  int num_steps = (int)(angle / (2.0 * PI * axle_length) * 360.0);
  double step_angle = 2.0 * PI * axle_length / 360.0 / wheel_radius;
  for (int i = 0; i < num_steps; i++) {
    theta += step_angle;
    printf("Turning to %f radians\n", theta);
  }
}

int main() {
  // Move the robot forward and turn
  forward(10.0);
  turn(PI / 2.0);
  forward(5.0);
  turn(-PI / 4.0);
  forward(7.0);
  turn(3.0 * PI / 4.0);

  return 0;
}