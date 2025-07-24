//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: complex
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

struct Vector {
    double x, y, z;
};

struct Body {
    char name[256];
    double mass;
    struct Vector position, velocity, acceleration;
};

void calculate_acceleration(struct Body* body, struct Body* other_bodies, int total_bodies) {
    struct Vector acceleration;
    acceleration.x = acceleration.y = acceleration.z = 0.0;
    for (int i = 0; i < total_bodies; ++i) {
        if (body == &other_bodies[i]) {
            continue;
        }
        struct Vector direction;
        direction.x = other_bodies[i].position.x - body->position.x;
        direction.y = other_bodies[i].position.y - body->position.y;
        direction.z = other_bodies[i].position.z - body->position.z;

        double distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2) + pow(direction.z, 2));
        double gravitational_force = (6.67430E-11 * body->mass * other_bodies[i].mass) / pow(distance, 2);
        double acceleration_magnitude = gravitational_force / body->mass;

        struct Vector unit_vector;
        unit_vector.x = direction.x / distance;
        unit_vector.y = direction.y / distance;
        unit_vector.z = direction.z / distance;

        acceleration.x += (unit_vector.x * acceleration_magnitude);
        acceleration.y += (unit_vector.y * acceleration_magnitude);
        acceleration.z += (unit_vector.z * acceleration_magnitude);
    }
    body->acceleration = acceleration;
}

void update_velocity(struct Body* body, double time_step) {
    body->velocity.x += body->acceleration.x * time_step;
    body->velocity.y += body->acceleration.y * time_step;
    body->velocity.z += body->acceleration.z * time_step;
}

void update_position(struct Body* body, double time_step) {
    body->position.x += body->velocity.x * time_step;
    body->position.y += body->velocity.y * time_step;
    body->position.z += body->velocity.z * time_step;
}

void simulate(struct Body* bodies, int total_bodies, double time_step, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        for (int j = 0; j < total_bodies; ++j) {
            calculate_acceleration(&bodies[j], bodies, total_bodies);
        }
        for (int j = 0; j < total_bodies; ++j) {
            update_velocity(&bodies[j], time_step);
            update_position(&bodies[j], time_step);
        }
    }
}

int main() {
    printf("Starting simulation...\n");

    struct Body sun = {"Sun", 1.98847E30, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    struct Body earth = {"Earth", 5.97237E24, {147095000000, 0, 0}, {0, 30290, 0}, {0, 0, 0}};
    struct Body moon = {"Moon", 7.342E22, {147095000000, 384400000, 0}, {-1022, 30290, 0}, {0, 0, 0}};

    struct Body bodies[3] = {sun, earth, moon};

    double time_step = 86400.0; // 1 day
    int iterations = 365;

    simulate(bodies, 3, time_step, iterations);

    for (int i = 0; i < 3; ++i) {
        printf("%s:\n", bodies[i].name);
        printf(" Position: (%f, %f, %f)\n", bodies[i].position.x, bodies[i].position.y, bodies[i].position.z);
        printf(" Velocity: (%f, %f, %f)\n", bodies[i].velocity.x, bodies[i].velocity.y, bodies[i].velocity.z);
        printf(" Acceleration: (%f, %f, %f)\n", bodies[i].acceleration.x, bodies[i].acceleration.y, bodies[i].acceleration.z);
    }

    return 0;
}