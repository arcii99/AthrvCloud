//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>

int remote_control(int speed, int distance);

int main() {
    int speed = 5;
    int distance = 10;
    int total_distance;
    
    total_distance = remote_control(speed, distance);
    
    printf("The remote control vehicle travelled %d units.\n", total_distance);
    
    return 0;
}

int remote_control(int speed, int distance) {
    if (distance == 0) {
        return 0;
    } else {
        printf("The vehicle is travelling at speed %d.\n", speed);
        return speed + remote_control(speed, distance-1);
    }
}