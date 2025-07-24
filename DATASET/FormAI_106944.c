//FormAI DATASET v1.0 Category: Physics simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 6.67430e-11 
#define EARTH_MASS 5.972e24 

typedef struct object // Object structure
{
    double mass;  
    double position[3];  
    double velocity[3];  
} Object;

void acceleration(Object *a, Object *b, double acceleration_vector[3])
{
  double distance_vector[3], distance, force;
  int i;

  for (i = 0; i < 3; ++i)
  {
    distance_vector[i] = a->position[i] - b->position[i];
  }

  distance = sqrt(pow(distance_vector[0],2) + pow(distance_vector[1],2) + pow(distance_vector[2],2));
  force = GRAV_CONST * a->mass * b->mass / pow(distance, 2);

  for (i = 0; i < 3; ++i)
  {
    acceleration_vector[i] = -force * distance_vector[i] / distance / a->mass;
  }
}

void simulate(Object solar_system[], int num_objects, double time_step, int num_steps)
{
  int i, j, k;
  double acceleration_vector[3];
  double velocity_vector[3];

  for (i = 0; i < num_steps; ++i)
  {
    for (j = 0; j < num_objects; ++j)
    {
      for (k = 0; k < 3; ++k)
      {
        acceleration_vector[k] = 0;
      }

      for (k = 0; k < num_objects; ++k)
      {
        if (j != k)
        {
          acceleration(&solar_system[j], &solar_system[k], acceleration_vector);
        }
      }
      for (k = 0; k < 3; ++k)
      {
        velocity_vector[k] = solar_system[j].velocity[k] + acceleration_vector[k] * time_step;
        solar_system[j].position[k] += velocity_vector[k] * time_step;
        solar_system[j].velocity[k] = velocity_vector[k];
      }
    }
  }
}

int main(int argc, char *argv[])
{
  int i;

  Object solar_system[] = {
      {EARTH_MASS, {0, 0, 0}, {0, 0, 0}}, // Earth
      {1, {0, 6371000, 0}, {7700, 0, 0}}, // Rocket
      {5.972e25, {1.5e11, 0, 0}, {0, 30000, 0}}, //Sun
  };
  int num_objects = sizeof(solar_system) / sizeof(Object);

  double time_step = 10000; 
  int num_steps = 100000; 

  simulate(solar_system, num_objects, time_step, num_steps);

  // Print the results
  for (i = 0; i < num_objects; i++)
  {
    printf("Object %d: (%e, %e, %e)\n", i, solar_system[i].position[0], solar_system[i].position[1], solar_system[i].position[2]);
  }

  return 0;
}