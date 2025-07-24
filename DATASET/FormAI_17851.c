//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: synchronous
#include <stdio.h>

#define NUM_FLOORS 10
#define ELEVATOR_CAPACITY 5

enum direction {UP, DOWN, NEUTRAL};

struct person {
    int origin_floor;
    int destination_floor;
};

struct elevator {
    int current_floor;
    enum direction dir;
    struct person passengers[ELEVATOR_CAPACITY];
    int num_passengers;
};

struct floor {
    int num_people_waiting;
    struct person people_waiting[ELEVATOR_CAPACITY];
};

void print_floor(struct floor f) {
    printf("Num people waiting: %d\n", f.num_people_waiting);
    for (int i = 0; i < f.num_people_waiting; i++) {
        printf("Person %d: Origin Floor = %d, Destination Floor = %d\n", i, f.people_waiting[i].origin_floor, f.people_waiting[i].destination_floor);
    }
}

void print_elevator(struct elevator e) {
    printf("Current Floor: %d | Direction: ", e.current_floor);
    if (e.dir == UP) {
        printf("UP\n");
    } else if (e.dir == DOWN) {
        printf("DOWN\n");
    } else {
        printf("NEUTRAL\n");
    }
    printf("Num passengers: %d\n", e.num_passengers);
    for (int i = 0; i < e.num_passengers; i++) {
        printf("Passenger %d: Origin Floor = %d, Destination Floor = %d\n", i, e.passengers[i].origin_floor, e.passengers[i].destination_floor);
    }
}

// Returns the index of a person with the given origin floor or -1 if not found
int find_waiting_person_with_origin_floor(struct floor f, int origin_floor) {
    for (int i = 0; i < f.num_people_waiting; i++) {
        if (f.people_waiting[i].origin_floor == origin_floor) {
            return i;
        }
    }
    return -1;
}

// Returns the index of an empty slot in the elevator or -1 if full
int find_empty_elevator_slot(struct elevator e) {
    for (int i = 0; i < ELEVATOR_CAPACITY; i++) {
        if (e.passengers[i].origin_floor == -1) {
            return i;
        }
    }
    return -1;
}

// Returns the index of a passenger with the given destination floor or -1 if not found
int find_elevator_passenger_with_destination_floor(struct elevator e, int destination_floor) {
    for (int i = 0; i < e.num_passengers; i++) {
        if (e.passengers[i].destination_floor == destination_floor) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct elevator e = {0, NEUTRAL, {}, 0};
    struct floor floors[NUM_FLOORS];
    for (int i = 0; i < NUM_FLOORS; i++) {
        floors[i].num_people_waiting = 0;
    }

    floors[0].num_people_waiting = 3;
    floors[0].people_waiting[0] = (struct person) {0, 9};
    floors[0].people_waiting[1] = (struct person) {0, 2};
    floors[0].people_waiting[2] = (struct person) {0, 4};

    floors[2].num_people_waiting = 1;
    floors[2].people_waiting[0] = (struct person) {2, 6};

    floors[5].num_people_waiting = 2;
    floors[5].people_waiting[0] = (struct person) {5, 8};
    floors[5].people_waiting[1] = (struct person) {5, 1};

    floors[9].num_people_waiting = 1;
    floors[9].people_waiting[0] = (struct person) {9, 3};

    int num_ticks = 0;
    while (num_ticks < 1000) {
        printf("Tick %d:\n", num_ticks);
        print_elevator(e);
        for (int i = 0; i < NUM_FLOORS; i++) {
            printf("Floor %d:\n", i);
            print_floor(floors[i]);
        }

        if (e.dir == NEUTRAL) {
            int up_index = e.current_floor + 1;
            int down_index = e.current_floor - 1;

            if (up_index <= NUM_FLOORS - 1) {
                int waiting_index = find_waiting_person_with_origin_floor(floors[up_index], up_index);
                if (waiting_index != -1) {
                    int empty_slot = find_empty_elevator_slot(e);
                    if (empty_slot != -1) {
                        e.passengers[empty_slot] = floors[up_index].people_waiting[waiting_index];
                        e.num_passengers++;
                        floors[up_index].num_people_waiting--;
                        for (int j = waiting_index; j < floors[up_index].num_people_waiting; j++) {
                            floors[up_index].people_waiting[j] = floors[up_index].people_waiting[j + 1];
                        }
                        e.dir = UP;
                    }
                }
            }

            if (down_index >= 0) {
                int waiting_index = find_waiting_person_with_origin_floor(floors[down_index], down_index);
                if (waiting_index != -1) {
                    int empty_slot = find_empty_elevator_slot(e);
                    if (empty_slot != -1) {
                        e.passengers[empty_slot] = floors[down_index].people_waiting[waiting_index];
                        e.num_passengers++;
                        floors[down_index].num_people_waiting--;
                        for (int j = waiting_index; j < floors[down_index].num_people_waiting; j++) {
                            floors[down_index].people_waiting[j] = floors[down_index].people_waiting[j + 1];
                        }
                        e.dir = DOWN;
                    }
                }
            }

            if (e.dir == NEUTRAL) {
                e.dir = UP; // If no one is waiting, default to UP
            }
        }

        if (e.dir == UP) {
            e.current_floor++;
            for (int i = 0; i < e.num_passengers; i++) {
                if (e.passengers[i].destination_floor == e.current_floor) {
                    e.passengers[i].origin_floor = -1;
                    e.passengers[i].destination_floor = -1;
                    e.num_passengers--;
                    for (int j = i; j < e.num_passengers; j++) {
                        e.passengers[j] = e.passengers[j + 1];
                    }
                }
            }
            if (e.current_floor == NUM_FLOORS - 1) {
                e.dir = DOWN;
            }
        }

        if (e.dir == DOWN) {
            e.current_floor--;
            for (int i = 0; i < e.num_passengers; i++) {
                if (e.passengers[i].destination_floor == e.current_floor) {
                    e.passengers[i].origin_floor = -1;
                    e.passengers[i].destination_floor = -1;
                    e.num_passengers--;
                    for (int j = i; j < e.num_passengers; j++) {
                        e.passengers[j] = e.passengers[j + 1];
                    }
                }
            }
            if (e.current_floor == 0) {
                e.dir = UP;
            }
        }

        int waiting_index = find_waiting_person_with_origin_floor(floors[e.current_floor], e.current_floor);
        while (waiting_index != -1 && e.num_passengers < ELEVATOR_CAPACITY) {
            int empty_slot = find_empty_elevator_slot(e);
            if (empty_slot != -1) {
                e.passengers[empty_slot] = floors[e.current_floor].people_waiting[waiting_index];
                e.num_passengers++;
                floors[e.current_floor].num_people_waiting--;
                for (int j = waiting_index; j < floors[e.current_floor].num_people_waiting; j++) {
                    floors[e.current_floor].people_waiting[j] = floors[e.current_floor].people_waiting[j + 1];
                }
                waiting_index = find_waiting_person_with_origin_floor(floors[e.current_floor], e.current_floor);
            } else {
                break; // Elevator is full, stop picking up people
            }
        }

        num_ticks++;
    }

    return 0;
}