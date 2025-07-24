//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Function to display the current board state
void display_board(char board[ROWS][COLS])
{
    printf("\n");
    printf("\t\t Tic Tac Toe \n\n");
    for (int i = 0; i < ROWS; i++) {
        printf("\t\t");
        for (int j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
            if (j != 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i != 2) {
            printf("\t\t-----------\n");
        }
    }
    printf("\n");
}

// Function to check if the game is over
int is_game_over(char board[ROWS][COLS])
{
    // Check for a horizontal win
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check for a vertical win
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check for a diagonal win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    // Check for a tie
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    // If all spaces are filled and no one wins, it's a tie
    return -1;
}

// Function to let the player take a turn
void player_turn(char board[ROWS][COLS])
{
    int x, y;

    while(1) {
        printf("Enter the row and column (ex: 1 1) you want to place your marker: ");
        scanf("%d %d", &y, &x);

        if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
            printf("Invalid row/column specified, please try again.\n");
            continue;
        }

        if (board[x][y] != ' ') {
            printf("That spot is already taken, please try again.\n");
            continue;
        }

        board[x][y] = 'X';
        break;
    }
}

// Function to let the computer take a turn
void computer_turn(char board[ROWS][COLS])
{
    int x, y;

    printf("Computer is taking its turn.\n");

    while(1) {
        x = rand() % ROWS;
        y = rand() % COLS;

        if (board[x][y] == ' ') {
            board[x][y] = 'O';
            break;
        }
    }
}

int main()
{
    char board[ROWS][COLS] = { {' ', ' ', ' '},
                               {' ', ' ', ' '},
                               {' ', ' ', ' '} };
    int game_over = 0;

    // Seed for the RNG
    srand(time(NULL));

    printf("Welcome to Tic Tac Toe!\n");

    do {
        // Player turn
        display_board(board);
        player_turn(board);
        game_over = is_game_over(board);
        if (game_over != 0) {
            break;
        }

        // Computer turn
        computer_turn(board);
        display_board(board);
        game_over = is_game_over(board);
    } while(game_over == 0);

    // Game is over, display result
    if (game_over == 1) {
        printf("Congratulations! You won!\n");
    } else if (game_over == -1) {
        printf("The game ended in a tie.\n");
    } else {
        printf("Sorry, you lost.\n");
    }

    return 0;
}