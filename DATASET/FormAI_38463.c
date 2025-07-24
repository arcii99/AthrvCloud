//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GRID_SIZE 10
#define MAX_ENERGY 500

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int energy;
} Vehicle;

Position create_random_position() {
    Position pos;
    pos.x = rand() % GRID_SIZE;
    pos.y = rand() % GRID_SIZE;
    return pos;
}

void print_grid(Vehicle *vehicles, int num_vehicles) {
    char grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '-';
        }
    }

    for (int i = 0; i < num_vehicles; i++) {
        int x = vehicles[i].pos.x;
        int y = vehicles[i].pos.y;
        grid[x][y] = 'V';
    }

    printf("\n");

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_move(Position pos) {
    if ((pos.x >= 0 && pos.x < GRID_SIZE) && (pos.y >= 0 && pos.y < GRID_SIZE)) {
        return true;
    } else {
        return false;
    }
}

void move_vehicle(Vehicle *vehicle) {
    int direction = rand() % 4;
    Position new_pos = vehicle->pos;

    switch(direction) {
        case 0: // move up
            new_pos.x -= 1;
            break;
        case 1: // move down
            new_pos.x += 1;
            break;
        case 2: // move left
            new_pos.y -= 1;
            break;
        case 3: // move right
            new_pos.y += 1;
            break;
        default:
            break;
    }

    if (is_valid_move(new_pos)) {
        vehicle->pos = new_pos;
        vehicle->energy--;
    }
}

bool is_game_over(Vehicle *vehicles, int num_vehicles) {
    int total_energy = 0;
    for (int i = 0; i < num_vehicles; i++) {
        total_energy += vehicles[i].energy;
    }
    
    if (total_energy == 0) {
        return true;
    } else {
        return false;
    }
}

void simulate_game(Vehicle *vehicles, int num_vehicles) {
    while (!is_game_over(vehicles, num_vehicles)) {
        for (int i = 0; i < num_vehicles; i++) {
            move_vehicle(&vehicles[i]);
        }

        print_grid(vehicles, num_vehicles);
    }
}

int main() {
    srand(time(NULL));

    // create vehicles
    int num_vehicles = 4;
    Vehicle vehicles[num_vehicles];
    for (int i = 0; i < num_vehicles; i++) {
        vehicles[i].pos = create_random_position();
        vehicles[i].energy = rand() % MAX_ENERGY + 1;
    }

    // simulate game
    simulate_game(vehicles, num_vehicles);

    return 0;
}