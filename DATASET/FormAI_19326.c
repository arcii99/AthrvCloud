//FormAI DATASET v1.0 Category: Physics simulation ; Style: Cryptic
#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;
    int z = 0;
    int time = 0;
    int velocity_x = 0;
    int velocity_y = 0;
    int velocity_z = 0;
    int acceleration_x = 0;
    int acceleration_y = 0;
    int acceleration_z = -9.81; // acceleration due to gravity
    
    printf("Enter initial velocity in x-direction: ");
    scanf("%d", &velocity_x);
    printf("Enter initial velocity in y-direction: ");
    scanf("%d", &velocity_y);
    printf("Enter initial velocity in z-direction: ");
    scanf("%d", &velocity_z);
    
    while (z >= 0) {
        time++;
        x = x + velocity_x + 0.5 * acceleration_x * time * time;
        y = y + velocity_y + 0.5 * acceleration_y * time * time;
        z = z + velocity_z + 0.5 * acceleration_z * time * time;
        velocity_x = velocity_x + acceleration_x * time;
        velocity_y = velocity_y + acceleration_y * time;
        velocity_z = velocity_z + acceleration_z * time;
        
        printf("Time: %d seconds, Position: (%d, %d, %d), Velocity: (%d, %d, %d)\n", time, x, y, z, velocity_x, velocity_y, velocity_z);
    }
    
    printf("The object has hit the ground in %d seconds\n", time);

    return 0;
}