//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: puzzling
#include <stdio.h>
#include <math.h>

#define G 6.67428e-11
#define M_SUN 1.989e30
#define M_EARTH 5.9742e24
#define AU 1.496e11

typedef struct{
    double x;
    double y;
    double z;
}vect;

typedef struct{
    vect r;
    vect v;
    double m;
}body;

body bodies[] = {
    {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, M_SUN},
    {{AU, 0.0, 0.0}, {0.0, 30.0 * 1000.0, 0.0}, M_EARTH}
};

int num_bodies = sizeof(bodies) / sizeof(body);

void update(body *bodies, int num_bodies, double dt){
    vect a[num_bodies];
    int i, j;
    for(i = 0; i < num_bodies; i++){
        a[i].x = a[i].y = a[i].z = 0.0;
        for(j = 0; j < num_bodies; j++){
            if(i == j) continue;
            double dx = bodies[j].r.x - bodies[i].r.x;
            double dy = bodies[j].r.y - bodies[i].r.y;
            double dz = bodies[j].r.z - bodies[i].r.z;
            double dist = sqrt(dx * dx + dy * dy + dz * dz);
            double F = G * bodies[i].m * bodies[j].m / (dist * dist);
            a[i].x += F * dx / dist;
            a[i].y += F * dy / dist;
            a[i].z += F * dz / dist;
        }
    }
    for(i = 0; i < num_bodies; i++){
        bodies[i].r.x += bodies[i].v.x * dt + 0.5 * a[i].x * dt * dt;
        bodies[i].r.y += bodies[i].v.y * dt + 0.5 * a[i].y * dt * dt;
        bodies[i].r.z += bodies[i].v.z * dt + 0.5 * a[i].z * dt * dt;
        bodies[i].v.x += a[i].x * dt;
        bodies[i].v.y += a[i].y * dt;
        bodies[i].v.z += a[i].z * dt;
    }
}

int main(){
    int i;
    for(i = 0; i < num_bodies; i++){
        printf("Body %d:\n", i);
        printf("Position: (%lf, %lf, %lf)\n", bodies[i].r.x, bodies[i].r.y, bodies[i].r.z);
        printf("Velocity: (%lf, %lf, %lf)\n", bodies[i].v.x, bodies[i].v.y, bodies[i].v.z);
    }
    double dt = 60.0 * 60.0 * 24.0;
    for(i = 0; i < 365; i++){
        update(bodies, num_bodies, dt);
    }
    for(i = 0; i < num_bodies; i++){
        printf("Body %d:\n", i);
        printf("Position: (%lf, %lf, %lf)\n", bodies[i].r.x, bodies[i].r.y, bodies[i].r.z);
        printf("Velocity: (%lf, %lf, %lf)\n", bodies[i].v.x, bodies[i].v.y, bodies[i].v.z);
    }
    return 0;
}