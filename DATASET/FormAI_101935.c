//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: realistic
#include <stdio.h>
#include <math.h>
#define G 6.6743e-11 // Gravitational constant
#define MAX_OBJECTS 10 // Maximum number of objects

/* Define the object struct */
typedef struct Object {
  double mass; // kg
  double x; // m
  double y; // m
  double vx; // m/s
  double vy; // m/s
} Object;

/* Function to calculate the gravitational force between two objects */
void calcForce(Object obj1, Object obj2, double *fx, double *fy) {
  double r, f;

  r = sqrt(pow(obj2.x - obj1.x, 2) + pow(obj2.y - obj1.y, 2));
  f = G * obj1.mass * obj2.mass / pow(r, 2);

  *fx = f * (obj2.x - obj1.x) / r;
  *fy = f * (obj2.y - obj1.y) / r;
}

int main() {
  Object objects[MAX_OBJECTS];
  double fx[MAX_OBJECTS][MAX_OBJECTS], fy[MAX_OBJECTS][MAX_OBJECTS];
  int nObjects, i, j, t, dt = 1;
  double ax, ay;

  /* Read in the number of objects */
  printf("Enter the number of objects: ");
  scanf("%d", &nObjects);

  /* Read in each object's properties */
  for(i = 0; i < nObjects; i++) {
    printf("Enter mass of object %d (in kg): ", i+1);
    scanf("%lf", &objects[i].mass);

    printf("Enter x-coordinate of object %d (in m): ", i+1);
    scanf("%lf", &objects[i].x);

    printf("Enter y-coordinate of object %d (in m): ", i+1);
    scanf("%lf", &objects[i].y);

    printf("Enter x-velocity of object %d (in m/s): ", i+1);
    scanf("%lf", &objects[i].vx);

    printf("Enter y-velocity of object %d (in m/s): ", i+1);
    scanf("%lf", &objects[i].vy);
  }

  /* Run the simulation for 100 timesteps */
  for(t = 0; t < 100; t++) {
    /* Calculate the force on each object */
    for(i = 0; i < nObjects; i++) {
      fx[i][i] = 0;
      fy[i][i] = 0;

      for(j = i+1; j < nObjects; j++) {
        calcForce(objects[i], objects[j], &fx[i][j], &fy[i][j]);
        fx[j][i] = -fx[i][j];
        fy[j][i] = -fy[i][j];
      }
    }

    /* Calculate the acceleration on each object */
    for(i = 0; i < nObjects; i++) {
      ax = 0;
      ay = 0;

      for(j = 0; j < nObjects; j++) {
        if(i == j) {
          continue;
        }

        ax += fx[i][j] / objects[i].mass;
        ay += fy[i][j] / objects[i].mass;
      }

      /* Update the velocity and position of each object */
      objects[i].vx += ax * dt;
      objects[i].vy += ay * dt;
      objects[i].x += objects[i].vx * dt;
      objects[i].y += objects[i].vy * dt;
    }

    /* Print out the position of each object */
    printf("\nTimestep %d:\n", t+1);
    for(i = 0; i < nObjects; i++) {
      printf("Object %d: (%lf, %lf)\n", i+1, objects[i].x, objects[i].y);
    }
  }

  return 0;
}