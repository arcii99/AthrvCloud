//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3];

void initialize_board(void)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board(void)
{
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

bool check_tie(void)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool check_winner(char symbol)
{
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == symbol) &&
            (board[i][1] == symbol) &&
            (board[i][2] == symbol)) {
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if ((board[0][j] == symbol) &&
            (board[1][j] == symbol) &&
            (board[2][j] == symbol)) {
            return true;
        }
    }

    if ((board[0][0] == symbol) &&
        (board[1][1] == symbol) &&
        (board[2][2] == symbol)) {
        return true;
    }

    if ((board[2][0] == symbol) &&
        (board[1][1] == symbol) &&
        (board[0][2] == symbol)) {
        return true;
    }

    return false;
}

int minmax(bool is_maximizer)
{
    if (check_winner('X')) {
        return -1;
    } else if (check_winner('O')) {
        return 1;
    } else if (check_tie()) {
        return 0;
    }

    if (is_maximizer) {
        int max_val = -2;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int val = minmax(false);
                    board[i][j] = ' ';
                    if (val > max_val) {
                        max_val = val;
                    }
                }
            }
        }
        return max_val;
    } else {
        int min_val = 2;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int val = minmax(true);
                    board[i][j] = ' ';
                    if (val < min_val) {
                        min_val = val;
                    }
                }
            }
        }
        return min_val;
    }
}

void computer_move(void)
{
    int move_i = -1;
    int move_j = -1;
    int min_val = 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int val = minmax(false);
                board[i][j] = ' ';
                if (val < min_val) {
                    min_val = val;
                    move_i = i;
                    move_j = j;
                }
            }
        }
    }

    board[move_i][move_j] = 'O';
}

void player_move(void)
{
    int i, j;

    do {
        printf("Enter row number (1-3): ");
        scanf("%d", &i);
        printf("Enter column number (1-3): ");
        scanf("%d", &j);
    } while ((i < 1) || (i > 3) || (j < 1) || (j > 3) || (board[i-1][j-1] != ' '));

    board[i-1][j-1] = 'X';
}

int main(void)
{
    int turn = 0;
    int winner = 0;

    initialize_board();

    printf("Welcome to the tragic game of Tic Tac Toe! The two star-crossed lovers shall play until there is a winner or a tie.");

    while (! winner) {
        display_board();

        if (turn % 2 == 0) {
            player_move();
        } else {
            printf("The hamartia of fate falls upon us once again. It is O's turn.\n");
            computer_move();
        }

        if (check_winner('X')) {
            printf("Alas, Romeo wins.\n");
            winner = 1;
        } else if (check_winner('O')) {
            printf("Oh cruel fate! Juliet wins.\n");
            winner = -1;
        } else if (check_tie()) {
            printf("Death, that hath sucked the honey of thy breath, hath had no power yet upon our game. It is a tie.\n");
            winner = 2;
        }

        turn++;
    }

    display_board();

    return 0;
}