//FormAI DATASET v1.0 Category: Physics simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int speed_of_light = 299792458;
  int proton_mass = 1.007276;
  int electron_mass = 0.00054858;
  int neutron_mass = 1.008664;

  srand(time(NULL));  // Seed the random number generator

  float energy = rand() % 1000;  // Generate a random energy level between 0 and 999
  printf("Energy level: %.3f MeV\n", energy);

  float kinetic_energy = energy * 1.6e-13;  // Convert to joules
  printf("Kinetic energy: %.3e J\n", kinetic_energy);

  float momentum = sqrt(2 * electron_mass * kinetic_energy);  // Calculate momentum
  printf("Momentum: %.3e kg m/s\n", momentum);

  float velocity = momentum / electron_mass;  // Calculate velocity
  printf("Velocity: %.3e m/s\n", velocity);

  float relativistic_mass = electron_mass / sqrt(1 - (velocity*velocity)/(speed_of_light*speed_of_light));  // Calculate relativistic mass
  printf("Relativistic mass: %.3e kg\n", relativistic_mass);

  float circumference = 2 * 3.14 * (relativistic_mass / (proton_mass + neutron_mass));  // Calculate circumference of a circular accelerator based on the relativistic mass
  printf("Circumference: %.3f m\n", circumference);

  float frequency = speed_of_light / circumference;  // Calculate frequency of the circular accelerator
  printf("Frequency: %.3e Hz\n", frequency);

  return 0;
}