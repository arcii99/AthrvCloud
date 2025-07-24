//FormAI DATASET v1.0 Category: Physics simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 6.67430e-11

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    Vector2D position;
    Vector2D velocity;
    double mass;
} Body;

void update_position(Body *body, double dt) {
    body->position.x += body->velocity.x * dt;
    body->position.y += body->velocity.y * dt;
}

void update_velocity(Body *body, Vector2D acceleration, double dt) {
    body->velocity.x += acceleration.x * dt;
    body->velocity.y += acceleration.y * dt;
}

Vector2D calculate_gravity_force(Body *body1, Body *body2) {
    Vector2D direction;
    double distance, magnitude, force;
    
    direction.x = body2->position.x - body1->position.x;
    direction.y = body2->position.y - body1->position.y;
    distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    magnitude = G * body1->mass * body2->mass / (distance * distance);
    force = magnitude / body1->mass;
    
    direction.x /= distance;
    direction.y /= distance;
    direction.x *= force;
    direction.y *= force;
    
    return direction;
}

void update_acceleration(Body *body1, Body *body2, Vector2D *acceleration) {
    Vector2D force = calculate_gravity_force(body1, body2);
    acceleration->x += force.x;
    acceleration->y += force.y;
}

int main() {
    Body earth = { {0, 0}, {0, 0}, 5.97e24 };
    Body moon = { {384400000, 0}, {0, 1022.0}, 7.35e22 };
    Vector2D acceleration_e = {0, 0}, acceleration_m = {0, 0};
    
    double dt = 60;
    int steps = 3600;
    
    for (int i = 0; i < steps; i++) {
        update_acceleration(&earth, &moon, &acceleration_e);
        update_acceleration(&moon, &earth, &acceleration_m);
        
        update_velocity(&earth, acceleration_e, dt);
        update_velocity(&moon, acceleration_m, dt);
        
        update_position(&earth, dt);
        update_position(&moon, dt);
        
        acceleration_e.x = acceleration_e.y = 0;
        acceleration_m.x = acceleration_m.y = 0;
        
        printf("Step %d\n", i+1);
        printf("Earth Position: (%f, %f)\n", earth.position.x, earth.position.y);
        printf("Moon Position: (%f, %f)\n", moon.position.x, moon.position.y);
        printf("Earth Velocity: (%f, %f)\n", earth.velocity.x, earth.velocity.y);
        printf("Moon Velocity: (%f, %f)\n", moon.velocity.x, moon.velocity.y);
        printf("\n");
    }
    
    return 0;
}