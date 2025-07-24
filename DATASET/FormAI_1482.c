//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct {
   double x;
   double y;
} Vector2D;

typedef struct {
   Vector2D position;
   Vector2D velocity;
   double mass;
} Body;

void updateVelocity(Body *body, Vector2D acceleration, double timeStep) {
   body->velocity.x += acceleration.x * timeStep;
   body->velocity.y += acceleration.y * timeStep;
}

void updatePosition(Body *body, double timeStep) {
   body->position.x += body->velocity.x * timeStep;
   body->position.y += body->velocity.y * timeStep;
}

double getDistance(Vector2D v1, Vector2D v2) {
   return sqrt(pow((v2.x - v1.x), 2) + pow((v2.y - v1.y), 2));
}

Vector2D calculateForce(Body *body1, Body *body2) {
   double G = 6.67408 * pow(10, -11);
   double distance = getDistance(body1->position, body2->position);
   double force = G * body1->mass * body2->mass / pow(distance, 2);

   Vector2D direction;
   direction.x = body2->position.x - body1->position.x;
   direction.y = body2->position.y - body1->position.y;

   double magnitude = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
   direction.x /= magnitude;
   direction.y /= magnitude;

   Vector2D forceVector;
   forceVector.x = force * direction.x;
   forceVector.y = force * direction.y;
   
   return forceVector;
}

Vector2D calculateGravity(Body *body1, Body *body2) {
   Vector2D gravity;

   Vector2D forceVector = calculateForce(body1, body2);
   gravity.x = forceVector.x / body1->mass;
   gravity.y = forceVector.y / body1->mass;

   return gravity;
}

int main() {
   srand(time(NULL));

   // Set up the solar system (for artistic purposes!)
   const int numBodies = 6;
   Body bodies[numBodies];
   bodies[0].position.x = 0;
   bodies[0].position.y = 0;
   bodies[0].velocity.x = 0;
   bodies[0].velocity.y = 0;
   bodies[0].mass = 1.989 * pow(10, 30);
   bodies[1].position.x = 0;
   bodies[1].position.y = -69;
   bodies[1].velocity.x = -54100;
   bodies[1].velocity.y = 0;
   bodies[1].mass = 3.285 * pow(10, 23);
   bodies[2].position.x = sqrt(2.761 * pow(10, 23) / 5.965 * pow(10, 24)) * 149.6 * pow(10, 6);
   bodies[2].position.y = 0;
   bodies[2].velocity.x = 0;
   bodies[2].velocity.y = sqrt(3.986 * pow(10, 14) / (sqrt(2.761 * pow(10, 23) / 5.965 * pow(10, 24)) * 149.6 * pow(10, 6)));
   bodies[2].mass = 5.965 * pow(10, 24);
   bodies[3].position.x = 0;
   bodies[3].position.y = sqrt(2.445 * pow(10, 23) / 5.965 * pow(10, 24)) * 149.6 * pow(10, 6);
   bodies[3].velocity.x = sqrt(3.986 * pow(10, 14) / (sqrt(2.445 * pow(10, 23) / 5.965 * pow(10, 24)) * 149.6 * pow(10, 6)));
   bodies[3].velocity.y = 0;
   bodies[3].mass = 2.445 * pow(10, 23);
   bodies[4].position.x = 0;
   bodies[4].position.y = -816;
   bodies[4].velocity.x = -47900;
   bodies[4].velocity.y = 0;
   bodies[4].mass = 6.39 * pow(10, 23);
   bodies[5].position.x = 0;
   bodies[5].position.y = sqrt(1.086 * pow(10, 22) / 5.965 * pow(10, 24)) * 149.6 * pow(10, 6);
   bodies[5].velocity.x = sqrt(3.986 * pow(10, 14) / (sqrt(1.086 * pow(10, 22) / 5.965 * pow(10, 24)) * 149.6 * pow(10, 6)));
   bodies[5].velocity.y = 0;
   bodies[5].mass = 1.086 * pow(10, 22);

   // Set simulation parameters
   const double timeStep = 1000;
   const double simulationTime = 2 * 365.25 * 24 * 60 * 60;

   // Start simulation
   for (double time = 0; time < simulationTime; time += timeStep) {
      // Calculate forces and update velocities
      Vector2D gravity[numBodies];
      for (int i = 0; i < numBodies; i++) {
         for (int j = i + 1; j < numBodies; j++) {
            Vector2D gravityFromB2 = calculateGravity(&bodies[i], &bodies[j]);
            Vector2D gravityFromB1;
            gravityFromB1.x = -gravityFromB2.x;
            gravityFromB1.y = -gravityFromB2.y;
            gravity[i].x += gravityFromB1.x;
            gravity[i].y += gravityFromB1.y;
            gravity[j].x += gravityFromB2.x;
            gravity[j].y += gravityFromB2.y;
         }
      }

      for (int i = 0; i < numBodies; i++) {
         updateVelocity(&bodies[i], gravity[i], timeStep);
      }

      // Update positions
      for (int i = 0; i < numBodies; i++) {
         updatePosition(&bodies[i], timeStep);
      }

      // Print progress
      printf("Time: %f\n", time);
      for (int i = 0; i < numBodies; i++) {
         printf("Body %d: x = %f, y = %f\n", i, bodies[i].position.x, bodies[i].position.y);
      }
   }

   return 0;
}