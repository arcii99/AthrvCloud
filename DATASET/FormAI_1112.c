//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: calm
// C Bingo Simulator Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 5

// Function prototypes
void generate_card(int card[ROWS][COLS]);
void display_card(int card[ROWS][COLS]);
int draw_number(int drawn_numbers[], int numbers_drawn);
int check_win(int card[ROWS][COLS]);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare variables
    int player_card[ROWS][COLS];
    int drawn_numbers[75] = {0};
    int numbers_drawn = 0;

    // Generate and display player's card
    generate_card(player_card);
    printf("Player's Card:\n");
    display_card(player_card);

    // Game loop
    while (1) {
        // Prompt user to draw a number
        printf("Press enter to draw a number...");
        getchar();

        // Draw a number
        int number_drawn = draw_number(drawn_numbers, numbers_drawn);
        printf("Number drawn: %d\n", number_drawn);
        numbers_drawn++;

        // Check if number is on player's card
        int row, col, found = 0;
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                if (player_card[row][col] == number_drawn) {
                    player_card[row][col] = 0;
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        // Display updated player's card
        printf("Player's Card:\n");
        display_card(player_card);

        // Check if player has won
        if (check_win(player_card)) {
            printf("Bingo! You win!\n");
            break;
        }

        // Check if all numbers have been drawn
        if (numbers_drawn == 75) {
            printf("Sorry, no more numbers to draw. You lose.\n");
            break;
        }
    }

    return 0;
}

// Function to generate player's card
void generate_card(int card[ROWS][COLS]) {
    int row, col, num;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            // Generate unique random number for each cell
            do {
                num = (col * 15) + (rand() % 15) + 1;
            } while (num_in_row(num, card, row) || num_in_col(num, card, col));
            card[row][col] = num;
        }
    }
}

// Function to check if a number is already in the same row
int num_in_row(int num, int card[ROWS][COLS], int row) {
    int col;
    for (col = 0; col < COLS; col++) {
        if (card[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is already in the same column
int num_in_col(int num, int card[ROWS][COLS], int col) {
    int row;
    for (row = 0; row < ROWS; row++) {
        if (card[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to display player's card
void display_card(int card[ROWS][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%2d ", card[row][col]);
        }
        printf("\n");
    }
}

// Function to draw a number
int draw_number(int drawn_numbers[], int numbers_drawn) {
    int num;
    do {
        num = (rand() % 75) + 1;
    } while (drawn(num, drawn_numbers, numbers_drawn));
    drawn_numbers[numbers_drawn] = num;
    return num;
}

// Function to check if a number has already been drawn
int drawn(int num, int drawn_numbers[], int numbers_drawn) {
    int i;
    for (i = 0; i < numbers_drawn; i++) {
        if (drawn_numbers[i] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if player has won
int check_win(int card[ROWS][COLS]) {
    int row, col, num_zeros;
    // Check rows
    for (row = 0; row < ROWS; row++) {
        num_zeros = 0;
        for (col = 0; col < COLS; col++) {
            if (card[row][col] == 0) {
                num_zeros++;
            }
        }
        if (num_zeros == COLS) {
            return 1;
        }
    }
    // Check columns
    for (col = 0; col < COLS; col++) {
        num_zeros = 0;
        for (row = 0; row < ROWS; row++) {
            if (card[row][col] == 0) {
                num_zeros++;
            }
        }
        if (num_zeros == ROWS) {
            return 1;
        }
    }
    // Check diagonals
    if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0) {
        return 1;
    }
    if (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0) {
        return 1;
    }
    return 0;
}