//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant
#define MARTH_MASS 5.9722e24 // mass of the Earth
#define MARS_MASS 6.4171e23 // mass of Mars
#define DT 86400 // time step in seconds (1 day)
#define SIM_TIME 86400 * 365 // simulate for 1 year (in seconds)

struct Vector // a struct to represent a 2D vector
{
    double x;
    double y;
};

struct Body // a struct to represent a celestial body
{
    char name[20];
    double mass;
    double radius;
    struct Vector position;
    struct Vector velocity;
    struct Vector acceleration;
};

void calculate_gravity(struct Body *b1, struct Body *b2)
{
    struct Vector r;
    double distance;
    struct Vector force;
    
    r.x = b2->position.x - b1->position.x;
    r.y = b2->position.y - b1->position.y;
    distance = sqrt(pow(r.x, 2) + pow(r.y, 2));
    
    force.x = G * b1->mass * b2->mass / pow(distance, 2) * r.x / distance;
    force.y = G * b1->mass * b2->mass / pow(distance, 2) * r.y / distance;
    
    b1->acceleration.x += force.x / b1->mass;
    b1->acceleration.y += force.y / b1->mass;
    
    b2->acceleration.x -= force.x / b2->mass;
    b2->acceleration.y -= force.y / b2->mass;
}

void move_bodies(struct Body *bodies, int num_bodies, double dt)
{
    int i;
    
    for (i = 0; i < num_bodies; i++)
    {
        bodies[i].velocity.x += bodies[i].acceleration.x * dt;
        bodies[i].velocity.y += bodies[i].acceleration.y * dt;
        
        bodies[i].position.x += bodies[i].velocity.x * dt;
        bodies[i].position.y += bodies[i].velocity.y * dt;
        
        bodies[i].acceleration.x = 0;
        bodies[i].acceleration.y = 0;
    }
}

int main()
{
    struct Body earth = {"Earth", MARTH_MASS, 6371000, {0, 0}, {0, 0}, {0, 0}};
    struct Body mars = {"Mars", MARS_MASS, 3389500, {227900000000, 0}, {0, 24000}, {0, 0}};
    
    int num_bodies = 2;
    double t = 0;
    
    while (t < SIM_TIME)
    {
        calculate_gravity(&earth, &mars);
        calculate_gravity(&mars, &earth);
        
        move_bodies(&earth, 1, DT);
        move_bodies(&mars, 1, DT);
        
        printf("t=%.0f, Earth: x=%.0fkm y=%.0fkm, Mars: x=%.0fkm y=%.0fkm\n", t, earth.position.x/1000, earth.position.y/1000, mars.position.x/1000, mars.position.y/1000);
        
        t += DT;
    }
    
    return 0;
}