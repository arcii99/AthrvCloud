//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: systematic
#include <stdio.h>
#include <math.h>

#define G 6.67e-11     // gravitational constant
#define MASS 5.97e24    // mass of earth
#define RADIUS 6.371e6  // radius of earth

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    Vector2D position;
    Vector2D velocity;
    double mass;
} Planet;

Vector2D CalculateGravity(Planet planet1, Planet planet2) {
    Vector2D direction;
    double distance = sqrt(pow(planet1.position.x - planet2.position.x, 2) + pow(planet1.position.y - planet2.position.y, 2));
    direction.x = (planet2.position.x - planet1.position.x) / distance;
    direction.y = (planet2.position.y - planet1.position.y) / distance;
    double force = (G * planet1.mass * planet2.mass) / pow(distance, 2);
    Vector2D gravityForce;
    gravityForce.x = force * direction.x;
    gravityForce.y = force * direction.y;
    return gravityForce;
}

void UpdatePositionVelocity(Planet *planet, Vector2D acceleration, double timeStep) {
    planet->velocity.x += acceleration.x * timeStep;
    planet->velocity.y += acceleration.y * timeStep;
    planet->position.x += planet->velocity.x * timeStep;
    planet->position.y += planet->velocity.y * timeStep;
}

int main() {
    Planet earth = { {0, RADIUS}, {29290, 0}, MASS };
    Planet moon = { {384400, RADIUS}, {-1023, 0}, 7.35e22 };
    double timeStep = 1;  // in seconds
    double simulationTime = 2592000;  // one month in seconds

    for (double t = 0; t < simulationTime; t += timeStep) {
        Vector2D gravity1 = CalculateGravity(earth, moon);
        Vector2D gravity2 = CalculateGravity(moon, earth);
        UpdatePositionVelocity(&earth, gravity1, timeStep);
        UpdatePositionVelocity(&moon, gravity2, timeStep);
        printf("Earth position: x = %lf, y = %lf\n", earth.position.x, earth.position.y);
        printf("Moon position: x = %lf, y = %lf\n", moon.position.x, moon.position.y);
    }

    return 0;
}