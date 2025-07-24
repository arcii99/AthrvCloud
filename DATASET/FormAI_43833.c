//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.6743*pow(10, -11) // gravitational constant
#define SOLAR_MASS 1.989*pow(10, 30) // mass of the sun
#define AU 1.496*pow(10, 11) // astronomical unit (average distance between Earth and Sun)

struct vec3{
    double x; // x component
    double y; // y component
    double z; // z component
};

typedef struct vec3 vec3;

struct body{
    double mass; // mass of the object
    vec3 pos; // position of the object
    vec3 vel; // velocity of the object
    vec3 acc; // acceleration of the object
};

typedef struct body body;

vec3 vec3_add(vec3 a, vec3 b){
    vec3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

vec3 vec3_sub(vec3 a, vec3 b){
    vec3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

vec3 vec3_mul(vec3 a, double b){
    vec3 result;
    result.x = a.x * b;
    result.y = a.y * b;
    result.z = a.z * b;
    return result;
}

double vec3_dot(vec3 a, vec3 b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

double vec3_mag(vec3 a){
    return sqrt(pow(a.x, 2)+pow(a.y, 2)+pow(a.z, 2));
}

vec3 vec3_norm(vec3 a){
    double mag = vec3_mag(a);
    vec3 result;
    result.x = a.x / mag;
    result.y = a.y / mag;
    result.z = a.z / mag;
    return result;
}

body create_body(double mass, vec3 pos, vec3 vel){
    body b;
    b.mass = mass;
    b.pos = pos;
    b.vel = vel;
    b.acc = vec3_mul(pos, 0);
    return b;
}

void update_acceleration(body* b, body* bodies, int num_bodies){
    vec3 net_acc = vec3_mul(b->pos, 0);
    for(int i=0; i<num_bodies; i++){
        if(bodies[i].mass != b->mass){
            vec3 r_vec = vec3_sub(bodies[i].pos, b->pos);
            double r_mag = vec3_mag(r_vec);
            double force_mag = G*bodies[i].mass*pow(r_mag, -2);
            vec3 force_vec = vec3_norm(r_vec);
            force_vec = vec3_mul(force_vec, force_mag);
            net_acc = vec3_add(net_acc, vec3_mul(force_vec, pow(r_mag, -1)));
        }
    }
    b->acc = net_acc;
}

void update_velocity(body* b, double dt){
    b->vel = vec3_add(b->vel, vec3_mul(b->acc, dt));
}

void update_position(body* b, double dt){
    b->pos = vec3_add(b->pos, vec3_mul(b->vel, dt));
}

void simulate(body* bodies, int num_bodies, double dt, double total_time){
    int num_steps = total_time / dt;
    for(int step=0; step<num_steps; step++){
        for(int i=0; i<num_bodies; i++){
            update_acceleration(&bodies[i], bodies, num_bodies);
        }
        for(int i=0; i<num_bodies; i++){
            update_velocity(&bodies[i], dt);
            update_position(&bodies[i], dt);
        }
    }
}

int main(){
    // create the sun and planets
    body sun = create_body(SOLAR_MASS, (vec3){0, 0, 0}, (vec3){0, 0, 0});
    body planets[8] = {
        create_body(3.30*pow(10, 23), (vec3){-1.471*pow(10, 11), 0, 0}, (vec3){0, -3.0287*pow(10, 4), 0}), // Mercury
        create_body(4.87*pow(10, 24), (vec3){0, -1.082*pow(10, 11), 0}, (vec3){-4.787*pow(10, 4), 0, 0}), // Venus
        create_body(5.97*pow(10, 24), (vec3){AU, 0, 0}, (vec3){0, 2.978*pow(10, 4), 0}), // Earth
        create_body(6.42*pow(10, 23), (vec3){1.523*pow(10, 11), 0, 0}, (vec3){0, 2.413*pow(10, 4), 0}), // Mars
        create_body(1.90*pow(10, 27), (vec3){778.6*pow(10, 9), 0, 0}, (vec3){0, 1.307*pow(10, 4), 0}), // Jupiter
        create_body(5.68*pow(10, 26), (vec3){1.43*pow(10, 12), 0, 0}, (vec3){0, 9.653*pow(10, 3), 0}), // Saturn
        create_body(8.68*pow(10, 25), (vec3){2.87*pow(10, 12), 0, 0}, (vec3){0, 6.812*pow(10, 3), 0}), // Uranus
        create_body(1.02*pow(10, 26), (vec3){4.50*pow(10, 12), 0, 0}, (vec3){0, 5.447*pow(10, 3), 0}), // Neptune
    };
    
    // simulate the solar system for one year
    double dt = 24*60*60; // one day in seconds
    double total_time = 365.25*24*60*60; // one year in seconds
    simulate(planets, 8, dt, total_time);
    
    // print out the final positions of the planets
    printf("Final Positions of Planets (relative to initial positions):\n");
    for(int i=0; i<8; i++){
        printf("Planet %d: (%.2e, %.2e, %.2e)\n", i, planets[i].pos.x - planets[i].pos.x, planets[i].pos.y - planets[i].pos.y, planets[i].pos.z - planets[i].pos.z);
    }
    
    return 0;
}