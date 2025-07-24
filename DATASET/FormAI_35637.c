//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//defining constants
#define G 6.674e-11 //universal gravitational constant
#define INTERVAL 0.001 // time interval
#define STEPS 100000 //total number of steps

int main()
{
    double m1, m2, r, d, v1[2], v2[2], a1[2], a2[2], p1[2], p2[2];
    double t, fx, fy, f, dx, dy, dist, dist_cubed, dt_sqr;

    //initializing planet 1 parameters
    m1 = 5.97e+24;
    p1[0] = 0;
    p1[1] = 0;
    v1[0] = 0;
    v1[1] = 0;

    //initializing planet 2 parameters
    m2 = 6.39e+23;
    p2[0] = 3.84e+8;
    p2[1] = 0;
    v2[0] = 0;
    v2[1] = 1022;

    //calculating initial distance and force between 2 planets
    dx = p1[0] - p2[0];
    dy = p1[1] - p2[1];
    dist = sqrt(dx*dx + dy*dy);
    dist_cubed = dist*dist*dist;
    f = (G*m1*m2)/dist_cubed;
    fx = f*dx;
    fy = f*dy;

    //performing simulation for each time step
    for(int i = 0; i < STEPS; i++)
    {
        //calculating acceleration for each planet
        a1[0] = -fx/m1;
        a1[1] = -fy/m1;
        a2[0] = fx/m2;
        a2[1] = fy/m2;

        //updating position for each planet
        p1[0] += v1[0]*INTERVAL + 0.5*a1[0]*INTERVAL*INTERVAL;
        p1[1] += v1[1]*INTERVAL + 0.5*a1[1]*INTERVAL*INTERVAL;

        p2[0] += v2[0]*INTERVAL + 0.5*a2[0]*INTERVAL*INTERVAL;
        p2[1] += v2[1]*INTERVAL + 0.5*a2[1]*INTERVAL*INTERVAL;

        //updating velocity for each planet
        v1[0] += a1[0]*INTERVAL;
        v1[1] += a1[1]*INTERVAL;

        v2[0] += a2[0]*INTERVAL;
        v2[1] += a2[1]*INTERVAL;

        //calculating new distance and force between 2 planets
        dx = p1[0] - p2[0];
        dy = p1[1] - p2[1];
        dist = sqrt(dx*dx + dy*dy);
        dist_cubed = dist*dist*dist;
        f = (G*m1*m2)/dist_cubed;
        fx = f*dx;
        fy = f*dy;

        //printing time, planet1 and planet2 positions
        if(i%5 == 0) //printing only for few steps
        {
            printf("Time: %.2f s\tPlanet1: (%.2f, %.2f) m\tPlanet2: (%.2f, %.2f) m\n", i*INTERVAL, p1[0], p1[1], p2[0], p2[1]);
        }
    }

    return 0;
}