//FormAI DATASET v1.0 Category: Checkers Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

/* Board representation */
int board[SIZE][SIZE] = {
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1},
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1}
};

/* Function to print board */
void print_board()
{
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == -1) {
                printf("x ");
            } else if (board[i][j] == 0) {
                printf(". ");
            } else {
                printf("O ");
            }
        }
        printf("%d\n", i+1);
    }
    printf("  A B C D E F G H\n");
}

/* Function to move pieces */
int move(int start_x, int start_y, int end_x, int end_y)
{
    /* Check if move is legal */
    if (board[start_y][start_x] == -1 || board[end_y][end_x] != 0) {
        return 0;
    } else if (start_x == end_x && abs(start_y - end_y) == 1) {
        /* Move single space forward */
        board[end_y][end_x] = board[start_y][start_x];
        board[start_y][start_x] = 0;
        return 1;
    } else if (abs(start_x - end_x) == 1 && abs(start_y - end_y) == 1) {
        /* Move one space diagonally */
        board[end_y][end_x] = board[start_y][start_x];
        board[start_y][start_x] = 0;
        return 1;
    } else if (abs(start_x - end_x) == 2 && abs(start_y - end_y) == 2) {
        /* Jump over opponent */
        int middle_x = (start_x + end_x) / 2;
        int middle_y = (start_y + end_y) / 2;
        if (board[middle_y][middle_x] == 1) {
            board[middle_y][middle_x] = 0;
            board[end_y][end_x] = board[start_y][start_x];
            board[start_y][start_x] = 0;
            return 1;
        }
    }
    return 0;
}

/* Main function */
int main()
{
    int turn = 1;
    int column_start, row_start, column_end, row_end;
    int gameover = 0;

    /* Print starting board */
    print_board();

    /* Loop for taking turns */
    while (!gameover) {
        printf("\nTurn %d. Your move: ", turn);
        scanf("%c%d %c%d", &column_start, &row_start, &column_end, &row_end);
        column_start -= 'A';
        row_start--;
        column_end -= 'A';
        row_end--;

        if (move(column_start, row_start, column_end, row_end)) {
            /* Valid move */
            print_board();
            if (turn == 1) {
                turn = 2;
            } else {
                turn = 1;
            }
        } else {
            /* Invalid move */
            printf("\nInvalid move. Try again.\n");
        }

        /* Check for game over */
        int player1_pieces = 0, player2_pieces = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 1) {
                    player1_pieces++;
                } else if (board[i][j] == -1) {
                    player2_pieces++;
                }
            }
        }
        if (player1_pieces == 0 || player2_pieces == 0) {
            printf("\nGame over! ");
            if (player1_pieces == 0) {
                printf("Player 2 wins!\n");
            } else {
                printf("Player 1 wins!\n");
            }
            gameover = 1;
        }
    }

    return 0;
}