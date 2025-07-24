//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14159265358979323846

typedef struct Vec3{
    double x, y, z;
} Vec3;

typedef struct Body{
    Vec3 position;
    Vec3 velocity;
    Vec3 acceleration;
    double mass;
} Body;

void init_body(Body *b, double x, double y, double z, double vx, double vy, double vz, double m){
    b->position.x = x;
    b->position.y = y;
    b->position.z = z;
    b->velocity.x = vx;
    b->velocity.y = vy;
    b->velocity.z = vz;
    b->mass = m;
}

void print_body(Body b){
    printf("Body: position (%lf, %lf, %lf), velocity (%lf, %lf, %lf), mass %lf\n",
           b.position.x, b.position.y, b.position.z,
           b.velocity.x, b.velocity.y, b.velocity.z,
           b.mass);
}

Vec3 vec3_add(Vec3 v1, Vec3 v2){
    Vec3 v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;
    return v3;
}

Vec3 vec3_sub(Vec3 v1, Vec3 v2){
    Vec3 v3;
    v3.x = v1.x - v2.x;
    v3.y = v1.y - v2.y;
    v3.z = v1.z - v2.z;
    return v3;
}

Vec3 vec3_mul(Vec3 v, double d){
    Vec3 v2;
    v2.x = v.x * d;
    v2.y = v.y * d;
    v2.z = v.z * d;
    return v2;
}

double vec3_mag(Vec3 v){
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

Vec3 vec3_norm(Vec3 v){
    double mag = vec3_mag(v);
    Vec3 norm_v = vec3_mul(v, 1/mag);
    return norm_v;
}

double vec3_dot(Vec3 v1, Vec3 v2){
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

Vec3 vec3_cross(Vec3 v1, Vec3 v2){
    Vec3 v3;
    v3.x = v1.y*v2.z - v1.z*v2.y;
    v3.y = v1.z*v2.x - v1.x*v2.z;
    v3.z = v1.x*v2.y - v1.y*v2.x;
    return v3;
}

void update_velocity(Body *b, Vec3 acceleration, double dt){
    b->velocity = vec3_add(b->velocity, vec3_mul(acceleration, dt));
}

void update_position(Body *b, Vec3 velocity, double dt){
    b->position = vec3_add(b->position, vec3_mul(velocity, dt));
}

void calculate_acceleration(Body *b, Body *bodies, int num_bodies, double G){
    Vec3 acceleration = {0, 0, 0};

    for(int i=0; i<num_bodies; i++){
        if(b != &bodies[i]){
            Vec3 direction = vec3_norm(vec3_sub(bodies[i].position, b->position));
            double distance = vec3_mag(vec3_sub(bodies[i].position, b->position));
            double mag = G * bodies[i].mass / (distance * distance);
            Vec3 a = vec3_mul(direction, mag);
            acceleration = vec3_add(acceleration, a);
        }
    }

    b->acceleration = acceleration;
}

void simulate(Body *bodies, int num_bodies, double G, double dt, double total_time){
    for(double t=0; t<total_time; t+=dt){
        for(int i=0; i<num_bodies; i++){
            calculate_acceleration(&bodies[i], bodies, num_bodies, G);
        }

        for(int i=0; i<num_bodies; i++){
            update_velocity(&bodies[i], bodies[i].acceleration, dt);
            update_position(&bodies[i], bodies[i].velocity, dt);
        }

        // Output positions
        for(int i=0; i<num_bodies; i++){
            printf("%lf %lf %lf\n", bodies[i].position.x, bodies[i].position.y, bodies[i].position.z);
        }
    }
}

int main(){
    const int num_bodies = 4;
    Body bodies[num_bodies];

    init_body(&bodies[0], 0, 0, 0, 0, 0, 0, 1);
    init_body(&bodies[1], 1, 0, 0, 0, 0.017, 0, 1e-6);
    init_body(&bodies[2], 0, 1, 0, -0.017, 0, 0, 1e-6);
    init_body(&bodies[3], 0, 0, 1, 0, 0, 0.017, 1e-6);

    const double G = 6.67408e-11;
    const double dt = 0.01;
    const double total_time = 10;

    simulate(bodies, num_bodies, G, dt, total_time);

    return 0;
}