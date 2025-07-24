//FormAI DATASET v1.0 Category: Physics simulation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

/*This program simulates the motion of a projectile launched at an angle above the horizontal*/

int main() {

  double v0;  //initial velocity
  double theta; //launch angle
  double g = 9.81; //acceleration due to gravity
  double y = 0.0; //initial position
  double t = 0.0;

  printf("Enter the initial velocity and launch angle separated by a space: ");
  scanf("%lf %lf", &v0, &theta);

  double vx = v0 * cos(theta); //x component of velocity
  double vy = v0 * sin(theta); //y component of velocity

  while (y >= 0) {

    /*Calculate the position of the projectile at each time step*/

    double x = vx * t;
    y = vy * t - 0.5 * g * pow(t, 2);

    printf("At time %lf seconds, the position of the projectile is (%lf, %lf) meters.\n", t, x, y);

    t += 0.1; //increment the time step by 0.1 seconds
  }

  printf("The projectile hits the ground at time %lf seconds.\n", t);

  return 0;
}