//FormAI DATASET v1.0 Category: Robot movement control ; Style: automated
#include <stdio.h>

// Define a constant for the maximum possible speed
#define MAX_SPEED 100

// Define a function to calculate the speed adjustment required based on the current and target speeds
int calculateSpeedAdjustment(int currentSpeed, int targetSpeed) {
  return (targetSpeed - currentSpeed) / 2;
}

// Define a function to adjust the robot's speed
void adjustSpeed(int currentSpeed, int targetSpeed) {
  // Calculate the required speed adjustment
  int speedAdjustment = calculateSpeedAdjustment(currentSpeed, targetSpeed);

  // If the adjustment brings the speed below zero, set it to zero
  if (currentSpeed + speedAdjustment < 0) {
    speedAdjustment = -currentSpeed;
  }

  // If the adjustment brings the speed above the maximum, set it to the maximum
  if (currentSpeed + speedAdjustment > MAX_SPEED) {
    speedAdjustment = MAX_SPEED - currentSpeed;
  }

  // Apply the speed adjustment
  int newSpeed = currentSpeed + speedAdjustment;

  printf("Adjusting speed from %d to %d\n", currentSpeed, newSpeed);

  // Do something with the new speed, like communicating it to the robot's hardware
}

int main() {
  // Assume the current speed is zero
  int currentSpeed = 0;

  // Set the target speeds for each movement
  int forwardSpeed = 50;
  int reverseSpeed = -50;
  int leftSpeed = 25;
  int rightSpeed = -25;

  // Move the robot forward
  adjustSpeed(currentSpeed, forwardSpeed);

  // Wait for a second to let the robot move
  sleep(1);

  // Stop the robot
  adjustSpeed(forwardSpeed, 0);

  // Move the robot in reverse
  adjustSpeed(0, reverseSpeed);

  // Wait for a second to let the robot move
  sleep(1);

  // Stop the robot
  adjustSpeed(reverseSpeed, 0);

  // Move the robot to the left
  adjustSpeed(0, leftSpeed);

  // Wait for a second to let the robot move
  sleep(1);

  // Stop the robot
  adjustSpeed(leftSpeed, 0);

  // Move the robot to the right
  adjustSpeed(0, rightSpeed);

  // Wait for a second to let the robot move
  sleep(1);

  // Stop the robot
  adjustSpeed(rightSpeed, 0);

  return 0;
}