//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>

#define ROWS 4
#define COLUMNS 5

void printHeader() {
    printf("   ");
    for (int i = 0; i < COLUMNS; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void printHorizontalLine() {
    printf("  ");
    for (int i = 0; i < COLUMNS * 2; i++) {
        printf("-");
    }
    printf("\n");
}

void printGraph(int data[][COLUMNS], char labels[]) {
    // Print the header
    printHeader();
    printHorizontalLine();

    // Print the rows
    for (int i = 0; i < ROWS; i++) {
        printf("%c |", labels[i]);
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    printHorizontalLine();
}

int main() {
    int data[ROWS][COLUMNS] = {
        {3, 4, 2, 6, 7},
        {2, 3, 4, 1, 2},
        {5, 6, 3, 2, 1},
        {8, 5, 4, 7, 3}
    };

    char labels[ROWS] = {'A', 'B', 'C', 'D'};

    // Print the graph
    printGraph(data, labels);

    return 0;
}