//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: lively
#include <stdio.h>

#define GRAV_CONST 6.674e-11 // gravitational constant
#define MASS_EARTH 5.97e24   // mass of the Earth
#define RADIUS_EARTH 6371000 // radius of the Earth

int main()
{
  double m1 = MASS_EARTH; // mass of the first celestial body (Earth in this case)
  double m2 = 1000;       // mass of the second celestial body
  double r = RADIUS_EARTH + 100000; // distance between the two celestial bodies (Earth's radius + 100 km)
  double Fg = GRAV_CONST * m1 * m2 / (r * r); // gravitational force between the two celestial bodies
  double a = Fg / m2; // acceleration of the second celestial body

  printf("Gravity Simulation\n\n");

  printf("Celestial body 1 (Earth):\n");
  printf("Mass\t\t%.2e kg\n", m1);
  printf("Radius\t\t%d m\n", RADIUS_EARTH);

  printf("\nCelestial body 2:\n");
  printf("Mass\t\t%.2e kg\n", m2);
  printf("Distance\t%.2e m\n", r);

  printf("\nGravitational Force\n");
  printf("Fg\t\t%.2e N\n", Fg);

  printf("\nAcceleration of Celestial body 2\n");
  printf("a\t\t%.2e m/s2\n", a);

  return 0;
}