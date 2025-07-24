//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The game board and ball set
int board[5][5];
int balls[75];

// Function to generate a random number within a range
int generate_random_number(int min, int max)
{
    srand(time(NULL));
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

// Function to check if a number has already been called
int check_called(int num)
{
    for (int i = 0; i < 75; i++) {
        if (balls[i] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to display the game board
void display_board()
{
    printf("  B  I  N  G  O\n");
    for (int i = 0; i < 5; i++) {
        printf("-----------------\n");
        for (int j = 0; j < 5; j++) {
            printf("|%2d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------\n");
}

// Function to mark a number on the board
void mark_board(int num)
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == num) {
                board[i][j] = 0;
            }
        }
    }
}

int main()
{
    // Set up the game board
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                board[i][j] = 0;
            } else {
                board[i][j] = generate_random_number((j*15)+1, (j*15)+15);
            }
        }
    }

    // Set up the ball set
    for (int i = 0; i < 75; i++) {
        balls[i] = i + 1;
    }

    // Shuffle the ball set
    for (int i = 0; i < 75; i++) {
        int j = generate_random_number(0, 74);
        int temp = balls[i];
        balls[i] = balls[j];
        balls[j] = temp;
    }

    printf("Welcome to the Bingo Simulator, Mr. Holmes!\n");
    printf("Press enter to start the game...\n");
    getchar();

    // Play the game
    while (1) {
        // Call the next number
        int num = balls[0];
        balls[0] = 0;
        for (int i = 0; i < 74; i++) {
            balls[i] = balls[i+1];
        }
        balls[74] = 0;

        // Check if the number has already been called
        if (check_called(num)) {
            printf("I'm sorry, Mr. Holmes, but number %d has already been called.\n", num);
            continue;
        } else {
            printf("The next number is... %d!\n", num);
            mark_board(num);
            display_board();
        }

        // Check if anyone has won
        int winner = 0;
        for (int i = 0; i < 5; i++) {
            int row_sum = 0;
            int col_sum = 0;
            int diag_sum1 = 0;
            int diag_sum2 = 0;
            for (int j = 0; j < 5; j++) {
                row_sum += board[i][j];
                col_sum += board[j][i];
                if (i == j) {
                    diag_sum1 += board[i][j];
                }
                if (i == 4-j) {
                    diag_sum2 += board[i][j];
                }
            }
            if (row_sum == 0 || col_sum == 0 || diag_sum1 == 0 || diag_sum2 == 0) {
                winner = 1;
                break;
            }
        }

        if (winner) {
            printf("Congratulations, Mr. Holmes! You have won!\n");
            break;
        }
    }

    return 0;
}