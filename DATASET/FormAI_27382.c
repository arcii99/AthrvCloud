//FormAI DATASET v1.0 Category: Physics simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.81

typedef struct {
  double x;
  double y;
  double vx;
  double vy;
  double ax;
  double ay;
  double m;
} Ball;

void update_ball(Ball *b, double dt);
double dist(double x1, double y1, double x2, double y2);

int main(void) {
  Ball ball = {0.0, 5.0, 5.0, 0.0, 0.0, 0.0, 2.0};
  double t = 0.0;
  double dt = 0.01;
  int i = 0;

  printf("Time(s)\tX(m)\t\tY(m)\n");

  while (ball.y >= 0.0) {
    update_ball(&ball, dt);
    t += dt;
    if (i % 10 == 0) {
      printf("%.2f\t%.2f\t%.2f\n", t, ball.x, ball.y);
    }
    i++;
  }

  return 0;
}

void update_ball(Ball *b, double dt) {
  double Fx = 0.0;
  double Fy = -G * b->m;
  double ax = Fx / b->m;
  double ay = Fy / b->m;
  b->vx += ax * dt;
  b->vy += ay * dt;
  b->x += b->vx * dt;
  b->y += b->vy * dt;
}

double dist(double x1, double y1, double x2, double y2) {
  double dx = x2 - x1;
  double dy = y2 - y1;
  return sqrt(dx*dx + dy*dy);
}