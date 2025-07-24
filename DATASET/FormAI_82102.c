//FormAI DATASET v1.0 Category: Physics simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  
  printf("Welcome to the amazing physics simulation!\n");
  printf("In this simulation, we will calculate the trajectory of a basketball being thrown into a hoop.\n");
  printf("Let's get started!\n\n");

  float x = 0.0;  // x position of ball
  float y = 0.0;  // y position of ball
  float vx = 30.0;  // initial x velocity of ball
  float vy = 40.0;  // initial y velocity of ball
  float ax = 0.0;  // x acceleration of ball
  float ay = -9.81;  // y acceleration of ball due to gravity
  float dt = 0.1;  // time step in seconds
  float t = 0.0;  // current time
  float d = 0.0;  // distance from ball to hoop
  int points = 0;  // number of points scored

  printf("Enter the distance from the ball to the hoop in meters: ");
  scanf("%f", &d);

  while (y >= 0.0) {  // loop until the ball hits the ground
    x += vx * dt + 0.5 * ax * dt * dt;
    y += vy * dt + 0.5 * ay * dt * dt;
    vx += ax * dt;
    vy += ay * dt;
    t += dt;

    // check if ball has crossed the hoop
    if (x >= d && fabs(y) <= 0.3) {
      printf("SWISH! You scored a point!\n");
      points++;
      x = 0.0;
      y = 0.0;
      vx = 30.0;
      vy = 40.0;
      t = 0.0;
    }
  }

  printf("\nYou scored %d points!\n", points);

  return 0;
}