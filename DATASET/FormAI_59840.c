//FormAI DATASET v1.0 Category: Physics simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//defining the constants
#define G 6.67 * pow(10, -11)
#define MASS_EARTH 5.97 * pow(10, 24)

int main() {

  double t = 0, t_step = 1, distance = 0;
  double x = 0, y = 0, vx = 1000, vy = 0;
  double fx = 0, fy = 0;
  double altitude, speed, time;

  while(1) {
    //calculating the distance of the object from the Earth's center
    distance = sqrt(x*x + y*y);
    if (distance < 6371000) //taking radius of the Earth as 6371km or 6371000m
      altitude = 0;
    else
      altitude = distance - 6371000;

    //calculating speed of the object
    speed = sqrt(vx*vx + vy*vy);

    //calculating time taken by the object to orbit once around the Earth
    time = (2 * M_PI * distance) / speed;

    //printing the details at an interval of 10 seconds
    if ((int)t % 10 == 0) {
      printf("Altitude: %.2lf m\n", altitude);
      printf("Speed: %.2lf m/s\n", speed);
      printf("Time for one complete orbit: %.2lf s\n", time);
      printf("---------------------------------------\n");
    }

    if (altitude > 500000) //breaking the loop if the altitude is greater than 500,000m
      break;

    //calculating the force of gravity experienced by the object due to the Earth
    fx = (-1 * G * MASS_EARTH * vx) / distance;
    fy = (-1 * G * MASS_EARTH * vy) / distance;

    //updating the velocity and position of the object
    vx += fx * t_step;
    vy += fy * t_step;
    x += vx * t_step;
    y += vy * t_step;

    t += t_step;
  }

  return 0;
}