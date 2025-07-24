//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: genious
#include <stdio.h>

char board[3][3] = { { '.', '.', '.' },
                     { '.', '.', '.' },
                     { '.', '.', '.' } };

int check_win() {
    int i, j;

    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') return 1;
            else if (board[i][0] == 'O') return 2;
        }
    }

    // check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'X') return 1;
            else if (board[0][j] == 'O') return 2;
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') return 1;
        else if (board[0][0] == 'O') return 2;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') return 1;
        else if (board[0][2] == 'O') return 2;
    }

    return 0;
}

void print_board() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int minimax(int depth, int player) {
    int i, j, best_row, best_col;
    char max_player = 'X', min_player = 'O';

    if (check_win() == 1)
        return 10 - depth;
    else if (check_win() == 2)
        return depth - 10;
    else if (depth == 9)
        return 0;

    int best_score, cur_score;

    if (player == 1) {
        best_score = -100;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == '.') {
                    board[i][j] = max_player;
                    cur_score = minimax(depth + 1, 2);
                    if (cur_score > best_score) {
                        best_score = cur_score;
                        best_row = i;
                        best_col = j;
                    }
                    board[i][j] = '.';
                }
            }
        }
        if (depth == 0) {
            printf("AI move: row %d, col %d\n", best_row, best_col);
            board[best_row][best_col] = max_player;
        }
        return best_score;
    }

    else {
        best_score = 100;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == '.') {
                    board[i][j] = min_player;
                    cur_score = minimax(depth + 1, 1);
                    if (cur_score < best_score) {
                        best_score = cur_score;
                        best_row = i;
                        best_col = j;
                    }
                    board[i][j] = '.';
                }
            }
        }
        if (depth == 0) {
            printf("Player move: row %d, col %d\n", best_row, best_col);
            board[best_row][best_col] = min_player;
        }
        return best_score;
    }
}

int main() {
    printf("Welcome to Tic Tac Toe AI!\n");
    printf("You are X, AI is O\n");

    int row, col, i, j, depth = 0;
    char c;

    while (check_win() == 0 && depth < 9) {

        print_board();
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter col (1-3): ");
        scanf("%d", &col);

        if (board[row-1][col-1] == '.') {
            board[row-1][col-1] = 'X';
            depth++;
            minimax(0, 1);
            depth++;
        }
        else {
            printf("Invalid move, try again...\n");
            continue;
        }
    }

    print_board();

    if (check_win() == 1) printf("Player wins!\n");
    else if (check_win() == 2) printf("AI wins!\n");
    else printf("Draw!\n");

    return 0;
}