//FormAI DATASET v1.0 Category: Chess AI ; Style: light-weight
#include <stdio.h>

#define DEPTH 3 // max number of moves ahead to explore
#define MIN_SCORE -9999 // minimum score, for worst-case scenario
#define MAX_SCORE 9999 // maximum score, for best-case scenario

struct Node {
    char board[8][8]; // the chess board
    int score; // score of the current state
    int depth; // depth of the current state
};

// evaluate board and calculate score
int evaluate(char board[][8]) {
    int score = 0;
    // add up values of each piece on the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (board[i][j]) {
                case 'K': // king
                    score += 1000;
                    break;
                case 'Q': // queen
                    score += 9;
                    break;
                case 'R': // rook
                    score += 5;
                    break;
                case 'B': // bishop
                    score += 3;
                    break;
                case 'N': // knight
                    score += 3;
                    break;
                case 'P': // pawn
                    score += 1;
                    break;
                case 'k': // enemy king
                    score -= 1000;
                    break;
                case 'q': // enemy queen
                    score -= 9;
                    break;
                case 'r': // enemy rook
                    score -= 5;
                    break;
                case 'b': // enemy bishop
                    score -= 3;
                    break;
                case 'n': // enemy knight
                    score -= 3;
                    break;
                case 'p': // enemy pawn
                    score -= 1;
                    break;
            }
        }
    }
    return score;
}

// calculate best score for next move using minimax algorithm
int minimax(struct Node node, int alpha, int beta, int maxPlayer) {
    if (node.depth == DEPTH) {
        node.score = evaluate(node.board);
        return node.score;
    }
    int bestScore = maxPlayer ? MIN_SCORE : MAX_SCORE;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (node.board[i][j] == 'K' || node.board[i][j] == 'k') { // ignore non-king pieces
                for (int x = 0; x < 8; x++) {
                    for (int y = 0; y < 8; y++) {
                        if (node.board[i][j] == 'K') { // player's king
                            if (node.board[x][y] == ' ' || node.board[x][y] == 'k') { // only move to empty spaces or spaces with enemy pieces
                                char temp = node.board[x][y];
                                node.board[x][y] = 'K';
                                node.board[i][j] = ' ';
                                node.depth++;
                                int score = minimax(node, alpha, beta, !maxPlayer);
                                node.depth--;
                                node.board[i][j] = 'K';
                                node.board[x][y] = temp;
                                if (maxPlayer) {
                                    if (score > bestScore) {
                                        bestScore = score;
                                    }
                                    if (score > alpha) {
                                        alpha = score;
                                    }
                                    if (beta <= alpha) {
                                        return bestScore;
                                    }
                                } else {
                                    if (score < bestScore) {
                                        bestScore = score;
                                    }
                                    if (score < beta) {
                                        beta = score;
                                    }
                                    if (beta <= alpha) {
                                        return bestScore;
                                    }
                                }
                            }
                        } else { // enemy's king
                            if (node.board[x][y] == ' ' || node.board[x][y] == 'K') { // only move to empty spaces or spaces with player's pieces
                                char temp = node.board[x][y];
                                node.board[x][y] = 'k';
                                node.board[i][j] = ' ';
                                node.depth++;
                                int score = minimax(node, alpha, beta, !maxPlayer);
                                node.depth--;
                                node.board[i][j] = 'k';
                                node.board[x][y] = temp;
                                if (maxPlayer) {
                                    if (score > bestScore) {
                                        bestScore = score;
                                    }
                                    if (score > alpha) {
                                        alpha = score;
                                    }
                                    if (beta <= alpha) {
                                        return bestScore;
                                    }
                                } else {
                                    if (score < bestScore) {
                                        bestScore = score;
                                    }
                                    if (score < beta) {
                                        beta = score;
                                    }
                                    if (beta <= alpha) {
                                        return bestScore;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return bestScore;
}

// get the next move using minimax algorithm
void getNextMove(char board[][8]) {
    struct Node node;
    node.depth = 0;
    node.score = MAX_SCORE;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'k') { // find the enemy's king
                for (int x = 0; x < 8; x++) {
                    for (int y = 0; y < 8; y++) {
                        if (board[x][y] == 'K') { // find the player's king
                            if (board[x][y] == ' ') { // only move to empty spaces or spaces with player's pieces
                                node.board[x][y] = 'k';
                                node.board[i][j] = ' ';
                                node.score = minimax(node, MIN_SCORE, MAX_SCORE, 0);
                                node.board[i][j] = 'k';
                                node.board[x][y] = ' ';
                            }
                        }                        
                    }
                }
            }
        }
    }
    printf("Score: %d\n", node.score);
}

int main() {
    // initialize chess board
    char board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    getNextMove(board);
    return 0;
}