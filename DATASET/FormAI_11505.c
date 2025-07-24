//FormAI DATASET v1.0 Category: Chess engine ; Style: optimized
#include <stdio.h>

#define ROWS 8
#define COLUMNS 8

// Create a 2D array representation of the chess board
int chessboard[ROWS][COLUMNS] = {
  {-1,-2,-3,-4,-5,-3,-2,-1},
  {-6,-6,-6,-6,-6,-6,-6,-6},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {6,6,6,6,6,6,6,6},
  {1,2,3,4,5,3,2,1}
};

// Piece values for evaluation
int piece_values[] = {0,100,320,330,500,900,20000};

// Evaluate the chess board
int evaluate_board() {
  int score = 0;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      int piece = chessboard[i][j];
      // Negate score if piece is for the opponent
      if (piece < 0) {
        score -= piece_values[-piece];
      } else {
        score += piece_values[piece];
      }
    }
  }
  return score;
}

// Alpha-beta search algorithm with depth limit
int alpha_beta(int depth, int alpha, int beta, int maximizing_player) {
  if (depth == 0) {
    return evaluate_board();
  }
  if (maximizing_player == 1) { // Maximizing player's turn
    int max_score = -99999;
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
        int piece = chessboard[i][j];
        if (piece > 0) { // Check if piece belongs to maximizing player
          for (int k = 0; k < ROWS; k++) {
            for (int l = 0; l < COLUMNS; l++) {
              int new_piece = chessboard[k][l];
              if (new_piece <= 0) { // Check if square is empty or occupied by opponent
                int tmp = chessboard[i][j];
                chessboard[i][j] = 0;
                chessboard[k][l] = tmp;
                int score = alpha_beta(depth - 1, alpha, beta, 0);
                chessboard[k][l] = new_piece;
                chessboard[i][j] = tmp;
                if (score > max_score) {
                  max_score = score;
                }
                if (max_score > alpha) {
                  alpha = max_score;
                }
                if (beta <= alpha) {
                  return max_score;
                }
              }
            }
          }
        }
      }
    }
    return max_score;
  } else { // Minimizing player's turn
    int min_score = 99999;
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
        int piece = chessboard[i][j];
        if (piece < 0) { // Check if piece belongs to minimizing player
          for (int k = 0; k < ROWS; k++) {
            for (int l = 0; l < COLUMNS; l++) {
              int new_piece = chessboard[k][l];
              if (new_piece >= 0) { // Check if square is empty or occupied by opponent
                int tmp = chessboard[i][j];
                chessboard[i][j] = 0;
                chessboard[k][l] = tmp;
                int score = alpha_beta(depth - 1, alpha, beta, 1);
                chessboard[k][l] = new_piece;
                chessboard[i][j] = tmp;
                if (score < min_score) {
                  min_score = score;
                }
                if (min_score < beta) {
                  beta = min_score;
                }
                if (beta <= alpha) {
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

int main() {
  int score = alpha_beta(3, -99999, 99999, 1); // Computer's turn
  printf("Score of board: %d\n", score);
  return 0;
}