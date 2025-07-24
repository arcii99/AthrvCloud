//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 12

int current_floor = 1;
int num_passengers = 0;
int elevator_capacity = 4;
int max_floors = 5;
int floors[MAX_FLOORS] = {0};
char passengers[MAX_PASSENGERS][20];

void print_elevator_status() {
    printf("Current Floor: %d\n", current_floor);
    printf("Number of Passengers: %d\n", num_passengers);
    printf("Passengers: ");
    for (int i = 0; i < num_passengers; i++) {
        printf("%s ", passengers[i]);
    }
    printf("\n");
}

void print_floor_status(int floor) {
    printf("Floor %d: ", floor);
    if (floors[floor - 1]) {
        printf("Occupied\n");
    } else {
        printf("Empty\n");
    }
}

void print_building_status() {
    printf("Elevator Status:\n");
    print_elevator_status();
    printf("Floor Status:\n");
    for (int i = 1; i <= max_floors; i++) {
        print_floor_status(i);
    }
    printf("\n");
}

void move_elevator(int floor) {
    if (floor >= 1 && floor <= max_floors) {
        current_floor = floor;
    }
}

void add_passenger(char *name) {
    if (num_passengers < elevator_capacity) {
        strcpy(passengers[num_passengers], name);
        num_passengers++;
    }
}

void remove_passenger(char *name) {
    for (int i = 0; i < num_passengers; i++) {
        if (strcmp(passengers[i], name) == 0) {
            for (int j = i; j < num_passengers - 1; j++) {
                strcpy(passengers[j], passengers[j+1]);
            }
            num_passengers--;
            strcpy(passengers[num_passengers], "");
            return;
        }
    }
}

void add_floor(int floor) {
    if (floor >= 1 && floor <= max_floors) {
        floors[floor - 1] = 1;
    }
}

void remove_floor(int floor) {
    if (floor >= 1 && floor <= max_floors) {
        floors[floor - 1] = 0;
    }
}

void run_simulation() {
    printf("Welcome to the Medieval Elevator Simulation!\n\n");
    while (1) {
        print_building_status();
        printf("What would you like to do?\n");
        printf("(1) Move Elevator\n");
        printf("(2) Add Passenger\n");
        printf("(3) Remove Passenger\n");
        printf("(4) Add Floor\n");
        printf("(5) Remove Floor\n");
        printf("(6) End Simulation\n");
        printf("Enter Choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Enter the floor you would like to move to: ");
                int floor;
                scanf("%d", &floor);
                move_elevator(floor);
                break;
            }
            case 2: {
                printf("Enter the name of the passenger: ");
                char name[20];
                scanf("%s", name);
                add_passenger(name);
                break;
            }
            case 3: {
                printf("Enter the name of the passenger to remove: ");
                char name[20];
                scanf("%s", name);
                remove_passenger(name);
                break;
            }
            case 4: {
                printf("Enter the floor you would like to add: ");
                int floor;
                scanf("%d", &floor);
                add_floor(floor);
                break;
            }
            case 5: {
                printf("Enter the floor you would like to remove: ");
                int floor;
                scanf("%d", &floor);
                remove_floor(floor);
                break;
            }
            case 6: {
                return;
            }
            default: {
                printf("Invalid Choice!\n");
            }
        }
    }
}

int main() {
    run_simulation();
    return 0;
}