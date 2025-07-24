//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Linus Torvalds
#include<stdio.h>
#include<math.h>

#define G  6.674e-11   // Gravitational constant 

#define SUN_MASS     1.98892e30
#define EARTH_MASS   5.97e24
#define MOON_MASS    7.342e22
#define MERCURY_MASS 3.3011e23
#define VENUS_MASS   4.872e24
#define MARS_MASS    6.39e23
#define JUPITER_MASS 1.8982e27
#define SATURN_MASS  5.683e26
#define URANUS_MASS  8.681e25
#define NEPTUNE_MASS 1.024e26
#define PLUTO_MASS   1.309e22

#define AU          149597870700   // Astronomical unit in meters

typedef struct {
    double x_pos;   // x-coordinate of position in meters
    double y_pos;   // y-coordinate of position in meters
    double x_vel;   // x-component of velocity in meters/sec
    double y_vel;   // y-component of velocity in meters/sec
    double mass;    // mass in kilograms
} body;

int main() {
    body sun    = {0, 0, 0, 0, SUN_MASS},
         earth  = {AU, 0, 0, 29783, EARTH_MASS},
         moon   = {AU + 384400e3, 0, 0, 1022, MOON_MASS},
         mercury= {0.39 * AU, 0, 0, 47870, MERCURY_MASS},
         venus  = {0.72 * AU, 0, 0, 35020, VENUS_MASS},
         mars   = {1.52 * AU, 0, 0, 24077, MARS_MASS},
         jupiter= {5.20 * AU, 0, 0, 13070, JUPITER_MASS},
         saturn = {9.58 * AU, 0, 0, 9690, SATURN_MASS},
         uranus = {19.18 * AU, 0, 0, 6810, URANUS_MASS},
         neptune= {30.07 * AU, 0, 0, 5430, NEPTUNE_MASS},
         pluto  = {39.48 * AU, 0, 0, 4740, PLUTO_MASS};

    body bodies[] = {sun, earth, moon, mercury, venus, mars, jupiter, saturn, uranus, neptune, pluto};
    int num_bodies = sizeof(bodies) / sizeof(bodies[0]);

    double ax[num_bodies], ay[num_bodies];
    double G_mass[num_bodies], dx, dy, r, f;

    double timestep = 3600;   // seconds
    double t, year = 365.25 * 24 * 3600;   // seconds

    printf("Simulation started\nYear: 0\n");

    for (t = 0; t < year; t += timestep) {

        for(int i=0;i<num_bodies;i++)
            G_mass[i] = G * bodies[i].mass;

        for (int i = 0; i < num_bodies; i++) {
            ax[i] = 0;
            ay[i] = 0;

            for (int j = 0; j < num_bodies; j++) {
                if (i == j) continue;
                dx = bodies[j].x_pos - bodies[i].x_pos;
                dy = bodies[j].y_pos - bodies[i].y_pos;
                r = sqrt(dx*dx + dy*dy);
                f = G_mass[i] * G_mass[j] / (r * r);
                ax[i] += f * dx / (r * bodies[i].mass);
                ay[i] += f * dy / (r * bodies[i].mass);
            }
        }

        for (int i = 0; i < num_bodies; i++) {
            bodies[i].x_pos += timestep * bodies[i].x_vel;
            bodies[i].y_pos += timestep * bodies[i].y_vel;
            bodies[i].x_vel += timestep * ax[i];
            bodies[i].y_vel += timestep * ay[i];
        }
          
        if((int)t % (int)year == 0) printf("Year: %d\n", (int)(t/year)+1);
        
    }

    printf("Simulation completed\n");

    return 0;
}