//FormAI DATASET v1.0 Category: Chess engine ; Style: recursive
#include <stdio.h>

char board[8][8] = { // initializing starting chess board
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

int value(char piece) { // assigning values to each chess piece
    switch(piece) {
        case 'K': return 5;
        case 'Q': return 9;
        case 'R': return 5;
        case 'B': return 3;
        case 'N': return 3;
        case 'P': return 1;
        case 'k': return -5;
        case 'q': return -9;
        case 'r': return -5;
        case 'b': return -3;
        case 'n': return -3;
        case 'p': return -1;
        default: return 0;
    }
}

int evaluate() { // evaluate current state of the board
    int score = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            score += value(board[i][j]);
        }
    }
    return score;
}

int max(int a, int b) { // helper function to return maximum value
    return (a > b) ? a : b;
}

int min(int a, int b) { // helper function to return minimum value
    return (a < b) ? a : b;
}

int minimax(int depth, int alpha, int beta, int maximizingPlayer) { // recursive minimax algorithm
    if(depth == 0) { // if maximum depth reached, return evaluation of current state
        return evaluate();
    }
    if(maximizingPlayer) { // if the player is maximizing, try to maximize score
        int maxScore = -9999;
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                if(board[i][j] != ' ' && (isupper(board[i][j]) || board[i][j] == 'k')) { // check if piece belongs to current player
                    for(int x=0; x<8; x++) {
                        for(int y=0; y<8; y++) {
                            if(board[x][y] == ' ') { // check if position is empty
                                char temp = board[x][y];
                                board[x][y] = board[i][j];
                                board[i][j] = ' ';
                                maxScore = max(maxScore, minimax(depth-1, alpha, beta, 0)); // recursive call with depth reduced and player changed
                                board[i][j] = board[x][y];
                                board[x][y] = temp;
                                alpha = max(alpha, maxScore);
                                if(beta <= alpha) {
                                    return maxScore;
                                }
                            }
                        }
                    }
                }
            }
        }
        return maxScore;
    } else { // if the player is minimizing, try to minimize score
        int minScore = 9999;
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                if(board[i][j] != ' ' && (islower(board[i][j]) || board[i][j] == 'K')) { // check if piece belongs to current player
                    for(int x=0; x<8; x++) {
                        for(int y=0; y<8; y++) {
                            if(board[x][y] == ' ') { // check if position is empty
                                char temp = board[x][y];
                                board[x][y] = board[i][j];
                                board[i][j] = ' ';
                                minScore = min(minScore, minimax(depth-1, alpha, beta, 1)); // recursive call with depth reduced and player changed
                                board[i][j] = board[x][y];
                                board[x][y] = temp;
                                beta = min(beta, minScore);
                                if(beta <= alpha) {
                                    return minScore;
                                }
                            }
                        }
                    }
                }
            }
        }
        return minScore;
    }
}

int main() {
    printf("Current state of the board:\n");
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    int score = minimax(3, -9999, 9999, 1); // calling minimax algorithm with depth=3 and maximizing player
    printf("Score after three levels deep: %d", score);
    return 0;
}