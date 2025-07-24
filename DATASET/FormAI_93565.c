//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: portable
#include <stdio.h>
#include <math.h>

double PI = 3.14159265359;

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    Vector2D position;
    Vector2D velocity;
    double mass;
    double radius;
} Body;

typedef struct {
    double G;
    double timeStep;
    Body bodies[8];
} SolarSystem;

// Calculates the distance between two bodies
double distance(Vector2D p1, Vector2D p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

// Calculates the force of attraction between two bodies
Vector2D attraction(Body b1, Body b2, double G) {
    double r = distance(b1.position, b2.position);
    double f = G * b1.mass * b2.mass / (r * r);
    Vector2D direction = { (b2.position.x - b1.position.x) / r, (b2.position.y - b1.position.y) / r };
    Vector2D force = { direction.x * f, direction.y * f };
    return force;
}

// Updates the velocity of a body based on the forces acting on it
void updateVelocity(Body *body, Vector2D forces[], double timeStep) {
    double ax = 0.0;
    double ay = 0.0;
    for (int i = 0; i < 8; i++) {
        if (body != &body[i]) {
            Vector2D force = forces[i];
            ax += force.x / body->mass;
            ay += force.y / body->mass;
        }
    }
    body->velocity.x += ax * timeStep;
    body->velocity.y += ay * timeStep;
}

// Updates the position of a body based on its velocity
void updatePosition(Body *body, double timeStep) {
    body->position.x += body->velocity.x * timeStep;
    body->position.y += body->velocity.y * timeStep;
}

// Draws a circle with a given position and radius
void drawCircle(Vector2D position, double radius) {
    printf("Circle at (%f, %f) with radius %f\n", position.x, position.y, radius);
}

int main() {
    Body sun = { { 0.0, 0.0 }, { 0.0, 0.0 }, 1989000e24, 696340e3 };
    Body mercury = { { 5.791e10, 0.0 }, { 0.0, 47.4e3 }, 3.285e23, 2439.7e3 };
    Body venus = { { 1.0821e11, 0.0 }, { 0.0, 35.0e3 }, 4.867e24, 6052e3 };
    Body earth = { { 1.496e11, 0.0 }, { 0.0, 29.8e3 }, 5.972e24, 6378e3 };
    Body mars = { { 2.279e11, 0.0 }, { 0.0, 24.1e3 }, 6.39e23, 3396e3 };
    Body jupiter = { { 7.783e11, 0.0 }, { 0.0, 13.1e3 }, 1.898e27, 71492e3 };
    Body saturn = { { 1.429e12, 0.0 }, { 0.0, 9.7e3 }, 5.683e26, 60268e3 };
    Body uranus = { { 2.871e12, 0.0 }, { 0.0, 6.8e3 }, 8.681e25, 25559e3 };
    Body neptune = { { 4.495e12, 0.0 }, { 0.0, 5.4e3 }, 1.024e26, 24764e3 };

    SolarSystem solarSystem = { 6.6743e-11, 86400.0, { sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune } };

    for (int i = 0; i < 365; i++) {
        Vector2D forces[8] = {};
        for (int j = 0; j < 8; j++) {
            for (int k = j + 1; k < 8; k++) {
                Vector2D force = attraction(solarSystem.bodies[j], solarSystem.bodies[k], solarSystem.G);
                forces[j].x += force.x;
                forces[j].y += force.y;
                forces[k].x -= force.x;
                forces[k].y -= force.y;
            }
        }
        for (int j = 0; j < 8; j++) {
            Body *body = &solarSystem.bodies[j];
            updateVelocity(body, forces, solarSystem.timeStep);
            updatePosition(body, solarSystem.timeStep);
        }

        for (int j = 0; j < 8; j++) {
            Body body = solarSystem.bodies[j];
            drawCircle(body.position, body.radius);
        }
    }

    return 0;
}