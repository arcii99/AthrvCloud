//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 20

int elevator[MAX_PEOPLE] = {0};
int floor[MAX_PEOPLE] = {0};

int num_people = 0;
int num_floors = 0;
int current_floor = 1;

void generate_people() {
    srand(time(NULL));

    num_people = rand() % MAX_PEOPLE + 1;
    num_floors = rand() % MAX_FLOORS + 1;

    printf("Generated %d people and %d floors\n", num_people, num_floors);

    for(int i = 0; i < num_people; i++) {
        elevator[i] = 0;
        floor[i] = (rand() % num_floors) + 1;

        printf("Person %d is on floor %d\n", i+1, floor[i]);
    }
}

void move_elevator() {
    int direction = 1;

    while(1) {
        if(current_floor == num_floors) {
            direction = -1;
        } else if(current_floor == 1) {
            direction = 1;
        }

        for(int i = 0; i < num_people; i++) {
            if((floor[i] == current_floor) && (elevator[i] == 0)) {
                printf("Person %d got on the elevator on floor %d\n", i+1, current_floor);
                elevator[i] = 1;
            } else if((floor[i] == current_floor) && (elevator[i] == 1)) {
                printf("Person %d got off the elevator on floor %d\n", i+1, current_floor);
                floor[i] = 0;
            }
        }

        printf("Elevator is on floor %d\n", current_floor);

        current_floor += direction;

        sleep(1);
    }
}

int main() {
    generate_people();

    move_elevator();

    return 0;
}