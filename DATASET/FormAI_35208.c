//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 5
#define MAX_DISTANCE 100

int main() {
    srand(time(0));

    int distance = rand() % MAX_DISTANCE + 1;
    int speed = rand() % MAX_SPEED + 1;
    int time_taken = distance / speed;

    printf("Distance to travel: %d meters\n", distance);
    printf("Maximum speed: %d meters per second\n", speed);
    printf("Time taken: %d seconds\n", time_taken);

    int current_distance = 0;
    int current_speed = 0;
    int current_time = 0;
    
    while(current_distance < distance) {
        printf("Vehicle position: %d meters, Speed: %d meters per second, Time taken: %d seconds\n", current_distance, current_speed, current_time);
        current_distance += current_speed;
        current_speed += rand() % 2 - 1; // Randomly increase or decrease speed by 1
        current_speed = (current_speed < 0) ? 0 : current_speed; // Ensure speed is never negative
        current_speed = (current_speed > speed) ? speed : current_speed; // Ensure speed never exceeds maximum speed
        current_time++;
    }

    printf("Vehicle has reached destination in %d seconds!\n", current_time);

    return 0;
}