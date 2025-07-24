//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 6

void print_board(int board[ROWS][COLS]);
void update_board(int board[ROWS][COLS], int row, int col, int player);
int check_winner(int board[ROWS][COLS]);

int main()
{
    int board[ROWS][COLS] = {{-1,-1,-1,-1,-1,-1},
                             {-1,-1,-1,-1,-1,-1},
                             {-1,-1,-1,-1,-1,-1},
                             {-1,-1,-1,-1,-1,-1},
                             {-1,-1,-1,-1,-1,-1},
                             {-1,-1,-1,-1,-1,-1}};
    int player = 0;
    int row, col, winner;

    // Set random seed
    srand(time(NULL));

    printf("Welcome to the Peaceful Table Game!\n\n");

    do {
        print_board(board);
        printf("\nPlayer %d's turn\n", player+1);
        printf("Enter row (1-6): ");
        scanf("%d", &row);
        printf("Enter column (1-6): ");
        scanf("%d", &col);

        row--; col--;

        if (board[row][col] != -1) {
            printf("\nSorry, that cell is already taken. Please choose another.\n");
            continue;
        }

        update_board(board, row, col, player);
        winner = check_winner(board);

        // Switch player
        player = (player + 1) % 2;

    } while (winner == -1);

    print_board(board);

    if (winner == 0) {
        printf("\nCongratulations! Player 1 is the winner.\n");
    } else if (winner == 1) {
        printf("\nCongratulations! Player 2 is the winner.\n");
    } else {
        printf("\nIt's a tie!\n");
    }

    return 0;
}

void print_board(int board[ROWS][COLS])
{
    printf("\n   1 2 3 4 5 6\n");
    printf("  -------------\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d| ", i+1);
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("  ");
            } else if (board[i][j] == 0) {
                printf("O ");
            } else {
                printf("X ");
            }
        }
        printf("|\n");
    }

    printf("  -------------\n");
}

void update_board(int board[ROWS][COLS], int row, int col, int player)
{
    board[row][col] = player;
}

int check_winner(int board[ROWS][COLS])
{
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if ((board[i][0] != -1) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][2] == board[i][3]) && (board[i][3] == board[i][4]) && (board[i][4] == board[i][5])) {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        if ((board[0][j] != -1) && (board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[2][j] == board[3][j]) && (board[3][j] == board[4][j]) && (board[4][j] == board[5][j])) {
            return board[0][j];
        }
    }

    // Check diagonals
    if ((board[0][0] != -1) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] == board[3][3]) && (board[3][3] == board[4][4]) && (board[4][4] == board[5][5])) {
        return board[0][0];
    }

    if ((board[0][5] != -1) && (board[0][5] == board[1][4]) && (board[1][4] == board[2][3]) && (board[2][3] == board[3][2]) && (board[3][2] == board[4][1]) && (board[4][1] == board[5][0])) {
        return board[0][5];
    }

    // Check if game is a tie
    int tie = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                tie = 0;
                break;
            }
        }
    }

    if (tie) {
        return 2;   // Tie game
    }

    return -1;  // Game still in progress
}