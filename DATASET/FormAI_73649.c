//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // Gravitational constant

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    char* name;
    double mass;
    Vector2D position;
    Vector2D velocity;
    Vector2D force;
} Planet;

void updateForce(Planet* planet1, Planet* planet2) {
    Vector2D direction;
    double distance, magnitude, forceMagnitude;
    
    direction.x = planet2->position.x - planet1->position.x;
    direction.y = planet2->position.y - planet1->position.y;
    distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    magnitude = (planet1->mass * planet2->mass) / pow(distance, 2);
    forceMagnitude = G * magnitude;
    
    direction.x /= distance;
    direction.y /= distance;
    
    planet1->force.x += direction.x * forceMagnitude;
    planet1->force.y += direction.y * forceMagnitude;
}

void updateAcceleration(Planet* planet) {
    planet->force.x /= planet->mass;
    planet->force.y /= planet->mass;
    
    planet->velocity.x += planet->force.x;
    planet->velocity.y += planet->force.y;
    
    planet->force.x = 0;
    planet->force.y = 0;
}

void updatePosition(Planet* planet) {
    planet->position.x += planet->velocity.x;
    planet->position.y += planet->velocity.y;
}

int main() {
    Planet planets[2] = {
        {
            .name = "A",
            .mass = 5.97e24, // Earth mass
            .position = {.x = 0, .y = 0},
            .velocity = {.x = 0, .y = 0},
            .force = {.x = 0, .y = 0}
        },
        {
            .name = "B",
            .mass = 1.989e30, // Sun mass
            .position = {.x = 1.496e11, .y = 0},
            .velocity = {.x = 0, .y = 29.29e3}, // Earth's orbital velocity
            .force = {.x = 0, .y = 0}
        }
    };
    
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = i + 1; j < 2; j++) {
            updateForce(&planets[i], &planets[j]);
            updateForce(&planets[j], &planets[i]);
        }
    }
    
    updateAcceleration(&planets[0]);
    updateAcceleration(&planets[1]);
    
    updatePosition(&planets[0]);
    updatePosition(&planets[1]);
    
    printf("At time t = 0:\n");
    printf("Planet %s: x = %f, y = %f\n", planets[0].name, planets[0].position.x, planets[0].position.y);
    printf("Planet %s: x = %f, y = %f\n", planets[1].name, planets[1].position.x, planets[1].position.y);
    
    return 0;
}