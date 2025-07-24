//FormAI DATASET v1.0 Category: Memory Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define BOARD_SIZE ROWS * COLS

int main() {
    int board[BOARD_SIZE];
    int revealed[BOARD_SIZE] = { 0 };
    int open_count = 0;
    int i, j, index, last_index;

    srand(time(NULL));

    printf("Welcome to the Memory Game!\n\n");

    // initialize board
    for (i = 0; i < BOARD_SIZE / 2; i++) {
        board[i] = i;
        board[i + BOARD_SIZE / 2] = i;
    }

    // shuffle board
    for (i = BOARD_SIZE - 1; i >= 0; i--) {
        index = rand() % (i + 1);

        // swap values
        int temp = board[index];
        board[index] = board[i];
        board[i] = temp;
    }

    // reveal board
    printf("Here is the board:\n\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            index = i * COLS + j;
            printf("%d\t", board[index]);
        }
        printf("\n\n");
    }

    printf("Remember the locations of each number on the board!\n");
    printf("Press any key to continue...\n");

    getchar();

    // clear screen
    system("clear");

    // play game
    while (open_count < BOARD_SIZE) {
        printf("Memory Game\n\n");

        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                index = i * COLS + j;

                if (revealed[index]) {
                    printf("%d\t", board[index]);
                } else {
                    printf("?\t");
                }
            }
            printf("\n\n");
        }

        printf("Enter the location of the first number to reveal (row, col): ");
        scanf("%d, %d", &i, &j);
        index = (i - 1) * COLS + (j - 1);

        if (revealed[index]) {
            printf("That location has already been revealed! Press any key to continue...\n");
            getchar();
            continue;
        }

        revealed[index] = 1;
        open_count++;

        printf("\nEnter the location of the second number to reveal (row, col): ");
        scanf("%d, %d", &i, &j);
        last_index = (i - 1) * COLS + (j - 1);

        if (revealed[last_index]) {
            printf("That location has already been revealed! Press any key to continue...\n");
            getchar();
            revealed[index] = 0;
            open_count--;
            continue;
        }

        revealed[last_index] = 1;
        open_count++;

        if (board[index] == board[last_index]) {
            printf("\n\nMatch found! Press any key to continue...\n");
            getchar();
        } else {
            printf("\n\nNo match found. Press any key to continue...\n");
            getchar();
            revealed[index] = 0;
            revealed[last_index] = 0;
            open_count -= 2;
        }

        // clear screen
        system("clear");
    }

    printf("Congratulations! You have matched all numbers on the board!\n");

    return 0;
}