//FormAI DATASET v1.0 Category: Physics simulation ; Style: energetic
#include <stdio.h>
#include <math.h>

int main() {
    float velocity, distance, time, acceleration;
    printf("Enter the initial velocity: ");
    scanf("%f", &velocity);
    printf("Enter the distance: ");
    scanf("%f", &distance);
    printf("Enter the time: ");
    scanf("%f", &time);
    acceleration = (2*(distance - (velocity * time))) / (time*time);
    printf("Acceleration is: %.2f m/s^2\n", acceleration);
    printf("Now let's simulate the motion using physics equations!\n");
    
    float t = 0.0, dt = 0.01, u = velocity, s = 0.0;
    while (s < distance) {
        float a = acceleration;
        float v = u + (a*dt);
        float ds = u*dt + 0.5*a*dt*dt;
        s = s+ds;
        t = t+dt;
        printf("At t=%.2f sec, distance traveled is %.2f m with velocity %.2f m/s and acceleration %.2f m/s^2\n", t, s, v, a);
        u = v;
    }

    printf("The simulation has ended at t=%.2f sec.\n", t);
    return 0;
}