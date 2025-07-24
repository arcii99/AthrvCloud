//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

// Function to initialize the bingo card
void initialize_card(int card[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card[i][j] = 0;
        }
    }
}

// Function to print the bingo card
void print_card(int card[ROWS][COLS]) {
    printf("  B  I  N  G  O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                printf("  ");
            } else {
                printf("%2d ", card[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to generate a random number between 1 and 75
int generate_random_number() {
    return rand() % MAX_NUM + 1;
}

// Function to check if a number is already on the bingo card
int check_number(int card[ROWS][COLS], int number) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == number) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to mark a number on the bingo card
void mark_number(int card[ROWS][COLS], int number) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == number) {
                card[i][j] = 0;
                return;
            }
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the bingo card
    int card[ROWS][COLS];
    initialize_card(card);

    // Print the bingo card
    print_card(card);

    // Play the game
    int number;
    while (1) {
        // Generate a random number
        number = generate_random_number();

        // Check if the number is already on the card
        if (check_number(card, number)) {
            // If the number is on the card, mark it
            mark_number(card, number);
        }

        // Print the number
        printf("\n%d\n", number);

        // Print the updated bingo card
        print_card(card);

        // Check if the game is over
        int game_over = 1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] != 0) {
                    game_over = 0;
                    break;
                }
            }
            if (!game_over) {
                break;
            }
        }

        if (game_over) {
            printf("\nBingo!\n");
            break;
        }

        // Wait for input before generating the next number
        printf("\nPress any key to continue...\n");
        getchar();
    }

    return 0;
}