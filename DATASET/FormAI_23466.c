//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: excited
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

#define PI 3.14159265358979323846
#define G 6.673e-11 // m^3/(kg*s^2)
#define SCALE 1.5e-11 // 1 pixel = 1.5e-11 meters
#define TIMESTEP 86400 // 1 simulation day = 86400 seconds

typedef struct {
  double x, y;
} Vector;

typedef struct {
  Vector pos, vel, force;
  double mass, radius;
} Body;

Body sun, earth, moon;

void init() {
  sun.mass = 1.989e30; // kg
  sun.radius = 696340000; // m
  sun.pos.x = 0;
  sun.pos.y = 0;
  sun.vel.x = 0;
  sun.vel.y = 0;
  earth.mass = 5.972e24;
  earth.radius = 6371000;
  earth.pos.x = -147095000000;
  earth.pos.y = 0;
  earth.vel.x = 0;
  earth.vel.y = 29800;
  moon.mass = 7.342e22;
  moon.radius = 1737100;
  moon.pos.x = earth.pos.x + 384400000;
  moon.pos.y = 0;
  moon.vel.x = earth.vel.x + 1022;
  moon.vel.y = earth.vel.y;

  glClearColor(0, 0, 0, 0);
  glColor3f(1, 1, 1);
}

void drawCircle(Vector v, double r) {
  glBegin(GL_POLYGON);
  int i;
  for (i = 0; i < 360; i++) {
    double rad = i * PI / 180;
    double x = v.x + r * cos(rad);
    double y = v.y + r * sin(rad);
    glVertex2f(x, y);
  }
  glEnd();
}

void drawText(char* text, Vector v) {
  glRasterPos2f(v.x, v.y);
  int i;
  for (i = 0; i < strlen(text); i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
  }
}

void draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawCircle(sun.pos, sun.radius * SCALE);
  drawCircle(earth.pos, earth.radius * SCALE);
  drawCircle(moon.pos, moon.radius * SCALE);
  drawText("Sun", sun.pos);
  drawText("Earth", earth.pos);
  drawText("Moon", moon.pos);
  glutSwapBuffers();
}

void updateForces(Body* b1, Body* b2) {
  double dx = b2->pos.x - b1->pos.x;
  double dy = b2->pos.y - b1->pos.y;
  double d = sqrt(dx*dx + dy*dy);
  double f = G * b1->mass * b2->mass / (d*d);
  b1->force.x += f * dx/d;
  b1->force.y += f * dy/d;
}

void updateBody(Body* b) {
  b->vel.x += b->force.x / b->mass * TIMESTEP;
  b->vel.y += b->force.y / b->mass * TIMESTEP;
  b->pos.x += b->vel.x * TIMESTEP;
  b->pos.y += b->vel.y * TIMESTEP;
}

void update() {
  sun.force.x = 0; sun.force.y = 0;
  earth.force.x = 0; earth.force.y = 0;
  moon.force.x = 0; moon.force.y = 0;

  updateForces(&sun, &earth);
  updateForces(&earth, &sun);
  updateForces(&earth, &moon);
  updateForces(&moon, &earth);

  updateBody(&sun);
  updateBody(&earth);
  updateBody(&moon);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Solar System Simulation");
  init();
  glutDisplayFunc(draw);
  glutIdleFunc(update);
  glutMainLoop();
  return 0;
}