//FormAI DATASET v1.0 Category: Physics simulation ; Style: introspective
#include <stdio.h>

int main() {
    int mass, velocity, time, force;
    
    printf("Please enter the mass of the object in kg: ");
    scanf("%d", &mass);
    
    printf("Please enter the velocity of the object in m/s: ");
    scanf("%d", &velocity);
    
    printf("Please enter the time duration in seconds: ");
    scanf("%d", &time);
    
    force = mass * velocity / time;
    
    printf("The force exerted on the object is %d N.\n", force);
    
    return 0;
}