//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20
#define MAX_SPEED 5

typedef struct {
    int position;
    int speed;
} Car;

void print_road(Car road[], int road_length) {
    for (int i = 0; i < road_length; i++) {
        if (road[i].position == -1)
            printf("-");
        else
            printf("%d", road[i].position);
    }
    printf("\n");
}

void simulate_traffic_flow(Car road[], int road_length) {
    int time = 0;
    while (1) {
        print_road(road, road_length);
        // Update car positions and speeds
        for (int i = 0; i < road_length; i++) {
            if (road[i].position == -1)
                continue;
            int distance_to_next_car = -1;
            for (int j = i+1; j < road_length; j++) {
                if (road[j].position != -1) {
                    distance_to_next_car = j - i - 1;
                    break;
                }
            }
            if (distance_to_next_car == -1) {
                road[i].position = (road[i].position + road[i].speed) % road_length;
            } else {
                int max_speed = distance_to_next_car;
                if (road[i].speed > max_speed)
                    road[i].speed = max_speed;
                road[i].speed += 1;
                road[i].position = (road[i].position + road[i].speed) % road_length;
            }
        }
        // Check for collisions
        for (int i = 0; i < road_length; i++) {
            if (road[i].position == -1)
                continue;
            for (int j = i+1; j < road_length; j++) {
                if (road[j].position == -1)
                    continue;
                if (road[i].position == road[j].position) {
                    // Collision!
                    printf("Collision at position %d and time %d\n", road[i].position, time);
                    road[i].position = -1;
                    road[i].speed = 0;
                    road[j].position = -1;
                    road[j].speed = 0;
                    break;
                }
            }
        }
        // Check if all cars have exited the road
        int all_cars_gone = 1;
        for (int i = 0; i < road_length; i++) {
            if (road[i].position != -1) {
                all_cars_gone = 0;
                break;
            }
        }
        if (all_cars_gone)
            break;
        time++;
    }
}

int main() {
    srand(time(NULL));
    Car road[ROAD_LENGTH];
    // Initialize road
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i].position = -1;
        road[i].speed = 0;
    }
    // Add cars randomly to the road
    for (int i = 0; i < ROAD_LENGTH/2; i++) {
        int position = rand() % ROAD_LENGTH;
        if (road[position].position == -1)
            road[position].position = position;
        else
            i--;
    }
    // Add speeds to the cars
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (road[i].position == -1)
            continue;
        road[i].speed = rand() % MAX_SPEED + 1;
    }
    printf("Initial road:\n");
    print_road(road, ROAD_LENGTH);
    printf("\n");
    simulate_traffic_flow(road, ROAD_LENGTH);
    printf("\nFinal road after traffic simulation:\n");
    print_road(road, ROAD_LENGTH);
    return 0;
}