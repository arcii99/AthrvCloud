//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Initialize variables
  int speed = 0;
  int steering = 0;
  int rpm = 0;
  int distance = 0;
  
  // Display welcome message
  printf("Welcome to the Remote Control Vehicle Simulation Program!\n");
  
  // Prompt user for input
  printf("Enter the desired speed: ");
  scanf("%d", &speed);
  printf("Enter the steering angle: ");
  scanf("%d", &steering);
  
  // Calculate RPM and distance
  rpm = speed * steering;
  distance = rpm / 10;
  
  // Display results
  printf("The RPM is: %d\n", rpm);
  printf("The distance traveled is: %d meters\n", distance);
  
  return 0;
}