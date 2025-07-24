//FormAI DATASET v1.0 Category: Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMap(char map[][100], int rows, int cols) {
    /* Print the map */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void generateMap(char map[][100], int rows, int cols) {
    /* Generate the map randomly */
    srand(time(0));
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (j == 0 || j == cols - 1 || i == 0 || i == rows - 1) {
                /* Create walls */
                map[i][j] = '#';
            } else {
                /* Create random terrain */
                int r = rand() % 10;
                if (r < 2) {
                    map[i][j] = '*'; /* Asteroids */
                } else if (r < 4) {
                    map[i][j] = '0'; /* Empty space */
                } else {
                    map[i][j] = '.'; /* Ground */
                }
            }
        }
    }
}

int main() {
    char map[100][100];
    int rows = 20, cols = 50, x = 1, y = 1;
    char input;

    generateMap(map, rows, cols);
    /* Place player */
    map[x][y] = '@';

    while (1) {
        system("clear");
        printMap(map, rows, cols);
        printf("Use WASD to move\n");
        /* Get user input */
        scanf("%c", &input);
        if (input == 'w') {
            /* Move up */
            if (map[x - 1][y] == '.') {
                map[x][y] = '.';
                x--;
                map[x][y] = '@';
            }
        } else if (input == 's') {
            /* Move down */
            if (map[x + 1][y] == '.') {
                map[x][y] = '.';
                x++;
                map[x][y] = '@';
            }
        } else if (input == 'a') {
            /* Move left */
            if (map[x][y - 1] == '.') {
                map[x][y] = '.';
                y--;
                map[x][y] = '@';
            }
        } else if (input == 'd') {
            /* Move right */
            if (map[x][y + 1] == '.') {
                map[x][y] = '.';
                y++;
                map[x][y] = '@';
            }
        }
    }

    return 0;
}