//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: rigorous
#include <stdio.h>
#include <math.h>

#define G_CONST 6.67430E-11    // Gravitational constant
#define M_SUN 1.989E30          // Mass of the sun
#define AU 1.496E11            // Astronomical unit
#define YEAR 31536000          // Year in seconds
#define PI 3.14159265358979323846

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

typedef struct body {
    vector position;
    vector velocity;
    double mass;
} body;

void update_velocity(body* b1, body* b2, double time_step);
void update_position(body* b, double time_step);

int main() {
    double time = 0.0;
    double time_step = 86400.0;
    double simulation_time = 365.0 * YEAR;
    body sun = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, M_SUN};
    body earth = {{AU, 0.0, 0.0}, {0.0, 30000.0, 0.0}, 5.97E24};
    body moon = {{AU + 384400000.0, 0.0, 0.0}, {0.0, 29784.0, 0.0}, 7.342E22};
    
    printf("Time (years)\tEarth x (AU)\tEarth y (AU)\tMoon x (AU)\tMoon y (AU)\n");
    
    while (time < simulation_time) {
        update_velocity(&earth, &sun, time_step);
        update_velocity(&moon, &sun, time_step);
        update_velocity(&moon, &earth, time_step);
        update_position(&earth, time_step);
        update_position(&moon, time_step);
        time += time_step;
        printf("%f\t%f\t%f\t%f\t%f\n", time / YEAR, earth.position.x / AU, earth.position.y / AU, moon.position.x / AU, moon.position.y / AU);
    }
    
    return 0;
}

void update_velocity(body* b1, body* b2, double time_step) {
    double distance_x = b2->position.x - b1->position.x;
    double distance_y = b2->position.y - b1->position.y;
    double distance_z = b2->position.z - b1->position.z;
    double distance = sqrt(distance_x * distance_x + distance_y * distance_y + distance_z * distance_z);
    double force = (G_CONST * b1->mass * b2->mass) / (distance * distance);
    double acceleration = force / b1->mass;
    b1->velocity.x += acceleration * time_step * distance_x / distance;
    b1->velocity.y += acceleration * time_step * distance_y / distance;
    b1->velocity.z += acceleration * time_step * distance_z / distance;
}

void update_position(body* b, double time_step) {
    b->position.x += b->velocity.x * time_step;
    b->position.y += b->velocity.y * time_step;
    b->position.z += b->velocity.z * time_step;
}