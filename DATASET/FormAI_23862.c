//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11

struct vector {
    double x;
    double y;
    double z;
};

struct planet {
    char* name;
    double mass;
    struct vector position;
    struct vector velocity;
};

double distance(struct vector v1, struct vector v2) {
    double dx = v2.x - v1.x;
    double dy = v2.y - v1.y;
    double dz = v2.z - v1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

struct vector gravitational_force(struct planet p1, struct planet p2) {
    struct vector f;
    double d = distance(p1.position, p2.position);
    double f_magnitude = G * p1.mass * p2.mass / (d*d);
    f.x = f_magnitude * ((p2.position.x - p1.position.x) / d);
    f.y = f_magnitude * ((p2.position.y - p1.position.y) / d);
    f.z = f_magnitude * ((p2.position.z - p1.position.z) / d);
    return f;
}

void update_position(struct planet* p, double dt) {
    p->position.x += p->velocity.x * dt;
    p->position.y += p->velocity.y * dt;
    p->position.z += p->velocity.z * dt;
}

void update_velocity(struct planet* p, struct vector f, double dt) {
    p->velocity.x += (f.x / p->mass) * dt;
    p->velocity.y += (f.y / p->mass) * dt;
    p->velocity.z += (f.z / p->mass) * dt;
}

int main() {
    // Define planets
    struct planet sun = {"Sun", 1.989e30, {0, 0, 0}, {0, 0, 0}};
    struct planet earth = {"Earth", 5.972e24, {147e9, 0, 0}, {0, 30300, 0}};
    struct planet moon = {"Moon", 7.342e22, {147e9 + 384400000, 0, 0}, {0, 30300 + 1023, 0}};
    
    // Set simulation parameters
    double dt = 60 * 60 * 24; // 1 day
    double t = 0;
    double t_max = 365 * 24 * 60 * 60; // 1 year
    
    // Simulation loop
    while (t < t_max) {
        // Calculate forces
        struct vector f_s_e = gravitational_force(sun, earth);
        struct vector f_s_m = gravitational_force(sun, moon);
        struct vector f_e_m = gravitational_force(earth, moon);
        
        // Update velocities and positions
        update_velocity(&sun, f_s_e, dt);
        update_velocity(&sun, f_s_m, dt);
        update_velocity(&earth, f_e_m, dt);
        update_velocity(&earth, f_s_e, dt);
        update_velocity(&moon, f_s_m, dt);
        update_velocity(&moon, f_e_m, dt);
        update_position(&sun, dt);
        update_position(&earth, dt);
        update_position(&moon, dt);
        
        // Print positions
        printf("t=%.0f days    %s=(%.0f, %.0f, %.0f)    %s=(%.0f, %.0f, %.0f)    %s=(%.0f, %.0f, %.0f)\n",
               t / (60*60*24),
               sun.name, sun.position.x, sun.position.y, sun.position.z,
               earth.name, earth.position.x, earth.position.y, earth.position.z,
               moon.name, moon.position.x, moon.position.y, moon.position.z);
        
        // Increment time
        t += dt;
    }
    
    return 0;
}