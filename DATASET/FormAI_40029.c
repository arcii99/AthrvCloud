//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20
#define MAX_CARS 10

int cars_on_road = 0;
int time_elapsed = 0;

void print_road(char road[], int road_length) {
    printf("%s\n", road);
}

int car_index(char road[], int road_length, int num_cars) {
    int i = 0;
    int current_index = -1;
    while (i < road_length && current_index == -1) {
        if (road[i] == 'C') {
            num_cars--;
        }
        if (num_cars == 0) {
            current_index = i;
        }
        i++;
    }
    return current_index;
}

void move_cars(char road[], int road_length, int num_cars) {
    for (int i = 0; i < num_cars; i++) {
        int current_index = car_index(road, road_length, i+1);
        if (current_index == -1) {
            continue;
        }
        // Move the car forward
        if (current_index < (road_length-1) && road[current_index+1] == '_') {
            road[current_index+1] = 'C';
            road[current_index] = '_';
        }
        // Stop the car
        else if (current_index < (road_length-2) && road[current_index+1] == 'C' && road[current_index+2] == 'C') {
            road[current_index+1] = 'C';
            road[current_index] = '_';
        }
    }
}

void generate_car(char road[], int road_length) {
    int position = rand() % road_length;
    while (road[position] == 'C') {
        position = rand() % road_length;
    }
    road[position] = 'C';
    cars_on_road++;
}

void simulate_traffic(char road[], int road_length, int max_cars, int max_time) {
    print_road(road, road_length);
    while (time_elapsed < max_time && cars_on_road < max_cars) {
        // Move the cars
        move_cars(road, road_length, cars_on_road);
        // Generate new cars
        if (rand() % 3 == 0) {
            generate_car(road, road_length);
        }
        print_road(road, road_length);
        // Update the time and car count
        time_elapsed++;
        printf("Time elapsed: %d seconds\n", time_elapsed);
        printf("Cars on road: %d\n\n", cars_on_road);
    }
    printf("Simulation complete.\n");
}

int main() {
    srand(time(NULL));
    char road[ROAD_LENGTH+1];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = '_';
    }
    road[ROAD_LENGTH] = '\0';
    simulate_traffic(road, ROAD_LENGTH, MAX_CARS, 20);
    return 0;
}