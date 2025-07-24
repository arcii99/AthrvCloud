//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TOTAL_FLOORS 10 // total number of floors in the building
#define MIN_FLOOR 1 // the minimum floor number
#define MAX_FLOOR 10 // the maximum floor number
#define ELEVATOR_CAPACITY 10 // max number of people the elevator can hold
#define TIME_INTERVAL 5 // time interval between each floor (in seconds)

struct person {
    int id; // unique ID for each person
    int start_floor; // the floor at which the person enters the elevator
    int end_floor; // the floor at which the person exits the elevator
    bool is_inside; // whether the person is inside the elevator or not
};

struct elevator {
    int current_floor; // the current floor of the elevator
    int num_people; // the number of people currently inside the elevator
    struct person people[ELEVATOR_CAPACITY]; // array to store the people inside the elevator
};

int generate_random_floor() {
    // generates a random floor number between MIN_FLOOR and MAX_FLOOR
    return rand() % (MAX_FLOOR - MIN_FLOOR + 1) + MIN_FLOOR;
}

void add_person(struct elevator *elev, int person_id, int start_floor, int end_floor) {
    // adds a person to the elevator
    elev->people[elev->num_people].id = person_id;
    elev->people[elev->num_people].start_floor = start_floor;
    elev->people[elev->num_people].end_floor = end_floor;
    elev->people[elev->num_people].is_inside = true;
    elev->num_people++;
}

void remove_person(struct elevator *elev, int person_id) {
    // removes a person from the elevator
    for (int i = 0; i < elev->num_people; i++) {
        if (elev->people[i].id == person_id) {
            elev->people[i].is_inside = false;
            for (int j = i; j < elev->num_people - 1; j++) {
                elev->people[j] = elev->people[j + 1];
            }
            elev->num_people--;
            break;
        }
    }
}

void print_elevator(struct elevator *elev) {
    // prints the current state of the elevator
    printf("Current floor: %d\n", elev->current_floor);
    printf("Number of people: %d\n", elev->num_people);
    printf("\n");
    for (int i = 0; i < elev->num_people; i++) {
        printf("Person %d: start floor %d, end floor %d\n", elev->people[i].id, elev->people[i].start_floor, elev->people[i].end_floor);
    }
}

int main() {
    srand(time(NULL)); // used to generate random numbers
    struct elevator elev = {1, 0, {0}}; // initialize elevator at first floor, with 0 people inside
    int person_id = 1; // used to generate unique IDs for each person

    while (true) {
        // generate a random number of people (between 0 and ELEVATOR_CAPACITY) to add to the elevator
        int num_people_to_add = rand() % (ELEVATOR_CAPACITY + 1);
        for (int i = 0; i < num_people_to_add; i++) {
            // generate a random start floor and end floor for each person
            int start_floor = generate_random_floor();
            int end_floor = generate_random_floor();
            while (end_floor == start_floor) {
                end_floor = generate_random_floor(); // make sure start floor and end floor are different
            }
            add_person(&elev, person_id, start_floor, end_floor);
            printf("Added person %d to elevator at floor %d, going to floor %d\n", person_id, start_floor, end_floor);
            person_id++;
        }

        // simulate elevator movement between floors
        while (elev.num_people > 0) {
            if (elev.current_floor < elev.people[0].start_floor) {
                printf("Elevator going up...\n");
                while (elev.current_floor < elev.people[0].start_floor) {
                    sleep(TIME_INTERVAL);
                    elev.current_floor++;
                    printf("Elevator at floor %d\n", elev.current_floor);
                }
            } else if (elev.current_floor > elev.people[0].start_floor) {
                printf("Elevator going down...\n");
                while (elev.current_floor > elev.people[0].start_floor) {
                    sleep(TIME_INTERVAL);
                    elev.current_floor--;
                    printf("Elevator at floor %d\n", elev.current_floor);
                }
            }

            printf("Elevator at floor %d, opening doors...\n", elev.current_floor);
            for (int i = 0; i < elev.num_people; i++) {
                if (elev.people[i].start_floor == elev.current_floor) {
                    printf("Person %d exiting elevator\n", elev.people[i].id);
                    remove_person(&elev, elev.people[i].id);
                    i--; // adjust index after removing person from array
                }
            }

            for (int i = 0; i < elev.num_people; i++) {
                if (elev.people[i].end_floor == elev.current_floor) {
                    printf("Person %d entering elevator\n", elev.people[i].id);
                }
            }

            for (int i = 0; i < elev.num_people; i++) {
                if (elev.people[i].end_floor == elev.current_floor) {
                    add_person(&elev, elev.people[i].id, elev.current_floor, -1);
                    remove_person(&elev, elev.people[i].id);
                    i--; // adjust index after removing person from array
                }
            }

            printf("Elevator doors closing...\n");
            sleep(TIME_INTERVAL);
        }
    }

    return 0;
}