//FormAI DATASET v1.0 Category: Physics simulation ; Style: unmistakable
#include <stdio.h>
#define MAX_TIME 1000000

int main()
{
    float x, y, z, vx, vy, vz, m, t, dt;
    float fx, fy, fz, ax, ay, az;
    int i;

    x = 0;
    y = 0;
    z = 0;
    vx = 0;
    vy = 0;
    vz = 0;
    m = 10;
    t = 0;
    dt = 0.01;

    for(i=1; i<MAX_TIME; i++)
    {
        fx = -(x/2);
        fy = -(y/2);
        fz = -(z/2);

        ax = fx/m;
        ay = fy/m;
        az = fz/m;

        vx = vx + ax*dt;
        vy = vy + ay*dt;
        vz = vz + az*dt;
        x = x + vx*dt;
        y = y + vy*dt;
        z = z + vz*dt;

        t = t + dt;

        printf("%f %f %f %f\n", t, x, y, z);
    }

    return 0;
}