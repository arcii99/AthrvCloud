//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define car_speed_limit 60
#define road_length 400
#define max_cars 20

int main() {
    srand(time(NULL));
    int num_of_cars = rand() % max_cars + 1;
    printf("Initializing Traffic Flow Simulator...\n");
    printf("Setting up road...\n\n");
    printf("Road length: %dm\n", road_length);
    printf("Maximum speed limit: %dkm/h\n\n", car_speed_limit);

    int curr_pos[max_cars];
    bool is_crash_detected = false;
    printf("Cars on the road: %d\n", num_of_cars);
    printf("Starting positions:\n");
    for (int i = 0; i < num_of_cars; i++) {
        curr_pos[i] = rand() % road_length;
        printf("Car %d: %dm\n", i+1, curr_pos[i]);
    }
    printf("\n");

    int tick = 0;
    while (!is_crash_detected) {
        printf("Current tick: %d\n", tick);
        for (int i = 0; i < num_of_cars; i++) {
            int move = rand() % 2 + 1; // randomize car's move
            int speed = rand() % car_speed_limit; // randomize car's speed

            if (curr_pos[i] != road_length) {
                curr_pos[i] += move * speed; // move car
                if (curr_pos[i] == road_length) {
                    printf("Car %d has arrived at the destination.\n", i+1);
                } else if (i > 0 && curr_pos[i] - curr_pos[i-1] < 10) {
                    printf("Car %d has crashed into Car %d at %dm!!!\n", i+1, i, curr_pos[i]);
                    is_crash_detected = true;
                    break;
                }
            }
            printf("Car %d's current position: %dm\n", i+1, curr_pos[i]);
        }
        printf("\n");
        tick++;
    }

    printf("Traffic Flow Simulator terminated due to a crash.\n");
    return 0;
}