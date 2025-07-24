//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_VEHICLE_SPEED 3
#define MAX_CONTROL_DISTANCE 3
#define INITIAL_X_POS 5
#define INITIAL_Y_POS 6

typedef struct position {
    int x;
    int y;
} Position;

typedef struct vehicle {
    Position position;
    int speed;
} Vehicle;

void print_map(char map[MAP_SIZE][MAP_SIZE], Position control_position);
int is_in_range(Position p1, Position p2, int range);
Position get_new_position(Position old_position, int direction);
void move_vehicle(Vehicle *vehicle, Position control_position);

int main() {
    char map[MAP_SIZE][MAP_SIZE] = {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    Position control_position = {INITIAL_X_POS, INITIAL_Y_POS};
    Vehicle vehicle = { {2, 2}, MAX_VEHICLE_SPEED};

    print_map(map, control_position);

    srand(time(NULL));
    int move_count = 0;
    while (move_count < 10) {
        int direction = rand() % 4;
        Position new_position = get_new_position(vehicle.position, direction);

        if (is_in_range(control_position, new_position, MAX_CONTROL_DISTANCE)) {
            move_vehicle(&vehicle, control_position);
            move_count++;
            printf("Direction: %d : Moved vehicle to (%d, %d).\n", direction, vehicle.position.x, vehicle.position.y);
        } else {
            printf("Direction: %d : Vehicle is out of control distance.\n", direction);
        }

        print_map(map, control_position);
    }

    return 0;
}

void print_map(char map[MAP_SIZE][MAP_SIZE], Position control_position) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == control_position.y && j == control_position.x) {
                printf("C ");
            } else {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int is_in_range(Position p1, Position p2, int range) {
    int distance = abs(p1.x - p2.x) + abs(p1.y - p2.y);
    return distance <= range;
}

Position get_new_position(Position old_position, int direction) {
    Position new_position = old_position;
    switch(direction) {
        case 0: // Up
            new_position.y--;
            break;
        case 1: // Right
            new_position.x++;
            break;
        case 2: // Down
            new_position.y++;
            break;
        case 3: // Left
            new_position.x--;
            break;
    }
    return new_position;
}

void move_vehicle(Vehicle *vehicle, Position control_position) {
    int x_distance = control_position.x - vehicle->position.x;
    int y_distance = control_position.y - vehicle->position.y;

    if (x_distance > 0) {
        vehicle->position.x = vehicle->position.x + (vehicle->speed > x_distance ? x_distance : vehicle->speed);
    } else if (x_distance < 0) {
        vehicle->position.x = vehicle->position.x - (vehicle->speed > abs(x_distance) ? abs(x_distance) : vehicle->speed);
    }

    if (y_distance > 0) {
        vehicle->position.y = vehicle->position.y + (vehicle->speed > y_distance ? y_distance : vehicle->speed);
    } else if (y_distance < 0) {
        vehicle->position.y = vehicle->position.y - (vehicle->speed > abs(y_distance) ? abs(y_distance) : vehicle->speed);
    }
}