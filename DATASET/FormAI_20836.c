//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_TIME 20

int main() {
    srand(time(NULL)); // seed the random number generator

    int time, num_cars;
    int arrivals[MAX_TIME];
    int departures[MAX_TIME];
    int flow[MAX_TIME] = {0};
    int total_flow = 0;

    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    // Generate arrival and departure times for each car
    for (int i = 0; i < num_cars; i++) {
        arrivals[i] = rand() % MAX_TIME;
        departures[i] = arrivals[i] + (rand() % (MAX_TIME - arrivals[i]));
    }

    // Calculate the flow of cars at each time interval
    for (time = 0; time < MAX_TIME; time++) {
        for (int i = 0; i < num_cars; i++) {
            if (arrivals[i] == time) {
                flow[time]++;
            }
            if (departures[i] == time) {
                flow[time]--;
            }
        }
        total_flow += flow[time];
    }

    // Output the results
    printf("Time\tArrivals\tDepartures\tFlow\n");
    for (time = 0; time < MAX_TIME; time++) {
        printf("%d\t%d\t%d\t\t%d\n", time, arrivals[time], departures[time], flow[time]);
    }
    printf("Total flow: %d cars\n", total_flow);

    return 0;
}