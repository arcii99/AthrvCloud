//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANE_LENGTH 20
#define NUM_LANES 4
#define CYCLE_TIME 5

void print_lane(char lane[]) {
    printf("| ");
    for (int i = 0; i < LANE_LENGTH; i++) {
        printf("%c ", lane[i]);
    }
    printf("|\n");
}

void print_intersection(char lanes[NUM_LANES][LANE_LENGTH]) {
    printf("\n");
    printf("    North\n");
    printf("    |    \n");
    printf("West|East\n");
    printf("    |    \n");
    printf("    South\n");
    printf("\n");

    for (int i = 0; i < NUM_LANES; i++) {
        print_lane(lanes[i]);
    }
}

/* Move all cars in the lane forward by one position */
void move_cars_forward(char lane[]) {
    for (int i = LANE_LENGTH - 1; i > 0; i--) {
        lane[i] = lane[i - 1];
    }
    lane[0] = ' ';
}

/* Returns true if the lane is clear of cars */
int is_lane_clear(char lane[]) {
    for (int i = 0; i < LANE_LENGTH; i++) {
        if (lane[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

/* Add a new car at the front of the lane */
void add_car_to_lane(char lane[]) {
    lane[0] = 'X';
}

/* Simulate traffic flow for one cycle */
void simulate_traffic_flow(char lanes[NUM_LANES][LANE_LENGTH]) {
    /* Move cars all cars forward and remove cars that leave the lane */
    for (int i = 0; i < NUM_LANES; i++) {
        move_cars_forward(lanes[i]);
        if (lanes[i][LANE_LENGTH-1] != ' ') {
            lanes[i][LANE_LENGTH-1] = ' ';
        }
    }

    /* Determine which lanes should have new cars added */
    int north_south_has_car = (rand() % 2 == 0);
    int west_east_has_car = (rand() % 2 == 0);

    /* Add cars to the lanes that need them */
    if (north_south_has_car && is_lane_clear(lanes[0]) && is_lane_clear(lanes[2])) {
        add_car_to_lane(lanes[rand() % 2 == 0 ? 0 : 2]);
    }
    if (west_east_has_car && is_lane_clear(lanes[1]) && is_lane_clear(lanes[3])) {
        add_car_to_lane(lanes[rand() % 2 == 0 ? 1 : 3]);
    }
}

int main() {
    srand(time(NULL));

    /* Initialize all lanes to be empty */
    char lanes[NUM_LANES][LANE_LENGTH];
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < LANE_LENGTH; j++) {
            lanes[i][j] = ' ';
        }
    }

    int num_cycles = 10;
    for (int i = 1; i <= num_cycles; i++) {
        printf("Cycle %d:\n", i);
        simulate_traffic_flow(lanes);
        print_intersection(lanes);
        printf("\n");

        /* Sleep for the duration of the cycle time */
        printf("Waiting for next cycle...\n");
        for (int j = 0; j < CYCLE_TIME; j++) {
            printf("%d seconds remaining...\n", CYCLE_TIME - j);
            sleep(1);
        }
    }

    return 0;
}