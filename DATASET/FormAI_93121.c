//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_maze(int maze[][COLS], int rows, int cols);
void generate_maze(int maze[][COLS], int rows, int cols);
void create_path(int maze[][COLS], int rows, int cols, int row, int col);
int is_valid_move(int maze[][COLS], int rows, int cols, int row, int col, int move);
int get_random_move(int valid_moves[], int num_valid_moves);
void shuffle_array(int arr[], int n);

int main() {
    int maze[ROWS][COLS];
    srand(time(0)); // seed random number generator

    generate_maze(maze, ROWS, COLS);
    print_maze(maze, ROWS, COLS);

    return 0;
}

void print_maze(int maze[][COLS], int rows, int cols) {
    printf(" ");
    for (int i = 0; i < cols * 2 - 1; i++) {
        printf("_");
    }
    printf("\n");

    for (int row = 0; row < rows; row++) {
        printf("|");
        for (int col = 0; col < cols; col++) {
            if (maze[row][col] & 8) {
                printf("_");
            } else {
                printf(" ");
            }
            if (maze[row][col] & 2) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_maze(int maze[][COLS], int rows, int cols) {
    // initialize maze
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            maze[row][col] = 15; // set all walls to closed
        }
    }

    // create path from top left corner
    create_path(maze, rows, cols, 0, 0);
}

void create_path(int maze[][COLS], int rows, int cols, int row, int col) {
    int moves[4] = {0, 1, 2, 3}; // north, east, south, west
    shuffle_array(moves, 4); // randomize order of moves

    for (int i = 0; i < 4; i++) {
        int move = moves[i];
        int next_row = row + (move == 0 ? -1 : move == 2 ? 1 : 0);
        int next_col = col + (move == 1 ? 1 : move == 3 ? -1 : 0);

        if (next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols && maze[next_row][next_col] == 15) {
            // valid move, break wall and continue path
            maze[row][col] &= ~(1 << move);
            maze[next_row][next_col] &= ~(1 << (move + 2));
            create_path(maze, rows, cols, next_row, next_col);
        }
    }
}

int is_valid_move(int maze[][COLS], int rows, int cols, int row, int col, int move) {
    int next_row = row + (move == 0 ? -1 : move == 2 ? 1 : 0);
    int next_col = col + (move == 1 ? 1 : move == 3 ? -1 : 0);

    return next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols && maze[next_row][next_col] == 15;
}

int get_random_move(int valid_moves[], int num_valid_moves) {
    int index = rand() % num_valid_moves;
    return valid_moves[index];
}

void shuffle_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}