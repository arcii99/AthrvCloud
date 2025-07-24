//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: systematic
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // Gravitational constant
#define M1 6e24 // Mass of planet 1 in kg
#define M2 7.5e22 // Mass of planet 2 in kg

struct vector {
    double x, y;
};

struct planet {
    struct vector position;
    struct vector velocity;
    double mass;
};

void update_position(struct planet *p, double time_step) {
    p->position.x += p->velocity.x * time_step;
    p->position.y += p->velocity.y * time_step;
}

void update_velocity(struct planet *p, struct vector force, double time_step) {
    double acceleration_x = force.x / p->mass;
    double acceleration_y = force.y / p->mass;
    p->velocity.x += acceleration_x * time_step;
    p->velocity.y += acceleration_y * time_step;
}

double distance(struct vector v1, struct vector v2) {
    double dx = v2.x - v1.x;
    double dy = v2.y - v1.y;
    return sqrt(dx * dx + dy * dy);
}

double magnitude(struct vector v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

struct vector get_unit_vector(struct vector v) {
    struct vector unit_v;
    double mag = magnitude(v);
    if (mag > 0) {
        unit_v.x = v.x / mag;
        unit_v.y = v.y / mag;
    } else {
        unit_v.x = 0;
        unit_v.y = 0;
    }
    return unit_v;
}

struct vector calculate_gravitational_force(struct planet p1, struct planet p2) {
    double dist = distance(p1.position, p2.position);
    double force_mag = (G * p1.mass * p2.mass) / (dist * dist);
    struct vector force;
    force.x = force_mag * (p2.position.x - p1.position.x) / dist;
    force.y = force_mag * (p2.position.y - p1.position.y) / dist;
    return force;
}

int main() {
    struct planet earth = { {0, 0}, {0, 0}, M1 };
    struct planet mars = { {227939200000, 0}, {0, 24074}, M2 };
    double time_step = 3600; // 1 hour in seconds
    double sim_time = 31536000; // 1 year in seconds
    int num_steps = sim_time / time_step;

    for (int i = 0; i < num_steps; i++) {
        struct vector f_earth_mars = calculate_gravitational_force(earth, mars);
        struct vector f_mars_earth = { -f_earth_mars.x, -f_earth_mars.y };
        update_velocity(&earth, f_mars_earth, time_step);
        update_velocity(&mars, f_earth_mars, time_step);
        update_position(&earth, time_step);
        update_position(&mars, time_step);
    }

    printf("Final positions:\n");
    printf("Earth: (%g, %g)\n", earth.position.x, earth.position.y);
    printf("Mars: (%g, %g)\n", mars.position.x, mars.position.y);

    return 0;
}