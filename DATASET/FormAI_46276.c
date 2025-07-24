//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 3
#define SIM_TIME 1000
#define DELTA_T 0.01

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    char name[20];
    double mass;
    Vector2D position;
    Vector2D velocity;
} Planet;

Planet planets[NUM_PLANETS];

void updateVelocity(int i, double simTimeRemaining) {
    double accelerationX = 0.0, accelerationY = 0.0;

    // calculate acceleration due to each planet
    for (int j = 0; j < NUM_PLANETS; j++){
        if (i == j) continue;

        double distanceX = planets[j].position.x - planets[i].position.x;
        double distanceY = planets[j].position.y - planets[i].position.y;

        double distance = sqrt(distanceX*distanceX + distanceY*distanceY);

        double force = planets[j].mass / (distance * distance);

        accelerationX += force * distanceX / distance;
        accelerationY += force * distanceY / distance;
    }

    // calculate new velocity
    double newVelocityX = planets[i].velocity.x + accelerationX * DELTA_T;
    double newVelocityY = planets[i].velocity.y + accelerationY * DELTA_T;

    // calculate distance travelled during this interval and update position
    double distanceX = (planets[i].velocity.x + newVelocityX) / 2.0 * DELTA_T;
    double distanceY = (planets[i].velocity.y + newVelocityY) / 2.0 * DELTA_T;

    planets[i].position.x += distanceX;
    planets[i].position.y += distanceY;

    // update velocity
    planets[i].velocity.x = newVelocityX;
    planets[i].velocity.y = newVelocityY;

    if (simTimeRemaining - DELTA_T > 0) {
        updateVelocity(i, simTimeRemaining - DELTA_T);
    }
}

void updatePositions() {
    for (int i = 0; i < NUM_PLANETS; i++) {
        updateVelocity(i, DELTA_T);
    }
}

int main() {
    // planet 1
    strcpy(planets[0].name, "Earth");
    planets[0].mass = 5.97e24;
    planets[0].position.x = 0.0;
    planets[0].position.y = 0.0;
    planets[0].velocity.x = 0.0;
    planets[0].velocity.y = 0.0;

    // planet 2
    strcpy(planets[1].name, "Moon");
    planets[1].mass = 7.35e22;
    planets[1].position.x = 384.4e6;
    planets[1].position.y = 0.0;
    planets[1].velocity.x = 0.0;
    planets[1].velocity.y = 1.02e3;

    // planet 3
    strcpy(planets[2].name, "Sun");
    planets[2].mass = 1.99e30;
    planets[2].position.x = 0.0;
    planets[2].position.y = 0.0;
    planets[2].velocity.x = 0.0;
    planets[2].velocity.y = 0.0;

    // simulate motion
    for (double time = 0.0; time <= SIM_TIME; time += DELTA_T) {
        updatePositions();
        printf("Time: %.2f\n", time);
        for (int i = 0; i < NUM_PLANETS; i++) {
            printf("\t%s: (%.2f, %.2f)\n", planets[i].name, planets[i].position.x, planets[i].position.y);
        }
    }

    return 0;
}