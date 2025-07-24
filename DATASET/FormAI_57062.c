//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: intelligent
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.67e-11
#define TIME_DIFF 10

typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Body;

void update_position(Body *body, double time_diff) {
    body->x += body->vx * time_diff;
    body->y += body->vy * time_diff;
    body->z += body->vz * time_diff;
}

void update_velocity(Body *body, double time_diff, double fx, double fy, double fz) {
    double ax = fx / body->mass;
    double ay = fy / body->mass;
    double az = fz / body->mass;
    
    body->vx += ax * time_diff;
    body->vy += ay * time_diff;
    body->vz += az * time_diff;
}

void compute_forces(Body *bodies, int num_bodies, double *fx, double *fy, double *fz) {
    for (int i = 0; i < num_bodies; i++) {
        fx[i] = fy[i] = fz[i] = 0.0;
        for (int j = 0; j < num_bodies; j++) {
            if (i != j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double dz = bodies[j].z - bodies[i].z;
                double dist = sqrt(dx*dx + dy*dy + dz*dz);
                double inv_dist = 1.0 / dist;
                double inv_dist_cubed = inv_dist * inv_dist * inv_dist;
                double force = GRAV_CONST * bodies[i].mass * bodies[j].mass * inv_dist_cubed;
                
                fx[i] += force * dx;
                fy[i] += force * dy;
                fz[i] += force * dz;
            }
        }
    }
}

int main() {
    Body bodies[3] = {
        { 5.97e24, 0, 0, 0, 0, 0, 0 },
        { 7.35e22, 0, 3.84e8, 0, 1022, 0, 0 },
        { 1000, 400000, 0, 0, 0, 700, 0 }
    };
    
    double fx[3], fy[3], fz[3];
    
    for (double t = 0; t < 3600*24*365; t += TIME_DIFF) {
        compute_forces(bodies, 3, fx, fy, fz);
        
        for (int i = 0; i < 3; i++) {
            update_velocity(&bodies[i], TIME_DIFF, fx[i], fy[i], fz[i]);
        }
        
        for (int i = 0; i < 3; i++) {
            update_position(&bodies[i], TIME_DIFF);
        }
    }
    
    printf("Final position of Moon: (%f, %f, %f).\n", bodies[1].x, bodies[1].y, bodies[1].z);
    
    return 0;
}