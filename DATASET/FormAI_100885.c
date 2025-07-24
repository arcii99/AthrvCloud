//FormAI DATASET v1.0 Category: Physics simulation ; Style: scalable
#include <stdio.h>

#define GRAVITY 9.81f

typedef struct {
  float x, y;
  float radius;
  float mass;
} Circle;

typedef struct {
  Circle circle;
  float vx, vy;
} MovingCircle;

void update_circle_position(MovingCircle* circle, float dt) {
  circle->circle.x += circle->vx * dt;
  circle->circle.y += circle->vy * dt - 0.5f * GRAVITY * dt * dt;
  circle->vy -= GRAVITY * dt;
}

float distance(float x1, float y1, float x2, float y2) {
  float dx = x1 - x2;
  float dy = y1 - y2;
  return sqrtf(dx * dx + dy * dy);
}

int main() {
  MovingCircle ball = {
    .circle = {
      .x = 0.0f,
      .y = 0.0f,
      .radius = 10.0f,
      .mass = 5.0f
    },
    .vx = 10.0f,
    .vy = 10.0f
  };

  float dt = 0.1f;
  float time = 0.0f;
  float distance_traveled = 0.0f;
  while (ball.circle.y >= 0.0f) {
    update_circle_position(&ball, dt);
    time += dt;
    distance_traveled += distance(ball.circle.x, ball.circle.y, 
                                   ball.circle.x - ball.vx * dt, 
                                   ball.circle.y - ball.vy * dt);
    printf("Time: %f s, Position: (%f, %f), Distance Traveled: %f m\n",
           time, ball.circle.x, ball.circle.y, distance_traveled);
  }

  printf("Ball hit the ground after %f seconds.\n", time);

  return 0;
}