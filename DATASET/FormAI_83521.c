//FormAI DATASET v1.0 Category: Robot movement control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_HEIGHT 10
#define MAP_WIDTH 10

int map[MAP_HEIGHT][MAP_WIDTH] = {0};

typedef struct {
    int x;
    int y;
} Position;

void initialize_map() {
    // randomly place obstacles on the map
    int obstacle_x, obstacle_y;
    for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH / 4; i++) {
        obstacle_x = rand() % MAP_WIDTH;
        obstacle_y = rand() % MAP_HEIGHT;
        if (map[obstacle_y][obstacle_x] == 0) {
            map[obstacle_y][obstacle_x] = 1; // mark as obstacle
        }
    }
}

void print_map(Position robot_pos) {
    // print the map with the robot symbol
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == robot_pos.y && j == robot_pos.x) {
                printf("R ");
            } else if (map[i][j] == 1) {
                printf("O ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

Position move(Position current_pos, int dx, int dy) {
    // check if the move is valid and update the position
    Position new_pos = current_pos;
    new_pos.x += dx;
    new_pos.y += dy;
    if (new_pos.x < 0 || new_pos.x >= MAP_WIDTH) {
        printf("The robot cannot move in that direction!\n");
    } else if (new_pos.y < 0 || new_pos.y >= MAP_HEIGHT) {
        printf("The robot cannot move in that direction!\n");
    } else if (map[new_pos.y][new_pos.x] == 1) {
        printf("The robot cannot move to an obstacle!\n");
    } else {
        printf("The robot moves to (%d,%d).\n", new_pos.x, new_pos.y);
        current_pos = new_pos;
    }
    return current_pos;
}

int main() {
    printf("Welcome to the Medieval Robot Movement Control Program!\n");

    srand(time(NULL)); // seed random number generator
    initialize_map();

    // randomly place the robot on the map
    Position robot_pos = {rand() % MAP_WIDTH, rand() % MAP_HEIGHT};
    while (map[robot_pos.y][robot_pos.x] == 1) {
        robot_pos.x = rand() % MAP_WIDTH;
        robot_pos.y = rand() % MAP_HEIGHT;
    }

    printf("The robot appears on the map at (%d,%d).\n", robot_pos.x, robot_pos.y);
    print_map(robot_pos);

    char command;
    do {
        printf("Enter a command (N/S/E/W): ");
        scanf(" %c", &command);
        switch (command) {
            case 'N':
                robot_pos = move(robot_pos, 0, -1);
                break;
            case 'S':
                robot_pos = move(robot_pos, 0, 1);
                break;
            case 'E':
                robot_pos = move(robot_pos, 1, 0);
                break;
            case 'W':
                robot_pos = move(robot_pos, -1, 0);
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
        print_map(robot_pos);
    } while (command != 'Q');

    printf("Exiting the Medieval Robot Movement Control Program.\n");
    return 0;
}