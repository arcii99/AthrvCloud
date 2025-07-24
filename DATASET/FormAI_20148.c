//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_ROADS 10
#define MAX_NUM_OF_CARS 100
#define SIMULATION_TIME 60 // seconds
#define CAR_CREATION_FREQUENCY 1 // new car every 1 second

int main()
{
    // initialization
    srand(time(NULL));
    int roads[NUM_OF_ROADS] = {0};
    int total_cars = 0;
    int created_cars = 0;
    int removed_cars = 0;
    int max_cars_on_road = 0;

    // simulation loop
    for (int time = 0; time < SIMULATION_TIME; time++) {

        // generate new cars
        if (time % CAR_CREATION_FREQUENCY == 0 && created_cars < MAX_NUM_OF_CARS) {
            int road = rand() % NUM_OF_ROADS;
            roads[road]++;
            total_cars++;
            created_cars++;
        }

        // remove cars from roads
        for (int road = 0; road < NUM_OF_ROADS; road++) {
            if (roads[road] > 0) {
                roads[road]--;
                removed_cars++;
            }
        }

        // statistics
        int cars_on_roads = 0;
        for (int road = 0; road < NUM_OF_ROADS; road++) {
            cars_on_roads += roads[road];
            if (roads[road] > max_cars_on_road) {
                max_cars_on_road = roads[road];
            }
        }

        // print statistics for this second
        printf("Second %d: Total Cars=%d, Created Cars=%d, Removed Cars=%d, Cars on Roads=%d, Max Cars on Road=%d\n",
               time, total_cars, created_cars, removed_cars, cars_on_roads, max_cars_on_road);
    }

    return 0;
}