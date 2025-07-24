//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_X 20
#define MAX_Y 20

char map[MAX_X][MAX_Y] = {
    "11111111111111111111",
    "10000000000000000001",
    "10001000000000000001",
    "10000100000000000001",
    "10000010000000000001",
    "10000001111000000001",
    "10000000000000000001",
    "10000000000000010001",
    "10000000000000111001",
    "10000000000001000001",
    "10000000000001000001",
    "10000000000001000001",
    "10000000000000111001",
    "10000000000000010001",
    "10000000000000000001",
    "10000001111000000001",
    "10000010000000000001",
    "10000100000000000001",
    "10001000000000000001",
    "10000000000000000001",
    "11111111111111111111"
};

typedef struct {
    int x;
    int y;
} position;

void clear_screen() {
    printf("\033[H\033[J");
}

void print_map(position robot_pos) {
    clear_screen();
    int x, y;
    for (x = 0; x < MAX_X; x++) {
        for (y = 0; y < MAX_Y; y++) {
            if (robot_pos.x == x && robot_pos.y == y) {
                printf("R");
            } else {
                printf("%c", map[x][y]);
            }
        }
        printf("\n");
    }
}

bool can_move_to(position current_pos, position new_pos) {
    if (new_pos.x >= MAX_X || new_pos.x < 0 || new_pos.y >= MAX_Y || new_pos.y < 0) {
        return false;
    }

    if (map[new_pos.x][new_pos.y] == '1') {
        return false;
    }

    return true;
}

int main() {
    position robot_pos = {1, 1};
    char move_command;
    bool running = true;

    while (running) {
        print_map(robot_pos);

        printf("Move robot (w: up, a: left, s: down, d: right, q: quit): ");
        scanf(" %c", &move_command);

        position new_pos = {robot_pos.x, robot_pos.y};
        if (move_command == 'w') {
            new_pos.x--;
        } else if (move_command == 'a') {
            new_pos.y--;
        } else if (move_command == 's') {
            new_pos.x++;
        } else if (move_command == 'd') {
            new_pos.y++;
        } else if (move_command == 'q') {
            running = false;
        } else {
            printf("Invalid command\n");
            continue;
        }

        if (can_move_to(robot_pos, new_pos)) {
            robot_pos = new_pos;
        } else {
            printf("Can't move there\n");
            sleep(1);
        }
    }

    printf("Goodbye!\n");
    return 0;
}