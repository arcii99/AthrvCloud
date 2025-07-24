//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: retro
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.673e-11 //Gravitational constant
#define step 86400 //Time step in seconds

struct planet {
  char name[20];
  double mass;
  double x; //x position
  double y; //y position
  double z; //z position
  double vx; //velocity in x direction
  double vy; //velocity in y direction
  double vz; //velocity in z direction
};

int main() {
  srand(time(NULL));
  
  struct planet p[3];
  
  //Initial positions and velocities of planets
  strcpy(p[0].name, "Earth");
  p[0].mass = 5.97e24;
  p[0].x = 0;
  p[0].y = 0;
  p[0].z = 0;
  p[0].vx = 0;
  p[0].vy = 0;
  p[0].vz = 0;

  strcpy(p[1].name, "Mars");
  p[1].mass = 6.39e23;
  p[1].x = 2e11;
  p[1].y = 0;
  p[1].z = 0;
  p[1].vx = 0;
  p[1].vy = 24000;
  p[1].vz = 0;

  strcpy(p[2].name, "Jupiter");
  p[2].mass = 1.89e27;
  p[2].x = -7.8e11;
  p[2].y = 0;
  p[2].z = 0;
  p[2].vx = 0;
  p[2].vy = -13000;
  p[2].vz = 0;

  double force[3][3];
  
  int i, j, k;

  double dx, dy, dz, distance, f;

  for (i = 0; i < 3; i++) {
    for (j = i + 1; j < 3; j++) {
      dx = p[j].x - p[i].x;
      dy = p[j].y - p[i].y;
      dz = p[j].z - p[i].z;
      
      distance = sqrt(dx*dx + dy*dy + dz*dz);
      
      f = G*p[i].mass*p[j].mass/distance/distance;

      force[i][j] = f;
      force[j][i] = -f;
    }
  }

  double ax[3], ay[3], az[3];

  double delta_vx, delta_vy, delta_vz;
  
  while (1) {
    //Update acceleration
    for (i = 0; i < 3; i++) {
      ax[i] = 0;
      ay[i] = 0;
      az[i] = 0;
      
      for (j = 0; j < 3; j++) {
        if (j == i) continue;
        
        dx = p[j].x - p[i].x;
        dy = p[j].y - p[i].y;
        dz = p[j].z - p[i].z;
        
        distance = sqrt(dx*dx + dy*dy + dz*dz);
        
        f = force[i][j];
        
        ax[i] += f*dx/distance/p[i].mass;
        ay[i] += f*dy/distance/p[i].mass;
        az[i] += f*dz/distance/p[i].mass;
      }
    }
    
    //Update velocity and position
    for (i = 0; i < 3; i++) {
      delta_vx = ax[i]*step;
      delta_vy = ay[i]*step;
      delta_vz = az[i]*step;
      
      p[i].vx += delta_vx;
      p[i].vy += delta_vy;
      p[i].vz += delta_vz;
      
      p[i].x += p[i].vx*step;
      p[i].y += p[i].vy*step;
      p[i].z += p[i].vz*step;
      
      printf("%s: x=%.2e y=%.2e z=%.2e\n", p[i].name, p[i].x, p[i].y, p[i].z);
    }
    
    for (i = 0; i < 3; i++) {
      for (j = i + 1; j < 3; j++) {
        dx = p[j].x - p[i].x;
        dy = p[j].y - p[i].y;
        dz = p[j].z - p[i].z;
        
        distance = sqrt(dx*dx + dy*dy + dz*dz);
        
        f = G*p[i].mass*p[j].mass/distance/distance;
        
        force[i][j] = f;
        force[j][i] = -f;
      }
    }
  }

  return 0;
}