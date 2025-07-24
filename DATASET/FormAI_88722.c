//FormAI DATASET v1.0 Category: Physics simulation ; Style: innovative
#include <stdio.h>
#include <math.h>

/* This program simulates the trajectory of a cannonball fired at a certain angle with a certain initial velocity.
It takes into account the force of gravity and air resistance in the form of a drag coefficient.
The program outputs the distance traveled by the cannonball.
*/

#define PI 3.1415926535

int main() {
  double v0 = 50.0; // initial velocity in m/s
  double angle = PI/4; // firing angle in radians
  double x = 0.0; // initial position in x-direction
  double y = 0.0; // initial position in y-direction
  double t = 0.0; // initial time
  double dt = 0.01; // time step
  double g = 9.81; // gravitational acceleration
  double m = 1.0; // mass of cannonball
  double rho = 1.2; // air density
  double A = 0.01; // cross-sectional area of cannonball
  double Cd = 0.47; // drag coefficient
  double vx = v0*cos(angle); // initial velocity in x-direction
  double vy = v0*sin(angle); // initial velocity in y-direction
  double ax, ay; // acceleration in x and y directions
  double Fx, Fy; // forces in x and y directions
  double v, v_squared; // speed and speed squared
  double air_resistance; // air resistance

  while(y >= 0) { // keep iterating until cannonball hits the ground
    v_squared = vx*vx + vy*vy;
    v = sqrt(v_squared);
    air_resistance = 0.5*rho*A*Cd*v_squared;
    ax = -air_resistance/m*vx;
    ay = -g - air_resistance/m*vy;
    Fx = m*ax;
    Fy = m*ay;
    vx += Fx/m*dt;
    vy += Fy/m*dt;
    x += vx*dt;
    y += vy*dt;
    t += dt;
  }

  printf("Distance traveled: %f meters\n", x);
  return 0;
}