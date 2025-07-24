//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: rigorous
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant
#define pi 3.14159265358979323846 // value of pi

typedef struct // structure for storing the position, velocity and acceleration of each celestial body
{
    double x, y, z, vx, vy, vz, ax, ay, az;
} celestial_body;

void update_acceleration(celestial_body* cb, int n) // function to calculate acceleration of each celestial body
{
    int i, j;
    double dx, dy, dz, dist, dist_cubed, force;

    for (i = 0; i < n; i++)
    {
        cb[i].ax = cb[i].ay = cb[i].az = 0;

        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            dx = cb[j].x - cb[i].x;
            dy = cb[j].y - cb[i].y;
            dz = cb[j].z - cb[i].z;

            dist = sqrt(dx*dx + dy*dy + dz*dz);
            dist_cubed = dist*dist*dist;

            force = G*cb[j].vx/dist_cubed;

            cb[i].ax += force*dx;
            cb[i].ay += force*dy;
            cb[i].az += force*dz;
        }
    }
}

void update_velocity(celestial_body* cb, double dt, int n) // function to update velocity of each celestial body
{
    int i;

    for (i = 0; i < n; i++)
    {
        cb[i].vx += cb[i].ax*dt;
        cb[i].vy += cb[i].ay*dt;
        cb[i].vz += cb[i].az*dt;
    }
}

void update_position(celestial_body* cb, double dt, int n) // function to update position of each celestial body
{
    int i;

    for (i = 0; i < n; i++)
    {
        cb[i].x += cb[i].vx*dt;
        cb[i].y += cb[i].vy*dt;
        cb[i].z += cb[i].vz*dt;
    }
}

void print_pos(celestial_body* cb, char* name, int n) // utility function to print the position of each celestial body
{
    int i;

    printf("%s\n", name);
    for (i = 0; i < n; i++)
    {
        printf("Body %d: (%f, %f, %f)\n", i+1, cb[i].x, cb[i].y, cb[i].z);
    }
}

int main()
{
    int n = 5, i;
    double tmax = 365*24*3600*5, dt = 3600*24;
    celestial_body cb[n];

    cb[0] = (celestial_body) {1.496e11, 0, 0, 0, 29783, 0, 0, 0, 0}; // sun
    cb[1] = (celestial_body) {0, 0, 0, 0, 0, 0, 0, 0, 0}; // mercury
    cb[2] = (celestial_body) {5.790e10, 0, 0, 0, 0, 47870, 0, 0, 0}; // venus
    cb[3] = (celestial_body) {1.082e11, 0, 0, 0, 35020, 0, 0, 0, 0}; // earth
    cb[4] = (celestial_body) {1.496e11, 7.788e10, 0, -23560, 0, 0, 0, 0, 0}; // mars

    for (i = 0; i < tmax/dt; i++)
    {
        update_acceleration(cb, n);
        update_velocity(cb, dt, n);
        update_position(cb, dt, n);
    }

    print_pos(cb, "Final positions:", n);

    return 0;
}