//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_LANES 4
#define MAX_CAPACITY 20
#define MAX_TRAVEL_TIME 10
#define MAX_INTERVAL_TIME 3

typedef struct {
    int capacity;
    int num_of_cars;
    int travel_time;
    int interval;
} lane;

void print_traffic_flow(lane traffic[]) {
    printf("----------------------------------------------\n");
    for (int i = 0; i < NUM_OF_LANES; i++) {
        printf("Lane %d:  Capacity: %d | Num of Cars: %d | Travel Time: %d | Interval: %d\n", 
                    i+1, traffic[i].capacity, traffic[i].num_of_cars, traffic[i].travel_time, traffic[i].interval);
    }
    printf("----------------------------------------------\n");
}

int main() {
    srand(time(NULL)); // initialize random seed
    
    lane traffic[NUM_OF_LANES];
    for (int i = 0; i < NUM_OF_LANES; i++) {
        traffic[i].capacity = rand() % MAX_CAPACITY + 1;
        traffic[i].num_of_cars = rand() % traffic[i].capacity + 1;
        traffic[i].travel_time = rand() % MAX_TRAVEL_TIME + 1;
        traffic[i].interval = rand() % MAX_INTERVAL_TIME + 1;
    }
    
    printf("Initial Traffic Flow:\n");
    print_traffic_flow(traffic);
    
    // simulate traffic flow
    for (int i = 0; i < 10; i++) { // simulate for 10 time periods
        printf("Time Period %d:\n", i+1);
        for (int j = 0; j < NUM_OF_LANES; j++) {
            // update number of cars in lane
            if (traffic[j].num_of_cars > 0) {
                traffic[j].num_of_cars -= traffic[j].travel_time;
            } else if (traffic[j].num_of_cars < 0) {
                traffic[j].num_of_cars = 0;
            }
            // add new cars to lane if capacity is not full
            if (traffic[j].num_of_cars < traffic[j].capacity) {
                traffic[j].num_of_cars += rand() % traffic[j].capacity + 1;
            }
            // update interval time for lane
            traffic[j].interval = rand() % MAX_INTERVAL_TIME + 1;
        }
        print_traffic_flow(traffic);
        printf("------------------------------------------------\n");
    }
    
    return 0;
}