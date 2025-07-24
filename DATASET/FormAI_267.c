//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int is_open(int board[3][3], int row, int col) {
    return board[row][col] == 0;
}

int is_full(int board[3][3]) {
    int row, col;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (is_open(board, row, col)) {
                return 0;
            }
        }
    }
    return 1;
}

int check_win(int board[3][3]) {
    int row, col;
    for (row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][0] == board[row][2]) {
            return board[row][0];
        }
    }
    for (col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[0][col] == board[2][col]) {
            return board[0][col];
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    return 0;
}

int evaluate(int board[3][3], int player) {
    int winner = check_win(board);
    if (winner == player) {
        return 1;
    } else if (winner == 3 - player) {
        return -1;
    } else {
        return 0;
    }
}

int minimax(int board[3][3], int player, int depth) {
    int score = evaluate(board, player);
    if (score != 0 || depth == 0) {
        return score;
    }
    int best_score = is_full(board) ? 0 : -player;
    int row, col;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (is_open(board, row, col)) {
                board[row][col] = player;
                int this_score = -minimax(board, 3 - player, depth - 1);
                if (this_score * player > best_score * player) {
                    best_score = this_score;
                }
                board[row][col] = 0;
            }
        }
    }
    return best_score;
}

void make_move(int board[3][3], int player) {
    int best_score = -player;
    int best_row, best_col;
    int row, col;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (is_open(board, row, col)) {
                board[row][col] = player;
                int this_score = -minimax(board, 3 - player, 5);
                if (this_score * player > best_score * player) {
                    best_score = this_score;
                    best_row = row;
                    best_col = col;
                }
                board[row][col] = 0;
            }
        }
    }
    board[best_row][best_col] = player;
}

void print_board(int board[3][3]) {
    int row, col;
    printf("  1 2 3\n");
    printf(" +-+-+-+\n");
    for (row = 0; row < 3; row++) {
        printf("%c", 'a' + row);
        for (col = 0; col < 3; col++) {
            printf("|%c", board[row][col] == 0 ? ' ' : board[row][col] == 1 ? 'X' : 'O');
        }
        printf("|\n");
        printf(" +-+-+-+\n");
    }
}

int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int row, col;
    int winner = 0;
    for (int i=0; i<9; i++) {
        print_board(board);
        if (player == 1) {
            printf("It's your turn (X)\n");
            printf("Enter move (ex. a1): ");
            char input[10];
            fgets(input, 10, stdin);
            row = input[0] - 'a';
            col = input[1] - '1';
            if (board[row][col] != 0) {
                printf("Invalid move!\n");
                i--;
                continue;
            }
        } else {
            printf("It's my turn (O)\n");
            make_move(board, player);
        }
        board[row][col] = player;
        winner = check_win(board);
        if (winner != 0) {
            break;
        }
        player = 3 - player;
    }
    print_board(board);
    if (winner == 1) {
        printf("You win!\n");
    } else if (winner == 2) {
        printf("I win!\n");
    } else {
        printf("Tie game.\n");
    }
    return 0;
}