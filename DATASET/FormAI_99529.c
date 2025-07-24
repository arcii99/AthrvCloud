//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    int hour, minute, current_speed, traffic_intensity;
    float speed_limit;
 
    printf("Enter the current hour: ");
    scanf("%d", &hour);
    printf("Enter current minute: ");
    scanf("%d", &minute);
 
    // initializing random seed
    srand(time(0));
 
    // generating random speed limit
    speed_limit = rand() % 76 + 25;
 
    // generating random traffic intensity between 1 and 10
    traffic_intensity = rand() % 10 + 1;
 
    printf("Speed limit on this road is %.2f mph.\n", speed_limit);
    printf("Traffic intensity is %d/10 vehicles.\n", traffic_intensity);
 
    // generating random current speed based on traffic intensity
    if (traffic_intensity > 3 && traffic_intensity <= 7) {
        current_speed = rand() % 36 + 25;
    } else if (traffic_intensity > 7) {
        current_speed = rand() % 31 + 10;
    } else {
        current_speed = rand() % 31 + 40;
    }
 
    // making sure current speed does not exceed speed limit
    if (current_speed > speed_limit) {
        printf("You are driving too fast! Slow down.\n");
        current_speed = speed_limit;
    }
 
    printf("It is currently %02d:%02d and your current speed is %d mph.\n", hour, minute, current_speed);
 
    return 0;
}