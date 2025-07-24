//FormAI DATASET v1.0 Category: Physics simulation ; Style: Cryptic
#include <stdio.h>
#include <math.h>

//Cryptic C Physics simulation program
//Calculates the trajectory of a projectile
//Funky variable naming scheme for added mystery

int main() {
    int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    int y1 = 0, y2 = 0, y3 = 0, y4 = 0;
    int z1 = 0, z2 = 0, z3 = 0, z4 = 0;

    double v0 = 50, a = 45, t = 0.001;
    double vx = v0*cos(a*(M_PI/180));
    double vy = v0*sin(a*(M_PI/180));
    double vz = 0;

    while (y4 >= 0) {
        y4 = y1 + vy*t + 0.5*(-9.81)*pow(t,2);
        x4 = x1 + vx*t;
        z4 = z1 + vz*t;

        printf("Projectile at coordinates: (%d, %d, %d)\n", x4, y4, z4);
        
        y1 = y2; y2 = y3; y3 = y4;
        x1 = x2; x2 = x3; x3 = x4;
        z1 = z2; z2 = z3; z3 = z4;

        vy += (-9.81)*t;
    }

    return 0;
}