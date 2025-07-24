//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 8

typedef struct{
  float x,y,z;
}Vector3D;

typedef struct{
  char name[15];
  float mass, radius;
  Vector3D pos, vel, acc;
}Planet;

void updateAcceleration(Planet *planets){
  int i,j;
  float r,g;
  Vector3D f;
  for (i=0; i<NUM_PLANETS; i++){
    f.x=f.y=f.z=0.0;
    for (j=0; j<NUM_PLANETS; j++){
      if (i==j) continue;
      r=sqrt(pow(planets[j].pos.x-planets[i].pos.x,2)+
             pow(planets[j].pos.y-planets[i].pos.y,2)+
             pow(planets[j].pos.z-planets[i].pos.z,2));
             
      g=planets[j].mass/(r*r);
      f.x+=g*(planets[j].pos.x-planets[i].pos.x)/r;
      f.y+=g*(planets[j].pos.y-planets[i].pos.y)/r;
      f.z+=g*(planets[j].pos.z-planets[i].pos.z)/r;
    }
    planets[i].acc.x=f.x;
    planets[i].acc.y=f.y;
    planets[i].acc.z=f.z;
  }
}

void updateVelocity(Planet *planets, float dt){
  int i;
  for (i=0; i<NUM_PLANETS; i++){
    planets[i].vel.x+=planets[i].acc.x*dt;
    planets[i].vel.y+=planets[i].acc.y*dt;
    planets[i].vel.z+=planets[i].acc.z*dt;
  }
}

void updatePosition(Planet *planets, float dt){
  int i;
  for (i=0; i<NUM_PLANETS; i++){
    planets[i].pos.x+=planets[i].vel.x*dt;
    planets[i].pos.y+=planets[i].vel.y*dt;
    planets[i].pos.z+=planets[i].vel.z*dt;
  }
}

int main(){
  int i, t=0, num_steps=1000;
  float dt=0.01;
  Planet planets[NUM_PLANETS]={
    {"Sun", 1.989e30, 695.7e6, {0.0,0.0,0.0}, {0.0,0.0,0.0}, {0.0,0.0,0.0}},
    {"Mercury", 3.285e23, 2.44e6, {0.39e12,0.0,0.0}, {0.0,47.4e3,0.0}, {0.0,0.0,0.0}},
    {"Venus", 4.867e24, 6.05e6, {0.72e12,0.0,0.0}, {0.0,35.0e3,0.0}, {0.0,0.0,0.0}},
    {"Earth", 5.972e24, 6.37e6, {1.0e12,0.0,0.0}, {0.0,29.8e3,0.0}, {0.0,0.0,0.0}},
    {"Mars", 6.390e23, 3.39e6, {1.52e12,0.0,0.0}, {0.0,24.1e3,0.0}, {0.0,0.0,0.0}},
    {"Jupiter", 1.898e27, 69.91e6, {5.20e12,0.0,0.0}, {0.0,13.1e3,0.0}, {0.0,0.0,0.0}},
    {"Saturn", 5.683e26, 58.23e6, {9.58e12,0.0,0.0}, {0.0,9.7e3,0.0}, {0.0,0.0,0.0}},
    {"Uranus", 8.681e25, 25.36e6, {19.18e12,0.0,0.0}, {0.0,6.8e3,0.0}, {0.0,0.0,0.0}},
    {"Neptune", 1.024e26, 24.62e6, {30.07e12,0.0,0.0}, {0.0,5.4e3,0.0}, {0.0,0.0,0.0}}
  };

  for (t=0; t<num_steps; t++){
    printf("Step: %d\n",t);
    updateAcceleration(planets);
    updateVelocity(planets,dt);
    updatePosition(planets,dt);
  }

  return 0;
}