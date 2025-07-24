//FormAI DATASET v1.0 Category: Physics simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 9.8  // m/s^2
#define DELTA_T 0.1  // s
#define MAX_TIME 10  // s

int main() {
    double height = 10.0;  // m
    double velocity = 0.0; // m/s
    double time_elapsed = 0.0; // s
    
    while (time_elapsed <= MAX_TIME) {
        double position = height - 0.5 * GRAVITY * pow(time_elapsed, 2) + velocity * time_elapsed;
        printf("Time Elapsed: %0.1f s, Position: %0.2f m\n", time_elapsed, position);
        velocity = velocity - GRAVITY * DELTA_T;
        time_elapsed += DELTA_T;
        if (position <= 0.0) {
            break;
        }
        // Randomly add a gust of wind
        srand(time(NULL));
        double gust = ((double)rand() / (double)RAND_MAX) * 5.0;  // up to 5 m/s wind gust
        velocity += gust;
    }
    
    return 0;
}