//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 20

void print_maze(int maze[ROWS][COLS]);
int generate_random_direction(int current_row, int current_col, int visited[ROWS][COLS]);
int is_valid_move(int row, int col);
void generate_maze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];
    srand(time(NULL));
    generate_maze(maze);
    print_maze(maze);
    return 0;
}

void print_maze(int maze[ROWS][COLS]) {
    printf("\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (maze[row][col]) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int generate_random_direction(int current_row, int current_col, int visited[ROWS][COLS]) {
    int directions[4];
    int count = 0;
    if (is_valid_move(current_row - 1, current_col) && !visited[current_row - 1][current_col]) {
        directions[count] = 0;
        count++;
    }
    if (is_valid_move(current_row, current_col + 1) && !visited[current_row][current_col + 1]) {
        directions[count] = 1;
        count++;
    }
    if (is_valid_move(current_row + 1, current_col) && !visited[current_row + 1][current_col]) {
        directions[count] = 2;
        count++;
    }
    if (is_valid_move(current_row, current_col - 1) && !visited[current_row][current_col - 1]) {
        directions[count] = 3;
        count++;
    }
    if (count == 0) {
        return -1;
    }
    int random_index = rand() % count;
    return directions[random_index];
}

int is_valid_move(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

void generate_maze(int maze[ROWS][COLS]) {
    int visited[ROWS][COLS] = {0};
    int current_row = 0;
    int current_col = 0;
    visited[current_row][current_col] = 1;
    int direction = generate_random_direction(current_row, current_col, visited);
    while (direction != -1) {
        switch (direction) {
            case 0:
                maze[current_row - 1][current_col] = 1;
                current_row--;
                break;
            case 1:
                maze[current_row][current_col + 1] = 1;
                current_col++;
                break;
            case 2:
                maze[current_row + 1][current_col] = 1;
                current_row++;
                break;
            case 3:
                maze[current_row][current_col - 1] = 1;
                current_col--;
                break;
        }
        visited[current_row][current_col] = 1;
        direction = generate_random_direction(current_row, current_col, visited);
    }
}