//FormAI DATASET v1.0 Category: Memory Game ; Style: high level of detail
// C Memory Game Example

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

char board[BOARD_SIZE][BOARD_SIZE]; // initialize game board to store characters

void initialize_board() {
    // populate game board with random characters
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = letters[count % (BOARD_SIZE * BOARD_SIZE / 2)];
            count++;
        }
    }

    // shuffle the characters randomly
    srand(time(NULL));
    count = BOARD_SIZE * BOARD_SIZE;

    while (count > 0) {
        int random_pos1 = rand() % (BOARD_SIZE * BOARD_SIZE);
        int random_pos2 = rand() % (BOARD_SIZE * BOARD_SIZE);

        if (random_pos1 == random_pos2) {
            continue;
        }

        int row1 = random_pos1 / BOARD_SIZE;
        int col1 = random_pos1 % BOARD_SIZE;
        int row2 = random_pos2 / BOARD_SIZE;
        int col2 = random_pos2 % BOARD_SIZE;

        char temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;

        count -= 2;
    }
}

void print_board() {
    // print the current state of the game board
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int main() {
    int flips = 0;
    int choice1_row = -1;
    int choice1_col = -1;
    int choice2_row = -1;
    int choice2_col = -1;

    initialize_board(); // initialize game board
    printf("Welcome to the Memory Game!\n");
    print_board(); // print the initial game board

    while (flips < BOARD_SIZE * BOARD_SIZE / 2) {
        printf("Please enter the position of your first choice (e.g. 1 3): ");
        scanf("%d %d", &choice1_row, &choice1_col);

        while ((choice1_row < 0 || choice1_row >= BOARD_SIZE) || (choice1_col < 0 || choice1_col >= BOARD_SIZE)) {
            printf("Invalid selection. Please enter the position of your first choice (e.g. 1 3): ");
            scanf("%d %d", &choice1_row, &choice1_col);
        }

        if (board[choice1_row][choice1_col] == '*') {
            printf("This position has already been matched. Please choose another position.\n");
            continue;
        }

        printf("\n");
        board[choice1_row][choice1_col] = '*'; // flip the first choice over
        print_board(); // print the updated game board

        printf("Please enter the position of your second choice (e.g. 1 3): ");
        scanf("%d %d", &choice2_row, &choice2_col);

        while ((choice2_row < 0 || choice2_row >= BOARD_SIZE) || (choice2_col < 0 || choice2_col >= BOARD_SIZE)) {
            printf("Invalid selection. Please enter the position of your second choice (e.g. 1 3): ");
            scanf("%d %d", &choice2_row, &choice2_col);
        }

        if (board[choice2_row][choice2_col] == '*') {
            printf("This position has already been matched. Please choose another position.\n");
            continue;
        }

        board[choice2_row][choice2_col] = '*'; // flip the second choice over
        print_board(); // print the updated game board

        if (board[choice1_row][choice1_col] == board[choice2_row][choice2_col]) { // if the two choices match
            printf("Congratulations! You found a match.\n");
            flips++;
        } else {
            board[choice1_row][choice1_col] = board[choice2_row][choice2_col] = ' '; // flip the two choices back over
            printf("Sorry! These two positions do not match.\n");
        }

        choice1_row = choice1_col = choice2_row = choice2_col = -1; // reset variables for next turn
    }

    printf("Great job! You have matched all characters on the board.\n");

    return 0;
}