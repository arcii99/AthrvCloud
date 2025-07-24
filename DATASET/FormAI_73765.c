//FormAI DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define WINNING_SCORE 5

void printBoard(int board[][BOARD_SIZE]);
void initBoard(int board[][BOARD_SIZE]);
int checkWin(int board[][BOARD_SIZE], int row, int col, int player);
int game(int board[][BOARD_SIZE], int player, int score[]);
int pickRandomMove(int board[][BOARD_SIZE], int *row, int *col);
int recursiveMove(int board[][BOARD_SIZE], int *row, int *col, int depth, int player);

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int score[2] = {0, 0};

    srand(time(NULL));
    initBoard(board);
    game(board, 1, score);

    printf("Player 1 Score: %d\n", score[0]);
    printf("Player 2 Score: %d\n", score[1]);

    return 0;
}

void printBoard(int board[][BOARD_SIZE])
{
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0)
                printf(". ");
            else if (board[i][j] == 1)
                printf("X ");
            else
                printf("O ");
        }
        printf("\n");
    }
    printf("\n");
}

void initBoard(int board[][BOARD_SIZE])
{
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++)
            board[i][j] = 0;
    }
}

int checkWin(int board[][BOARD_SIZE], int row, int col, int player)
{
    int i, j;
    int count;

    // Check horizontal
    count = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == player)
            count++;
        else
            count = 0;
        if (count == WINNING_SCORE)
            return 1;
    }

    // Check vertical
    count = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == player)
            count++;
        else
            count = 0;
        if (count == WINNING_SCORE)
            return 1;
    }

    // Check diagonal
    count = 0;
    i = row - col;
    j = 0;
    while (i < 0) {
        i++;
        j++;
    }
    while (i < BOARD_SIZE && j < BOARD_SIZE) {
        if (board[i][j] == player)
            count++;
        else
            count = 0;
        if (count == WINNING_SCORE)
            return 1;
        i++;
        j++;
    }

    // Check reverse diagonal
    count = 0;
    i = row + col;
    j = 0;
    while (i >= BOARD_SIZE) {
        i--;
        j++;
    }
    while (i >= 0 && j < BOARD_SIZE) {
        if (board[i][j] == player)
            count++;
        else
            count = 0;
        if (count == WINNING_SCORE)
            return 1;
        i--;
        j++;
    }

    return 0;
}

int game(int board[][BOARD_SIZE], int player, int score[])
{
    int row, col;
    int winner;
    int ai_row, ai_col;

    while (1) {
        printf("Player %d's turn.\n", player);
        printBoard(board);

        if (player == 1) {
            do {
                printf("Enter row (1-%d) and column (1-%d): ", BOARD_SIZE, BOARD_SIZE);
                scanf("%d %d", &row, &col);
                row--;
                col--;
            } while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != 0);
        } else {
            printf("Computer thinking...\n");
            pickRandomMove(board, &row, &col);
            recursiveMove(board, &row, &col, 0, 2);
        }

        board[row][col] = player;
        winner = checkWin(board, row, col, player);
        if (winner) {
            printf("Player %d wins!\n", player);
            score[player-1]++;
            return player;
        }

        if (player == 1)
            player = 2;
        else
            player = 1;

        if (score[0] + score[1] == WINNING_SCORE) {
            printf("Game over.\n");
            if (score[0] > score[1])
                return 1;
            else if (score[1] > score[0])
                return 2;
            else
                return 0;
        }
    }
}

int pickRandomMove(int board[][BOARD_SIZE], int *row, int *col)
{
    int i, j;
    int count = 0;
    int options[BOARD_SIZE*BOARD_SIZE][2];

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                options[count][0] = i;
                options[count][1] = j;
                count++;
            }
        }
    }

    if (count > 0) {
        i = rand() % count;
        *row = options[i][0];
        *col = options[i][1];
        return 1;
    } else {
        return 0;
    }
}

int recursiveMove(int board[][BOARD_SIZE], int *row, int *col, int depth, int player)
{
    int i, j;
    int winner;
    int score;
    int best_row = -1;
    int best_col = -1;
    int best_score = -1;
    int new_board[BOARD_SIZE][BOARD_SIZE];

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                // Copy board
                for (int x = 0; x < BOARD_SIZE; x++) {
                    for (int y = 0; y < BOARD_SIZE; y++) {
                        new_board[x][y] = board[x][y];
                    }
                }

                // Make move
                new_board[i][j] = player;

                // Check for winner
                winner = checkWin(new_board, i, j, player);
                if (winner) {
                    score = 100 - depth;
                } else if (depth == 3) {
                    score = 0;
                } else {
                    if (player == 1) {
                        score = recursiveMove(new_board, &i, &j, depth+1, 2);
                    } else {
                        score = recursiveMove(new_board, &i, &j, depth+1, 1);
                    }
                }

                // Update best move
                if (score > best_score) {
                    best_row = i;
                    best_col = j;
                    best_score = score;
                }
            }
        }
    }

    *row = best_row;
    *col = best_col;
    return best_score;
}