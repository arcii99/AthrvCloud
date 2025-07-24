//FormAI DATASET v1.0 Category: Physics simulation ; Style: high level of detail
#include<stdio.h>
#include<math.h>

#define PI 3.14

int main(){

  float theta, v, u, a = -9.8, t, x, y;

  printf("Enter the initial velocity (m/s): ");
  scanf("%f", &u);

  printf("Enter the angle of projection (degree): ");
  scanf("%f", &theta);

  // convert degree to radians
  theta = theta * PI / 180;

  // calculate the horizontal and vertical components of initial velocity
  v = u * cos(theta);
  u = u * sin(theta);

  // calculate the time of flight
  t = (2 * v) / (-a);

  // calculate the horizontal and vertical displacement
  x = v * t;
  y = (u * t) + (0.5 * a * t * t);

  // print the output
  printf("\n\nAt an initial velocity of %f m/s and projection angle of %f degree, the projectile\n\n", u, theta*180/PI);
  printf("reaches a maximum height of %.2f meters and travels a horizontal distance of %.2f meters.\n", y, x);

  return 0;
}