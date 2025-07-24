//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DRIVER_NAME_LENGTH 20
#define MAX_SPEED 100
#define MAX_DISTANCE 1000

typedef struct {
    char name[DRIVER_NAME_LENGTH];
    int speed;
    int distance_traveled;
    int position;
} Driver;

int main() {
    srand(time(NULL));

    Driver driver1 = {"Harry", rand() % MAX_SPEED, 0, 0};
    Driver driver2 = {"Tom", rand() % MAX_SPEED, 0, 0};

    int race_distance = rand() % MAX_DISTANCE;

    while (driver1.position < race_distance && driver2.position < race_distance) {
        if (driver1.position == driver2.position) {
            if (rand() % 2 == 0) {
                driver1.position++;
            } else {
                driver2.position++;
            }
        } else if (driver1.position > driver2.position) {
            driver2.position++;
        } else {
            driver1.position++;
        }

        driver1.distance_traveled += driver1.speed;
        driver2.distance_traveled += driver2.speed;

        printf("-----------------------\n");
        printf("%s is at position %d with distance traveled %d\n", driver1.name, driver1.position, driver1.distance_traveled);
        printf("%s is at position %d with distance traveled %d\n", driver2.name, driver2.position, driver2.distance_traveled);
        printf("-----------------------\n");
    }

    if (driver1.position > driver2.position) {
        printf("%s wins!\n", driver1.name);
    } else {
        printf("%s wins!\n", driver2.name);
    }

    return 0;
}