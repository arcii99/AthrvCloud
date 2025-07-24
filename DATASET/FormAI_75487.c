//FormAI DATASET v1.0 Category: Physics simulation ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.6743e-11     // N m^2 / kg^2
#define EARTH_MASS 5.972e24                   // kg
#define EARTH_RADIUS 6.3781e6                 // m

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    double mass;
    Vector2D position;
    Vector2D velocity;
} Body;

Vector2D Vector2D_Add(Vector2D v1, Vector2D v2) {
    Vector2D result = {
        .x = v1.x + v2.x,
        .y = v1.y + v2.y,
    };
    return result;
}

Vector2D Vector2D_Subtract(Vector2D v1, Vector2D v2) {
    Vector2D result = {
        .x = v1.x - v2.x,
        .y = v1.y - v2.y,
    };
    return result;
}

Vector2D Vector2D_Multiply(Vector2D v, double scalar) {
    Vector2D result = {
        .x = v.x * scalar,
        .y = v.y * scalar,
    };
    return result;
}

double Vector2D_Distance(Vector2D v1, Vector2D v2) {
    double dx = v1.x - v2.x;
    double dy = v1.y - v2.y;
    return sqrt(dx * dx + dy * dy);
}

double Body_Distance(Body body1, Body body2) {
    return Vector2D_Distance(body1.position, body2.position);
}

Vector2D Body_GravitationalForce(Body body1, Body body2) {
    double distance = Body_Distance(body1, body2);
    double magnitude = (GRAVITATIONAL_CONSTANT * body1.mass * body2.mass) / (distance * distance);
    Vector2D direction = Vector2D_Subtract(body2.position, body1.position);
    direction = Vector2D_Multiply(direction, 1.0 / distance);
    Vector2D force = Vector2D_Multiply(direction, magnitude);
    return force;
}

void Body_Update(Body *body, Vector2D force, double dt) {
    Vector2D acceleration = Vector2D_Multiply(force, 1.0 / body->mass);
    body->velocity = Vector2D_Add(body->velocity, Vector2D_Multiply(acceleration, dt));
    body->position = Vector2D_Add(body->position, Vector2D_Multiply(body->velocity, dt));
}

void Body_Print(Body body) {
    printf("Mass: %g kg, Position: (%g, %g) m, Velocity: (%g, %g) m/s\n",
           body.mass, body.position.x, body.position.y, body.velocity.x, body.velocity.y);
}

int main() {
    Body earth = {
        .mass = EARTH_MASS,
        .position = { .x = 0, .y = 0 },
        .velocity = { .x = 0, .y = 0 },
    };

    Body moon = {
        .mass = 7.342e22,
        .position = { .x = 384400000, .y = 0 },
        .velocity = { .x = 0, .y = 1022 },
    };

    double dt = 60;
    int nsteps = 365 * 24 * 60 * 60 / dt;

    for (int i = 0; i < nsteps; i++) {
        Vector2D force = Body_GravitationalForce(earth, moon);
        Body_Update(&earth, force, dt);
        Body_Update(&moon, Vector2D_Multiply(force, -1), dt);

        if (i % (nsteps / 10) == 0) {
            printf("Step %d:\n", i);
            Body_Print(earth);
            Body_Print(moon);
        }
    }
    
    return 0;
}