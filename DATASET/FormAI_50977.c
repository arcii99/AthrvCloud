//FormAI DATASET v1.0 Category: Memory Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_ATTEMPTS 8

int board[ROWS][COLS];
int guesses[ROWS][COLS];
int attempts = 0;

// Function Declarations
void init();
void display();
int reveal(int row, int col);
int get_random_int(int min, int max);
void play();

int main() {
    srand(time(0)); // Set the seed for random number generation
    init(); // Initialize the game board
    display(); // Display the game board
    play(); // Start the game
    return 0;
}

// Initializes the game board with random numbers
void init() {
    int nums[ROWS*COLS/2];
    int count = 0;
    for (int i = 0; i < ROWS*COLS/2; i++) {
        nums[i] = count++;
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int index = get_random_int(0, ROWS*COLS/2-1);
            board[i][j] = nums[index];
            board[ROWS-i-1][COLS-j-1] = nums[index]; // Pairs of numbers
            nums[index] = -1; // Mark as used
            while (nums[index] == -1) index = get_random_int(0, ROWS*COLS/2-1);
        }
    }
}

// Displays the game board
void display() {
    printf("=============\n");
    for (int i = 0; i < ROWS; i++) {
        printf("| ");
        for (int j = 0; j < COLS; j++) {
            if (guesses[i][j] == 1) printf("%d ", board[i][j]);
            else printf("* ");
        }
        printf("|\n");
    }
    printf("=============\n");
}

// Reveals a cell on the game board
int reveal(int row, int col) {
    if (guesses[row][col] == 1) {
        printf("You have chosen that before, try again.\n");
        return 0;
    }
    guesses[row][col] = 1;
    display();
    return board[row][col];
}

// Generates a random integer between min and max (inclusive)
int get_random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Plays the game
void play() {
    while (attempts < MAX_ATTEMPTS) {
        int row1, row2, col1, col2;
        int found = 0;
        printf("Enter the first cell to reveal (row, column): ");
        scanf("%d,%d", &row1, &col1);
        printf("Enter the second cell to reveal (row, column): ");
        scanf("%d,%d", &row2, &col2);
        int value1 = reveal(row1, col1);
        int value2 = reveal(row2, col2);
        if (value1 == value2) {
            printf("You found a match!\n");
            found = 1;
        } else {
            printf("Sorry, try again.\n");
            attempts++;
        }
        if (found == 1) {
            // Check if all cells have been revealed
            int done = 1;
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (guesses[i][j] == 0) done = 0;
                }
            }
            if (done == 1) {
                printf("Congratulations! You have won the game in %d attempts!\n", attempts);
                return;
            }
        }
    }
    printf("Game over. You have reached the maximum number of attempts.\n");
}