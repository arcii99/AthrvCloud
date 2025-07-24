//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // Newton's gravitational constant

struct Planet
{
    char name[20];
    double mass; // in kg
    double radius; // in km
    double x, y; // position vector components in km
    double vx, vy; // velocity vector components in km/s
    double ax, ay; // acceleration vector components in km/s^2
};

double distance(struct Planet p1, struct Planet p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

double force(struct Planet p1, struct Planet p2)
{
    double r = distance(p1, p2);
    return G * p1.mass * p2.mass / (r * r);
}

double acceleration(double f, double m)
{
    return f / m;
}

void update_position(struct Planet *p, double dt)
{
    p->x += p->vx * dt + 0.5 * p->ax * dt * dt;
    p->y += p->vy * dt + 0.5 * p->ay * dt * dt;
}

void update_velocity(struct Planet *p, double dt)
{
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
}

void update_acceleration(struct Planet *p1, struct Planet *p2)
{
    double f = force(*p1, *p2);
    double a = acceleration(f, p1->mass);
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double r = distance(*p1, *p2);
    p1->ax = a * dx / r;
    p1->ay = a * dy / r;
}

void print_planet(struct Planet p)
{
    printf("%s: mass = %.2e kg, radius = %.2f km, x = %.2f km, y = %.2f km, vx = %.2f km/s, vy = %.2f km/s\n",
           p.name, p.mass, p.radius, p.x, p.y, p.vx, p.vy);
}

int main()
{
    struct Planet sun = {"Sun", 1.989e30, 696340, 0, 0, 0, 0, 0};
    struct Planet earth = {"Earth", 5.972e24, 6378, 149.6e6, 0, 0, 29.78, 0};
    struct Planet moon = {"Moon", 7.342e22, 1737, 149.6e6+384400, 0, 0, 29.78+1.022, 0};
    
    int num_steps = 365*24*60*60/100; // simulate 1 year with 100 time steps per day
    double dt = 1.0 / 100; // time step of 1/100th of a day
    for (int i = 0; i < num_steps; i++)
    {
        update_acceleration(&earth, &sun);
        update_acceleration(&moon, &earth);
        update_acceleration(&moon, &sun);
        update_velocity(&earth, dt);
        update_velocity(&moon, dt);
        update_position(&earth, dt);
        update_position(&moon, dt);
        
        printf("Step %d: ", i+1);
        print_planet(earth);
        print_planet(moon);
        printf("\n");
    }
    
    return 0;
}