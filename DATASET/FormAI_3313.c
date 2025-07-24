//FormAI DATASET v1.0 Category: Physics simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 500
#define PARTICLES 100

typedef struct {
  float x;
  float y;
  float vx;
  float vy;
  float mass;
  float radius;
} Particle;

Particle particles[PARTICLES];

void init_particles() {
  int i;
  srand(time(0));
  for (i = 0; i < PARTICLES; i++) {
    particles[i].x = (float)rand() / RAND_MAX * WIDTH;
    particles[i].y = (float)rand() / RAND_MAX * HEIGHT;
    particles[i].vx = ((float)rand() / RAND_MAX - 0.5) * 10;
    particles[i].vy = ((float)rand() / RAND_MAX - 0.5) * 10;
    particles[i].mass = (float)rand() / RAND_MAX * 10 + 1;
    particles[i].radius = particles[i].mass * 0.5;
  }
}

void update_particle(int i, float dt) {
  int j;
  float fx = 0, fy = 0;
  for (j = 0; j < PARTICLES; j++) {
    if (i == j) continue;
    float dx = particles[j].x - particles[i].x;
    float dy = particles[j].y - particles[i].y;
    float d = sqrt(dx*dx + dy*dy);
    if (d < particles[i].radius + particles[j].radius) {
      // collision
      float m1 = particles[i].mass;
      float m2 = particles[j].mass;
      float vx1 = (particles[i].vx * (m1 - m2) + 2 * m2 * particles[j].vx) / (m1 + m2);
      float vy1 = (particles[i].vy * (m1 - m2) + 2 * m2 * particles[j].vy) / (m1 + m2);
      float vx2 = (particles[j].vx * (m2 - m1) + 2 * m1 * particles[i].vx) / (m1 + m2);
      float vy2 = (particles[j].vy * (m2 - m1) + 2 * m1 * particles[i].vy) / (m1 + m2);
      particles[i].vx = vx1;
      particles[i].vy = vy1;
      particles[j].vx = vx2;
      particles[j].vy = vy2;
    }
    else {
      // gravitational force
      float f = particles[i].mass * particles[j].mass / (d*d);
      fx += f * dx / d;
      fy += f * dy / d;
    }
  }
  // update position
  particles[i].vx += fx * dt;
  particles[i].vy += fy * dt;
  particles[i].x += particles[i].vx * dt;
  particles[i].y += particles[i].vy * dt;
  // check boundary
  if (particles[i].x < particles[i].radius) {
    particles[i].x = particles[i].radius;
    particles[i].vx = -particles[i].vx;
  }
  if (particles[i].x > WIDTH - particles[i].radius) {
    particles[i].x = WIDTH - particles[i].radius;
    particles[i].vx = -particles[i].vx;
  }
  if (particles[i].y < particles[i].radius) {
    particles[i].y = particles[i].radius;
    particles[i].vy = -particles[i].vy;
  }
  if (particles[i].y > HEIGHT - particles[i].radius) {
    particles[i].y = HEIGHT - particles[i].radius;
    particles[i].vy = -particles[i].vy;
  }
}

void draw_particles(FILE* fp) {
  int i;
  fprintf(fp, "set term x11 size %d,%d\n", WIDTH, HEIGHT);
  fprintf(fp, "set size ratio -1\n");
  fprintf(fp, "set style circle radius %f\n", particles[0].radius);
  fprintf(fp, "set xrange [0:%d]\n", (int)WIDTH);
  fprintf(fp, "set yrange [0:%d]\n", (int)HEIGHT);
  fprintf(fp, "plot '-' with circles fill solid\n");
  for (i = 0; i < PARTICLES; i++) {
    fprintf(fp, "%f %f\n", particles[i].x, particles[i].y);
  }
  fprintf(fp, "e\n");
  fflush(fp);
}

int main() {
  int i;
  init_particles();
  FILE* fp = popen("gnuplot", "w");
  if (fp == NULL) {
    printf("Error: cannot open gnuplot pipe\n");
    return 1;
  }
  for (i = 0; i < 10000; i++) {
    update_particle(i%PARTICLES, 0.1);
    draw_particles(fp);
    usleep(10000);
  }
  pclose(fp);
  return 0;
}