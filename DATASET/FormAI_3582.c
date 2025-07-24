//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: mind-bending
#include <stdio.h>
#include <math.h>

int main() {
  double time, dt, pos_x, pos_y, vel_x, vel_y, mass, net_force_x, net_force_y, distance, force_magnitude;
  double sun_pos_x = 0, sun_pos_y = 0, sun_mass = 1.989E30;
  double earth_pos_x = 1.471E11, earth_pos_y = 0, earth_mass = 5.972E24, earth_vel_x = 0, earth_vel_y = 3E4;
  double moon_pos_x = 1.471E11 + 3.84E8, moon_pos_y = 0, moon_mass = 7.342E22, moon_vel_x = 0, moon_vel_y = 1E3;

  printf("\n\nSimulation of the Solar System\n\n");

  printf("Enter the duration of the simulation (in seconds): ");
  scanf("%lf", &time);

  printf("Enter the time step (in seconds): ");
  scanf("%lf", &dt);

  while (time > 0) {
    // Calculate net force on Earth from Sun
    distance = sqrt(pow(earth_pos_x - sun_pos_x, 2) + pow(earth_pos_y - sun_pos_y, 2));
    force_magnitude = 6.67E-11 * (earth_mass * sun_mass) / pow(distance, 2);
    net_force_x = force_magnitude * (sun_pos_x - earth_pos_x) / distance;
    net_force_y = force_magnitude * (sun_pos_y - earth_pos_y) / distance;

    // Calculate net force on Moon from Earth
    distance = sqrt(pow(moon_pos_x - earth_pos_x, 2) + pow(moon_pos_y - earth_pos_y, 2));
    force_magnitude = 6.67E-11 * (moon_mass * earth_mass) / pow(distance, 2);
    net_force_x += force_magnitude * (earth_pos_x - moon_pos_x) / distance;
    net_force_y += force_magnitude * (earth_pos_y - moon_pos_y) / distance;

    // Update Earth's velocity and position
    vel_x += net_force_x / earth_mass * dt;
    vel_y += net_force_y / earth_mass * dt;
    earth_pos_x += vel_x * dt;
    earth_pos_y += vel_y * dt;

    // Calculate net force on Moon from Sun
    distance = sqrt(pow(moon_pos_x - sun_pos_x, 2) + pow(moon_pos_y - sun_pos_y, 2));
    force_magnitude = 6.67E-11 * (moon_mass * sun_mass) / pow(distance, 2);
    net_force_x = force_magnitude * (sun_pos_x - moon_pos_x) / distance;
    net_force_y = force_magnitude * (sun_pos_y - moon_pos_y) / distance;

    // Calculate net force on Moon from Earth
    distance = sqrt(pow(moon_pos_x - earth_pos_x, 2) + pow(moon_pos_y - earth_pos_y, 2));
    force_magnitude = 6.67E-11 * (moon_mass * earth_mass) / pow(distance, 2);
    net_force_x += force_magnitude * (earth_pos_x - moon_pos_x) / distance;
    net_force_y += force_magnitude * (earth_pos_y - moon_pos_y) / distance;

    // Update Moon's velocity and position
    moon_vel_x += net_force_x / moon_mass * dt;
    moon_vel_y += net_force_y / moon_mass * dt;
    moon_pos_x += moon_vel_x * dt;
    moon_pos_y += moon_vel_y * dt;

    time -= dt;
  }

  printf("\nPositions of the bodies after the simulation:\n\n");
  printf("Sun: (%.2e, %.2e)\n", sun_pos_x, sun_pos_y);
  printf("Earth: (%.2e, %.2e)\n", earth_pos_x, earth_pos_y);
  printf("Moon: (%.2e, %.2e)\n\n", moon_pos_x, moon_pos_y);

  return 0;
}