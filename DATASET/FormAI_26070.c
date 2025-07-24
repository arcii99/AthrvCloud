//FormAI DATASET v1.0 Category: Physics simulation ; Style: minimalist
#include <stdio.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.67430e-11  // Gravitational constant (m^3 kg^-1 s^-2)

struct Point {  // Structure to represent points in space
    double x;
    double y;
};

struct Body {  // Structure to represent bodies in space
    double mass;
    struct Point position;
    struct Point velocity;
};

double distance(struct Point a, struct Point b) {  // Function to calculate distance between two points
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double calculate_force(struct Body a, struct Body b) {  // Function to calculate gravitational force between two bodies
    double r = distance(a.position, b.position);
    return GRAVITATIONAL_CONSTANT * a.mass * b.mass / pow(r, 2);
}

int main(void) {
    struct Body earth = {5.9722e24, {0, 0}, {0, 0}};  // Earth body
    struct Body moon = {7.342e22, {384400000, 0}, {0, 1022}};  // Moon body

    double force = calculate_force(earth, moon);  // Gravitational force between Earth and Moon
    printf("Gravitational force between Earth and Moon: %f N\n", force);

    return 0;
}