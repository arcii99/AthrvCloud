//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

char board[3][3];

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int check_winner(char c) {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) {
            return 1;
        }
        if (board[0][j] == c && board[1][j] == c && board[2][j] == c) {
            return 1;
        }
    }
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c) {
        return 1;
    }
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c) {
        return 1;
    }
    return 0;
}

int is_board_full() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void make_move(char c, int row, int col) {
    board[row][col] = c;
}

void make_ai_move(char c) {
    int i, j;
    // If there are any winning moves, make that move
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = c;
                if (check_winner(c)) {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // If the player has two in a row and the third space is empty, block it
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                if (check_winner('X')) {
                    board[i][j] = c;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // If the center space is empty, take it
    if (board[1][1] == ' ') {
        board[1][1] = c;
        return;
    }
    // If the player has a corner, take the opposite corner
    if (board[0][0] == 'X' && board[2][2] == ' ') {
        board[2][2] = c;
        return;
    }
    if (board[0][2] == 'X' && board[2][0] == ' ') {
        board[2][0] = c;
        return;
    }
    if (board[2][0] == 'X' && board[0][2] == ' ') {
        board[0][2] = c;
        return;
    }
    if (board[2][2] == 'X' && board[0][0] == ' ') {
        board[0][0] = c;
        return;
    }
    // Take any available corner
    if (board[0][0] == ' ') {
        board[0][0] = c;
        return;
    }
    if (board[0][2] == ' ') {
        board[0][2] = c;
        return;
    }
    if (board[2][0] == ' ') {
        board[2][0] = c;
        return;
    }
    if (board[2][2] == ' ') {
        board[2][2] = c;
        return;
    }
    // Take any available side
    if (board[0][1] == ' ') {
        board[0][1] = c;
        return;
    }
    if (board[1][0] == ' ') {
        board[1][0] = c;
        return;
    }
    if (board[1][2] == ' ') {
        board[1][2] = c;
        return;
    }
    if (board[2][1] == ' ') {
        board[2][1] = c;
        return;
    }
}

int main() {
    initialize_board();
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are X, the computer is O.\n");
    printf("The positions on the board are numbered as follows:\n");
    printf(" 1 | 2 | 3 \n");
    printf("---|---|---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---|---|---\n");
    printf(" 7 | 8 | 9 \n");
    printf("Let's begin!\n");
    print_board();
    while (!check_winner('X') && !check_winner('O') && !is_board_full()) {
        int move = 0;
        while (move < 1 || move > 9 || board[(move - 1) / 3][(move - 1) % 3] != ' ') {
            printf("Enter a position (1-9): ");
            scanf("%d", &move);
        }
        make_move('X', (move - 1) / 3, (move - 1) % 3);
        printf("You placed an X in position %d.\n", move);
        print_board();
        if (check_winner('X')) {
            printf("Congratulations! You win!\n");
            break;
        }
        if (is_board_full()) {
            printf("The game is a tie.\n");
            break;
        }
        printf("Now it's my turn.\n");
        make_ai_move('O');
        print_board();
        if (check_winner('O')) {
            printf("Sorry, you lose.\n");
            break;
        }
        if (is_board_full()) {
            printf("The game is a tie.\n");
            break;
        }
    }
    return 0;
}