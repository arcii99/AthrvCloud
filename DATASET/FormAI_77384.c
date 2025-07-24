//FormAI DATASET v1.0 Category: Graph representation ; Style: mind-bending
#include <stdio.h>

#define ROWS 6
#define COLS 6

int main() {

    int graph[ROWS][COLS] = {
            {0, 1, 1, 1, 0, 0},
            {1, 0, 0, 0, 1, 0},
            {1, 0, 0, 0, 1, 1},
            {1, 0, 0, 0, 0, 1},
            {0, 1, 1, 0, 0, 1},
            {0, 0, 1, 1, 1, 0},
    };

    printf("Graph visualization:\n\n\t");

    for (int i = 1; i <= COLS; i++) {
        printf("%d\t", i);
    }

    printf("\n\t");

    for (int i = 1; i <= COLS; i++) {
        printf("_\t");
    }

    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%c\t| ", i + 65);

        for (int j = 0; j < COLS; j++) {
            if (graph[i][j] == 1) {
                printf("X\t");
            } else {
                printf("-\t");
            }
        }

        printf("\n");
    }
    
    return 0;
}