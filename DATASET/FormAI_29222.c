//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>

char board[3][3]; // the tic tac toe board
char ai = 'X';    // the AI's marker
char human = 'O'; // the human's marker

// this function prints the current state of the board
void print_board() {
    printf("-------------\n");
    for(int i=0; i<3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

// this function checks if there is a winner
char check_winner() {
    char winner = '-';

    // check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            winner = board[i][0];
            break;
        }
    }

    // check columns
    if(winner == '-') {
        for(int j=0; j<3; j++) {
            if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                winner = board[0][j];
                break;
            }
        }
    }

    // check diagonals
    if(winner == '-') {
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
        } else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board[0][2];
        }
    }

    return winner;
}

// this function evaluates the current state of the board and returns a score
int evaluate() {
    char winner = check_winner();
    if(winner == ai) {
        return 10;
    } else if(winner == human) {
        return -10;
    } else {
        return 0;
    }
}

// this function checks if the board has no more moves left
int is_board_full() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

// this function performs the minimax algorithm with alpha-beta pruning
int minimax(int depth, int alpha, int beta, int max_mode) {
    int score = evaluate();

    if(score != 0 || is_board_full()) {
        return score;
    }

    if(max_mode) {
        int best_score = -1000;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = ai;
                    int current_score = minimax(depth+1, alpha, beta, 0);
                    board[i][j] = '-';
                    if(current_score > best_score) {
                        best_score = current_score;
                    }
                    if(best_score > alpha) {
                        alpha = best_score;
                    }
                    if(beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = human;
                    int current_score = minimax(depth+1, alpha, beta, 1);
                    board[i][j] = '-';
                    if(current_score < best_score) {
                        best_score = current_score;
                    }
                    if(best_score < beta) {
                        beta = best_score;
                    }
                    if(beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return best_score;
    }
}

// this function makes the AI move
void ai_move() {
    int best_score = -1000;
    int best_i = -1;
    int best_j = -1;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                board[i][j] = ai;
                int current_score = minimax(0, -1000, 1000, 0);
                board[i][j] = '-';
                if(current_score > best_score) {
                    best_score = current_score;
                    best_i = i;
                    best_j = j;
                }
            }
        }
    }

    printf("The AI has made a move at (%d,%d)\n", best_i+1, best_j+1);
    board[best_i][best_j] = ai;
    print_board();
}

int main() {
    // initialize the board
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = '-';
        }
    }

    print_board();

    while(1) {
        printf("Enter the row and column where you want to place your marker (e.g. 1 2): ");
        int row, col;
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if(board[row][col] == '-') {
            board[row][col] = human;
            print_board();
        } else {
            printf("Invalid move! Try again.\n");
            continue;
        }
        char winner = check_winner();
        if(winner == human) {
            printf("You have won!\n");
            break;
        } else if(is_board_full()) {
            printf("It's a tie.\n");
            break;
        }
        ai_move();
        winner = check_winner();
        if(winner == ai) {
            printf("The AI has won!\n");
            break;
        } else if(is_board_full()) {
            printf("It's a tie.\n");
            break;
        }
    }

    return 0;
}