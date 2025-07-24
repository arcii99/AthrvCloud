//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20
#define NUM_CARS 5
#define MAX_SPEED 5
#define TIME_STEP 1

typedef struct {
    int location;
    int speed;
} Car;

void print_road(Car cars[], int time) {
    printf("Time: %d seconds\n", time);
    printf("-----------------\n");
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (i == cars[0].location) {
            printf("C");
        } else if (i == cars[1].location) {
            printf("R");
        } else if (i == cars[2].location) {
            printf("A");
        } else if (i == cars[3].location) {
            printf("S");
        } else if (i == cars[4].location) {
            printf("!");
        } else {
            printf("-");
        }
    }
    printf("\n\n");
}

int main() {
    srand(time(NULL));
    Car cars[NUM_CARS];
    int time = 0;

    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].location = i + 1;
        cars[i].speed = rand() % MAX_SPEED + 1;
    }

    while (cars[NUM_CARS - 1].location < ROAD_LENGTH) {
        print_road(cars, time);

        for (int i = 0; i < NUM_CARS; i++) {
            if (cars[i].location < ROAD_LENGTH) {
                int ahead = 1;
                for (int j = i + 1; j < NUM_CARS; j++) {
                    if (cars[j].location == cars[i].location + ahead) {
                        ahead = cars[j].speed + 1;
                        break;
                    }
                }
                cars[i].location += cars[i].speed < ahead ? cars[i].speed : ahead - 1;
            }
        }

        time += TIME_STEP;
    }

    print_road(cars, time);
    printf("All cars have reached the end of the road!\n");

    return 0;
}