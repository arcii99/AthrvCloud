//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>

int main() {
    float velocity, acceleration, time, distance;
    
    printf("Enter the velocity (in meters per second): ");
    scanf("%f", &velocity);
    
    printf("Enter the acceleration (in meters per second squared): ");
    scanf("%f", &acceleration);
    
    printf("Enter the time (in seconds): ");
    scanf("%f", &time);
    
    distance = velocity * time + 0.5 * acceleration * time * time;
    
    printf("The distance traveled is %.2f meters\n", distance);
    
    return 0;
}