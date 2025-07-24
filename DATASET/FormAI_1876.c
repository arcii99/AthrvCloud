//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int traffic_flow[5][10];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
            traffic_flow[i][j] = rand() % 3; // 0 for no vehicle, 1 for car, 2 for truck
        }
    }

    printf("    |   Hwy 1   |   Hwy 2   |   Hwy 3   |   Hwy 4   |   Hwy 5   \n");
    printf("------------------------------------------------------------------\n");

    for(int r = 0; r < 10; r++) {
        printf(" %2d |", r+1);
        for(int c = 0; c < 5; c++) {
            if(traffic_flow[c][r] == 0) {
                printf("   -    |");
            } else if(traffic_flow[c][r] == 1) {
                printf("   CAR  |");
            } else {
                printf(" TRUCK  |");
            }
        }
        printf("\n");
    }
    return 0;
}