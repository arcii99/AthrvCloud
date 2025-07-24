//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: irregular
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

typedef struct
{
    double x;
    double y;
} Vector2D;

typedef struct
{
    Vector2D pos;
    Vector2D vel;
    Vector2D force;
    double mass;
} Body;

void calculate_force(Body *body, Body *other_body)
{
    Vector2D r, F;
    double dist, force_mag;
    
    r.x = other_body->pos.x - body->pos.x;
    r.y = other_body->pos.y - body->pos.y;
    dist = sqrt(r.x*r.x + r.y*r.y);
    force_mag = G*body->mass*other_body->mass/(dist*dist);
    
    F.x = force_mag*r.x/dist;
    F.y = force_mag*r.y/dist;
    
    body->force.x += F.x;
    body->force.y += F.y;
}

void calculate_forces(Body *bodies, int num_bodies)
{
    for (int i = 0; i < num_bodies; i++)
    {
        for (int j = 0; j < num_bodies; j++)
        {
            if (i != j)
            {
                calculate_force(&bodies[i], &bodies[j]);
            }
        }
    }
}

void update_body(Body *body, double dt)
{
    body->vel.x += (body->force.x/body->mass)*dt;
    body->vel.y += (body->force.y/body->mass)*dt;
    body->pos.x += body->vel.x*dt;
    body->pos.y += body->vel.y*dt;
    body->force.x = 0;
    body->force.y = 0;
}

void update_bodies(Body *bodies, int num_bodies, double dt)
{
    for (int i = 0; i < num_bodies; i++)
    {
        update_body(&bodies[i], dt);
    }
}

int main()
{
    int num_bodies = 4;
    Body bodies[num_bodies];
    
    // Sun
    bodies[0].pos.x = 0;
    bodies[0].pos.y = 0;
    bodies[0].vel.x = 0;
    bodies[0].vel.y = 0;
    bodies[0].mass = 1.989e30;
    
    // Earth
    bodies[1].pos.x = 1.496e11;
    bodies[1].pos.y = 0;
    bodies[1].vel.x = 0;
    bodies[1].vel.y = 29783;
    bodies[1].mass = 5.972e24;
    
    // Moon
    bodies[2].pos.x = 1.496e11 + 384400000;
    bodies[2].pos.y = 0;
    bodies[2].vel.x = 0;
    bodies[2].vel.y = 3079 + 29783;
    bodies[2].mass = 7.342e22;
    
    // Mars
    bodies[3].pos.x = 2.279e11;
    bodies[3].pos.y = 0;
    bodies[3].vel.x = 0;
    bodies[3].vel.y = 24077;
    bodies[3].mass = 6.39e23;
    
    double dt = 3600*24;
    double simulation_time = 3600*24*365*2; // 2 years
    
    for (double t = 0; t < simulation_time; t += dt)
    {
        calculate_forces(bodies, num_bodies);
        update_bodies(bodies, num_bodies, dt);
    }
    
    printf("Final positions:\n");
    for (int i = 0; i < num_bodies; i++)
    {
        printf("Body %d: (%e, %e)\n", i, bodies[i].pos.x, bodies[i].pos.y);
    }
    
    return 0;
}