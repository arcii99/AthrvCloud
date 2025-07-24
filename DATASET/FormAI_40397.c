//FormAI DATASET v1.0 Category: Physics simulation ; Style: satisfied
#include<stdio.h>

#define G 6.67e-11 // Gravitational constant

// Define a structure for planets
typedef struct {
  char name[20];
  double mass;
  double x, y;
  double vx, vy;
} Planet;

// Function to calculate the distance between two planets
double distance(Planet p1, Planet p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return sqrt(dx*dx + dy*dy);
}

// Function to calculate the gravitational force between two planets
double force(Planet p1, Planet p2) {
  double r = distance(p1, p2);
  return G * p1.mass * p2.mass / (r*r);
}

// Function to calculate the acceleration of a planet due to other planets
void acceleration(Planet p, Planet others[], int n, double *ax, double *ay) {
  *ax = 0.0;
  *ay = 0.0;
  for (int i = 0; i < n; i++) {
    if (strcmp(others[i].name, p.name) == 0) continue;
    double f = force(p, others[i]);
    double r = distance(p, others[i]);
    *ax += f * (others[i].x - p.x) / (p.mass * r);
    *ay += f * (others[i].y - p.y) / (p.mass * r);
  }
}

// Function to update the position and velocity of a planet
void update(Planet *p, double ax, double ay, double dt) {
  p->vx += ax * dt;
  p->vy += ay * dt;
  p->x += p->vx * dt;
  p->y += p->vy * dt;
}

int main() {
  
  // Set the number of planets and simulation time
  int n = 2;
  double t_sim = 86400.0; // One day in seconds

  // Initialize the planets
  Planet planets[n];
  strcpy(planets[0].name, "Earth");
  planets[0].mass = 5.97e24;
  planets[0].x = 0.0;
  planets[0].y = 0.0;
  planets[0].vx = 0.0;
  planets[0].vy = 0.0;
  strcpy(planets[1].name, "Moon");
  planets[1].mass = 7.34e22;
  planets[1].x = 3.84e8;
  planets[1].y = 0.0;
  planets[1].vx = 0.0;
  planets[1].vy = 1022.0;

  // Simulation parameters
  double dt = 60.0; // Time step in seconds
  int n_steps = (int)(t_sim / dt); // Number of simulation steps

  // Simulation loop
  for (int step = 0; step < n_steps; step++) {

    // Calculate the acceleration of each planet
    double ax[n], ay[n];
    for (int i = 0; i < n; i++) {
      acceleration(planets[i], planets, n, &ax[i], &ay[i]);
    }

    // Update the position and velocity of each planet
    for (int i = 0; i < n; i++) {
      update(&planets[i], ax[i], ay[i], dt);
    }

    // Print the position and velocity of each planet
    for (int i = 0; i < n; i++) {
      printf("%s: (%.2f, %.2f)\t(%.2f, %.2f)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
    }

  }
  
  return 0;
}