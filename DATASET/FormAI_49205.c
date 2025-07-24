//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define G 6.67e-11 // Gravitational constant

typedef struct {
  double x, y;
} Vector2;

typedef struct {
  Vector2 position, velocity, acceleration;
  double mass;
} Body;

// Function to calculate distance between two bodies
double distance(Body* body1, Body* body2) {
  double x_diff = body2->position.x - body1->position.x;
  double y_diff = body2->position.y - body1->position.y;
  double dist = sqrt(pow(x_diff, 2.0) + pow(y_diff, 2.0));
  return dist;
}

// Function to calculate force between two bodies
Vector2 force(Body* body1, Body* body2) {
  Vector2 force_vect;
  double dist = distance(body1, body2);
  double f = (G * body1->mass * body2->mass) / pow(dist, 2.0);
  force_vect.x = f * (body2->position.x - body1->position.x) / dist;
  force_vect.y = f * (body2->position.y - body1->position.y) / dist;
  return force_vect;
}

// Function to update velocity and position of a body
void update_body(Body* body, double dt) {
  body->velocity.x += body->acceleration.x * dt;
  body->velocity.y += body->acceleration.y * dt;
  body->position.x += body->velocity.x * dt;
  body->position.y += body->velocity.y * dt;
}

// Main function
int main() {

  // Create bodies for the solar system
  Body sun = {{0, 0}, {0, 0}, {0, 0}, 1.98892e30};
  Body earth = {{-1.471e11, 0}, {0, 29783}, {0, 0}, 5.97219e24};
  Body moon = {{-1.471e11 - 3.844e8, 0}, {0, 29783 + 1022}, {0, 0}, 7.342e22};
  Body mars = {{2.279e11, 0}, {0, 24077}, {0, 0}, 6.4171e23};
  Body venus = {{108.2e9, 0}, {0, 35020}, {0, 0}, 4.867e24};
  Body mercury = {{-46.0e9, 0}, {0, 58980}, {0, 0}, 3.301e23};

  // Set up simulation variables
  double dt = 86400; // One day in seconds
  double simulation_time = 31536000 * 5; // Five years in seconds
  int steps = simulation_time / dt;

  // Set up output file
  FILE* file = fopen("solar_system_simulation.csv", "w");
  fprintf(file, "Time, Earth x position, Earth y position, Moon x position, Moon y position, Mars x position, Mars y position, Venus x position, Venus y position, Mercury x position, Mercury y position\n");

  // Run simulation
  for (int i = 0; i < steps; i++) {
    // Calculate forces on bodies
    Vector2 force_earth_sun = force(&earth, &sun);
    Vector2 force_moon_earth = force(&moon, &earth);
    Vector2 force_moon_sun = force(&moon, &sun);
    Vector2 force_mars_sun = force(&mars, &sun);
    Vector2 force_venus_sun = force(&venus, &sun);
    Vector2 force_mercury_sun = force(&mercury, &sun);

    // Update acceleration of bodies
    earth.acceleration.x = force_earth_sun.x / earth.mass;
    earth.acceleration.y = force_earth_sun.y / earth.mass;
    moon.acceleration.x = force_moon_sun.x / moon.mass + force_moon_earth.x / moon.mass;
    moon.acceleration.y = force_moon_sun.y / moon.mass + force_moon_earth.y / moon.mass;
    mars.acceleration.x = force_mars_sun.x / mars.mass;
    mars.acceleration.y = force_mars_sun.y / mars.mass;
    venus.acceleration.x = force_venus_sun.x / venus.mass;
    venus.acceleration.y = force_venus_sun.y / venus.mass;
    mercury.acceleration.x = force_mercury_sun.x / mercury.mass;
    mercury.acceleration.y = force_mercury_sun.y / mercury.mass;

    // Update velocity and position of bodies
    update_body(&earth, dt);
    update_body(&moon, dt);
    update_body(&mars, dt);
    update_body(&venus, dt);
    update_body(&mercury, dt);

    // Write data to output file
    fprintf(file, "%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n", (i + 1) * dt, earth.position.x, earth.position.y, moon.position.x, moon.position.y, mars.position.x, mars.position.y, venus.position.x, venus.position.y, mercury.position.x, mercury.position.y);
  }

  // Close output file
  fclose(file);

  return 0;
}