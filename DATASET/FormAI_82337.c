//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include <stdio.h>

void simulate_traffic_flow(int num_cars, int current_iteration) {
    // Base case: No more cars left to simulation
    if (num_cars == 0) {
        printf("Simulation complete after %d iterations.\n", current_iteration);
        return;
    }

    // Recursive case: Simulate one iteration of traffic flow
    int num_cars_moved = 0;
    printf("Currently simulating iteration %d...\n", current_iteration);
    for (int i = 0; i < num_cars; i++) {
        // Randomly determine if the car will move forward
        int move_forward = rand() % 2;
        if (move_forward) {
            num_cars_moved++;
        }
    }

    // Recursive call
    simulate_traffic_flow(num_cars - num_cars_moved, current_iteration + 1);
}

int main() {
    int num_cars;
    printf("Enter the number of cars to simulate traffic flow: ");
    scanf("%d", &num_cars);

    simulate_traffic_flow(num_cars, 1);

    return 0;
}