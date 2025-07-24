//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_GAMES 5
#define MAX_MOVES 10

void display_instructions() {
    printf("Welcome to the game of Tic Tac Toe!\n");
    printf("Player 1 will use X and Player 2 will use O.\n");
    printf("To place your marker, input the row and column numbers.\n");
    printf("For example, to place your marker in the top left corner, enter 1 1.\n");
    printf("You have a maximum of 10 moves per game.\n");
}

void init_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void display_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int get_player_move(int player, char board[ROWS][COLS]) {
    int row, col;
    do {
        printf("Player %d's turn - enter row and column numbers (1-5): ", player);
        scanf("%d %d", &row, &col);
        row--;
        col--;
    } while (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != '-');
    board[row][col] = (player == 1) ? 'X' : 'O';
    return 1;
}

int check_win(char board[ROWS][COLS], char player) {
    // check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player &&
            board[i][3] == player && board[i][4] == player) {
            return 1;
        }
    }

    // check columns
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player &&
            board[3][i] == player && board[4][i] == player) {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player &&
        board[3][3] == player && board[4][4] == player) {
        return 1;
    }

    if (board[0][4] == player && board[1][3] == player && board[2][2] == player &&
        board[3][1] == player && board[4][0] == player) {
        return 1;
    }

    return 0;
}

int play_game() {
    char board[ROWS][COLS];
    init_board(board);
    display_board(board);
    int player = 1;
    int move = 1;
    while (move <= MAX_MOVES) {
        get_player_move(player, board);
        display_board(board);
        if (check_win(board, (player == 1) ? 'X' : 'O')) {
            printf("Player %d wins!\n", player);
            return 1;
        }
        player = (player == 1) ? 2 : 1;
        move++;
    }
    printf("Game over - no winner\n");
    return 0;
}

int main() {
    srand(time(0));
    int games_played = 0;
    int games_won = 0;
    display_instructions();
    while (games_played < MAX_GAMES) {
        printf("Game %d\n", games_played+1);
        games_won += play_game();
        games_played++;
        printf("--------------------\n");
    }
    printf("You won %d out of %d games\n", games_won, MAX_GAMES);
    return 0;
}