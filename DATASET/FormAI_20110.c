//FormAI DATASET v1.0 Category: Chess AI ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 5

typedef enum { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;
typedef enum { WHITE, BLACK } Side;

typedef struct {
  Piece piece;
  Side side;
} Square;

typedef struct {
  Square squares[BOARD_SIZE][BOARD_SIZE];
  Side player;
  int white_king_row;
  int white_king_col;
  int black_king_row;
  int black_king_col;
} Board;

typedef struct {
  int from_row;
  int from_col;
  int to_row;
  int to_col;
} Move;

// Function declarations
int evaluate(Board* board, Side side);
int minimax(Board* board, int depth, int alpha, int beta, Side maximizingSide);
void make_move(Board* board, Move* move);
void undo_move(Board* board, Move* move);
int is_legal_move(Board* board, Move* move);
void print_board(Board* board);
void initialize_board(Board* board);

int main() {
  Board board;
  initialize_board(&board);
  print_board(&board);

  return 0;
}

void initialize_board(Board* board) {
  // Initialize squares
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (row == 1) {
        board->squares[row][col] = (Square) {PAWN, BLACK};
      } else if (row == 6) {
        board->squares[row][col] = (Square) {PAWN, WHITE};
      } else {
        board->squares[row][col] = (Square) {EMPTY, WHITE};
      }
    }
  }

  // Initialize kings' positions
  board->white_king_row = 7;
  board->white_king_col = 4;
  board->black_king_row = 0;
  board->black_king_col = 4;

  // Set starting player to white
  board->player = WHITE;
}

void print_board(Board* board) {
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      switch (board->squares[row][col].piece) {
        case EMPTY:
          printf(" ");
          break;
        case PAWN:
          printf("P");
          break;
        case KNIGHT:
          printf("N");
          break;
        case BISHOP:
          printf("B");
          break;
        case ROOK:
          printf("R");
          break;
        case QUEEN:
          printf("Q");
          break;
        case KING:
          printf("K");
          break;
      }
    }
    printf("\n");
  }
}

int is_legal_move(Board* board, Move* move) {
  // TODO: Implement
  return 1; // Placeholder
}

void make_move(Board* board, Move* move) {
  // Update squares
  board->squares[move->to_row][move->to_col] = board->squares[move->from_row][move->from_col];
  board->squares[move->from_row][move->from_col] = (Square) {EMPTY, WHITE};

  // Update kings' positions if moved
  Square moved_square = board->squares[move->to_row][move->to_col];
  if (moved_square.piece == KING) {
    if (moved_square.side == WHITE) {
      board->white_king_row = move->to_row;
      board->white_king_col = move->to_col;
    } else {
      board->black_king_row = move->to_row;
      board->black_king_col = move->to_col;
    }
  }
  
  // Update player
  board->player = (board->player == WHITE) ? BLACK : WHITE;
}

void undo_move(Board* board, Move* move) {
  // Update squares
  board->squares[move->from_row][move->from_col] = board->squares[move->to_row][move->to_col];
  board->squares[move->to_row][move->to_col] = (Square) {EMPTY, WHITE};

  // Update kings' positions if moved
  Square moved_square = board->squares[move->from_row][move->from_col];
  if (moved_square.piece == KING) {
    if (moved_square.side == WHITE) {
      board->white_king_row = move->from_row;
      board->white_king_col = move->from_col;
    } else {
      board->black_king_row = move->from_row;
      board->black_king_col = move->from_col;
    }
  }

  // Update player
  board->player = (board->player == WHITE) ? BLACK : WHITE;
}

int evaluate(Board* board, Side side) {
  // TODO: Implement
  return 0; // Placeholder
}

int minimax(Board* board, int depth, int alpha, int beta, Side maximizingSide) {
  // Base case: depth reached or game is over
  if (depth == MAX_DEPTH) {
    return evaluate(board, maximizingSide);
  }

  // Search through all possible moves
  int best_score = (maximizingSide == board->player) ? -100000 : 100000; // Set best score according to side
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board->squares[row][col].side == board->player) {
        for (int dest_row = 0; dest_row < BOARD_SIZE; dest_row++) {
          for (int dest_col = 0; dest_col < BOARD_SIZE; dest_col++) {
            Move move = {row, col, dest_row, dest_col};
            if (is_legal_move(board, &move)) {
              int old_row = move.from_row;
              int old_col = move.from_col;
              make_move(board, &move);
              int score = minimax(board, depth+1, alpha, beta, maximizingSide);
              undo_move(board, &move);

              if (maximizingSide == board->player) { // maximizing
                if (score > best_score) {
                  best_score = score;
                }
                if (score > alpha) {
                  alpha = score;
                }
              } else { // minimizing
                if (score < best_score) {
                  best_score = score;
                }
                if (score < beta) {
                  beta = score;
                }
              }
              if (beta <= alpha) {
                break;
              }
            }
          }
        }
      }
    }
  }
  return best_score;
}