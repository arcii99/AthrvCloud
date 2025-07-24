//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANES 4
#define CAR_LENGTH 4
#define SIM_TIME 1000

int main() {
    int flow[LANES][SIM_TIME];
    int car_speed[LANES][SIM_TIME];
    int car_pos[LANES][SIM_TIME];
    int lane_mean_speed[LANES] = {60, 70, 80, 90};
    int time_elapsed = 0;
    int total_cars = 0;

    srand(time(NULL));

    while(time_elapsed < SIM_TIME) {
        int lane;

        for(lane = 0; lane < LANES; lane++) {
            int new_cars = (rand() % 5) + 5;

            for(int j = 0; j < new_cars; j++) {
                flow[lane][time_elapsed] = 1;
                car_speed[lane][time_elapsed] = lane_mean_speed[lane] - (rand() % 20);

                if(time_elapsed == 0) {
                    car_pos[lane][time_elapsed] = 0;
                } else {
                    int prev_pos = car_pos[lane][time_elapsed - 1];
                    int prev_speed = car_speed[lane][time_elapsed - 1];

                    car_pos[lane][time_elapsed] = prev_pos + prev_speed;
                }

                total_cars++;
            }
        }

        time_elapsed++;
    }

    printf("Completed simulation with %d total cars.\n", total_cars);

    return 0;
}