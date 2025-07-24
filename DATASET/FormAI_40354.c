//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G_CONST 6.67428e-11 // gravitational constant
#define SOLAR_MASS 1.9891e30 // mass of the sun
#define DAY_SEC 86400 // seconds per day

struct vec3d // vector in 3D space
{
    double x;
    double y;
    double z;
};

struct body // celestial body
{
    char name[20];
    double mass; // kg
    double radius; // m
    double dist; // m
    double eccentricity;
    double period; // days
    struct vec3d pos; // position vector
    struct vec3d vel; // velocity vector
};

void init_bodies(struct body *bodies)
{
    // init the sun
    struct body sun = {"Sun", SOLAR_MASS, 696342000, 0, 0, 0, {0, 0, 0}, {0, 0, 0}};
    bodies[0] = sun;
    
    // init the planets
    struct body mercury = {"Mercury", 3.3e23, 2439700, 57910000000, 0.2056, 87.969, {0, 0, 0}, {0, 0, 0}};
    bodies[1] = mercury;
    
    struct body venus = {"Venus", 4.87e24, 6051800, 108200000000, 0.0068, 224.701, {0, 0, 0}, {0, 0, 0}};
    bodies[2] = venus;
    
    struct body earth = {"Earth", 5.97e24, 6371000, 149600000000, 0.0168, 365.256, {0, 0, 0}, {0, 0, 0}};
    bodies[3] = earth;
    
    struct body mars = {"Mars", 6.42e23, 3397000, 227940000000, 0.0934, 686.971, {0, 0, 0}, {0, 0, 0}};
    bodies[4] = mars;
    
    struct body jupiter = {"Jupiter", 1.898e27, 71492000, 778330000000, 0.0489, 4332.59, {0, 0, 0}, {0, 0, 0}};
    bodies[5] = jupiter;
    
    struct body saturn = {"Saturn", 5.68e26, 60268000, 1429400000000, 0.0565, 10755.7, {0, 0, 0}, {0, 0, 0}};
    bodies[6] = saturn;
    
    struct body uranus = {"Uranus", 8.68e25, 25559000, 2870990000000, 0.0464, 30687.2, {0, 0, 0}, {0, 0, 0}};
    bodies[7] = uranus;
    
    struct body neptune = {"Neptune", 1.02e26, 24764000, 4504300000000, 0.0094, 60182, {0, 0, 0}, {0, 0, 0}};
    bodies[8] = neptune;
}

void update_pos(struct body *body, double dt)
{
    body->pos.x += body->vel.x * dt;
    body->pos.y += body->vel.y * dt;
    body->pos.z += body->vel.z * dt;
}

void update_vel(struct body *body, struct body *bodies, int n_bodies, double dt)
{
    struct vec3d accel = {0, 0, 0};
    
    for(int i = 0; i < n_bodies; i++)
    {
        if(body == &bodies[i]) // skip self
            continue;
        
        double dist = sqrt(pow(body->pos.x - bodies[i].pos.x, 2) 
                        + pow(body->pos.y - bodies[i].pos.y, 2) 
                        + pow(body->pos.z - bodies[i].pos.z, 2));
        
        double force = G_CONST * body->mass * bodies[i].mass / pow(dist, 2);
        
        struct vec3d dir = {(bodies[i].pos.x - body->pos.x) / dist, 
                            (bodies[i].pos.y - body->pos.y) / dist, 
                            (bodies[i].pos.z - body->pos.z) / dist};
        
        accel.x += force / body->mass * dir.x;
        accel.y += force / body->mass * dir.y;
        accel.z += force / body->mass * dir.z;
    }
    
    body->vel.x += accel.x * dt;
    body->vel.y += accel.y * dt;
    body->vel.z += accel.z * dt;
}

void simulate(struct body *bodies, int n_bodies, double duration, double dt)
{
    for(double time = 0; time < duration; time += dt)
    {
        for(int i = 0; i < n_bodies; i++)
            update_vel(&bodies[i], bodies, n_bodies, dt);

        for(int i = 0; i < n_bodies; i++)
            update_pos(&bodies[i], dt);
    }
}

int main()
{   
    struct body bodies[9]; // 9 celestial bodies

    init_bodies(bodies);

    double dt = DAY_SEC; // 1 day time step
    double duration = 365 * 10; // 10 years simulation

    simulate(bodies, 9, duration, dt);

    // print the final positions
    for(int i = 0; i < 9; i++)
        printf("%s: (%f, %f, %f)\n", bodies[i].name, bodies[i].pos.x, bodies[i].pos.y, bodies[i].pos.z);

    return 0;
}