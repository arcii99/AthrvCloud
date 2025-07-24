//FormAI DATASET v1.0 Category: Chess engine ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_DEPTH 6
#define MAX_MOVES 2048

// Piece values
const int PAWN_VALUE = 100;
const int KNIGHT_VALUE = 320;
const int BISHOP_VALUE = 330;
const int ROOK_VALUE = 500;
const int QUEEN_VALUE = 900;
const int KING_VALUE = 20000;

// Board layout
char game_board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

// Structs
typedef struct {
    int from_row;
    int from_col;
    int to_row;
    int to_col;
} Move;

typedef struct {
    int score;
    Move move;
} Rank;

// Function declarations
int minimax(int depth, int alpha, int beta, int maximizing_player);
void make_move(Move move);
void undo_move(Move move);
int evaluate_board();
Rank* generate_moves(int* num_moves);
int get_piece_value(char piece);
int get_piece_index(char piece);

int main() {
    printf("Welcome to the C Chess Engine!\n");

    // Game loop
    while (1) {
        printf("\nCurrent state of the board:\n");

        // Print current board state
        for (int row = 7; row >= 0; row--) {
            printf("%d ", row+1);
            for (int col = 0; col < 8; col++) {
                printf("%c ", game_board[row][col]);
            }
            printf("\n");
        }

        printf("  A B C D E F G H\n");

        // Get all possible moves and their scores
        Rank* moves = generate_moves(NULL);
        int num_moves = get_piece_index(' ') * 28;

        printf("Possible moves:\n");

        // Print possible moves
        for (int i = 0; i < num_moves; i++) {
            printf("%c%d to %c%d (score: %d)\n", moves[i].move.from_col + 'A', moves[i].move.from_row + 1,
                                                   moves[i].move.to_col + 'A', moves[i].move.to_row + 1,
                                                   moves[i].score);
        }

        // Ask user for move
        char input[5];
        printf("Enter your move (ex: e2 e4): ");
        fgets(input, 5, stdin);

        // Convert input to move
        Move selected_move;
        selected_move.from_col = input[0] - 'A';
        selected_move.from_row = input[1] - '1';
        selected_move.to_col = input[2] - 'A';
        selected_move.to_row = input[3] - '1';

        // Make the move and print new board state
        make_move(selected_move);

        printf("\nNew state of the board:\n");
        for (int row = 7; row >= 0; row--) {
            printf("%d ", row+1);
            for (int col = 0; col < 8; col++) {
                printf("%c ", game_board[row][col]);
            }
            printf("\n");
        }
    }
}

// Returns the minimax score of a certain move
int minimax(int depth, int alpha, int beta, int maximizing_player) {
    if (depth == 0) {
        return evaluate_board();
    }

    // Generate all possible moves for current player
    Rank* moves = generate_moves(NULL);
    int num_moves = get_piece_index(' ') * 28;

    if (maximizing_player) {
        int max_score = -100000;
        for (int i = 0; i < num_moves; i++) {
            make_move(moves[i].move);
            int score = minimax(depth-1, alpha, beta, 0);
            undo_move(moves[i].move);
            if (score > max_score) {
                max_score = score;
            }
            alpha = alpha > max_score ? alpha : max_score;
            if (beta <= alpha) {
                break;
            }
        }
        return max_score;
    } else {
        int min_score = 100000;
        for (int i = 0; i < num_moves; i++) {
            make_move(moves[i].move);
            int score = minimax(depth-1, alpha, beta, 1);
            undo_move(moves[i].move);
            if (score < min_score) {
                min_score = score;
            }
            beta = beta < min_score ? beta : min_score;
            if (beta <= alpha) {
                break;
            }
        }
        return min_score;
    }
}

// Make a move on the board
void make_move(Move move) {
    game_board[move.to_row][move.to_col] = game_board[move.from_row][move.from_col];
    game_board[move.from_row][move.from_col] = ' ';
}

// Undo a move on the board
void undo_move(Move move) {
    game_board[move.from_row][move.from_col] = game_board[move.to_row][move.to_col];
    game_board[move.to_row][move.to_col] = ' ';
}

// Evaluate the board state and return a score
int evaluate_board() {
    int score = 0;

    // Go through every square on the board
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            char piece = game_board[row][col];
            int value = get_piece_value(piece);
            if (piece != ' ') {
                score += (get_piece_index(piece) > 0 ? value : -value);
            }
        }
    }

    return score;
}

// Generate all possible moves and their scores
Rank* generate_moves(int* num_moves) {
    Rank* moves;
    if (num_moves == NULL) {
        moves = malloc(sizeof(Rank) * MAX_MOVES);
        num_moves = malloc(sizeof(int));
    } else {
        moves = malloc(sizeof(Rank) * (*num_moves));
    }

    int index = 0;

    // Loop through every square on the board
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            char piece = game_board[row][col];
            if (get_piece_index(piece) > 0) {
                // Loop through all possible moves for each piece and calculate their score
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (i != 0 || j != 0) {
                            int to_row = row + i;
                            int to_col = col + j;
                            if (to_row >= 0 && to_row < 8 && to_col >= 0 && to_col < 8) {
                                Move move;
                                move.from_row = row;
                                move.from_col = col;
                                move.to_row = to_row;
                                move.to_col = to_col;
                                int score = minimax(MAX_DEPTH, -100000, 100000, 0);
                                Rank rank;
                                rank.move = move;
                                rank.score = score;
                                moves[index] = rank;
                                index++;
                            }
                        }
                    }
                }
            }
        }
    }

    *num_moves = index;
    return moves;
}

// Return an integer value representing the value of a certain piece
int get_piece_value(char piece) {
    switch (piece) {
        case 'P':
        case 'p':
            return PAWN_VALUE;
        case 'N':
        case 'n':
            return KNIGHT_VALUE;
        case 'B':
        case 'b':
            return BISHOP_VALUE;
        case 'R':
        case 'r':
            return ROOK_VALUE;
        case 'Q':
        case 'q':
            return QUEEN_VALUE;
        case 'K':
        case 'k':
            return KING_VALUE;
        default:
            return 0;
    }
}

// Return an integer index representing the piece's position in the piece array
int get_piece_index(char piece) {
    const char* pieces = " KQBNRPkqbnrp.";
    const char* index = strchr(pieces, piece);
    return (int)(index - pieces);
}