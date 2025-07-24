//FormAI DATASET v1.0 Category: Physics simulation ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main() {
  
  //constants
  const double G = 6.67430e-11; //gravitational constant
  const double M = 5.972e24; //mass of earth
  const double R = 6.371e6; //radius of earth
  
  //initial conditions
  
  double t = 0; //time in seconds
  double dt = 1; //time step in seconds
  double x = 0; //x-position
  double y = R + 500000; //y-position (500km above surface)
  double vx = 7500; //x-velocity (launch velocity)
  double vy = 0; //y-velocity (initially at rest)
  double ax, ay; //acceleration components
  
  //simulation loop
  while (y >= R) {
    
    //calculate gravitational force
    double r = sqrt(x*x + y*y);
    double F = G*M/(r*r);
    
    //decompose into x and y components
    double theta = atan2(y, x);
    double Fx = -F*sin(theta);
    double Fy = -F*cos(theta);
    
    //calculate acceleration
    ax = Fx/M;
    ay = Fy/M;
    
    //update velocity
    vx += ax*dt;
    vy += ay*dt;
    
    //update position
    x += vx*dt;
    y += vy*dt;
    
    //update time
    t += dt;
    
  }
  
  //print results
  printf("Time of flight: %.2f seconds\n", t);
  printf("Maximum altitude: %.2f meters\n", y-R);
  
  return 0;
}