//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAP_SIZE 10

typedef struct {
    int x;
    int y;
} coordinate_t;

typedef struct {
    char name[20];
    int fuel;
    int health;
    coordinate_t location;
} spaceship_t;

void print_map(char map[MAP_SIZE][MAP_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void move_spaceship(spaceship_t *ship, coordinate_t destination) {
    printf("Moving spaceship %s from (%d,%d) to (%d,%d)\n", ship->name, ship->location.x, ship->location.y, destination.x, destination.y);
    ship->location = destination;
}

bool is_valid_move(char map[MAP_SIZE][MAP_SIZE], int rows, int cols, coordinate_t current, coordinate_t destination) {
    if (destination.x < 0 || destination.x >= rows) {
        printf("Invalid row\n");
        return false;
    }
    if (destination.y < 0 || destination.y >= cols) {
        printf("Invalid column\n");
        return false;
    }
    if (map[destination.x][destination.y] == 'X') {
        printf("Destination is a black hole\n");
        return false;
    }
    int diff_x = abs(current.x - destination.x);
    int diff_y = abs(current.y - destination.y);
    if (diff_x > 1 || diff_y > 1) {
        printf("Spaceship can only move by one unit at a time\n");
        return false;
    }
    return true;
}

int calculate_distance(coordinate_t point_1, coordinate_t point_2) {
    int delta_x = abs(point_1.x - point_2.x);
    int delta_y = abs(point_1.y - point_2.y);
    return delta_x + delta_y;
}

void execute_command(spaceship_t *ship, char command, char map[MAP_SIZE][MAP_SIZE]) {
    coordinate_t current_location = ship->location;
    coordinate_t destination;
    switch (command) {
        case 'N':
            destination = (coordinate_t) {current_location.x - 1, current_location.y};
            break;
        case 'S':
            destination = (coordinate_t) {current_location.x + 1, current_location.y};
            break;
        case 'E':
            destination = (coordinate_t) {current_location.x, current_location.y + 1};
            break;
        case 'W':
            destination = (coordinate_t) {current_location.x, current_location.y - 1};
            break;
        default:
            printf("Invalid command %c\n", command);
            return;
    }
    if (is_valid_move(map, MAP_SIZE, MAP_SIZE, current_location, destination)) {
        move_spaceship(ship, destination);
        if (map[destination.x][destination.y] == 'O') {
            int distance = calculate_distance(current_location, destination);
            printf("Spaceship %s found an alien planet and traveled %d units to get there\n", ship->name, distance);
            ship->health += 10;
            ship->fuel -= distance;
            map[destination.x][destination.y] = ' ';
        } else {
            printf("Spaceship %s moved to (%d,%d)\n", ship->name, destination.x, destination.y);
            ship->fuel--;
        }
    }
}

void generate_random_map(char map[MAP_SIZE][MAP_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (rand() % 8 == 0) {
                map[i][j] = 'X';
            } else if (rand() % 6 == 0) {
                map[i][j] = 'O';
            } else {
                map[i][j] = ' ';
            }
        }
    }
}

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    generate_random_map(map);
    spaceship_t spaceship = {"Voyager I", 100, 100, {0, 0}};
    printf("Welcome to the space adventure game! This is your spaceship:\n");
    printf("Name: %s | Fuel: %d | Health: %d | Location: (%d,%d)\n", spaceship.name, spaceship.fuel, spaceship.health, spaceship.location.x, spaceship.location.y);
    printf("Press N,S,E,W to move, or Q to quit\n");
    bool is_running = true;
    while (is_running) {
        print_map(map, MAP_SIZE, MAP_SIZE);
        printf("Enter command: ");
        char command;
        scanf(" %c", &command);
        if (command == 'Q') {
            printf("Thanks for playing!\n");
            is_running = false;
            return 0;
        }
        execute_command(&spaceship, command, map);
        printf("Name: %s | Fuel: %d | Health: %d | Location: (%d,%d)\n", spaceship.name, spaceship.fuel, spaceship.health, spaceship.location.x, spaceship.location.y);
        if (spaceship.fuel == 0 || spaceship.health == 0) {
            printf("Game over! Spaceship %s has run out of fuel or health\n", spaceship.name);
            is_running = false;
            return 0;
        }
    }
}