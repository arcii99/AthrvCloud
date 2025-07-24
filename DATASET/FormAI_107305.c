//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define MAX_SPEED 100
#define MAX_DISTANCE 1000

int cars[MAX_CARS];
int speeds[MAX_CARS];
int distances[MAX_CARS];

void init_cars() {
    srand(time(0));
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i] = i + 1;
        speeds[i] = rand() % MAX_SPEED + 1;
        distances[i] = rand() % MAX_DISTANCE + 1;
    }
}

void print_cars() {
    printf("%-10s %-10s %-10s\n", "Car", "Speed", "Distance");
    for (int i = 0; i < MAX_CARS; i++) {
        printf("%-10d %-10d %-10d\n", cars[i], speeds[i], distances[i]);
    }
}

int main() {
    init_cars();
    print_cars();
    return 0;
}