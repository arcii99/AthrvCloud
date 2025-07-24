//FormAI DATASET v1.0 Category: Physics simulation ; Style: Romeo and Juliet
#include<stdio.h>
#include<math.h>

int main()
{
  float mass = 1.2;       // kg
  float velocity = 5.0;   // m/s
  float height = 10.0;    // m
  float gravity = 9.81;   // m/s^2
  float force, energy, time, displacement;

  // Calculate force and energy
  force = mass * gravity;
  energy = mass * gravity * height;

  // Calculate time and displacement
  time = sqrt(2 * height / gravity);
  displacement = velocity * time;

  // Display results
  printf("Force = %f N\n", force);
  printf("Energy = %f J\n", energy);
  printf("Time of fall = %f s\n", time);
  printf("Displacement = %f m\n", displacement);

  return 0;
}