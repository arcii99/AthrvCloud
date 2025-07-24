//FormAI DATASET v1.0 Category: Chess AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the board size
#define SIZE 8

// Define the player types
#define BOT 0
#define HUMAN 1

// Define the piece types
#define EMPTY '.'
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'

// Define the board type
typedef struct {
  char pieces[SIZE][SIZE];
} Board;

// Define the coordinates type
typedef struct {
  int x;
  int y;
} Coordinates;

// Define the move type
typedef struct {
  Coordinates from;
  Coordinates to;
} Move;

// Define a list of possible moves for a piece
typedef struct {
  Move moves[SIZE*SIZE];
  int count;
} MoveList;

// Define a player
typedef struct {
  int type;
  char color;
  int score;
} Player;

// Define the game state
typedef struct {
  Board board;
  Player player1;
  Player player2;
  Player *current_player;
} GameState;

/**
 * Reset the board by placing the pieces in their initial positions
 */
void reset_board(GameState *state) {
  Board *b = &state->board;
  
  // Clear the board
  memset(b->pieces, EMPTY, sizeof(b->pieces));
  
  // Place the white pieces
  b->pieces[0][0] = ROOK;
  b->pieces[0][1] = KNIGHT;
  b->pieces[0][2] = BISHOP;
  b->pieces[0][3] = QUEEN;
  b->pieces[0][4] = KING;
  b->pieces[0][5] = BISHOP;
  b->pieces[0][6] = KNIGHT;
  b->pieces[0][7] = ROOK;
  for (int i = 0; i < SIZE; i++) {
    b->pieces[1][i] = PAWN;
  }
  
  // Place the black pieces
  b->pieces[7][0] = ROOK;
  b->pieces[7][1] = KNIGHT;
  b->pieces[7][2] = BISHOP;
  b->pieces[7][3] = QUEEN;
  b->pieces[7][4] = KING;
  b->pieces[7][5] = BISHOP;
  b->pieces[7][6] = KNIGHT;
  b->pieces[7][7] = ROOK;
  for (int i = 0; i < SIZE; i++) {
    b->pieces[6][i] = PAWN;
  }

  // Reset the players
  state->player1.color = 'W';
  state->player1.score = 0;
  state->player2.color = 'B';
  state->player2.score = 0;
  state->current_player = &state->player1;
}

/**
 * Print the board to the console
 */
void print_board(Board *b) {
  printf("  A B C D E F G H\n");
  printf("  ---------------\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%d|", i+1);
    for (int j = 0; j < SIZE; j++) {
      printf("%c|", b->pieces[i][j]);
    }
    printf("%d\n", i+1);
    printf(" |---------------|\n");
  }
  printf("  A B C D E F G H\n");
}

/**
 * Get the piece at the specified coordinates
 */
char get_piece(Board *b, Coordinates c) {
  return b->pieces[c.y][c.x];
}

/**
 * Set the piece at the specified coordinates
 */
void set_piece(Board *b, Coordinates c, char piece) {
  b->pieces[c.y][c.x] = piece;
}

/**
 * Check if the specified coordinates are on the board
 */
int on_board(Coordinates c) {
  return c.x >= 0 && c.x < SIZE && c.y >= 0 && c.y < SIZE;
}

/**
 * Get the list of possible moves for a pawn
 */
void get_pawn_moves(Board *b, Coordinates c, MoveList *moves) {
  int x = c.x;
  int y = c.y;
  char piece = get_piece(b, c);
  
  // Determine the direction of movement based on the color of the pawn
  int dy = (piece == PAWN && b->pieces[y][x] == 'W') ? -1 : 1;
  
  // Check if the pawn can move forward one square
  Coordinates c2 = {x, y+dy};
  if (on_board(c2) && get_piece(b, c2) == EMPTY) {
    Move move = {c, c2};
    moves->moves[moves->count++] = move;
  }
  
  // Check if the pawn can move forward two squares
  Coordinates c3 = {x, y+2*dy};
  if (y == 1 || y == 6) {
    if (on_board(c2) && get_piece(b, c2) == EMPTY && on_board(c3) && get_piece(b, c3) == EMPTY) {
      Move move = {c, c3};
      moves->moves[moves->count++] = move;
    }
  }
  
  // Check if the pawn can capture a piece diagonally
  Coordinates c4 = {x-1, y+dy};
  if (on_board(c4) && islower(get_piece(b, c4))) {
    Move move = {c, c4};
    moves->moves[moves->count++] = move;
  }
  Coordinates c5 = {x+1, y+dy};
  if (on_board(c5) && islower(get_piece(b, c5))) {
    Move move = {c, c5};
    moves->moves[moves->count++] = move;
  }
}

/**
 * Get the list of possible moves for a knight
 */
void get_knight_moves(Board *b, Coordinates c, MoveList *moves) {
  int x = c.x;
  int y = c.y;
  char piece = get_piece(b, c);
  
  int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
  
  for (int i = 0; i < 8; i++) {
    Coordinates c2 = {x+dx[i], y+dy[i]};
    if (on_board(c2) && (!isupper(get_piece(b, c2)) || tolower(get_piece(b, c2)) != piece)) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
    }
  }
}

/**
 * Get the list of possible moves for a bishop
 */
void get_bishop_moves(Board *b, Coordinates c, MoveList *moves) {
  int x = c.x;
  int y = c.y;
  char piece = get_piece(b, c);
  
  // Check moves in the NW direction
  for (int i = 1; i < SIZE; i++) {
    Coordinates c2 = {x-i, y-i};
    if (on_board(c2) && get_piece(b, c2) == EMPTY) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
    } else if (on_board(c2) && (!isupper(get_piece(b, c2)) || tolower(get_piece(b, c2)) != piece)) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
      break;
    } else {
      break;
    }
  }
  
  // Check moves in the NE direction
  for (int i = 1; i < SIZE; i++) {
    Coordinates c2 = {x+i, y-i};
    if (on_board(c2) && get_piece(b, c2) == EMPTY) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
    } else if (on_board(c2) && (!isupper(get_piece(b, c2)) || tolower(get_piece(b, c2)) != piece)) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
      break;
    } else {
      break;
    }
  }
  
  // Check moves in the SE direction
  for (int i = 1; i < SIZE; i++) {
    Coordinates c2 = {x+i, y+i};
    if (on_board(c2) && get_piece(b, c2) == EMPTY) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
    } else if (on_board(c2) && (!isupper(get_piece(b, c2)) || tolower(get_piece(b, c2)) != piece)) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
      break;
    } else {
      break;
    }
  }
  
  // Check moves in the SW direction
  for (int i = 1; i < SIZE; i++) {
    Coordinates c2 = {x-i, y+i};
    if (on_board(c2) && get_piece(b, c2) == EMPTY) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
    } else if (on_board(c2) && (!isupper(get_piece(b, c2)) || tolower(get_piece(b, c2)) != piece)) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
      break;
    } else {
      break;
    }
  }
}

/**
 * Get the list of possible moves for a rook
 */
void get_rook_moves(Board *b, Coordinates c, MoveList *moves) {
  int x = c.x;
  int y = c.y;
  char piece = get_piece(b, c);
  
  // Check moves in the N direction
  for (int i = 1; i < SIZE; i++) {
    Coordinates c2 = {x, y-i};
    if (on_board(c2) && get_piece(b, c2) == EMPTY) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
    } else if (on_board(c2) && (!isupper(get_piece(b, c2)) || tolower(get_piece(b, c2)) != piece)) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
      break;
    } else {
      break;
    }
  }
  
  // Check moves in the E direction
  for (int i = 1; i < SIZE; i++) {
    Coordinates c2 = {x+i, y};
    if (on_board(c2) && get_piece(b, c2) == EMPTY) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
    } else if (on_board(c2) && (!isupper(get_piece(b, c2)) || tolower(get_piece(b, c2)) != piece)) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
      break;
    } else {
      break;
    }
  }
  
  // Check moves in the S direction
  for (int i = 1; i < SIZE; i++) {
    Coordinates c2 = {x, y+i};
    if (on_board(c2) && get_piece(b, c2) == EMPTY) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
    } else if (on_board(c2) && (!isupper(get_piece(b, c2)) || tolower(get_piece(b, c2)) != piece)) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
      break;
    } else {
      break;
    }
  }
  
  // Check moves in the W direction
  for (int i = 1; i < SIZE; i++) {
    Coordinates c2 = {x-i, y};
    if (on_board(c2) && get_piece(b, c2) == EMPTY) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
    } else if (on_board(c2) && (!isupper(get_piece(b, c2)) || tolower(get_piece(b, c2)) != piece)) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
      break;
    } else {
      break;
    }
  }
}

/**
 * Get the list of possible moves for a queen
 */
void get_queen_moves(Board *b, Coordinates c, MoveList *moves) {
  get_bishop_moves(b, c, moves);
  get_rook_moves(b, c, moves);
}

/**
 * Get the list of possible moves for a king
 */
void get_king_moves(Board *b, Coordinates c, MoveList *moves) {
  int x = c.x;
  int y = c.y;
  char piece = get_piece(b, c);
  
  int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
  int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
  
  for (int i = 0; i < 8; i++) {
    Coordinates c2 = {x+dx[i], y+dy[i]};
    if (on_board(c2) && (!isupper(get_piece(b, c2)) || tolower(get_piece(b, c2)) != piece)) {
      Move move = {c, c2};
      moves->moves[moves->count++] = move;
    }
  }
}

/**
 * Get the list of possible moves for a piece
 */
void get_moves(Board *b, Coordinates c, MoveList *moves) {
  char piece = get_piece(b, c);
  
  switch (piece) {
    case PAWN:
      get_pawn_moves(b, c, moves);
      break;
    case KNIGHT:
      get_knight_moves(b, c, moves);
      break;
    case BISHOP:
      get_bishop_moves(b, c, moves);
      break;
    case ROOK:
      get_rook_moves(b, c, moves);
      break;
    case QUEEN:
      get_queen_moves(b, c, moves);
      break;
    case KING:
      get_king_moves(b, c, moves);
      break;
  }
}

/**
 * Check if a move is valid
 */
int is_valid_move(Board *b, Move *move) {
  MoveList moves;
  moves.count = 0;
  get_moves(b, move->from, &moves);
  for (int i = 0; i < moves.count; i++) {
    if (moves.moves[i].from.x == move->from.x &&
        moves.moves[i].from.y == move->from.y &&
        moves.moves[i].to.x == move->to.x &&
        moves.moves[i].to.y == move->to.y) {
      return 1;
    }
  }
  return 0;
}

/**
 * Make a move and update the game state
 */
void make_move(GameState *state, Move *move) {
  Board *b = &state->board;
  char piece = get_piece(b, move->from);
  
  // Move the piece
  set_piece(b, move->to, piece);
  set_piece(b, move->from, EMPTY);
  
  // Update the current player's score
  if (isupper(piece)) {
    state->current_player->score++;
  } else {
    state->current_player->score--;
  }
  
  // Switch the current player
  if (state->current_player == &state->player1) {
    state->current_player = &state->player2;
  } else {
    state->current_player = &state->player1;
  }
}

/**
 * Check if the game is over
 */
int is_game_over(GameState *state) {
  return state->player1.score == 16 || state->player2.score == 16;
}

/**
 * Get the user's input as a move
 */
void get_move_from_input(GameState *state, Move *move) {
  char input[10];
  
  do {
    printf("Enter your move (e.g. e2e4): ");
    scanf("%s", input);
  } while (strlen(input) != 4 || input[0] < 'a' || input[0] > 'h' || input[1] < '1' || input[1] > '8' ||
           input[2] < 'a' || input[2] > 'h' || input[3] < '1' || input[3] > '8');
  
  Coordinates from = {input[0]-'a', input[1]-'1'};
  Coordinates to = {input[2]-'a', input[3]-'1'};
  
  if (is_valid_move(&state->board, &(Move){from, to})) {
    move->from = from;
    move->to = to;
  } else {
    printf("Invalid move\n");
    get_move_from_input(state, move);
  }
}

/**
 * Get the computer's move
 */
void get_move_from_ai(GameState *state, Move *move) {
  // TODO: write an AI that makes moves
}

/**
 * Main function to start the game
 */ 
int main() {
  GameState state;
  reset_board(&state);
  
  print_board(&state.board);
  
  Move move;
  
  while (!is_game_over(&state)) {
    if (state.current_player->type == HUMAN) {
      get_move_from_input(&state, &move);
    } else {
      get_move_from_ai(&state, &move);
    }
    
    make_move(&state, &move);
    
    print_board(&state.board);
  }
  
  printf("Game over\n");
  
  return 0;
}