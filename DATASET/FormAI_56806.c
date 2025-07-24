//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
// C Traffic Flow Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20 // Road length
#define TRAFFIC_DENSITY 0.6 // Traffic density
#define MAX_SPEED 5 // Maximum speed allowed
#define MAX_ITERATIONS 100 // Maximum number of iterations

struct car {
    int position;
    int speed;
};

int main(void) {
    struct car road[ROAD_LENGTH];
    double threshold = TRAFFIC_DENSITY * (double)ROAD_LENGTH;
    int iteration = 0;
    int car_count = 0;
    int average_speed = 0;
    srand(time(NULL)); // Seed for random number generator

    // Initialize road
    for(int i = 0; i < ROAD_LENGTH; i++) {
        road[i].position = -1;
        road[i].speed = 0;
    }

    while(iteration < MAX_ITERATIONS && car_count < ROAD_LENGTH) {
        // Spawn new cars
        if((double)rand() / RAND_MAX < TRAFFIC_DENSITY && road[0].position == -1) {
            road[0].position = 0;
            road[0].speed = rand() % (MAX_SPEED + 1);
            car_count++;
        }

        // Update car positions
        for(int i = 0; i < ROAD_LENGTH; i++) {
            if(road[i].position >= 0) {
                int next_index = (i + road[i].speed) % ROAD_LENGTH;
                int next_position = road[i].position + road[i].speed;

                // Check for collision
                int collision = 0;
                for(int j = i + 1; j <= next_index; j++) {
                    if(road[j % ROAD_LENGTH].position != -1) {
                        collision = 1;
                        break;
                    }
                }

                if(collision) {
                    road[i].speed = 0;
                } else {
                    road[next_index].position = next_position >= ROAD_LENGTH ? -1 : next_position;
                    road[next_index].speed = next_position >= ROAD_LENGTH ? 0 : road[i].speed;
                    road[i].position = next_position >= ROAD_LENGTH ? -1 : next_position;
                    road[i].speed = next_position >= ROAD_LENGTH ? 0 : road[i].speed;
                }
            }
        }

        // Update average speed
        int total_speed = 0;
        int valid_cars = 0;
        for(int i = 0; i < ROAD_LENGTH; i++) {
            if(road[i].position != -1) {
                total_speed += road[i].speed;
                valid_cars++;
            }
        }
        average_speed = valid_cars == 0 ? 0 : total_speed / valid_cars;

        // Print road state
        printf("Iteration %d\n", iteration);
        for(int i = 0; i < ROAD_LENGTH; i++) {
            if(road[i].position == -1) {
                printf("-");
            } else {
                printf("%d", road[i].speed);
            }
        }
        printf("\n");

        // Slow down or speed up cars
        for(int i = 0; i < ROAD_LENGTH; i++) {
            if(road[i].position != -1) {
                int distance = ROAD_LENGTH;
                for(int j = i + 1; j < ROAD_LENGTH; j++) {
                    if(road[j].position != -1) {
                        distance = j - i;
                        break;
                    }
                }
                if(road[i].speed < MAX_SPEED && (double)rand() / RAND_MAX < (threshold / (double)distance) && road[i].speed < average_speed) {
                    road[i].speed++;
                } else if(road[i].speed > 0 && (double)rand() / RAND_MAX < (road[i].speed / (double)MAX_SPEED)) {
                    road[i].speed--;
                }
            }
        }

        iteration++;
    }

    return 0;
}