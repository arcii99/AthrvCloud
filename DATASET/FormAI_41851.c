//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11   // gravitational constant
#define TIME_STEP 1.0  // seconds
#define DELTA_TIME 86400 // day (in seconds)

// defining a struct to hold planet attributes
typedef struct planet {
   char name[20];
   double mass;
   double px;
   double py;
   double pz;
   double vx;
   double vy;
   double vz;
} Planet;

// function to calculate distance between two planets
double distance(Planet p1, Planet p2) {
   double x_diff = p2.px - p1.px;
   double y_diff = p2.py - p1.py;
   double z_diff = p2.pz - p1.pz;
   return sqrt(pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2));
}

// function to calculate gravitational force between two planets
double force(Planet p1, Planet p2) {
   double dist = distance(p1, p2);
   return (G * p1.mass * p2.mass) / pow(dist, 2);
}

// function to calculate acceleration of a planet due to gravitational forces
double acceleration(Planet p, Planet *planets, int num_planets) {
   double accel = 0.0;
   for(int i = 0; i < num_planets; i++) {
      if(strcmp(planets[i].name, p.name) != 0) {
         accel += force(p, planets[i]) / p.mass;
      }
   }
   return accel;
}

// function to update position and velocity of a planet based on acceleration and time
void update_planet(Planet *p, Planet *planets, int num_planets, double dt) {
   // calculating new velocity based on acceleration and time
   double ax = acceleration(*p, planets, num_planets);
   p->vx += ax * dt;
   double ay = acceleration(*p, planets, num_planets);
   p->vy += ay * dt;
   double az = acceleration(*p, planets, num_planets);
   p->vz += az * dt;

   // calculating new position based on velocity and time
   p->px += p->vx * dt;
   p->py += p->vy * dt;
   p->pz += p->vz * dt;
}

int main() {
   // creating an array of planets
   Planet solar_system[6] = {
      {"Sun", 1.989e30, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
      {"Mercury", 0.330e24, -5.791e10, 0.0, 0.0, 0.0, 47.87e3, 0.0},
      {"Venus", 4.87e24, -1.082e11, 0.0, 0.0, 0.0, 35.02e3, 0.0},
      {"Earth", 5.97e24, -1.496e11, 0.0, 0.0, 0.0, 29.78e3, 0.0},
      {"Mars", 0.642e24, -2.279e11, 0.0, 0.0, 0.0, 24.07e3, 0.0},
      {"Jupiter", 1.898e27, -7.788e11, 0.0, 0.0, 0.0, 13.07e3, 0.0}
   };

   // simulating the gravity motion for 365 days
   for(int t = 0; t < DELTA_TIME; t += TIME_STEP) {
      // updating the positions and velocity of all planets
      for(int i = 0; i < 6; i++) {
         update_planet(&solar_system[i], solar_system, 6, TIME_STEP);
      }
   }

   // outputting the final positions of all planets
   for(int i = 0; i < 6; i++) {
      printf("%s position: (%.2f, %.2f, %.2f)\n", solar_system[i].name, solar_system[i].px, solar_system[i].py, solar_system[i].pz);
   }
   return 0;
}