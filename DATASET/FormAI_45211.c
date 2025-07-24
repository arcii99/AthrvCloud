//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROWS 10
#define COLS 10

// Function to print the board
void print_board(int board[ROWS][COLS], int score) {
    printf("Score: %d\n", score);
    printf("  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|\n");
    printf("----------------------------------------\n");
    for(int i = 0; i < ROWS; i++) {
        printf("%d |", i+1);
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == 0) {
                printf("   |");
            } else if (board[i][j] == 1) {
                printf(" * |");
            } else if (board[i][j] == -1) {
                printf(" X |");
            }
        }
        printf("\n----------------------------------------\n");
    }
}

// Function to check if the game is over
int check_game_over(int board[ROWS][COLS], int score) {
    int count = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == 1) {
                count++;
            }
        }
    }
    if(score <= -10) {
        return 1;
    }
    if(count == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int board[ROWS][COLS] = {0};
    int bombs = 10; // Number of bombs placed on the board
    int score = 0;

    srand(time(NULL));

    // Place bombs randomly on the board
    for(int i = 0; i < bombs; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if(board[row][col] != 1) {
            board[row][col] = 1;
        } else {
            i--;
        }
    }

    // Play the game until it is over
    while(!check_game_over(board, score)) {
        system("clear"); // Clear the console
        print_board(board, score); // Print the board
        int row, col;
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
        row--;
        col--;

        // If the cell is already uncovered, skip it
        if(board[row][col] == -1 || board[row][col] == 0) {
            continue;
        }

        // If the cell has a bomb, update the score and uncover it
        if(board[row][col] == 1) {
            score -= 5;
            board[row][col] = -1;
        } else {
            // If the cell does not have a bomb, uncover it
            board[row][col] = -1;
            score++;
        }
        usleep(500000); // Wait for half a second before clearing the console
    }

    // Print the final board and score
    system("clear");
    print_board(board, score);
    if(score <= -10) {
        printf("Game over! You uncovered too many bombs!\n");
    } else {
        printf("Game over! You uncovered all the cells!\n");
    }
    return 0;
}