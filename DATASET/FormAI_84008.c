//FormAI DATASET v1.0 Category: Physics simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define GRAV_CONSTANT 6.67E-11

struct Particle {
    double x, y, z;
    double vx, vy, vz;
    double mass;
};

typedef struct Particle Particle;

Particle create_particle(double x, double y, double z, double vx, double vy, double vz, double mass){
    Particle p;
    p.x = x;
    p.y = y;
    p.z = z;
    p.vx = vx;
    p.vy = vy;
    p.vz = vz;
    p.mass = mass;
    return p;
}

void update_particle_position(Particle* p, double dt){
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

double calc_distance(Particle p1, Particle p2){
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void update_particle_velocity(Particle* p1, Particle p2, double dt){
    double m = p1->mass;
    double M = p2.mass;
    double r = calc_distance(*p1, p2);
    double F = GRAV_CONSTANT * m * M / (r*r);
    double ax = F / m * (p2.x - p1->x) / r;
    double ay = F / m * (p2.y - p1->y) / r;
    double az = F / m * (p2.z - p1->z) / r;
    p1->vx += ax * dt;
    p1->vy += ay * dt;
    p1->vz += az * dt;
}

int main(){
    Particle particles[2];
    particles[0] = create_particle(0, 0, 0, 0, 0, 0, 10);
    particles[1] = create_particle(10, 0, 0, 0, 0, 0, 1);
    double dt = 0.001;
    double t = 0;
    while(t < 100){
        update_particle_velocity(&particles[0], particles[1], dt);
        update_particle_velocity(&particles[1], particles[0], dt);
        update_particle_position(&particles[0], dt);
        update_particle_position(&particles[1], dt);
        t += dt;
    }
    printf("Particle 0 x = %f, y = %f, z = %f\n", particles[0].x, particles[0].y, particles[0].z);
    printf("Particle 1 x = %f, y = %f, z = %f\n", particles[1].x, particles[1].y, particles[1].z);
    return 0;
}