//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 3
#define LANE_LENGTH 20

void print_lane(int lane[]) {
    for (int i = 0; i < LANE_LENGTH; i++) {
        switch(lane[i]) {
            case 0:
                printf("."); // empty spot
                break;
            case 1:
                printf("|"); // car
                break;
            case 2:
                printf("="); // truck
                break;
            case 3:
                printf("O"); // obstacle
                break;
        }
    }
    printf("\n");
}

void update_lane(int lane[]) {
    int obstacles = rand() % 3;
    for (int i = 0; i < obstacles; i++) {
        int pos = rand() % LANE_LENGTH;
        lane[pos] = 3; // place an obstacle
    }

    for (int i = 0; i < LANE_LENGTH; i++) {
        if (lane[i] > 0) {
            if (i < LANE_LENGTH - 1 && lane[i+1] == 0) {
                lane[i+1] = lane[i]; // move right
                lane[i] = 0;
            }
            else if (i == LANE_LENGTH - 1) {
                lane[i] = 0; // reached end of lane
            }
        }
    }
}

int main() {
    srand(time(NULL)); // seed random generator

    int lanes[NUM_LANES][LANE_LENGTH] = {{0}};
    int scores[NUM_LANES] = {0};
    int gameover = 0;

    while(!gameover) {
        system("clear"); // clear console
        for (int i = 0; i < NUM_LANES; i++) {
            update_lane(lanes[i]);
            print_lane(lanes[i]);
            scores[i] += 1;
            if (lanes[i][LANE_LENGTH-1]) {
                printf("GAME OVER: Lane %d hit obstacle at score %d\n", i+1, scores[i]);
                gameover = 1;
            }
        }
        usleep(200000); // pause for 200ms
    }

    return 0;
}