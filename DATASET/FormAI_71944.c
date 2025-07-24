//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Sherlock Holmes
#include<stdio.h>
#include<math.h>

#define G 6.67E-11

typedef struct{
  double x, y;
  double vx, vy;
  double m;
} Body;

void update(Body *a, Body *b, double dt){
  double dx = b->x - a->x;
  double dy = b->y - a->y;
  double d = sqrt(dx*dx + dy*dy);
  double f = G*a->m*b->m/(d*d);
  double fx = f*dx/d;
  double fy = f*dy/d;
  a->vx += fx/a->m*dt;
  a->vy += fy/a->m*dt;
  b->vx -= fx/b->m*dt;
  b->vy -= fy/b->m*dt;
}

int main(){
  Body earth = {0, 0, 0, 0, 5.97E24};
  Body moon = {384400000, 0, 0, 1022, 7.35E22};
  double dt = 60;
  double t = 0;
  while(t<24*60*60){
    update(&earth, &moon, dt);
    earth.x += earth.vx*dt;
    earth.y += earth.vy*dt;
    moon.x += moon.vx*dt;
    moon.y += moon.vy*dt;
    t += dt;
  }
  printf("Earth position: (%g, %g)\n", earth.x, earth.y);
  printf("Moon position: (%g, %g)\n", moon.x, moon.y);
  return 0;
}