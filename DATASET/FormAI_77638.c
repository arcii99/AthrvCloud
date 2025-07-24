//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define MAX_COMMAND_LENGTH 20

struct Coord {
    int x;
    int y;
};

void generate_map(char map[MAP_WIDTH][MAP_HEIGHT]) {
    // Generate random obstacles
    srand(time(NULL));
    int num_obstacles = rand() % ((MAP_WIDTH * MAP_HEIGHT) / 3) + 1;
    for (int i = 0; i < num_obstacles; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        map[x][y] = '#';
    }

    // Generate random destination
    int dest_x = rand() % MAP_WIDTH;
    int dest_y = rand() % MAP_HEIGHT;
    map[dest_x][dest_y] = 'D';
}

void print_map(char map[MAP_WIDTH][MAP_HEIGHT], struct Coord current_pos) {
    printf("Current Position: (%d,%d)\n", current_pos.x, current_pos.y);
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (current_pos.x == j && current_pos.y == i) {
                printf("[X]");
            } else {
                printf("[%c]", map[j][i]);
            }
        }
        printf("\n");
    }
}

int main() {
    char map[MAP_WIDTH][MAP_HEIGHT] = {0};
    struct Coord current_pos = {rand() % MAP_WIDTH, rand() % MAP_HEIGHT};

    generate_map(map);
    print_map(map, current_pos);

    while (1) {
        char command[MAX_COMMAND_LENGTH];
        printf("Enter command (up, down, left, right): ");
        scanf("%s", command);

        if (strcmp(command, "up") == 0) {
            if (current_pos.y - 1 >= 0 && map[current_pos.x][current_pos.y - 1] != '#') {
                current_pos.y--;
            }
        } else if (strcmp(command, "down") == 0) {
            if (current_pos.y + 1 < MAP_HEIGHT && map[current_pos.x][current_pos.y + 1] != '#') {
                current_pos.y++;
            }
        } else if (strcmp(command, "left") == 0) {
            if (current_pos.x - 1 >= 0 && map[current_pos.x - 1][current_pos.y] != '#') {
                current_pos.x--;
            }
        } else if (strcmp(command, "right") == 0) {
            if (current_pos.x + 1 < MAP_WIDTH && map[current_pos.x + 1][current_pos.y] != '#') {
                current_pos.x++;
            }
        } else {
            printf("Invalid command. Try again.\n");
        }

        print_map(map, current_pos);

        if (map[current_pos.x][current_pos.y] == 'D') {
            printf("You have arrived at the destination!\n");
            break;
        }
    }

    return 0;
}