//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator
    int traffic[24]; // array to hold traffic flow per hour
    int i, totalTraffic = 0;
    
    // random traffic flow generation
    for(i = 0; i < 24; i++) {
        traffic[i] = rand() % 500 + 100; // range from 100 to 600
        totalTraffic += traffic[i];
    }
    
    // output traffic flow per hour
    printf("%-10s%-10s\n", "Hour", "Traffic");
    for(i = 0; i < 24; i++) {
        printf("%-10d%-10d\n", i, traffic[i]);
    }
    
    // output total traffic for the day
    printf("Total traffic for the day is %d vehicles.\n", totalTraffic);
    
    return 0;
}