//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

// Function prototypes
void initialize_board(int board[SIZE][SIZE], int size);
void print_board(int board[SIZE][SIZE], int size);
int check_bingo(int board[SIZE][SIZE], int size);

int main() {
    int board[SIZE][SIZE];
    int num, count = 0;
    srand(time(NULL));

    // Initialize the board with random numbers
    initialize_board(board, SIZE);

    // Print the initial board
    print_board(board, SIZE);

    // Keep playing until there's a bingo
    while (check_bingo(board, SIZE) == 0) {
        // Get a random number between 1 and 25
        num = rand() % 25 + 1;
        printf("The number called is: %d\n", num);

        // Search for that number in the board
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == num) {
                    // Replace the number with 0 to mark it as called
                    board[i][j] = 0;
                    count++;
                }
            }
        }

        // Print the current board
        printf("Current board:\n");
        print_board(board, SIZE);
    }

    // Print out the number of calls made
    printf("There was a BINGO after %d calls!\n", count);

    return 0;
}

// Initializes the board with random numbers
void initialize_board(int board[SIZE][SIZE], int size) {
    int nums[size * size];

    // Fill an array with the numbers between 1 and size^2
    for (int i = 0; i < size * size; i++) {
        nums[i] = i + 1;
    }

    // Shuffle the array randomly
    for (int i = 0; i < size * size; i++) {
        int j = rand() % size * size;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Copy the shuffled array into the board
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = nums[i * size + j];
        }
    }

    // Replace the middle number with a 0 to represent the free space
    board[size/2][size/2] = 0;
}

// Prints the board to the screen
void print_board(int board[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Checks if there's a bingo in the board
int check_bingo(int board[SIZE][SIZE], int size) {
    int bingo = 0;

    // Check rows and columns for a bingo
    for (int i = 0; i < size; i++) {
        if (board[i][0] == 0 && board[i][1] == 0 && board[i][2] == 0 && board[i][3] == 0 && board[i][4] == 0) {
            bingo = 1;
        }
        if (board[0][i] == 0 && board[1][i] == 0 && board[2][i] == 0 && board[3][i] == 0 && board[4][i] == 0) {
            bingo = 1;
        }
    }

    // Check diagonals for a bingo
    if (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0) {
        bingo = 1;
    }
    if (board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 && board[3][1] == 0 && board[4][0] == 0) {
        bingo = 1;
    }

    return bingo;
}