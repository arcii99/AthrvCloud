//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 50
#define TOTAL_SECONDS 86400 // 24 hours
#define SPEED_LIMIT 120 // km/h

typedef struct {
    int id;
    float length; // km
    float speed_limit; // km/h
    int num_cars;
  } road;

typedef struct {
    int id;
    road *current_road;
    float position_on_road; // km
    float speed; // km/h
    int start_time; // seconds from midnight
    int end_time; // seconds from midnight
    int is_active; // 0 if car is inactive
} car; 

int num_roads;
road roads[MAX_ROADS];
int num_cars;
car cars[MAX_CARS];
int current_time = 0;

// Generate a random number between min and max inclusive 
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Simulate movement of cars for 1 second
void move_cars() {
    for (int i = 0; i < num_cars; i++) {
        car *current_car = &cars[i];
        if (current_car->is_active == 0) {
            // Car is inactive
            continue;
        }
        if (current_time < current_car->start_time) {
            // Car has not started yet
            continue;
        }
        if (current_time > current_car->end_time) {
            // Car has reached its destination and should be removed
            current_car->is_active = 0;
            current_car->current_road->num_cars--;
            continue;
        }
        // Calculate distance travelled in 1 second
        float distance_travelled = current_car->speed / 3600.0;
        // Check if the car will go over the end of the road
        if ((current_car->position_on_road + distance_travelled) > current_car->current_road->length) {
            // Remove car from current road
            current_car->current_road->num_cars--;
            // Find next road
            int next_road_index = rand_int(0, num_roads - 1);
            while (next_road_index == current_car->current_road->id) {
                next_road_index = rand_int(0, num_roads - 1);
            }
            road *next_road = &roads[next_road_index];
            current_car->current_road = next_road;
            next_road->num_cars++;
            // Calculate distance remaining on current road
            float distance_remaining = current_car->current_road->length - current_car->position_on_road;
            // Calculate time taken to finish current road
            float time_to_finish_road = distance_remaining / current_car->speed * 3600;
            // Calculate start and end times for next road
            current_car->start_time = current_time + time_to_finish_road;
            current_car->end_time = current_car->start_time + (next_road->length / current_car->speed * 3600);
            // Set position on next road to be the difference between distance remaining on current road and distance travelled in 1 second
            current_car->position_on_road = distance_travelled - distance_remaining;
        } else {
            current_car->position_on_road += distance_travelled;
        }
    }
}

// Print the state for each road
void print_state() {
    printf("\nCurrent Time: %02d:%02d:%02d\n", current_time / 3600, (current_time / 60) % 60, current_time % 60);
    for (int i = 0; i < num_roads; i++) {
        printf("Road %d: %d cars\n", roads[i].id, roads[i].num_cars);
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    // Initialize roads
    num_roads = 4;
    float road_lengths[4] = {20, 30, 40, 50};
    float road_speed_limits[4] = {80, 100, 120, 100};
    for (int i = 0; i < num_roads; i++) {
        roads[i].id = i;
        roads[i].length = road_lengths[i];
        roads[i].speed_limit = road_speed_limits[i];
        roads[i].num_cars = 0;
    }

    // Initialize cars
    num_cars = 10;
    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i;
        cars[i].current_road = &roads[rand_int(0, num_roads - 1)];
        cars[i].position_on_road = rand_int(0, (int)cars[i].current_road->length);
        cars[i].speed = rand_int(0, SPEED_LIMIT);
        cars[i].start_time = rand_int(current_time, TOTAL_SECONDS - 1);
        cars[i].end_time = cars[i].start_time + (rand_int(0, (int)(TOTAL_SECONDS - cars[i].start_time - 1)));
        cars[i].is_active = 1;
        cars[i].current_road->num_cars++;
    }

    // Main loop to simulate traffic flow
    while (current_time < TOTAL_SECONDS) {
        print_state();
        move_cars();
        current_time++;
    }
    return 0;
}