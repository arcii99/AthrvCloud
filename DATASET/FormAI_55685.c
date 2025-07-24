//FormAI DATASET v1.0 Category: Chess AI ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define MAX_TREE_DEPTH 4

// Chess piece values
#define KING_VALUE 200
#define QUEEN_VALUE 9
#define ROOK_VALUE 5
#define BISHOP_VALUE 3
#define KNIGHT_VALUE 3
#define PAWN_VALUE 1

// Piece characters
#define EMPTY ' '
#define WHITE_KING 'K'
#define WHITE_QUEEN 'Q'
#define WHITE_ROOK 'R'
#define WHITE_BISHOP 'B'
#define WHITE_KNIGHT 'N'
#define WHITE_PAWN 'P'
#define BLACK_KING 'k'
#define BLACK_QUEEN 'q'
#define BLACK_ROOK 'r'
#define BLACK_BISHOP 'b'
#define BLACK_KNIGHT 'n'
#define BLACK_PAWN 'p'

// Board state struct
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int white_score;
    int black_score;
} BoardState;

// TreeNode struct for minimax tree
typedef struct TreeNode {
    BoardState *state;
    struct TreeNode *children[BOARD_SIZE * BOARD_SIZE];
    int child_count;
    int alpha;
    int beta;
} TreeNode;

// Global board state variable
BoardState current_state;

// Function to initialize the board state
void initialize_board_state() {
    // Place black pieces
    current_state.board[0][0] = BLACK_ROOK;
    current_state.board[0][1] = BLACK_KNIGHT;
    current_state.board[0][2] = BLACK_BISHOP;
    current_state.board[0][3] = BLACK_QUEEN;
    current_state.board[0][4] = BLACK_KING;
    current_state.board[0][5] = BLACK_BISHOP;
    current_state.board[0][6] = BLACK_KNIGHT;
    current_state.board[0][7] = BLACK_ROOK;

    for (int i = 0; i < BOARD_SIZE; i++) {
        current_state.board[1][i] = BLACK_PAWN;
    }

    // Place white pieces
    current_state.board[7][0] = WHITE_ROOK;
    current_state.board[7][1] = WHITE_KNIGHT;
    current_state.board[7][2] = WHITE_BISHOP;
    current_state.board[7][3] = WHITE_QUEEN;
    current_state.board[7][4] = WHITE_KING;
    current_state.board[7][5] = WHITE_BISHOP;
    current_state.board[7][6] = WHITE_KNIGHT;
    current_state.board[7][7] = WHITE_ROOK;

    for (int i = 0; i < BOARD_SIZE; i++) {
        current_state.board[6][i] = WHITE_PAWN;
    }

    // Set empty spaces to EMPTY character
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            current_state.board[i][j] = EMPTY;
        }
    }

    // Initialize scores
    current_state.white_score = 0;
    current_state.black_score = 0;

    // Calculate initial scores
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch(current_state.board[i][j]) {
                case WHITE_KING:
                    current_state.white_score += KING_VALUE;
                    break;
                case WHITE_QUEEN:
                    current_state.white_score += QUEEN_VALUE;
                    break;
                case WHITE_ROOK:
                    current_state.white_score += ROOK_VALUE;
                    break;
                case WHITE_BISHOP:
                    current_state.white_score += BISHOP_VALUE;
                    break;
                case WHITE_KNIGHT:
                    current_state.white_score += KNIGHT_VALUE;
                    break;
                case WHITE_PAWN:
                    current_state.white_score += PAWN_VALUE;
                    break;
                case BLACK_KING:
                    current_state.black_score += KING_VALUE;
                    break;
                case BLACK_QUEEN:
                    current_state.black_score += QUEEN_VALUE;
                    break;
                case BLACK_ROOK:
                    current_state.black_score += ROOK_VALUE;
                    break;
                case BLACK_BISHOP:
                    current_state.black_score += BISHOP_VALUE;
                    break;
                case BLACK_KNIGHT:
                    current_state.black_score += KNIGHT_VALUE;
                    break;
                case BLACK_PAWN:
                    current_state.black_score += PAWN_VALUE;
                    break;
            }
        }
    }
}

// Function to print the current state of the board
void print_board_state() {
    printf("\n   A B C D E F G H \n");
    printf("  +---------------+\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d | ", i + 1);

        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", current_state.board[i][j]);
        }

        printf("|\n");
    }

    printf("  +---------------+\n");
    printf("  White score: %d\n", current_state.white_score);
    printf("  Black score: %d\n", current_state.black_score);
}

// Function to determine the value of a given move based on the resulting board state
int evaluate_move(BoardState *state) {
    int score = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch(state->board[i][j]) {
                case WHITE_KING:
                    score += KING_VALUE;
                    break;
                case WHITE_QUEEN:
                    score += QUEEN_VALUE;
                    break;
                case WHITE_ROOK:
                    score += ROOK_VALUE;
                    break;
                case WHITE_BISHOP:
                    score += BISHOP_VALUE;
                    break;
                case WHITE_KNIGHT:
                    score += KNIGHT_VALUE;
                    break;
                case WHITE_PAWN:
                    score += PAWN_VALUE;
                    break;
                case BLACK_KING:
                    score -= KING_VALUE;
                    break;
                case BLACK_QUEEN:
                    score -= QUEEN_VALUE;
                    break;
                case BLACK_ROOK:
                    score -= ROOK_VALUE;
                    break;
                case BLACK_BISHOP:
                    score -= BISHOP_VALUE;
                    break;
                case BLACK_KNIGHT:
                    score -= KNIGHT_VALUE;
                    break;
                case BLACK_PAWN:
                    score -= PAWN_VALUE;
                    break;
            }
        }
    }

    return score;
}

// Function to create a new tree node
TreeNode *new_tree_node(BoardState *state) {
    TreeNode *new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->state = state;
    new_node->child_count = 0;
    new_node->alpha = -1000;
    new_node->beta = 1000;

    return new_node;
}

// Function to recursively generate the minimax tree, up to a certain depth limit
void generate_tree(TreeNode *root, int depth, int is_maximizing) {
    if (depth == 0) {
        return;
    }

    // Create child nodes for each possible move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((is_maximizing && root->state->board[i][j] >= 'A' && root->state->board[i][j] <= 'Z') ||
                (!is_maximizing && root->state->board[i][j] >= 'a' && root->state->board[i][j] <= 'z')) {
                // Create copy of board state and make move
                BoardState *new_state = (BoardState*)malloc(sizeof(BoardState));
                *new_state = *root->state;
                new_state->board[i][j] = new_state->board[i][j] >= 'a' ? new_state->board[i][j] - 32 : new_state->board[i][j];
                new_state->board[0][0] = new_state->board[0][0] == WHITE_ROOK ? EMPTY : new_state->board[0][0];
                new_state->board[0][7] = new_state->board[0][7] == WHITE_ROOK ? EMPTY : new_state->board[0][7];
                new_state->board[7][0] = new_state->board[7][0] == BLACK_ROOK ? EMPTY : new_state->board[7][0];
                new_state->board[7][7] = new_state->board[7][7] == BLACK_ROOK ? EMPTY : new_state->board[7][7];
                new_state->board[0][4] = WHITE_KING;
                new_state->board[7][4] = BLACK_KING;
                new_state->board[current_state.board[i][j] >= 'a' ? i + 1 : i - 1][j] = EMPTY;

                // Calculate new state scores
                new_state->white_score = 0;
                new_state->black_score = 0;

                for (int k = 0; k < BOARD_SIZE; k++) {
                    for (int l = 0; l < BOARD_SIZE; l++) {
                        switch(new_state->board[k][l]) {
                            case WHITE_KING:
                                new_state->white_score += KING_VALUE;
                                break;
                            case WHITE_QUEEN:
                                new_state->white_score += QUEEN_VALUE;
                                break;
                            case WHITE_ROOK:
                                new_state->white_score += ROOK_VALUE;
                                break;
                            case WHITE_BISHOP:
                                new_state->white_score += BISHOP_VALUE;
                                break;
                            case WHITE_KNIGHT:
                                new_state->white_score += KNIGHT_VALUE;
                                break;
                            case WHITE_PAWN:
                                new_state->white_score += PAWN_VALUE;
                                break;
                            case BLACK_KING:
                                new_state->black_score += KING_VALUE;
                                break;
                            case BLACK_QUEEN:
                                new_state->black_score += QUEEN_VALUE;
                                break;
                            case BLACK_ROOK:
                                new_state->black_score += ROOK_VALUE;
                                break;
                            case BLACK_BISHOP:
                                new_state->black_score += BISHOP_VALUE;
                                break;
                            case BLACK_KNIGHT:
                                new_state->black_score += KNIGHT_VALUE;
                                break;
                            case BLACK_PAWN:
                                new_state->black_score += PAWN_VALUE;
                                break;
                        }
                    }
                }

                // Create child node for move
                TreeNode *new_node = new_tree_node(new_state);
                root->children[root->child_count++] = new_node;

                // Recursively generate child nodes
                generate_tree(new_node, depth - 1, !is_maximizing);

                // Evaluate move and update parent node alpha/beta values
                int move_value = evaluate_move(new_state);

                if (is_maximizing) {
                    root->alpha = root->alpha > move_value ? root->alpha : move_value;
                } else {
                    root->beta = root->beta < move_value ? root->beta : move_value;
                }
            }
        }
    }
}

// Function to get the best move using minimax tree
int get_best_move(char player) {
    int best_move_value = player == 'W' ? -1000 : 1000;
    int best_move_index = -1;

    // Create root node for tree
    BoardState *root_state = (BoardState*)malloc(sizeof(BoardState));
    *root_state = current_state;

    TreeNode *root = new_tree_node(root_state);

    // Generate tree
    generate_tree(root, MAX_TREE_DEPTH, player == 'W');

    // Choose best move based on alpha/beta values
    for (int i = 0; i < root->child_count; i++) {
        if ((player == 'W' && root->children[i]->alpha > best_move_value) ||
            (player == 'B' && root->children[i]->beta < best_move_value)) {
            best_move_value = player == 'W' ? root->children[i]->alpha : root->children[i]->beta;
            best_move_index = i;
        }
    }

    // Make the best move and return the corresponding index
    BoardState *best_state = root->children[best_move_index]->state;
    int best_move_col = -1, best_move_row = -1;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (current_state.board[i][j] != best_state->board[i][j]) {
                best_move_row = i;
                best_move_col = j;
                break;
            }
        }

        if (best_move_row != -1) {
            break;
        }
    }

    current_state = *best_state;

    printf("\n%s's move: %c%d to %c%d\n", player == 'W' ? "White" : "Black", best_move_col + 'A', best_move_row + 1, best_move_col + 'A', best_move_row + 1);

    return best_move_row * BOARD_SIZE + best_move_col;
}

int main() {
    initialize_board_state();

    // Game loop
    int turn_count = 0;

    while (1) {
        char player = (turn_count % 2 == 0) ? 'W' : 'B';

        print_board_state();

        // Check for game over conditions
        if (current_state.board[0][0] == WHITE_KING || current_state.board[0][7] == WHITE_KING ||
            current_state.board[7][0] == BLACK_KING || current_state.board[7][7] == BLACK_KING) {
            printf("\n%s wins!\n", player == 'W' ? "White" : "Black");
            break;
        }

        int move_index;

        if (player == 'W') {
            // Human player's turn
            printf("\nWhite's turn. Enter move (e.g. 'B2 to B3'): ");

            char input[10];
            scanf("%s", input);

            int start_col = input[0] - 'A';
            int start_row = input[1] - '1';
            int end_col = input[7] - 'A';
            int end_row = input[8] - '1';

            move_index = start_row * BOARD_SIZE + start_col;
            int target_index = end_row * BOARD_SIZE + end_col;

            // Check if move is legal
            if (start_col < 0 || start_col >= BOARD_SIZE ||
                start_row < 0 || start_row >= BOARD_SIZE ||
                end_col < 0 || end_col >= BOARD_SIZE ||
                end_row < 0 || end_row >= BOARD_SIZE ||
                current_state.board[start_row][start_col] == EMPTY ||
                (current_state.board[start_row][start_col] >= 'a' && current_state.board[start_row][start_col] <= 'z') ||
                (current_state.board[start_row][start_col] >= 'A' && current_state.board[start_row][start_col] <= 'Z' &&
                 current_state.board[end_row][end_col] >= 'A' && current_state.board[end_row][end_col] <= 'Z')) {
                printf("\nInvalid move! Try again.\n\n");
                continue;
            }
        } else {
            // AI player's turn
            printf("\nBlack's turn (AI). Choosing move...\n");
            move_index = get_best_move(player);
        }

        // Make the move
        int row = move_index / BOARD_SIZE;
        int col = move_index % BOARD_SIZE;
        current_state.board[row][col] = current_state.board[row][col] >= 'a' ? current_state.board[row][col] - 32 : current_state.board[row][col];

        if (player == 'W') {
            int new_row = move_index % BOARD_SIZE == 0 ? move_index / BOARD_SIZE - 1 : move_index / BOARD_SIZE;
            current_state.board[new_row][move_index % BOARD_SIZE] = WHITE_PAWN;
        } else {
            int new_row = move_index % BOARD_SIZE == 7 ? move_index / BOARD_SIZE + 1 : move_index / BOARD_SIZE;
            current_state.board[new_row][move_index % BOARD_SIZE] = BLACK_PAWN;
        }

        current_state.board[0][0] = current_state.board[0][0] == WHITE_ROOK ? EMPTY : current_state.board[0][0];
        current_state.board[0][7] = current_state.board[0][7] == WHITE_ROOK ? EMPTY : current_state.board[0][7];
        current_state.board[7][0] = current_state.board[7][0] == BLACK_ROOK ? EMPTY : current_state.board[7][0];
        current_state.board[7][7] = current_state.board[7][7] == BLACK_ROOK ? EMPTY : current_state.board[7][7];
        current_state.board[0][4] = WHITE_KING;
        current_state.board[7][4] = BLACK_KING;

        current_state.white_score = 0;
        current_state.black_score = 0;

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                switch(current_state.board[i][j]) {
                    case WHITE_KING:
                        current_state.white_score += KING_VALUE;
                        break;
                    case WHITE_QUEEN:
                        current_state.white_score += QUEEN_VALUE;
                        break;
                    case WHITE_ROOK:
                        current_state.white_score += ROOK_VALUE;
                        break;
                    case WHITE_BISHOP:
                        current_state.white_score += BISHOP_VALUE;
                        break;
                    case WHITE_KNIGHT:
                        current_state.white_score += KNIGHT_VALUE;
                        break;
                    case WHITE_PAWN:
                        current_state.white_score += PAWN_VALUE;
                        break;
                    case BLACK_KING:
                        current_state.black_score += KING_VALUE;
                        break;
                    case BLACK_QUEEN:
                        current_state.black_score += QUEEN_VALUE;
                        break;
                    case BLACK_ROOK:
                        current_state.black_score += ROOK_VALUE;
                        break;
                    case BLACK_BISHOP:
                        current_state.black_score += BISHOP_VALUE;
                        break;
                    case BLACK_KNIGHT:
                        current_state.black_score += KNIGHT_VALUE;
                        break;
                    case BLACK_PAWN:
                        current_state.black_score += PAWN_VALUE;
                        break;
                }
            }
        }

        turn_count++;
    }

    return 0;
}