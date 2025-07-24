//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROADS 6
#define LANES 3
#define CARS_PER_LANE 10
#define TICK_DELAY 1000000

int main(void) {
    int traffic[ROADS][LANES][CARS_PER_LANE];
    int i, j, k;
    srand((unsigned int)time(NULL));
    printf("Welcome to the Traffic Flow Simulator!\n");
    printf("Press ctrl+c to quit at any time.\n\n");
    for(i = 0; i < ROADS; i++) {
        for(j = 0; j < LANES; j++) {
            for(k = 0; k < CARS_PER_LANE; k++) {
                traffic[i][j][k] = (rand() % 2 == 0) ? 1 : 0;
            }
        }
    }

    while(1) {
        system("clear");
        printf("Traffic Simulation:\n\n");
        for(i = 0; i < LANES; i++) {
            for(j = 0; j < ROADS; j++) {
                printf("|");
                for(k = 0; k < CARS_PER_LANE; k++) {
                    if(traffic[j][i][k] == 1) {
                        printf(" car ");
                    } else {
                        printf("     ");
                    }
                }
                printf("| ");
            }
            printf("\n");
        }
        usleep(TICK_DELAY);
        // Move cars forward
        for(i = 0; i < ROADS; i++) {
            for(j = 0; j < LANES; j++) {
                for(k = CARS_PER_LANE - 1; k > 0; k--) {
                    traffic[i][j][k] = traffic[i][j][k-1];
                }
                traffic[i][j][0] = (rand() % 2 == 0) ? 1 : 0;
            }
        }
    }
    return 0;
}