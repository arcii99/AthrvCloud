//FormAI DATASET v1.0 Category: Physics simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.67408e-11 /* Gravitational constant in m^3/kg.s^2 */
#define TIME_STEP 1.0 /* Time step in seconds */

typedef struct {
  double x, y; /* Position in meters */
  double vx, vy; /* Velocity in m/s */
  double mass; /* Mass in kg */
} body_t;

/*
 * Function to calculate the gravitational force between two bodies.
 * Input parameters: body_t body1, body_t body2
 * Output: double - gravitational force in N
 */
double calculate_gravitational_force(body_t body1, body_t body2) {
  double distance = sqrt(pow((body2.x-body1.x), 2) + pow((body2.y-body1.y), 2));
  double force = (GRAVITATIONAL_CONSTANT * body1.mass * body2.mass) / pow(distance, 2);
  return force;
}

int main() {
  /* Initialize bodies */
  body_t body1 = {0, 0, 0, 0, 5.97e24}; /* Earth */
  body_t body2 = {384400000.0, 0, 0, 1022.0, 7.34e22}; /* Moon */
  
  /* Initialize time and loop count */
  double time = 0;
  int loop_count = 0;
  
  /* Set simulation distance in meters */
  double simulation_distance = 1e9; /* 1 billion meters */
  
  /* Main simulation loop */
  while (fabs(body1.x - body2.x) <= simulation_distance) {
    /* Calculate gravitational force on each body */
    double force1 = calculate_gravitational_force(body1, body2);
    double force2 = calculate_gravitational_force(body2, body1);
    
    /* Calculate acceleration of each body */
    double acceleration1 = force1 / body1.mass;
    double acceleration2 = force2 / body2.mass;
    
    /* Calculate new velocities of each body */
    body1.vx += acceleration1 * TIME_STEP;
    body1.vy += acceleration1 * TIME_STEP;
    body2.vx += acceleration2 * TIME_STEP;
    body2.vy += acceleration2 * TIME_STEP;
    
    /* Calculate new positions of each body */
    body1.x += body1.vx * TIME_STEP;
    body1.y += body1.vy * TIME_STEP;
    body2.x += body2.vx * TIME_STEP;
    body2.y += body2.vy * TIME_STEP;
    
    /* Print position of each body every 10 loops */
    if (loop_count % 10 == 0) {
      printf("Time: %0.2f s \t Earth position: (%0.2f, %0.2f) m \t Moon position: (%0.2f, %0.2f) m \n", time, body1.x, body1.y, body2.x, body2.y);
    }
    
    /* Increment time and loop count */
    time += TIME_STEP;
    loop_count++;
  }
  
  return 0;
}