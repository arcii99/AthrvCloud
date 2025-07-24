//FormAI DATASET v1.0 Category: Physics simulation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//constants
#define G 6.674e-11 //gravitational constant

//functions
double get_distance(double x1, double y1, double x2, double y2);
double get_force(double m1, double m2, double distance);
void update_velocity(double *vx, double *vy, double ax, double ay, double time_step);
void update_position(double *x, double *y, double vx, double vy, double time_step);

int main()
{
    //random number generator seed
    srand(time(0));

    //initialize variables
    int num_bodies = 3;
    double mass[num_bodies];
    double x[num_bodies];
    double y[num_bodies];
    double vx[num_bodies];
    double vy[num_bodies];

    //initialize masses, positions, and velocities
    for(int i=0; i<num_bodies; i++)
    {
        mass[i] = (double)(rand()%10 + 1);
        x[i] = (double)(rand()%10 + 1);
        y[i] = (double)(rand()%10 + 1);
        vx[i] = (double)(rand()%10 + 1);
        vy[i] = (double)(rand()%10 + 1);
    }

    //simulation parameters
    double time_step = 1.0;
    double simulation_time = 10.0;

    //simulation loop
    for(double t=0.0; t<simulation_time; t+=time_step)
    {
        for(int i=0; i<num_bodies; i++)
        {
            double ax = 0.0;
            double ay = 0.0;

            for(int j=0; j<num_bodies; j++)
            {
                if(i == j)
                {
                    continue;
                }

                double distance = get_distance(x[i], y[i], x[j], y[j]);
                double force = get_force(mass[i], mass[j], distance);
                double fx = force * (x[j] - x[i]) / distance;
                double fy = force * (y[j] - y[i]) / distance;

                ax += fx / mass[i];
                ay += fy / mass[i];
            }

            update_velocity(&vx[i], &vy[i], ax, ay, time_step);
            update_position(&x[i], &y[i], vx[i], vy[i], time_step);
        }
    }

    //print final positions and velocities
    for(int i=0; i<num_bodies; i++)
    {
        printf("Body %d: Position = (%lf, %lf), Velocity = (%lf, %lf)\n", i+1, x[i], y[i], vx[i], vy[i]);
    }

    return 0;
}

//calculate distance between two points
double get_distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
}

//calculate gravitational force between two bodies
double get_force(double m1, double m2, double distance)
{
    return G * m1 * m2 / pow(distance, 2.0);
}

//update body velocity based on acceleration
void update_velocity(double *vx, double *vy, double ax, double ay, double time_step)
{
    *vx += ax * time_step;
    *vy += ay * time_step;
}

//update body position based on velocity
void update_position(double *x, double *y, double vx, double vy, double time_step)
{
    *x += vx * time_step;
    *y += vy * time_step;
}