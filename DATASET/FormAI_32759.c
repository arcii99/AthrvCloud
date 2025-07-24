//FormAI DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>

void display_board(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("\t %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("\t---|---|---\n");
    }
    printf("\n");
}

int check_win(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1;
    return 0;
}

int is_draw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int minimax(char board[3][3], char player, int depth, int is_maximizer) {
    if (check_win(board, player)) {
        if (is_maximizer) return -10 + depth;
        else return 10 - depth;
    } else if (is_draw(board)) {
        return 0;
    }
    
    int best_move, score;
    if (is_maximizer) {
        best_move = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = player;
                    score = minimax(board, player, depth + 1, 0);
                    best_move = best_move > score ? best_move : score;
                    board[i][j] = ' ';
                }
            }
        }
    } else {
        best_move = 1000;
        char opponent = player == 'X' ? 'O' : 'X';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = opponent;
                    score = minimax(board, player, depth + 1, 1);
                    best_move = best_move < score ? best_move : score;
                    board[i][j] = ' ';
                }
            }
        }
    }
    return best_move;
}

void make_next_move(char board[3][3], char player) {
    int row, column;
    int best_score = -1000;
    int score;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                score = minimax(board, player, 0, 0);
                if (score > best_score) {
                    best_score = score;
                    row = i;
                    column = j;
                }
                board[i][j] = ' ';
            }
        }
    }
    board[row][column] = player;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char player = 'X';
    display_board(board);
    int game_over = 0;
    while (!game_over) {
        if (player == 'X') {
            int row, column;
            printf("Enter the row number (1-3): ");
            scanf("%d", &row);
            printf("Enter the column number (1-3): ");
            scanf("%d", &column);
            if (board[row-1][column-1] == ' ') {
                board[row-1][column-1] = player;
                display_board(board);
                if (check_win(board, player)) {
                    printf("Player %c wins!\n", player);
                    game_over = 1;
                    break;
                }
                if (is_draw(board)) {
                    printf("Draw!\n");
                    game_over = 1;
                    break;
                }
                player = 'O';
            } else {
                printf("Invalid move! Try again.\n");
            }
        } else {
            make_next_move(board, player);
            display_board(board);
            if (check_win(board, player)) {
                printf("Player %c wins!\n", player);
                game_over = 1;
                break;
            }
            if (is_draw(board)) {
                printf("Draw!\n");
                game_over = 1;
                break;
            }
            player = 'X';
        }
    }
    return 0;
}