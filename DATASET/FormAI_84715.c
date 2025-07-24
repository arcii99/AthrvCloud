//FormAI DATASET v1.0 Category: Physics simulation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define G 9.81

int main()
{
    double v0, theta, t, dt;
    double x, y, vx, vy;
    double ax, ay;
    int i;
    
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &v0);
    
    printf("Enter the launch angle (degrees): ");
    scanf("%lf", &theta);
    theta *= PI / 180.0;
    
    printf("Enter the time step (s): ");
    scanf("%lf", &dt);
    
    x = 0.0;
    y = 0.0;
    vx = v0 * cos(theta);
    vy = v0 * sin(theta);
    
    printf("time\tx\ty\tvx\tvy\n");
    printf("----\t--\t--\t--\t--\n");
    
    for (i = 0, t = 0.0; y >= 0.0; i++, t += dt)
    {
        ax = 0.0;
        ay = -G;
        
        vx += ax * dt;
        vy += ay * dt;
        
        x += vx * dt;
        y += vy * dt;
        
        printf("%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n", t, x, y, vx, vy);
    }
    
    printf("The projectile hit the ground at time %.2lf s and distance %.2lf m.\n", t, x);
    
    return 0;
}