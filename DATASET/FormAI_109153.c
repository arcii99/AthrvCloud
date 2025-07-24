//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int table[rows][cols];

    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            table[i][j] = rand() % 100;
        }
    }

    printf("\nHere is your table:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    printf("\nLet's play a game. Choose a random number in the table: ");
    int target;
    scanf("%d", &target);

    int found = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (table[i][j] == target) {
                printf("You found it! It was at row %d, column %d.\n", i+1, j+1);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Sorry, the number you chose is not in the table.\n");
    }

    return 0;
}