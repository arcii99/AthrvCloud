//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: synchronous
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define solar system constants
#define G 6.67430e-11  // gravitational constant
#define M_sun 1.989e30 // mass of the sun
#define AU 149597870700 // astronomical unit

// Define planet constants
#define M_mercury 0.330e24
#define r_mercury 57909050000
#define v_mercury 47873.7
#define M_venus 4.87e24
#define r_venus 108208930000
#define v_venus 35020.5
#define M_earth 5.97e24
#define r_earth 149597870700
#define v_earth 29783.9
#define M_mars 0.642e24
#define r_mars 227936640000
#define v_mars 24130.3
#define M_jupiter 1898e24
#define r_jupiter 778412010000
#define v_jupiter 13069.7
#define M_saturn 568e24
#define r_saturn 1426725400000
#define v_saturn 9691.1
#define M_uranus 86.8e24
#define r_uranus 2870972200000
#define v_uranus 6806.6
#define M_neptune 102e24
#define r_neptune 4503443661000
#define v_neptune 5436.3

int main()
{
    double p[8][2] = { // planet positions
        {r_mercury, 0},
        {0, r_venus},
        {-r_earth, 0},
        {0, -r_mars},
        {r_jupiter, 0},
        {0, -r_saturn},
        {-r_uranus, 0},
        {0, r_neptune}
    };

    double v[8][2] = { // planet velocities
        {0, v_mercury},
        {-v_venus, 0},
        {0, -v_earth},
        {v_mars, 0},
        {0, v_jupiter},
        {v_saturn, 0},
        {0, -v_uranus},
        {-v_neptune, 0}
    };

    double a[8][2] = { // planet accelerations
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0}
    };

    double t = 0;           // simulation time
    double dt = 86400;      // time step (1 day)
    int steps = 365*10;     // number of steps (10 years)
    int i, j, k;            // loop indices

    // Perform simulation
    for (i = 0; i < steps; i++) {
        // Calculate accelerations
        for (j = 0; j < 8; j++) {
            a[j][0] = a[j][1] = 0;
            for (k = 0; k < 8; k++) {
                if (j == k) continue;
                double d = sqrt(pow(p[j][0] - p[k][0], 2) + pow(p[j][1] - p[k][1], 2));
                double f = G * M_sun * (k == 0 ? M_mercury : k == 1 ? M_venus : k == 2 ? M_earth :
                                        k == 3 ? M_mars : k == 4 ? M_jupiter : k == 5 ? M_saturn :
                                        k == 6 ? M_uranus : M_neptune) / pow(d, 2);
                double theta = atan2(p[k][1] - p[j][1], p[k][0] - p[j][0]);
                a[j][0] += f * cos(theta);
                a[j][1] += f * sin(theta);
            }
        }

        // Update positions and velocities
        for (j = 0; j < 8; j++) {
            p[j][0] += v[j][0] * dt + 0.5 * a[j][0] * pow(dt, 2);
            p[j][1] += v[j][1] * dt + 0.5 * a[j][1] * pow(dt, 2);
            v[j][0] += a[j][0] * dt;
            v[j][1] += a[j][1] * dt;
        }

        // Print current state
        printf("t = %.2f years:\n", t / 31536000);
        for (j = 0; j < 8; j++) {
            printf("%-8s: (%.2e, %.2e) m, (%.2e, %.2e) m/s\n",
                    j == 0 ? "Mercury" : j == 1 ? "Venus" : j == 2 ? "Earth" :
                    j == 3 ? "Mars" : j == 4 ? "Jupiter" : j == 5 ? "Saturn" :
                    j == 6 ? "Uranus" : "Neptune",
                    p[j][0], p[j][1], v[j][0], v[j][1]);
        }
        printf("\n");

        // Update time
        t += dt;
    }

    return 0;
}