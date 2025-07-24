//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: grateful
#include <stdio.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.67408E-11    // N(m/Kg)^2
#define SUN_MASS 1.989E30                      // Kg
#define EARTH_MASS 5.9736E24                   // Kg
#define EARTH_ORBIT_RADIUS 149.6E9             // meters
#define EARTH_ORBIT_VELOCITY 29783             // meters/second

typedef struct {
    double x, y;
} coordinates;

typedef struct {
    coordinates position, velocity, acceleration;
    double mass;
} celestial_body;

double calculate_distance(coordinates a, coordinates b) {
    double x_diff = a.x - b.x;
    double y_diff = a.y - b.y;

    return sqrt(pow(x_diff, 2) + pow(y_diff, 2));
}

double calculate_gravitational_force(double mass1, double mass2, double distance) {
    return GRAVITATIONAL_CONSTANT * mass1 * mass2 / pow(distance, 2);
}

coordinates calculate_acceleration(celestial_body body1, celestial_body body2) {
    double distance = calculate_distance(body1.position, body2.position);
    double force = calculate_gravitational_force(body1.mass, body2.mass, distance);
    double acceleration_magnitude = force / body1.mass;

    coordinates direction;
    direction.x = (body2.position.x - body1.position.x) / distance;
    direction.y = (body2.position.y - body1.position.y) / distance;

    coordinates acceleration;
    acceleration.x = acceleration_magnitude * direction.x;
    acceleration.y = acceleration_magnitude * direction.y;

    return acceleration;
}

void update_position(celestial_body *body, double time_step) {
    body->position.x += body->velocity.x * time_step + 0.5 * body->acceleration.x * pow(time_step, 2);
    body->position.y += body->velocity.y * time_step + 0.5 * body->acceleration.y * pow(time_step, 2);
}

void update_velocity(celestial_body *body, double time_step) {
    body->velocity.x += body->acceleration.x * time_step;
    body->velocity.y += body->acceleration.y * time_step;
}

void simulate_one_year(celestial_body *earth, celestial_body *sun) {
    double time_step = 86400;
    double time = 0;

    while (time < 365.25 * 24 * 60 * 60) {
        earth->acceleration = calculate_acceleration(*earth, *sun);

        update_position(earth, time_step);
        update_velocity(earth, time_step);

        time += time_step;
    }
}

int main() {
    celestial_body sun = { {0, 0}, {0, 0}, {0, 0}, SUN_MASS };
    celestial_body earth = { {EARTH_ORBIT_RADIUS, 0}, {0, EARTH_ORBIT_VELOCITY}, {0, 0}, EARTH_MASS };

    simulate_one_year(&earth, &sun);

    printf("After one year, the Earth is at position (%f, %f) meters.\n", earth.position.x, earth.position.y);

    return 0;
}