//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define FLOORS 10
#define MAX_PEOPLE 5

struct Person {
    int target_floor;
};

void update_elevator(int *current_floor, int *direction) {
    if (*current_floor == FLOORS) {
        *direction = -1;
    } else if (*current_floor == 1) {
        *direction = 1;
    }
    *current_floor += *direction;
}

void move_people(struct Person *people, int *num_people, int current_floor) {
    int i = 0;
    while (i < *num_people) {
        if (people[i].target_floor == current_floor) {
            printf("Person %d has reached its destination on floor %d.\n", i+1, current_floor);
            people[i] = people[--(*num_people)];
        } else {
            i++;
        }
    }
}

void board_people(struct Person *people, int *num_people, int current_floor) {
    if (*num_people < MAX_PEOPLE) {
        printf("There are %d people waiting on floor %d.\n", MAX_PEOPLE - *num_people, current_floor);
        for (int i = 0; i < MAX_PEOPLE - *num_people; i++) {
            struct Person p = { rand() % FLOORS + 1 };
            people[(*num_people)++] = p;
            printf("Person %d boarding the elevator to floor %d.\n", *num_people, p.target_floor);
        }
    }
}

int main() {
    int current_floor = 1;
    int direction = 1;
    int num_people = 0;
    struct Person people[MAX_PEOPLE];

    for (int i = 0; i < 20; i++) {
        printf("Elevator is on floor %d.\n", current_floor);

        move_people(people, &num_people, current_floor);

        board_people(people, &num_people, current_floor);

        update_elevator(&current_floor, &direction);
    }

    return 0;
}