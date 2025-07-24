//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Constants */
#define G 6.67E-11 /* N*m^2/kg^2 */
#define MIN_STEP 86400 /* 1 day */

/* Struct to hold information about the planets */
typedef struct
{
    char name[20];
    double mass; /* kg */
    double radius; /* m */
    double x, y, z; /* Position in m */
    double vx, vy, vz; /* Velocity in m/s */
} Planet;

/* Function to calculate distance between two planets */
double distance(Planet p1, Planet p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

/* Function to calculate force between two planets */
double force(Planet p1, Planet p2)
{
    return (G * p1.mass * p2.mass) / pow(distance(p1, p2), 2);
}

/* Function to calculate acceleration of a planet due to all other planets */
void acceleration(Planet planets[], int num_planets, int current, double *ax, double *ay, double *az)
{
    int i;
    double fx, fy, fz;

    for (i = 0; i < num_planets; i++)
    {
        if (i != current)
        {
            fx = force(planets[current], planets[i]) * (planets[i].x - planets[current].x) / distance(planets[current], planets[i]);
            fy = force(planets[current], planets[i]) * (planets[i].y - planets[current].y) / distance(planets[current], planets[i]);
            fz = force(planets[current], planets[i]) * (planets[i].z - planets[current].z) / distance(planets[current], planets[i]);

            *ax += fx / planets[current].mass;
            *ay += fy / planets[current].mass;
            *az += fz / planets[current].mass;
        }
    }
}

/* Function to update position and velocity of a planet */
void update(Planet *planet, double ax, double ay, double az, double dt)
{
    planet->x += planet->vx * dt + 0.5 * ax * pow(dt, 2);
    planet->y += planet->vy * dt + 0.5 * ay * pow(dt, 2);
    planet->z += planet->vz * dt + 0.5 * az * pow(dt, 2);

    planet->vx += ax * dt;
    planet->vy += ay * dt;
    planet->vz += az * dt;
}

/* Main function */
int main()
{
    int num_planets = 2;
    Planet planets[num_planets];

    /* Initialize planets */
    sprintf(planets[0].name, "Earth");
    planets[0].mass = 5.97E24;
    planets[0].radius = 6371E3;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;

    sprintf(planets[1].name, "Moon");
    planets[1].mass = 7.34E22;
    planets[1].radius = 1737E3;
    planets[1].x = 384400E3;
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].vx = 0;
    planets[1].vy = 1022;
    planets[1].vz = 0;

    /* Simulation loop */
    int i, j, step = 1;
    double ax, ay, az, dt = MIN_STEP;
    for (i = 0; i < 10000; i++) /* Run for 10000 days */
    {
        for (j = 0; j < num_planets; j++) /* Update all planets */
        {
            ax = 0;
            ay = 0;
            az = 0;
            acceleration(planets, num_planets, j, &ax, &ay, &az);
            update(&planets[j], ax, ay, az, dt);
        }

        if (i % step == 0) /* Print position of each planet */
        {
            printf("Day %d\n", i);
            for (j = 0; j < num_planets; j++)
            {
                printf("%s x:%.2f y:%.2f z:%.2f\n", planets[j].name, planets[j].x, planets[j].y, planets[j].z);
            }
            printf("\n");
        }
    }

    return 0;
}