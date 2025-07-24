//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function prototypes
void print_card(int card[ROWS][COLS]);
int generate_random_number(int *used_numbers, int num_used_numbers);
void mark_number(int card[ROWS][COLS], int number);
int check_bingo(int card[ROWS][COLS]);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the player's bingo card
    int card[ROWS][COLS] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Print the player's bingo card
    printf("Your bingo card:\n");
    print_card(card);

    // Initialize the used_numbers array
    int used_numbers[75];
    int num_used_numbers = 0;

    // Main game loop
    int number;
    while (1) {
        // Generate a random number
        number = generate_random_number(used_numbers, num_used_numbers);

        // Mark the number on the card
        mark_number(card, number);

        // Print the updated card
        printf("Number drawn: %d\n", number);
        print_card(card);

        // Check for bingo
        if (check_bingo(card)) {
            printf("BINGO! You win!\n");
            break;
        }

        // Add the number to the used_numbers array
        used_numbers[num_used_numbers] = number;
        num_used_numbers++;

        // Pause for dramatic effect
        printf("Press enter to draw the next number...");
        getchar();
    }

    return 0;
}

void print_card(int card[ROWS][COLS]) {
    printf("  B  I  N  G  O\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
}

int generate_random_number(int *used_numbers, int num_used_numbers) {
    int number;
    do {
        number = rand() % 75 + 1;
    } while (find_number(used_numbers, num_used_numbers, number));
    return number;
}

int find_number(int *array, int size, int number) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return 1;
        }
    }
    return 0;
}

void mark_number(int card[ROWS][COLS], int number) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == number) {
                card[i][j] = -number;
            }
        }
    }
}

int check_bingo(int card[ROWS][COLS]) {
    // Check for horizontal bingo
    for (int i = 0; i < ROWS; i++) {
        if (card[i][0] < 0 && card[i][1] < 0 && card[i][2] < 0 && card[i][3] < 0 && card[i][4] < 0) {
            return 1;
        }
    }

    // Check for vertical bingo
    for (int j = 0; j < COLS; j++) {
        if (card[0][j] < 0 && card[1][j] < 0 && card[2][j] < 0 && card[3][j] < 0 && card[4][j] < 0) {
            return 1;
        }
    }

    // Check for diagonal bingo (top-left to bottom-right)
    if (card[0][0] < 0 && card[1][1] < 0 && card[2][2] < 0 && card[3][3] < 0 && card[4][4] < 0) {
        return 1;
    }

    // Check for diagonal bingo (top-right to bottom-left)
    if (card[0][4] < 0 && card[1][3] < 0 && card[2][2] < 0 && card[3][1] < 0 && card[4][0] < 0) {
        return 1;
    }

    // No bingo yet
    return 0;
}