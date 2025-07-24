//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 2

struct Elevator {
    bool door_open;
    int current_floor;
    int destination_floor;
    int floors_traversed;
};

struct Floor {
    bool is_requested;
};

struct Building {
    struct Elevator elevators[NUM_ELEVATORS];
    struct Floor floors[NUM_FLOORS];
};

void initialize_building(struct Building *b)
{
    // Set elevator and floor initial values
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        b->elevators[i].door_open = false;
        b->elevators[i].current_floor = 0;
        b->elevators[i].destination_floor = -1;
        b->elevators[i].floors_traversed = 0;
    }
    for (int i = 0; i < NUM_FLOORS; i++) {
        b->floors[i].is_requested = false;
    }
}

void request_floor(struct Building *b, int floor)
{
    b->floors[floor].is_requested = true;
    printf("Floor %d requested.\n", floor);
}

void request_elevator(struct Building *b, int floor)
{
    int closest_elevator = -1; // Start with no elevator assigned
    int shortest_distance = NUM_FLOORS + 1;

    // Find the closest idle elevator to the requested floor
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (!b->elevators[i].door_open &&
            b->elevators[i].destination_floor == -1) { // Idle elevator
            int distance = abs(b->elevators[i].current_floor - floor);
            if (distance < shortest_distance) {
                closest_elevator = i;
                shortest_distance = distance;
            }
        }
    }

    if (closest_elevator != -1) {
        // Assign elevator to requested floor
        b->elevators[closest_elevator].destination_floor = floor;
        printf("Elevator %d assigned to floor %d.\n", closest_elevator, floor);
    } else {
        // No available idle elevators, queue up request
        printf("No idle elevators available. Request queued.\n");
        request_floor(b, floor);
    }
}

void move_elevators(struct Building *b)
{
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        struct Elevator *e = &b->elevators[i];
        if (e->destination_floor != -1) { // Elevator has destination
            // Move elevator towards destination
            if (e->destination_floor > e->current_floor) e->current_floor++;
            else if (e->destination_floor < e->current_floor) e->current_floor--;
            e->floors_traversed++;

            // Check if elevator has arrived at destination
            if (e->current_floor == e->destination_floor) {
                printf("Elevator %d arrived at floor %d.\n", i, e->current_floor);
                e->door_open = true;

                // Clear floor request
                b->floors[e->current_floor].is_requested = false;

                // Clear elevator destination
                e->destination_floor = -1;
            }
        } else if (e->door_open) {
            // Door is open, count down until close
            if (--e->door_open == 0) {
                printf("Elevator %d door closed.\n", i);
                e->door_open = false;
            }
        }
    }
}

int main()
{
    struct Building b;
    initialize_building(&b);

    // Request some floors
    request_elevator(&b, 3);
    request_elevator(&b, 5);
    request_elevator(&b, 7);
    request_elevator(&b, 1);
    request_elevator(&b, 8);

    // Move elevators until all requests are serviced
    while (true) {
        bool all_requests_serviced = true;
        for (int i = 0; i < NUM_FLOORS; i++) {
            if (b.floors[i].is_requested) {
                all_requests_serviced = false;
                break;
            }
        }
        if (all_requests_serviced) break;

        move_elevators(&b);
    }

    // Print elevator stats
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d traversed %d floors.\n", i, b.elevators[i].floors_traversed);
    }

    return 0;
}