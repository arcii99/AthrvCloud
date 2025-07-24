//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 1000
#define MAX_SPEED 90
#define MIN_SPEED 10

typedef struct {
    int id;
    int speed;
    int position;
} Car;

int main() {
    srand(time(NULL));
    Car cars[MAX_CARS];

    // initialize cars
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].id = i;
        cars[i].speed = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;
        cars[i].position = i * 10; // give cars some space between them
    }

    // simulate traffic flow
    while (1) {
        // move cars forward
        for (int i = 0; i < MAX_CARS; i++) {
            cars[i].position += cars[i].speed;
        }

        // check for collisions
        for (int i = 0; i < MAX_CARS - 1; i++) {
            for (int j = i + 1; j < MAX_CARS; j++) {
                if (cars[i].position == cars[j].position) {
                    printf("CRASH! Car %d and %d collided\n", cars[i].id, cars[j].id);
                    return 0;
                }
            }
        }

        // print current state
        system("clear"); // clear console
        for (int i = 0; i < MAX_CARS; i++) {
            char road[100];
            for (int j = 0; j < 100; j++) {
                road[j] = '-';
            }
            road[(int)(cars[i].position / 10)] = 'O';
            printf("%s\n", road);
        }

        // pause to simulate time passing
        usleep(50000);
    }

    return 0;
}