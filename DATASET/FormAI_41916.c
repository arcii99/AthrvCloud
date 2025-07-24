//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANES 3
#define MAX_CARS 10
#define MAX_SPEED 5

int traffic[LANES][MAX_CARS] = {0};

void display_traffic() {
    for(int i=0; i<LANES; i++) {
        for(int j=0; j<MAX_CARS; j++) {
            if(traffic[i][j] == -1) {
                printf("%c ", '|');
            } else {
                printf("%d ", traffic[i][j]); 
            }
        }
        printf("\n");
    }
}

void update_cars() {
    for(int i=0; i<LANES; i++) {
        int j = MAX_CARS - 1;
        while(j > 0) {
            if(traffic[i][j-1] == -1) {
                traffic[i][j] = -1; // Car has left the road
            } else if(traffic[i][j] == -1) {
                traffic[i][j] = traffic[i][j-1]; // Car has moved forward
                traffic[i][j-1] = -1; // Car has left the previous spot
            } else {
                traffic[i][j] = traffic[i][j-1] - 1; // Move the car forward based on speed
            }
            j--;
        }

        if(traffic[i][0] == -1) {
            // Add a new car to the road
            traffic[i][0] = rand() % MAX_SPEED + 1;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    for(int i=0; i<LANES; i++) {
        for(int j=0; j<MAX_CARS; j++) {
            if(j == 0) {
                traffic[i][j] = rand() % MAX_SPEED + 1; // Add a random speed to the first car
            } else {
                traffic[i][j] = -1; // Mark the rest of the lane as empty
            }
        }
    }

    while(1) {
        system("clear"); // Clear the terminal

        display_traffic();

        update_cars(); 

        usleep(500000); // Wait for half a second before updating again
    }

    return 0;
}