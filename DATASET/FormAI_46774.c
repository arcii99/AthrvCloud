//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int incoming_carts = 0;
    int outgoing_carts = 0;
    int entering_carts = 0;
    int exiting_carts = 0;
    int max_capacity = 10;
    int current_capacity = 0;
    int medieval_traffic_flow[10];
    int i, j;
    int wait_time = 0;
    srand(time(0));

    // Initialise the traffic flow array
    for (i = 0; i < 10; i++) {
        medieval_traffic_flow[i] = rand() % 3;
    }

    // Simulate the traffic flow for 10 rounds
    for (i = 0; i < 10; i++) {
        // Count the incoming and outgoing carts
        incoming_carts = 0;
        outgoing_carts = 0;
        for (j = 0; j < 10; j++) {
            if (medieval_traffic_flow[j] == 1) {
                incoming_carts++;
            }
            else if (medieval_traffic_flow[j] == 2) {
                outgoing_carts++;
            }
        }

        // Calculate the number of carts that enter and exit
        entering_carts = incoming_carts;
        if (current_capacity + entering_carts > max_capacity) {
            entering_carts = max_capacity - current_capacity;
        }

        exiting_carts = outgoing_carts;
        if (exiting_carts > current_capacity) {
            exiting_carts = current_capacity;
        }

        // Update the current capacity of the road
        current_capacity = current_capacity + entering_carts - exiting_carts;

        // Calculate the time taken for carts to wait
        if (entering_carts > (max_capacity - exiting_carts)) {
            wait_time += (entering_carts - (max_capacity - exiting_carts));
        }

        // Update the traffic flow array for the next round
        for (j = 0; j < 10; j++) {
            if (medieval_traffic_flow[j] == 1) {
                if (rand() % 2 == 0) {
                    medieval_traffic_flow[j] = 0;
                }
            }
            else if (medieval_traffic_flow[j] == 2) {
                if (rand() % 2 == 0) {
                    medieval_traffic_flow[j] = 0;
                }
            }
            else if (medieval_traffic_flow[j] == 0) {
                if (rand() % 2 == 0) {
                    medieval_traffic_flow[j] = 1;
                }
                else {
                    medieval_traffic_flow[j] = 2;
                }
            }
        }
    }

    // Print the results
    printf("Medieval Traffic Flow Simulation\n");
    printf("--------------------------------\n");
    printf("Total Wait Time: %d minutes\n", wait_time);
    printf("Average Wait Time: %f minutes\n", (float)wait_time / (float)incoming_carts);

    return 0;
}