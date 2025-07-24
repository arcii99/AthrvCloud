//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: enthusiastic
/* Welcome to the amazing Airport Baggage Handling Simulation Program! */
/* This program simulates the handling of baggage at an airport */
/* Get ready to experience the thrill of virtual baggage handling */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* Define the number of conveyor belts, dropping points and flights */
#define CONVEYOR_BELT_NUM 3
#define DROPPING_POINT_NUM 2
#define FLIGHT_NUM 5

/* Define the maximum possible bags that can be handled at a single time */
#define MAX_BAGS 10

/* Define the timeout period between dropping a new bag */
#define TIMEOUT 3

/* Define the structure of the bags */
struct bag {
    int bag_id;
    int dropping_point;
};

/* Define the structure of the conveyor belt */
struct conveyor_belt {
    int belt_id;
    int bag_num;
    struct bag bags[MAX_BAGS];
};

/* Define the structure of the dropping area */
struct dropping_area {
    int dropping_point_id;
    int bag_num;
    struct bag bags[MAX_BAGS];
};

/* Function declaration for handling the dropping of bags */
void handle_dropping(struct dropping_area dropping_points[DROPPING_POINT_NUM]);

/* Function declaration for handling the movement of bags along the conveyor belts */
void handle_movement(struct conveyor_belt conveyor_belts[CONVEYOR_BELT_NUM], struct dropping_area dropping_points[DROPPING_POINT_NUM]);

/* Main function */
int main() {
    struct conveyor_belt conveyor_belts[CONVEYOR_BELT_NUM];
    struct dropping_area dropping_points[DROPPING_POINT_NUM];
    int i, j, k;

    /* Initialize all conveyor belts to have no bags on them */
    for(i=0;i<CONVEYOR_BELT_NUM;i++) {
        conveyor_belts[i].belt_id = i+1;
        conveyor_belts[i].bag_num = 0;
    }

    /* Initialize all dropping points to have no bags at them */
    for(i=0;i<DROPPING_POINT_NUM;i++) {
        dropping_points[i].dropping_point_id = i+1;
        dropping_points[i].bag_num = 0;
    }

    /* Generate bags and handle them until the simulation is stopped */
    srand(time(NULL)); /* Seed the random number generator */
    while(true) {
        printf("Generating new bag...\n");
        struct bag new_bag;
        new_bag.bag_id = rand() % 1000 + 1;
        new_bag.dropping_point = rand() % DROPPING_POINT_NUM + 1;
        int belt_idx = rand() % CONVEYOR_BELT_NUM;
        if(conveyor_belts[belt_idx].bag_num < MAX_BAGS) {
            printf("Dropping bag %d on belt %d...\n", new_bag.bag_id, belt_idx+1);
            conveyor_belts[belt_idx].bags[conveyor_belts[belt_idx].bag_num] = new_bag;
            conveyor_belts[belt_idx].bag_num++;
        } else {
            printf("Belt %d is full, discarding bag %d...\n", belt_idx+1, new_bag.bag_id);
        }
        handle_dropping(dropping_points);
        handle_movement(conveyor_belts, dropping_points);
        printf("Sleeping for %d seconds...\n", TIMEOUT);
        sleep(TIMEOUT);
    }

    return 0;
}

/* Function to handle the dropping of bags at their respective dropping points */
void handle_dropping(struct dropping_area dropping_points[DROPPING_POINT_NUM]) {
    int i, j;
    for(i=0;i<DROPPING_POINT_NUM;i++) {
        int dropping_point_id = i+1;
        for(j=0;j<dropping_points[i].bag_num;j++) {
            if(dropping_points[i].bags[j].dropping_point == dropping_point_id) {
                printf("Bag %d has been dropped off at Dropping Point %d.\n", dropping_points[i].bags[j].bag_id, dropping_point_id);
                dropping_points[i].bags[j] = dropping_points[i].bags[dropping_points[i].bag_num-1];
                dropping_points[i].bag_num--;
                j--;
            }
        }
    }
}

/* Function to handle the movement of bags along the conveyor belts */
void handle_movement(struct conveyor_belt conveyor_belts[CONVEYOR_BELT_NUM], struct dropping_area dropping_points[DROPPING_POINT_NUM]) {
    int i, j;
    for(i=0;i<CONVEYOR_BELT_NUM;i++) {
        for(j=0;j<conveyor_belts[i].bag_num;j++) {
            struct bag current_bag = conveyor_belts[i].bags[j];
            if(current_bag.dropping_point == i+1) {
                printf("Bag %d has arrived at Dropping Point %d.\n", current_bag.bag_id, i+1);
                dropping_points[i].bags[dropping_points[i].bag_num] = current_bag;
                dropping_points[i].bag_num++;
                conveyor_belts[i].bags[j] = conveyor_belts[i].bags[conveyor_belts[i].bag_num-1];
                conveyor_belts[i].bag_num--;
                j--;
            } else if(i == CONVEYOR_BELT_NUM-1) {
                printf("Bag %d has been discarded, as there are no available dropping points.\n", current_bag.bag_id);
                conveyor_belts[i].bags[j] = conveyor_belts[i].bags[conveyor_belts[i].bag_num-1];
                conveyor_belts[i].bag_num--;
                j--;
            } else {
                printf("Bag %d is moving from Belt %d to Belt %d.\n", current_bag.bag_id, i+1, i+2);
                conveyor_belts[i+1].bags[conveyor_belts[i+1].bag_num] = current_bag;
                conveyor_belts[i+1].bag_num++;
                conveyor_belts[i].bags[j] = conveyor_belts[i].bags[conveyor_belts[i].bag_num-1];
                conveyor_belts[i].bag_num--;
                j--;
            }
        }
    }
}