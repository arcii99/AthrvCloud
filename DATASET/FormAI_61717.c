//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: interoperable
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // Gravitational Constant
#define AU 149.6e9 // Astronomical Unit

struct body
{
    char name[20];
    double mass; // in kg
    double radius; // in m
    double position[3]; // in m
    double velocity[3]; // in m/s
    double acceleration[3]; // in m/s^2
};

int main()
{
    struct body sun = {"Sun", 1.989e30, 696340e3, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    struct body earth = {"Earth", 5.972e24, 6371e3, {AU, 0, 0}, {0, 29.78e3, 0}, {0, 0, 0}};
    struct body moon = {"Moon", 7.342e22, 1737.4e3, {AU + 384400e3, 0, 0}, {0, 1022, 0}, {0, 0, 0}};
    
    double time_step = 60; // in seconds
    double time = 0; // in seconds
    double end_time = 365 * 24 * 60 * 60; // 1 year
    
    while (time < end_time)
    {
        // calculate gravitational force between bodies
        double r12[3], force12[3], r23[3], force23[3];
        double mag_r12, mag_r23, mag_force12, mag_force23;
           
        for (int i = 0; i < 3; ++i)
        {
            r12[i] = earth.position[i] - sun.position[i];
            force12[i] = -G * sun.mass * earth.mass * r12[i] / pow(sqrt(pow(r12[0], 2) + pow(r12[1], 2) + pow(r12[2], 2)), 3);
            
            r23[i] = moon.position[i] - earth.position[i];
            force23[i] = -G * earth.mass * moon.mass * r23[i] / pow(sqrt(pow(r23[0], 2) + pow(r23[1], 2) + pow(r23[2], 2)), 3);
        }
        
        // update accelerations
        for (int i = 0; i < 3; ++i)
        {
            earth.acceleration[i] = force12[i] / earth.mass;
            moon.acceleration[i] = (force23[i] - force12[i]) / moon.mass;
        }
        
        // update velocities and positions with Euler's Method
        for (int i = 0; i < 3; ++i)
        {
            earth.velocity[i] += earth.acceleration[i] * time_step;
            earth.position[i] += earth.velocity[i] * time_step;
            
            moon.velocity[i] += moon.acceleration[i] * time_step;
            moon.position[i] += moon.velocity[i] * time_step;
        }
        
        // print positions
        printf("Time: %g s\n", time);
        printf("Sun: (%g, %g, %g) m\n", sun.position[0], sun.position[1], sun.position[2]);
        printf("Earth: (%g, %g, %g) m\n", earth.position[0], earth.position[1], earth.position[2]);
        printf("Moon: (%g, %g, %g) m\n", moon.position[0], moon.position[1], moon.position[2]);
        printf("\n");
        
        time += time_step;
    }

    return 0;
}