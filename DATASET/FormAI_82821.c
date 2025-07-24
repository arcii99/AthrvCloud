//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>

void print_board(char board[3][3]) {
    printf("\n Tic Tac Toe Board \n\n");
    for(int i = 0; i < 3; i++) {
        printf("  %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);

        if(i != 2) {
            printf(" ---|---|---\n");
        }
    }
    printf("\n");
}

char check_winner(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }

        if(board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                return '-';
            }
        }
    }

    return 'T';
}

int minimax(char board[3][3], int depth, int isMaximizing) {
    char winner = check_winner(board);
    if(winner != '-') {
        if(winner == 'X') {
            return 1;
        } else if(winner == 'O') {
            return -1;
        } else {
            return 0;
        }
    }

    if(isMaximizing) {
        int bestScore = -1000;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = 'X';
                    int score = minimax(board, depth + 1, 0);
                    board[i][j] = '-';
                    if(score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = 'O';
                    int score = minimax(board, depth + 1, 1);
                    board[i][j] = '-';
                    if(score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

void make_move(char board[3][3]) {
    int bestScore = -1000;
    int bestX, bestY;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                board[i][j] = 'X';
                int score = minimax(board, 0, 0);
                board[i][j] = '-';

                if(score > bestScore) {
                    bestScore = score;
                    bestX = i;
                    bestY = j;
                }
            }
        }
    }

    board[bestX][bestY] = 'X';
    printf("AI's Move : %d %d\n", bestX, bestY);
}
 
int main() {
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    int i, j, k;
    printf("Tic Tac Toe game\n\n");

    for(i = 1; i <= 9; i++) {
        print_board(board);

        if(i % 2 == 1) {
            printf("Player's Move (O) : ");
            scanf("%d %d", &j, &k);
            if(board[j][k] != '-') {
                printf("Invalid move. Try Again.\n\n");
                i--;
                continue;
            }
            board[j][k] = 'O';
        } else {
            make_move(board);
        }

        char winner = check_winner(board);
        if(winner != '-') {
            print_board(board);
            if(winner == 'X') {
                printf("AI Wins !!!\n");
            } else if(winner == 'O') {
                printf("Player Wins !!!\n");
            } else {
                printf("Game Tied !!!\n");
            }
            return 0;
        }
    }

    return 0;
}