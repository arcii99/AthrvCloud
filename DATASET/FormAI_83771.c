//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int current_latitude = 0;
int current_longitude = 0;

int generate_coord() {
    // generate random coordinate between -10 and 10
    int coord = rand() % 21 - 10;
    return coord;
}

void update_location() {
    // generate new coordinates and update current location
    current_latitude += generate_coord();
    current_longitude += generate_coord();
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // simulate driving and updating location every 5 seconds
    for(int i = 0; i < 10; i++) {
        printf("Current location: (%d, %d)\n", current_latitude, current_longitude);
        update_location();
        printf("Updated location: (%d, %d)\n", current_latitude, current_longitude);
        printf("-------------------------\n");
        sleep(5);
    }

    return 0;
}