//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAZE_SIZE 15

void print_maze(int maze[][MAZE_SIZE]);
void generate_maze(int maze[][MAZE_SIZE], int row_pos, int col_pos);
bool is_valid_position(int row, int col);
bool is_unvisited(int maze[][MAZE_SIZE], int row, int col);
bool has_unvisited_neighbour(int maze[][MAZE_SIZE], int row, int col);
int get_random_direction();

int main() {
    int maze[MAZE_SIZE][MAZE_SIZE];
    srand(time(NULL));
    generate_maze(maze, 0, 0);
    print_maze(maze);
    return 0;
}

void print_maze(int maze[][MAZE_SIZE]) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c ", maze[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

void generate_maze(int maze[][MAZE_SIZE], int row_pos, int col_pos) {
    maze[row_pos][col_pos] = 1;

    while (has_unvisited_neighbour(maze, row_pos, col_pos)) {
        int direction = get_random_direction();

        switch (direction) {
        case 0: // North
            if (is_valid_position(row_pos - 2, col_pos) && is_unvisited(maze, row_pos - 2, col_pos)) {
                maze[row_pos - 1][col_pos] = 1;
                generate_maze(maze, row_pos - 2, col_pos);
            }
            break;

        case 1: // East
            if (is_valid_position(row_pos, col_pos + 2) && is_unvisited(maze, row_pos, col_pos + 2)) {
                maze[row_pos][col_pos + 1] = 1;
                generate_maze(maze, row_pos, col_pos + 2);
            }
            break;

        case 2: // South
            if (is_valid_position(row_pos + 2, col_pos) && is_unvisited(maze, row_pos + 2, col_pos)) {
                maze[row_pos + 1][col_pos] = 1;
                generate_maze(maze, row_pos + 2, col_pos);
            }
            break;

        case 3: // West
            if (is_valid_position(row_pos, col_pos - 2) && is_unvisited(maze, row_pos, col_pos - 2)) {
                maze[row_pos][col_pos - 1] = 1;
                generate_maze(maze, row_pos, col_pos - 2);
            }
            break;

        default:
            break;
        }
    }
}

bool is_valid_position(int row, int col) {
    return row >= 0 && row < MAZE_SIZE && col >= 0 && col < MAZE_SIZE;
}

bool is_unvisited(int maze[][MAZE_SIZE], int row, int col) {
    return maze[row][col] == 0;
}

bool has_unvisited_neighbour(int maze[][MAZE_SIZE], int row, int col) {
    int directions[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    for (int i = 0; i < 4; i++) {
        int new_row = row + directions[i][0] * 2;
        int new_col = col + directions[i][1] * 2;

        if (is_valid_position(new_row, new_col) && is_unvisited(maze, new_row, new_col)) {
            return true;
        }
    }

    return false;
}

int get_random_direction() {
    return rand() % 4;
}