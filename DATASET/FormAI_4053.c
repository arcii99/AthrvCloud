//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global Constants
#define ROWS 5
#define COLUMNS 5
#define MAX_NUM 75

// Function Prototypes
void print_board(int board[ROWS][COLUMNS], int numbers[MAX_NUM]);
int check_bingo(int board[ROWS][COLUMNS]);
void generate_numbers(int numbers[MAX_NUM]);
void mark_board(int board[ROWS][COLUMNS], int number);
void clear_screen();

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create and initialize board and number list
    int board[ROWS][COLUMNS] = {0};
    int numbers[MAX_NUM] = {0};
    generate_numbers(numbers);

    // Print out welcome message
    printf("Welcome to Bingo Medieval Simulator!\n\n");

    // Loop until there is a bingo
    while (check_bingo(board) == 0) {
        // Clear the screen and print the board and the current number
        clear_screen();
        printf("Current Number: %d\n\n", numbers[0]);
        print_board(board, numbers);

        // Get input from user and mark the board if the number is present
        int input;
        printf("Enter 0 to quit or enter the current number: ");
        scanf("%d", &input);

        if (input == 0) {
            printf("Exiting...\n");
            return 0;
        }

        int i;
        for (i = 0; i < MAX_NUM; i++) {
            if (numbers[i] == input) {
                mark_board(board, input);
                numbers[i] = -1;
                break;
            }
        }

        // If the number was not present, print an error message
        if (i == MAX_NUM) {
            printf("Error: Number not found!\n");
            getchar();
        }
    }

    // Print out win message and the final board
    printf("\n\nCongratulations on your Bingo win!!!\n\n");
    print_board(board, numbers);

    return 0;
}

// Print out the current board and the remaining numbers
void print_board(int board[ROWS][COLUMNS], int numbers[MAX_NUM]) {
    int i, j;

    printf("  B   I   N   G   O\n");
    for (i = 0; i < ROWS; i++) {
        printf("-------------------\n");

        for (j = 0; j < COLUMNS; j++) {
            if (j == 0) printf("| %2d ", board[i][j]);
            else printf("| %2d ", board[i][j]);

            if (i == 2 && j == 2) printf("|");
        }

        printf("|\n");
    }

    printf("-------------------\n\n");
    printf("Remaining Numbers:\n");

    for (i = 0; i < MAX_NUM; i++) {
        if (numbers[i] >= 0) printf("%2d ", numbers[i]);
    }

    printf("\n");
}

// Check for a bingo in the board
int check_bingo(int board[ROWS][COLUMNS]) {
    int i, j, count;

    // Check horizontal lines
    for (i = 0; i < ROWS; i++) {
        count = 0;

        for (j = 0; j < COLUMNS; j++) {
            if (board[i][j] != 0) count++;
        }

        if (count == ROWS) return 1;
    }

    // Check vertical lines
    for (j = 0; j < COLUMNS; j++) {
        count = 0;

        for (i = 0; i < ROWS; i++) {
            if (board[i][j] != 0) count++;
        }

        if (count == COLUMNS) return 1;
    }

    // Check diagonal lines
    count = 0;
    for (i = 0; i < ROWS; i++) {
        if (board[i][i] != 0) count++;
    }
    if (count == ROWS) return 1;

    count = 0;
    for (i = 0; i < ROWS; i++) {
        if (board[i][ROWS-i-1] != 0) count++;
    }
    if (count == ROWS) return 1;

    // Return 0 if there is no bingo
    return 0;
}

// Generate numbers list for the game
void generate_numbers(int numbers[MAX_NUM]) {
    int i, j, k;
    int max = MAX_NUM, temp;

    // Initialize array
    for (i = 0; i < MAX_NUM; i++) {
        numbers[i] = i+1;
    }

    // Shuffle array using Fisher-Yates shuffle algorithm
    for (i = MAX_NUM-1; i > 0; i--) {
        j = rand() % (i+1);
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}

// Mark the board if the number is present
void mark_board(int board[ROWS][COLUMNS], int number) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (board[i][j] == number) {
                board[i][j] = -1;
                return;
            }
        }
    }
}

// Clear the screen
void clear_screen() {
    system("cls");
}