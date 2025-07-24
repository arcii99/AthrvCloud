//FormAI DATASET v1.0 Category: Chess AI ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPTH 10 // maximum depth for minimax algorithm
#define INF 100000 // arbitrary large value for alpha-beta pruning

int minimax(int alpha, int beta, int depth, int is_maximizing, int board[8][8]);
int evaluate_board(int board[8][8]); 
int is_game_over(int board[8][8]);

// main function to play chess
int main() {
    // initialize chess board
    int board[8][8] = {
        {-2, -3, -4, -5, -6, -4, -3, -2},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 1,  1,  1,  1,  1,  1,  1,  1},
        { 2,  3,  4,  5,  6,  4,  3,  2},
    };
    
    int game_over = 0;
    int player_turn = 1;
    int x1, y1, x2, y2;
    
    while (!game_over) {
        // print board
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        
        // get player move
        if (player_turn == 1) {
            printf("Enter move for Player 1 (x1 y1 x2 y2): ");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            
            // check if move is valid
            if (board[x1][y1] <= 0 || board[x1][y1] >= 7) {
                printf("Invalid move. Try again.\n");
                continue;
            }
            if (board[x2][y2] > 0 && board[x2][y2] < 7) {
                printf("Invalid move. Try again.\n");
                continue;
            }
            if (board[x1][y1] == 1 && y1 != y2) {
                printf("Invalid move. Try again.\n");
                continue;
            }
            if (board[x1][y1] == 2 && !(y1 == y2 || x1 == x2)) {
                printf("Invalid move. Try again.\n");
                continue;
            }
            if (board[x1][y1] == 3 && !(abs(x1-x2) == abs(y1-y2))) {
                printf("Invalid move. Try again.\n");
                continue;
            }
            if (board[x1][y1] == 4 && !(x1 == x2 || y1 == y2)) {
                printf("Invalid move. Try again.\n");
                continue;
            }
            if (board[x1][y1] == 5 && !(abs(x1-x2) == 2 && abs(y1-y2) == 1) && !(abs(x1-x2) == 1 && abs(y1-y2) == 2)) {
                printf("Invalid move. Try again.\n");
                continue;
            }
            if (board[x1][y1] == 6 && !(abs(x1-x2) <= 1 && abs(y1-y2) <= 1)) {
                printf("Invalid move. Try again.\n");
                continue;
            }
        }
        // use AI move
        else {
            int best_score = -INF;
            int best_move[4];
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (board[i][j] >= 1 && board[i][j] <= 6) {
                        for (int k = 0; k < 8; k++) {
                            for (int l = 0; l < 8; l++) {
                                if (board[k][l] < 1 || board[k][l] > 6) {
                                    int new_board[8][8];
                                    for (int m = 0; m < 8; m++) {
                                        for (int n = 0; n < 8; n++) {
                                            new_board[m][n] = board[m][n];
                                        }
                                    }
                                    new_board[k][l] = new_board[i][j];
                                    new_board[i][j] = 0;
                                    int score = minimax(-INF, INF, MAX_DEPTH, 0, new_board);
                                    if (score > best_score) {
                                        best_score = score;
                                        best_move[0] = i;
                                        best_move[1] = j;
                                        best_move[2] = k;
                                        best_move[3] = l;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            x1 = best_move[0];
            y1 = best_move[1];
            x2 = best_move[2];
            y2 = best_move[3];
            printf("AI moves from (%d,%d) to (%d,%d)\n", x1, y1, x2, y2);
        }
        
        // make move
        int piece = board[x1][y1];
        board[x2][y2] = piece;
        board[x1][y1] = 0;

        // check if game over
        game_over = is_game_over(board);
        if (game_over) {
            printf("Game over!\n");
            if (evaluate_board(board) > 0) {
                printf("Player 1 wins!\n");
            }
            else {
                printf("AI wins!\n");
            }
        }
        
        // switch turn
        player_turn = (player_turn == 1) ? 0 : 1;
    }
    
    return 0;
}

// recursive function for minimax algorithm with alpha-beta pruning
int minimax(int alpha, int beta, int depth, int is_maximizing, int board[8][8]) {
    if (depth == 0 || is_game_over(board)) {
        return evaluate_board(board);
    }
    if (is_maximizing) {
        int max_score = -INF;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] >= 1 && board[i][j] <= 6) {
                    for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 8; l++) {
                            if (board[k][l] < 1 || board[k][l] > 6) {
                                int new_board[8][8];
                                for (int m = 0; m < 8; m++) {
                                    for (int n = 0; n < 8; n++) {
                                        new_board[m][n] = board[m][n];
                                    }
                                }
                                new_board[k][l] = new_board[i][j];
                                new_board[i][j] = 0;
                                int score = minimax(alpha, beta, depth-1, 0, new_board);
                                if (score > max_score) {
                                    max_score = score;
                                }
                                alpha = (alpha > score) ? alpha : score;
                                if (alpha >= beta) {
                                    return max_score;
                                }
                            }
                        }
                    }
                }
            }
        }
        return max_score;
    }
    else {
        int min_score = INF;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] >= 1 && board[i][j] <= 6) {
                    for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 8; l++) {
                            if (board[k][l] < 1 || board[k][l] > 6) {
                                int new_board[8][8];
                                for (int m = 0; m < 8; m++) {
                                    for (int n = 0; n < 8; n++) {
                                        new_board[m][n] = board[m][n];
                                    }
                                }
                                new_board[k][l] = new_board[i][j];
                                new_board[i][j] = 0;
                                int score = minimax(alpha, beta, depth-1, 1, new_board);
                                if (score < min_score) {
                                    min_score = score;
                                }
                                beta = (beta < score) ? beta : score;
                                if (alpha >= beta) {
                                    return min_score;
                                }
                            }
                        }
                    }
                }
            }
        }
        return min_score;
    }
}

// evaluate the board with simple scoring system
int evaluate_board(int board[8][8]) {
    int total_score = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int piece = board[i][j];
            if (piece == 1) {
                total_score += 1;
            }
            else if (piece == 2 || piece == 3) {
                total_score += 3;
            }
            else if (piece == 4) {
                total_score += 5;
            }
            else if (piece == 5) {
                total_score += 9;
            }
            else if (piece == 6) {
                total_score += 100;
            }
            else if (piece == -1) {
                total_score -= 1;
            }
            else if (piece == -2 || piece == -3) {
                total_score -= 3;
            }
            else if (piece == -4) {
                total_score -= 5;
            }
            else if (piece == -5) {
                total_score -= 9;
            }
            else if (piece == -6) {
                total_score -= 100;
            }
        }
    }
    return total_score;
}

// check if game over
int is_game_over(int board[8][8]) {
    int black_king = 0;
    int white_king = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 6) {
                black_king = 1;
            }
            if (board[i][j] == -6) {
                white_king = 1;
            }
        }
    }
    if (!black_king || !white_king) {
        return 1;
    }
    return 0;
}