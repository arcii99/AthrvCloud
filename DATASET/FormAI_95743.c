//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
int comp_pos[9] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

void init_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    printf("\n\n~~~~~~~~~~~\n\n");
    for (i = 0; i < 3; i++) {
        printf("|");
        for (j = 0; j < 3; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n~~~~~~~~~~~\n");
    }
}

int check_win() {
    int i;

    for (i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;
    }

    for (i = 0; i < 3; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    if (board[0][2] != ' ' && board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    return 0;
}

int minimax(int depth, int player) {
    int i;
    int score, best_score;

    if (check_win() == 1) {
        if (player == 1)
            return -10;
        else
            return 10;
    }

    if (depth == 9) {
        return 0;
    }

    if (player == 1) {
        best_score = -1000;

        for (i = 0; i < 9; i++) {
            int row = comp_pos[i] / 3;
            int col = comp_pos[i] % 3;

            if (board[row][col] == ' ') {
                board[row][col] = 'O';
                score = minimax(depth + 1, 0);
                board[row][col] = ' ';

                if (score > best_score) {
                    best_score = score;
                }
            }
        }
    } else {
        best_score = 1000;

        for (i = 0; i < 9; i++) {
            int row = comp_pos[i] / 3;
            int col = comp_pos[i] % 3;

            if (board[row][col] == ' ') {
                board[row][col] = 'X';
                score = minimax(depth + 1, 1);
                board[row][col] = ' ';

                if (score < best_score) {
                    best_score = score;
                }
            }
        }
    }

    return best_score;
}

void comp_turn() {
    int i;
    int score, best_score = -1000;
    int best_move = -1;

    for (i = 0; i < 9; i++) {
        int row = comp_pos[i] / 3;
        int col = comp_pos[i] % 3;

        if (board[row][col] == ' ') {
            board[row][col] = 'O';
            score = minimax(0, 0);
            board[row][col] = ' ';

            if (score > best_score) {
                best_score = score;
                best_move = i;
            }
        }
    }

    int row = comp_pos[best_move] / 3;
    int col = comp_pos[best_move] % 3;

    board[row][col] = 'O';
}

void player_turn() {
    int row, col;
    printf("\nEnter the row position (0-2): ");
    scanf("%d", &row);
    printf("Enter the column position (0-2): ");
    scanf("%d", &col);

    if (board[row][col] != ' ') {
        printf("\n Invalid move, try again! \n");
        player_turn();
    } else {
        board[row][col] = 'X';
    }
}

int main() {
    int i, rounds = 0;

    printf("~~~~~~~~~~~\n TIC TAC TOE \n~~~~~~~~~~~\n\n");

    init_board();
    print_board();

    while (rounds < 9) {
        player_turn();
        rounds++;
        print_board();

        if (check_win() == 1) {
            printf("\nCongratulations! You win!");
            return 0;
        }

        if (rounds == 9) {
            printf("\nIt's a tie!");
            return 0;
        }

        comp_turn();
        rounds++;
        print_board();

        if (check_win() == 1) {
            printf("\nSorry, you lost!");
            return 0;
        }

        printf("\n-----------------\n");
    }

    return 0;
}