//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the Solar System Simulation!\n");
    printf("Buckle up, we're about to take a wild ride through space!\n");

    int i, j, k;
    int num_bodies = 8;
    double G = 6.674E-11;  // gravitational constant
    double time_step = 86400;  // one day in seconds
    double timescale = 365;  // simulate one year
    double m[8] = {1.9885E30, 3.3011E23, 4.8675E24, 5.9724E24, 6.4185E23, 1.8986E27, 5.6846E26, 8.681E25};
    double x[8][3] = {{0,0,0}, {0,-57.9E9,0}, {0,0,0.723E11}, {0,0,1.496E11}, {0,0,2.279E11}, {0,0,7.78E11}, {0,0,1.43E12}, {0,0,2.87E12}};  // initial positions
    double v[8][3] = {{0,0,0}, {47.9E3,0,0}, {0,35.26E3,0}, {0,29.78E3,0}, {0,24.077E3,0}, {0,13.072E3,0}, {0,8.2E3,0}, {0,5.4E3,0}};  // initial velocities
    char* planets[8] = {"Sun", "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus"};

    for (i=0;i<timescale;i++){
        printf("Year %d:\n", i+1);
        for (j=0;j<num_bodies;j++){
            printf("%s: position (%.2f,%.2f,%.2f)\n", planets[j], x[j][0], x[j][1], x[j][2]);
            for (k=0;k<num_bodies;k++){
                if (j==k){
                    continue;
                }
                double distance = sqrt(pow(x[k][0]-x[j][0], 2) + pow(x[k][1]-x[j][1], 2) + pow(x[k][2]-x[j][2], 2));
                double acceleration = G * m[k] / pow(distance, 2);
                double ax = acceleration * (x[k][0]-x[j][0]) / distance;
                double ay = acceleration * (x[k][1]-x[j][1]) / distance;
                double az = acceleration * (x[k][2]-x[j][2]) / distance;
                v[j][0] += ax * time_step;
                v[j][1] += ay * time_step;
                v[j][2] += az * time_step;
            }
            x[j][0] += v[j][0] * time_step;
            x[j][1] += v[j][1] * time_step;
            x[j][2] += v[j][2] * time_step;
        }
    }

    printf("Simulation complete! Hope you had a blast!\n");

    return 0;
}