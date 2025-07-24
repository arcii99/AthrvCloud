//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: inquisitive
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67e-11         // gravitational constant
#define MASS_OF_SUN 2e30   // mass of the sun in kg
#define RADIUS_OF_SUN 695510 // radius of the sun in km

// structure to store properties of a celestial body
typedef struct {
   double mass;           // in kg
   double radius;         // in km
   double position[3];    // in km
   double velocity[3];    // in km/s
} celestial_body;

int main() {
   double time_step = 3600;            // in seconds
   double duration = 3.154e+7 * 10;    // 10 years in seconds
   int num_bodies = 9;                 // number of celestial bodies
   double total_energy = 0;            // total energy for each time step
   double kinetic_energy = 0;          // kinetic energy for each time step
   double potential_energy = 0;        // potential energy for each time step
   double distance = 0;                // distance between two celestial bodies
   int i, j, k;                        // loop iterators
   
   // initialize the celestial bodies
   celestial_body sun = {
      .mass = MASS_OF_SUN,
      .radius = RADIUS_OF_SUN,
      .position = {0, 0, 0},
      .velocity = {0, 0, 0}
   };
   celestial_body mercury = {
      .mass = 3.3e23,
      .radius = 2439.7,
      .position = {-46788000, 0, 0},
      .velocity = {0, -58380, 0}
   };
   celestial_body venus = {
      .mass = 4.87e24,
      .radius = 6051.8,
      .position = {0, 107480000, 0},
      .velocity = {35020, 0, 0}
   };
   celestial_body earth = {
      .mass = 5.97e24,
      .radius = 6371,
      .position = {147095000, 0, 0},
      .velocity = {0, 30200, 0}
   };
   celestial_body mars = {
      .mass = 6.39e23,
      .radius = 3389.5,
      .position = {0, -206620000, 0},
      .velocity = {-26500, 0, 0}
   };
   celestial_body jupiter = {
      .mass = 1.9e27,
      .radius = 69911,
      .position = {778547200, 0, 0},
      .velocity = {0, 13070, 0}
   };
   celestial_body saturn = {
      .mass = 5.68e26,
      .radius = 58232,
      .position = {0, 1433538000, 0},
      .velocity = {9690, 0, 0}
   };
   celestial_body uranus = {
      .mass = 8.68e25,
      .radius = 25362,
      .position = {-2876679081, 0, 0},
      .velocity = {0, -6835, 0}
   };
   celestial_body neptune = {
      .mass = 1.02e26,
      .radius = 24622,
      .position = {0, -4503443661, 0},
      .velocity = {5477, 0, 0}
   };
   
   // put the celestial bodies in an array
   celestial_body celestial_bodies[num_bodies];
   celestial_bodies[0] = sun;
   celestial_bodies[1] = mercury;
   celestial_bodies[2] = venus;
   celestial_bodies[3] = earth;
   celestial_bodies[4] = mars;
   celestial_bodies[5] = jupiter;
   celestial_bodies[6] = saturn;
   celestial_bodies[7] = uranus;
   celestial_bodies[8] = neptune;
   
   // simulation loop
   for (i = 0; i < duration; i += time_step) {
      total_energy = 0;
      kinetic_energy = 0;
      potential_energy = 0;
      // calculate the gravitational force on each celestial body
      for (j = 0; j < num_bodies; j++) {
         double acceleration[3] = {0, 0, 0};
         for (k = 0; k < num_bodies; k++) {
            if (j == k) {
               continue;
            }
            double force = G * celestial_bodies[j].mass * celestial_bodies[k].mass / pow(sqrt(pow(celestial_bodies[j].position[0] - celestial_bodies[k].position[0], 2) + pow(celestial_bodies[j].position[1] - celestial_bodies[k].position[1], 2) + pow(celestial_bodies[j].position[2] - celestial_bodies[k].position[2], 2)), 2);
            acceleration[0] += force * (celestial_bodies[k].position[0] - celestial_bodies[j].position[0]) / pow(sqrt(pow(celestial_bodies[j].position[0] - celestial_bodies[k].position[0], 2) + pow(celestial_bodies[j].position[1] - celestial_bodies[k].position[1], 2) + pow(celestial_bodies[j].position[2] - celestial_bodies[k].position[2], 2)), 2);
            acceleration[1] += force * (celestial_bodies[k].position[1] - celestial_bodies[j].position[1]) / pow(sqrt(pow(celestial_bodies[j].position[0] - celestial_bodies[k].position[0], 2) + pow(celestial_bodies[j].position[1] - celestial_bodies[k].position[1], 2) + pow(celestial_bodies[j].position[2] - celestial_bodies[k].position[2], 2)), 2);
            acceleration[2] += force * (celestial_bodies[k].position[2] - celestial_bodies[j].position[2]) / pow(sqrt(pow(celestial_bodies[j].position[0] - celestial_bodies[k].position[0], 2) + pow(celestial_bodies[j].position[1] - celestial_bodies[k].position[1], 2) + pow(celestial_bodies[j].position[2] - celestial_bodies[k].position[2], 2)), 2);
         }
         celestial_bodies[j].velocity[0] += acceleration[0] * time_step;
         celestial_bodies[j].velocity[1] += acceleration[1] * time_step;
         celestial_bodies[j].velocity[2] += acceleration[2] * time_step;
         celestial_bodies[j].position[0] += celestial_bodies[j].velocity[0] * time_step;
         celestial_bodies[j].position[1] += celestial_bodies[j].velocity[1] * time_step;
         celestial_bodies[j].position[2] += celestial_bodies[j].velocity[2] * time_step;
      }
      // calculate the kinetic and potential energy of the system
      for (j = 0; j < num_bodies; j++) {
         kinetic_energy += 0.5 * celestial_bodies[j].mass * pow(sqrt(pow(celestial_bodies[j].velocity[0], 2) + pow(celestial_bodies[j].velocity[1], 2) + pow(celestial_bodies[j].velocity[2], 2)), 2);
         for (k = j + 1; k < num_bodies; k++) {
            distance = sqrt(pow(celestial_bodies[k].position[0] - celestial_bodies[j].position[0], 2) + pow(celestial_bodies[k].position[1] - celestial_bodies[j].position[1], 2) + pow(celestial_bodies[k].position[2] - celestial_bodies[j].position[2], 2));
            potential_energy -= G * celestial_bodies[j].mass * celestial_bodies[k].mass / distance;
         }
      }
      total_energy = kinetic_energy + potential_energy;
      printf("Kinetic energy at time %is: %lf J\n", i, kinetic_energy);
      printf("Potential energy at time %is: %lf J\n", i, potential_energy);
      printf("Total energy at time %is: %lf J\n\n", i, total_energy);
   }

   return 0;
}