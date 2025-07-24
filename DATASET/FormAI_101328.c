//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5   // Number of rows in the Bingo board
#define COLS 5   // Number of columns in the Bingo board

// Function prototypes
void initializeBoard(int board[ROWS][COLS]);
void printBoard(int board[ROWS][COLS]);
int checkBingo(int board[ROWS][COLS]);

int main() {

    // Seed the random number generator with current time
    srand(time(NULL));

    int board[ROWS][COLS];
    int num, count = 0;
    int bingo = 0;

    // Initialize the Bingo board
    initializeBoard(board);

    printf("Welcome to the Bingo Simulator! \n");

    // Keep generating random numbers until there's a Bingo
    while (bingo != 1) {

        // Generate a random number between 1 and 25
        num = rand() % 25 + 1;

        // Loop through the board to see if the number matches
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = -1;   // Mark the number as found
                    count++;    // Keep track of the number of numbers found
                }
            }
        }

        // Print the updated Bingo board
        printf("\nNumber generated: %d\n", num);
        printBoard(board);

        // Check if there's a Bingo
        bingo = checkBingo(board);

        // If Bingo, print a congratulatory message
        if (bingo == 1) {
            printf("\nCongratulations! You got a Bingo!\n");
        }

        // If all numbers are found but still no Bingo, print a message
        if (count == ROWS * COLS && bingo == 0) {
            printf("\nNo Bingo! Try again.\n");
            break;
        }

        // Pause for a second before generating the next number
        sleep(1);

    }

    return 0;   // End of program
}

// Function to initialize the Bingo board with random numbers
void initializeBoard(int board[ROWS][COLS]) {
    int nums[25];
    int index = 0;

    // Fill the nums array with numbers from 1 to 25
    for (int i = 0; i < 25; i++) {
        nums[i] = i + 1;
    }

    // Shuffle the nums array using Fisher-Yates shuffle algorithm
    for (int i = 24; i >= 0; i--) {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Fill the Bingo board with the shuffled numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = nums[index];  // Assign each cell in the board with a shuffled number
            index++;
        }
    }

    // Mark the center cell as empty
    board[2][2] = -1;
}

// Function to print the Bingo board
void printBoard(int board[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("  ");    // Print a blank space for the center cell
            } else {
                printf("%d ", board[i][j]);     // Print the number
            }
        }
        printf("\n");
    }
}

// Function to check if a Bingo has been achieved
int checkBingo(int board[ROWS][COLS]) {
    int bingo = 0;

    // Check rows
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                count++;
            }
        }
        if (count == ROWS) {
            bingo = 1;
        }
    }

    // Check columns
    for (int i = 0; i < COLS; i++) {
        int count = 0;
        for (int j = 0; j < ROWS; j++) {
            if (board[j][i] == -1) {
                count++;
            }
        }
        if (count == COLS) {
            bingo = 1;
        }
    }

    // Check diagonals
    if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
        bingo = 1;
    }
    if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
        bingo = 1;
    }

    return bingo;
}