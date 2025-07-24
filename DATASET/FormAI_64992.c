//FormAI DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void shuffle(int *arr, size_t n) {
    srand((unsigned) time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int arr[ROWS * COLS];
    int found[ROWS * COLS] = {0};
    int temp = 0;

    // Generate array with pairs of numbers
    for (int i = 0; i < ROWS * COLS; i += 2) {
        arr[i] = temp;
        arr[i + 1] = temp;
        temp++;
    }

    shuffle(arr, ROWS * COLS);

    // Show the game board to the player
    printf("Welcome to Memory Game!\n\n");

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("[%d]", r * ROWS + c + 1);
        }
        printf("\n");
        for (int c = 0; c < COLS; c++) {
            printf(" %d ", arr[r * ROWS + c]);
        }
        printf("\n");
    }

    printf("\nTo begin, choose a number from 1 to 16.\n");
    printf("Enter '-1' to exit.\n\n");

    int guess1 = -1, guess2 = -1;
    int correct = 0;
    int tries = 0;

    while (correct < ROWS * COLS / 2) {
        int input = -1;

        // Ask user for the first guess
        while (input < 0 || input > ROWS * COLS) {
            printf("Enter the first guess: ");
            scanf("%d", &input);
            if (input == -1) {
                printf("Goodbye!\n");
                return 0;
            }
            if (found[input - 1] == 1) {
                printf("This tile has already been matched.\n");
                input = -1;
            }
        }
        guess1 = arr[input - 1];
        printf("You chose [%d] with value %d\n", input, guess1);

        // Ask user for the second guess
        input = -1;
        while (input < 0 || input > ROWS * COLS) {
            printf("Enter the second guess: ");
            scanf("%d", &input);
            if (input == -1) {
                printf("Goodbye!\n");
                return 0;
            }
            if (found[input - 1] == 1) {
                printf("This tile has already been matched.\n");
                input = -1;
            }
        }
        guess2 = arr[input - 1];
        printf("You chose [%d] with value %d\n", input, guess2);

        tries++;

        if (guess1 == guess2) {
            printf("You got it right!\n");
            found[input-1] = 1;
            found[(input-1)%2 ? input-2 : input] = 1;
            correct++;
        } else {
            printf("That's not a match.\n");
        }
    }

    printf("\nCongratulations! You matched all %d pairs in %d tries.\n", ROWS * COLS / 2, tries);

    return 0;
}