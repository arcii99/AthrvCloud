//FormAI DATASET v1.0 Category: Physics simulation ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

int main() {
  float mass, velocity, force, acceleration;
  float distance = 0;
  int time = 0;
  
  printf("Enter mass of the object in kg: ");
  scanf("%f", &mass);
  
  printf("Enter initial velocity of the object in m/s: ");
  scanf("%f", &velocity);
  
  printf("Enter force applied on the object in N: ");
  scanf("%f", &force);
  
  printf("Enter time interval in seconds: ");
  scanf("%d", &time);
  
  acceleration = force / mass;
  
  printf("\nObject at rest on the ground.");
  
  while (distance <= 100) {
    printf("\nTime %d seconds: Object travelled %.2f meters.", time, distance);
    distance += (velocity * time) + (0.5 * acceleration * pow(time, 2));
    velocity += acceleration * time;
    time++;
  }
  
  printf("\n\nObject stopped due to air resistance.");
  
  return 0;
}