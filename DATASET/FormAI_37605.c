//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10

int main() {
    srand(time(NULL)); // sets the seed for random number generation

    int board[SIZE][SIZE];

    // filling the board with random numbers from 1 to 100
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = (rand() % 100) + 1;
        }
    }

    bool is_winner = false;
    int counter = 0;
    int calls[SIZE*SIZE];
    int num_calls = 0;

    printf("Welcome to C Bingo Simulator!\n"
           "The rules are simple - try to get 5 numbers in a row.\n"
           "Let's start!\n\n");

    // game loop
    while (!is_winner) {
        printf("Current Board:\n");

        // printing the board
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == -1) { // if the number is called, mark it with an X
                    printf("X\t");
                }
                else {
                    printf("%d\t", board[i][j]);
                }
            }
            printf("\n");
        }

        // taking input from the user
        int call;
        printf("Enter the next number called: ");
        scanf("%d", &call);

        // checking if the number is on the board
        bool is_on_board = false;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == call) {
                    board[i][j] = -1; // changing the number to -1 to mark it as called
                    is_on_board = true;
                }
            }
        }

        if (is_on_board) {
            calls[num_calls++] = call; // adding the call to the calls array
            counter = 0;

            // checking for horizontal win
            for (int i = 0; i < SIZE; i++) {
                int row_counter = 0;
                for (int j = 0; j < SIZE; j++) {
                    if (board[i][j] == -1) {
                        row_counter++;
                    }
                }
                if (row_counter == SIZE) {
                    is_winner = true;
                    printf("HORIZONTAL WIN!\n");
                    break;
                }
            }

            if (!is_winner) {
                // checking for vertical win
                for (int i = 0; i < SIZE; i++) {
                    int col_counter = 0;
                    for (int j = 0; j < SIZE; j++) {
                        if (board[j][i] == -1) {
                            col_counter++;
                        }
                    }
                    if (col_counter == SIZE) {
                        is_winner = true;
                        printf("VERTICAL WIN!\n");
                        break;
                    }
                }
            }

            if (!is_winner) {
                // checking for diagonal win
                int diag_counter1 = 0;
                int diag_counter2 = 0;
                for (int i = 0; i < SIZE; i++) {
                    if (board[i][i] == -1) {
                        diag_counter1++;
                    }
                    if (board[i][SIZE-1-i] == -1) {
                        diag_counter2++;
                    }
                }
                if (diag_counter1 == SIZE || diag_counter2 == SIZE) {
                    is_winner = true;
                    printf("DIAGONAL WIN!\n");
                }
            }

            if (!is_winner) {
                // checking if the user has reached 20 calls without a win
                if (num_calls == 20) {
                    printf("NO WIN. BETTER LUCK NEXT TIME!\n");
                    is_winner = true;
                }
            }
        }
        else {
            printf("That number isn't on the board. Try again.\n");
            counter++;
            if (counter >= 3) {
                printf("You've missed 3 calls in a row. Game over!\n");
                break;
            }
        }
    }

    printf("\nHere are the calls made:\n");
    for (int i = 0; i < num_calls; i++) {
        printf("%d ", calls[i]);
    }

    printf("\n\nThanks for playing C Bingo Simulator!\n");

    return 0;
}