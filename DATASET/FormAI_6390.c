//FormAI DATASET v1.0 Category: Memory Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int main(void) {
    srand(time(0));
    printf("Welcome to the Memory Game!\n\n");

    int board[SIZE][SIZE] = {0};
    int options[SIZE * SIZE];
    int num_options = 0;

    // Initialize the board with random numbers
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int num = rand() % (SIZE * SIZE / 2) + 1;
            // Check if already added to options array
            int already_added = 0;
            for (int k = 0; k < num_options; k++) {
                if (options[k] == num) {
                    already_added = 1;
                    break;
                }
            }
            if (!already_added) {
                options[num_options] = num;
                num_options++;
            }
            board[i][j] = num;
        }
    }

    // Randomly assign options to board
    int counter = 0;
    while (num_options > 0) {
        int index = rand() % num_options;
        int num = options[index];
        options[index] = options[num_options - 1];
        num_options--;
        int pair = 0;
        while (pair < 2) {
            int i = rand() % SIZE;
            int j = rand() % SIZE;
            if (board[i][j] == num) {
                pair++;
                board[i][j] = counter + 1;
            }
        }
        counter++;
    }

    // Print the board
    printf("   ");
    for (int i = 0; i < SIZE; i++) {
        printf("%-3d", i);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%-3d", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%-3d", board[i][j]);
        }
        printf("\n");
    }

    // Play the game
    int num_guesses = 0;
    while (1) {
        int x1, y1, x2, y2;
        printf("Enter the coordinates of the first card: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the coordinates of the second card: ");
        scanf("%d %d", &x2, &y2);
        if (board[x1][y1] == board[x2][y2]) {
            printf("You found a match!\n");
            num_guesses++;
        } else {
            printf("Sorry, those cards do not match. Try again.\n");
            num_guesses++;
        }
        if (num_guesses == SIZE * SIZE / 2) {
            printf("Congratulations! You won in %d guesses!\n", num_guesses);
            break;
        }
    }

    return 0;
}