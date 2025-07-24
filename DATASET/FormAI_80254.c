//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: shocked
#include <stdio.h>
#include <math.h>

#define NUM_BODIES 9  /* number of celestial bodies */
#define GCONST     6.67430e-11  /* gravitational constant */
#define AU         1.496e+11    /* astronomical unit */

struct body {
  char name[20];
  double mass;
  double xPos;
  double yPos;
  double xVel;
  double yVel;
  double xAcc;
  double yAcc;
};

struct body bodies[NUM_BODIES];

double calcDistance(double xPos1, double yPos1, double xPos2, double yPos2) {
  double xDiff = xPos2 - xPos1;
  double yDiff = yPos2 - yPos1;
  return sqrt(xDiff * xDiff + yDiff * yDiff);
}

void calcAcc(struct body *body1, struct body *body2) {
  double distance = calcDistance(body1->xPos, body1->yPos, body2->xPos, body2->yPos);
  double force = GCONST * body1->mass * body2->mass / (distance * distance);
  double xForce = force * (body2->xPos - body1->xPos) / distance;
  double yForce = force * (body2->yPos - body1->yPos) / distance;
  body1->xAcc += xForce / body1->mass;
  body1->yAcc += yForce / body1->mass;
}

void simulate(double duration, double timeStep) {
  int i, j;
  double time = 0;

  while (time < duration) {
    for (i = 0; i < NUM_BODIES; i++) {
      bodies[i].xAcc = 0;
      bodies[i].yAcc = 0;
    }

    for (i = 0; i < NUM_BODIES - 1; i++) {
      for (j = i + 1; j < NUM_BODIES; j++) {
        calcAcc(&bodies[i], &bodies[j]);
        calcAcc(&bodies[j], &bodies[i]);
      }
    }

    for (i = 0; i < NUM_BODIES; i++) {
      bodies[i].xVel += bodies[i].xAcc * timeStep;
      bodies[i].yVel += bodies[i].yAcc * timeStep;
      bodies[i].xPos += bodies[i].xVel * timeStep;
      bodies[i].yPos += bodies[i].yVel * timeStep;
    }

    time += timeStep;
  }
}

int main() {
  int i;
  
  sprintf(bodies[0].name, "Sun");
  bodies[0].mass = 1.989e30;
  bodies[0].xPos = 0;
  bodies[0].yPos = 0;
  bodies[0].xVel = 0;
  bodies[0].yVel = 0;
  
  sprintf(bodies[1].name, "Mercury");
  bodies[1].mass = 3.302e23;
  bodies[1].xPos = 0.3871 * AU;
  bodies[1].yPos = 0;
  bodies[1].xVel = 0;
  bodies[1].yVel = 47890; /* km/s */
  
  sprintf(bodies[2].name, "Venus");
  bodies[2].mass = 4.869e24;
  bodies[2].xPos = 0.7233 * AU;
  bodies[2].yPos = 0;
  bodies[2].xVel = 0;
  bodies[2].yVel = 35020; /* km/s */
  
  sprintf(bodies[3].name, "Earth");
  bodies[3].mass = 5.972e24;
  bodies[3].xPos = 1 * AU;
  bodies[3].yPos = 0;
  bodies[3].xVel = 0;
  bodies[3].yVel = 29783; /* km/s */
  
  sprintf(bodies[4].name, "Mars");
  bodies[4].mass = 6.419e23;
  bodies[4].xPos = 1.524 * AU;
  bodies[4].yPos = 0;
  bodies[4].xVel = 0;
  bodies[4].yVel = 24007; /* km/s */
  
  sprintf(bodies[5].name, "Jupiter");
  bodies[5].mass = 1.899e27;
  bodies[5].xPos = 5.203 * AU;
  bodies[5].yPos = 0;
  bodies[5].xVel = 0;
  bodies[5].yVel = 13070; /* km/s */
  
  sprintf(bodies[6].name, "Saturn");
  bodies[6].mass = 5.685e26;
  bodies[6].xPos = 9.537 * AU;
  bodies[6].yPos = 0;
  bodies[6].xVel = 0;
  bodies[6].yVel = 9690; /* km/s */
  
  sprintf(bodies[7].name, "Uranus");
  bodies[7].mass = 8.682e25;
  bodies[7].xPos = 19.191 * AU;
  bodies[7].yPos = 0;
  bodies[7].xVel = 0;
  bodies[7].yVel = 6810; /* km/s */
  
  sprintf(bodies[8].name, "Neptune");
  bodies[8].mass = 1.024e26;
  bodies[8].xPos = 30.069 * AU;
  bodies[8].yPos = 0;
  bodies[8].xVel = 0;
  bodies[8].yVel = 5430; /* km/s */
  
  simulate(31557600 * 5, 86400); /* simulate Solar System for 5 years */
  
  for (i = 0; i < NUM_BODIES; i++) {
    printf("%s Position: (%.3f AU, %.3f AU)\n", bodies[i].name, bodies[i].xPos / AU, bodies[i].yPos / AU);
    printf("%s Velocity: (%.3f km/s, %.3f km/s)\n", bodies[i].name, bodies[i].xVel, bodies[i].yVel);
  }
  
  return 0;
}