//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
#include <stdio.h>

// Function to print the board
void print_board(char board[3][3]) {
    printf("\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the game is over
int game_over(char board[3][3]) {
    for(int i=0; i<3; i++) {
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if(board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 2;
}

// Function to evaluate the board
int evaluate(char board[3][3]) {
    int score = 0;
    for(int i=0; i<3; i++) {
        if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == '-') {
            score += 10;
        }
        if(board[i][0] == 'O' && board[i][1] == '-' && board[i][2] == 'O') {
            score += 10;
        }
        if(board[i][0] == '-' && board[i][1] == 'O' && board[i][2] == 'O') {
            score += 10;
        }
        if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == '-') {
            score -= 10;
        }
        if(board[i][0] == 'X' && board[i][1] == '-' && board[i][2] == 'X') {
            score -= 10;
        }
        if(board[i][0] == '-' && board[i][1] == 'X' && board[i][2] == 'X') {
            score -= 10;
        }
    }
    for(int i=0; i<3; i++) {
        if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == '-') {
            score += 10;
        }
        if(board[0][i] == 'O' && board[1][i] == '-' && board[2][i] == 'O') {
            score += 10;
        }
        if(board[0][i] == '-' && board[1][i] == 'O' && board[2][i] == 'O') {
            score += 10;
        }
        if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == '-') {
            score -= 10;
        }
        if(board[0][i] == 'X' && board[1][i] == '-' && board[2][i] == 'X') {
            score -= 10;
        }
        if(board[0][i] == '-' && board[1][i] == 'X' && board[2][i] == 'X') {
            score -= 10;
        }
    }
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == '-') {
        score += 10;
    }
    if(board[0][0] == 'O' && board[1][1] == '-' && board[2][2] == 'O') {
        score += 10;
    }
    if(board[0][0] == '-' && board[1][1] == 'O' && board[2][2] == 'O') {
        score += 10;
    }
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == '-') {
        score -= 10;
    }
    if(board[0][0] == 'X' && board[1][1] == '-' && board[2][2] == 'X') {
        score -= 10;
    }
    if(board[0][0] == '-' && board[1][1] == 'X' && board[2][2] == 'X') {
        score -= 10;
    }
    if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == '-') {
        score += 10;
    }
    if(board[0][2] == 'O' && board[1][1] == '-' && board[2][0] == 'O') {
        score += 10;
    }
    if(board[0][2] == '-' && board[1][1] == 'O' && board[2][0] == 'O') {
        score += 10;
    }
    if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == '-') {
        score -= 10;
    }
    if(board[0][2] == 'X' && board[1][1] == '-' && board[2][0] == 'X') {
        score -= 10;
    }
    if(board[0][2] == '-' && board[1][1] == 'X' && board[2][0] == 'X') {
        score -= 10;
    }
    return score;
}

// Function to find the best move
void find_best_move(char board[3][3], int *row, int *col) {
    int best_score = -1000;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                board[i][j] = 'O';
                int score = evaluate(board);
                board[i][j] = '-';
                if(score > best_score) {
                    best_score = score;
                    *row = i;
                    *col = j;
                }
            }
        }
    }
}

// Main function
int main() {
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    int turn = 0;
    while(1) {
        print_board(board);
        if(turn % 2 == 0) {
            // It's the player's turn
            int row, col;
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            if(board[row-1][col-1] == '-') {
                board[row-1][col-1] = 'X';
                turn++;
            } else {
                printf("\nInvalid move. Please try again.\n");
            }
        } else {
            // It's the AI's turn
            int row, col;
            find_best_move(board, &row, &col);
            board[row][col] = 'O';
            turn++;
        }
        int result = game_over(board);
        if(result == 1) {
            print_board(board);
            printf("Game over. You win!\n");
            break;
        } else if(result == -1) {
            print_board(board);
            printf("Game over. AI wins!\n");
            break;
        } else if(result == 0) {
            continue;
        } else {
            print_board(board);
            printf("Game over. Draw!\n");
            break;
        }
    }
    printf("\nThanks for playing!\n");
    return 0;
}