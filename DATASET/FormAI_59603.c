//FormAI DATASET v1.0 Category: Physics simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant
#define X 0 // Initial x-coordinate
#define Y 0 // Initial y-coordinate
#define Z 0 // Initial z-coordinate
#define VX 0 // Initial x-velocity
#define VY 0 // Initial y-velocity
#define VZ 0 // Initial z-velocity
#define M1 2.0e30 // Mass of object 1 (sun)
#define M2 5.97e24 // Mass of object 2 (earth)
#define DT 86400 // Time step (seconds in one day)
#define T 31536000 // Total simulation time (seconds in one year)
#define FILENAME "output.txt" // Output file name

int main() {
  double x1 = X, y1 = Y, z1 = Z; // Object 1 position
  double x2 = 1.49598e11, y2 = 0, z2 = 0; // Object 2 position
  double vx1 = VX, vy1 = VY, vz1 = VZ; // Object 1 velocity
  double vx2 = 0, vy2 = 29290, vz2 = 0; // Object 2 velocity
  double ax1 = 0, ay1 = 0, az1 = 0; // Object 1 acceleration
  double ax2 = 0, ay2 = 0, az2 = 0; // Object 2 acceleration
  double r, fx, fy, fz, f; // Variables for force calculation
  double t = 0; // Simulation time
  FILE* fp = fopen(FILENAME, "w"); // Output file pointer
  
  // Output initial conditions
  fprintf(fp, "%.8f %.8f %.8f %.8f %.8f %.8f\n", t, x1, y1, z1, x2, y2, z2);
  
  while (t <= T) {
    // Calculate distance between objects
    r = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1));
    
    // Calculate force on object 1
    f = G*M1*M2/(r*r);
    fx = f*(x2-x1)/r;
    fy = f*(y2-y1)/r;
    fz = f*(z2-z1)/r;
    
    // Calculate acceleration of object 1
    ax1 = fx/M1;
    ay1 = fy/M1;
    az1 = fz/M1;
    
    // Update position and velocity of object 1
    x1 += vx1*DT + 0.5*ax1*DT*DT;
    y1 += vy1*DT + 0.5*ay1*DT*DT;
    z1 += vz1*DT + 0.5*az1*DT*DT;
    vx1 += ax1*DT;
    vy1 += ay1*DT;
    vz1 += az1*DT;
    
    // Calculate force on object 2 (equal and opposite)
    fx = -fx;
    fy = -fy;
    fz = -fz;
    
    // Calculate acceleration of object 2
    ax2 = fx/M2;
    ay2 = fy/M2;
    az2 = fz/M2;
    
    // Update position and velocity of object 2
    x2 += vx2*DT + 0.5*ax2*DT*DT;
    y2 += vy2*DT + 0.5*ay2*DT*DT;
    z2 += vz2*DT + 0.5*az2*DT*DT;
    vx2 += ax2*DT;
    vy2 += ay2*DT;
    vz2 += az2*DT;
    
    // Increment simulation time
    t += DT;
    
    // Output current conditions
    fprintf(fp, "%.8f %.8f %.8f %.8f %.8f %.8f\n", t, x1, y1, z1, x2, y2, z2);
  }
  
  fclose(fp);
  
  return 0;
}