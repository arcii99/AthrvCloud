//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOOR_COUNT 10
#define ELEVATOR_CAP 10

int floors[FLOOR_COUNT][ELEVATOR_CAP]; // floors[i][j] indicates person id j at floor i
int floor_sizes[FLOOR_COUNT]; // floor_sizes[i] indicates number of people at floor i

int current_floor = 0; // elevator starts at ground floor
int elevator[10]; // elevator[i] indicates person id i in elevator
int elevator_size = 0; // number of people in elevator

int person_id_count = 0; // unique id for new people

void move_elevator() {
    int next_floor = current_floor;
    if (elevator_size == 0) {
        // if elevator is empty, go to closest floor with people waiting
        int closest_floor = -1;
        int closest_distance = FLOOR_COUNT + 1; // maximum possible distance
        for (int i = 0; i < FLOOR_COUNT; i++) {
            if (floor_sizes[i] > 0) {
                int distance = abs(i - current_floor);
                if (distance < closest_distance) {
                    closest_floor = i;
                    closest_distance = distance;
                }
            }
        }
        next_floor = closest_floor;
    } else {
        // if elevator has people, go to the floor with the highest demand
        int highest_demand_floor = -1;
        int highest_demand = -1;
        for (int i = 0; i < FLOOR_COUNT; i++) {
            if (floor_sizes[i] > highest_demand) {
                highest_demand_floor = i;
                highest_demand = floor_sizes[i];
            }
        }
        next_floor = highest_demand_floor;
    }

    // move elevator to next floor
    printf("Elevator moving from floor %d to floor %d\n", current_floor, next_floor);
    current_floor = next_floor;

    // load/unload people from elevator
    for (int i = 0; i < ELEVATOR_CAP; i++) {
        if (elevator[i] != -1 && floors[current_floor][i] == -1) {
            // unload person
            printf("Person %d getting off elevator at floor %d\n", elevator[i], current_floor);
            elevator[i] = -1;
            elevator_size--;
        } else if (elevator[i] == -1 && floors[current_floor][i] != -1) {
            // load person
            printf("Person %d getting on elevator at floor %d\n", floors[current_floor][i], current_floor);
            elevator[i] = floors[current_floor][i];
            floors[current_floor][i] = -1;
            elevator_size++;
            floor_sizes[current_floor]--;
        }
    }
}

void add_person() {
    // generate new person with random destination floor
    int dest = rand() % FLOOR_COUNT;
    while (dest == current_floor) { // person cannot have same destination as current floor
        dest = rand() % FLOOR_COUNT;
    }
    int id = person_id_count++;
    printf("Person %d added to floor %d with destination floor %d\n", id, current_floor, dest);

    // add person to current floor
    floors[current_floor][floor_sizes[current_floor]] = id;
    floor_sizes[current_floor]++;
}

int main() {
    srand(time(NULL));

    // initialize floors and elevator arrays to -1 (no people)
    for (int i = 0; i < FLOOR_COUNT; i++) {
        for (int j = 0; j < ELEVATOR_CAP; j++) {
            floors[i][j] = -1;
        }
        floor_sizes[i] = 0;
    }
    for (int i = 0; i < ELEVATOR_CAP; i++) {
        elevator[i] = -1;
    }

    // add some initial people randomly
    for (int i = 0; i < 10; i++) {
        if (rand() % 2 == 0) {
            add_person();
        }
    }

    // run elevator simulation
    while (1) {
        move_elevator();

        // add new person to current floor with 50% probability
        if (rand() % 2 == 0) {
            add_person();
        }

        // check if any people have reached their destination
        for (int i = 0; i < ELEVATOR_CAP; i++) {
            if (elevator[i] != -1 && current_floor == floors[elevator[i]][i]) {
                printf("Person %d has arrived at destination floor %d\n", elevator[i], current_floor);
                elevator[i] = -1;
                elevator_size--;
            }
        }

        // check if simulation is over (no people waiting and no people in elevator)
        int total_people = 0;
        for (int i = 0; i < FLOOR_COUNT; i++) {
            total_people += floor_sizes[i];
        }
        total_people += elevator_size;
        if (total_people == 0) {
            break;
        }
    }

    printf("Simulation over\n");
    return 0;
}