//FormAI DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100

//rules of game of life
#define COUNT_NEIGHBORS(i, j) map[i - 1][j] + map[i - 1][j - 1] + map[i][j - 1] + map[i + 1][j - 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1] + map[i - 1][j + 1]

//function to print current map
void print_map(int map[][MAX_COLS], int rows, int cols) {
    printf("\n  ");
    for (int i = 0; i < cols; ++i) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < rows; ++i) {
        printf("%d ", i);
        for (int j = 0; j < cols; ++j) {
            printf("%c ", map[i][j] ? '#' : '-');
        }
        printf("\n");
    }
}

int main(void) {
    int rows = 0, cols = 0, generations = 0;
    int map[MAX_ROWS][MAX_COLS] = {0}, buffer[MAX_ROWS][MAX_COLS] = {0};

    //taking input from user
    printf("Enter number of rows (MAX %d):", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (MAX %d):", MAX_COLS);
    scanf("%d", &cols);
    printf("Enter number of generations:");
    scanf("%d", &generations);

    //seeding the random generator
    srand(time(NULL));

    //initializing the map randomly
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            map[i][j] = rand() % 2;
        }
    }

    //printing initial map
    printf("\nInitial Map:\n");
    print_map(map, rows, cols);

    //simulating game of life
    for (int step = 1; step <= generations; ++step) {
        printf("\nGeneration %d:\n", step);
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                int count_neighbors = COUNT_NEIGHBORS(i, j);
                if (map[i][j] == 0 && count_neighbors == 3) {
                    buffer[i][j] = 1;
                } else if (map[i][j] == 1 && (count_neighbors < 2 || count_neighbors > 3)) {
                    buffer[i][j] = 0;
                } else {
                    buffer[i][j] = map[i][j];
                }
            }
        }
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                map[i][j] = buffer[i][j];
            }
        }
        print_map(map, rows, cols);
    }

    return 0;
}