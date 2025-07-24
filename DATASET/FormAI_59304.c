//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define G 6.67430E-11 // Gravitational constant
#define M_SUN 1.9885E30 // Mass of the Sun
#define AU 149597870700 // Astronomical Unit (distance from Earth to Sun)
#define DT 86400 // Time step in seconds (1 day)

typedef struct Vec3 {
    double x, y, z;
} Vec3;

typedef struct Body {
    char name[20]; // Name of the body
    double mass; // Mass of the body in kg
    Vec3 pos; // Position vector of the body in m
    Vec3 vel; // Velocity vector of the body in m/s
    Vec3 acc; // Acceleration vector of the body in m/s^2
} Body;

void print_body(Body *b);
void update_pos_vel_acc(Body *b, Body *other_bodies, int num_bodies);
void update_body(Body *b);

int main() {
    int num_bodies = 4;
    Body bodies[num_bodies];
    
    // Set up the Sun
    sprintf(bodies[0].name, "Sun");
    bodies[0].mass = M_SUN;
    bodies[0].pos = (Vec3){0, 0, 0};
    bodies[0].vel = (Vec3){0, 0, 0};
    bodies[0].acc = (Vec3){0, 0, 0};
    
    // Set up Earth
    sprintf(bodies[1].name, "Earth");
    bodies[1].mass = 5.972E24;
    bodies[1].pos = (Vec3){AU, 0, 0};
    bodies[1].vel = (Vec3){0, 29.78E3, 0};
    bodies[1].acc = (Vec3){0, 0, 0};
    
    // Set up Moon
    sprintf(bodies[2].name, "Moon");
    bodies[2].mass = 7.342E22;
    bodies[2].pos = (Vec3){AU + 384400000, 0, 0}; // Moon is 384400km away from Earth
    bodies[2].vel = (Vec3){0, 29.78E3 + 1022, 0}; // Moon orbits Earth at 1022m/s
    bodies[2].acc = (Vec3){0, 0, 0};
    
    // Set up Mars
    sprintf(bodies[3].name, "Mars");
    bodies[3].mass = 6.39E23;
    bodies[3].pos = (Vec3){-AU * 1.5, 0, 0}; // Mars is 1.5AU away from the Sun
    bodies[3].vel = (Vec3){0, -24.077E3, 0}; // Mars orbits the Sun at 24.077km/s
    bodies[3].acc = (Vec3){0, 0, 0};
    
    // Simulation loop
    printf("%10s%20s%20s%20s\n", "Name", "Pos (m)", "Vel (m/s)", "Acc (m/s^2)");
    for (int i = 0; i < num_bodies; i++) {
        print_body(&bodies[i]);
    }
    for (int i = 0; i < 365; i++) { // Simulate for 1 year
        for (int j = 0; j < num_bodies; j++) {
            update_pos_vel_acc(&bodies[j], bodies, num_bodies);
        }
        for (int j = 0; j < num_bodies; j++) {
            update_body(&bodies[j]);
            print_body(&bodies[j]);
        }
    }
    
    return 0;
}

void print_body(Body *b) {
    printf("%10s%20.2f,%20.2f,%20.2f%20.2f,%20.2f,%20.2f%20.2f,%20.2f,%20.2f\n",
        b->name, b->pos.x, b->pos.y, b->pos.z, b->vel.x, b->vel.y, b->vel.z, b->acc.x, b->acc.y, b->acc.z);
}

void update_pos_vel_acc(Body *b, Body *other_bodies, int num_bodies) {
    b->acc = (Vec3){0, 0, 0};
    for (int i = 0; i < num_bodies; i++) {
        if (b == &other_bodies[i]) {
            continue; // Skip yourself
        }
        
        Vec3 r = (Vec3){other_bodies[i].pos.x - b->pos.x, other_bodies[i].pos.y - b->pos.y, other_bodies[i].pos.z - b->pos.z};
        double r_mag = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
        double force_mag = G * b->mass * other_bodies[i].mass / (r_mag * r_mag);
        Vec3 force = (Vec3){force_mag*r.x/r_mag, force_mag*r.y/r_mag, force_mag*r.z/r_mag};
        
        b->acc.x += force.x / b->mass;
        b->acc.y += force.y / b->mass;
        b->acc.z += force.z / b->mass;
    }
    b->vel.x += b->acc.x * DT;
    b->vel.y += b->acc.y * DT;
    b->vel.z += b->acc.z * DT;
    b->pos.x += b->vel.x * DT;
    b->pos.y += b->vel.y * DT;
    b->pos.z += b->vel.z * DT;
}

void update_body(Body *b) {
    b->acc = (Vec3){0, 0, 0};
}