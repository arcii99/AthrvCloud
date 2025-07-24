//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define BOARD_SIZE 3
#define MAX_DEPTH 9

// Define board data structure
typedef struct Board {
    int grid[BOARD_SIZE][BOARD_SIZE];
} Board;

// Define node data structure for minimax tree
typedef struct Node {
    Board board;
    int value;
    int depth;
    struct Node* children[BOARD_SIZE*BOARD_SIZE];
} Node;

// Function to check if board is full
int is_board_full(Board* board) {
    int i, j;
    for (i=0; i<BOARD_SIZE; i++) {
        for (j=0; j<BOARD_SIZE; j++) {
            if (board->grid[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if player has won
int is_winner(Board* board, int player) {
    int i, j, win;
    // Check rows
    for (i=0; i<BOARD_SIZE; i++) {
        win = 1;
        for (j=0; j<BOARD_SIZE; j++) {
            if (board->grid[i][j] != player) {
                win = 0;
                break;
            }
        }
        if (win) {
            return 1;
        }
    }
    // Check columns
    for (i=0; i<BOARD_SIZE; i++) {
        win = 1;
        for (j=0; j<BOARD_SIZE; j++) {
            if (board->grid[j][i] != player) {
                win = 0;
                break;
            }
        }
        if (win) {
            return 1;
        }
    }
    // Check diagonals
    win = 1;
    for (i=0; i<BOARD_SIZE; i++) {
        if (board->grid[i][i] != player) {
            win = 0;
            break;
        }
    }
    if (win) {
        return 1;
    }
    win = 1;
    for (i=0; i<BOARD_SIZE; i++) {
        if (board->grid[i][BOARD_SIZE-i-1] != player) {
            win = 0;
            break;
        }
    }
    if (win) {
        return 1;
    }
    return 0;
}

// Function to print board
void print_board(Board* board) {
    int i, j;
    for (i=0; i<BOARD_SIZE; i++) {
        for (j=0; j<BOARD_SIZE; j++) {
            printf("%d ", board->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to create a new board
Board new_board() {
    Board board;
    int i, j;
    for (i=0; i<BOARD_SIZE; i++) {
        for (j=0; j<BOARD_SIZE; j++) {
            board.grid[i][j] = 0;
        }
    }
    return board;
}

// Function to make a move on the board
void make_move(Board* board, int row, int col, int player) {
    board->grid[row][col] = player;
}

// Function to undo a move on the board
void undo_move(Board* board, int row, int col) {
    board->grid[row][col] = 0;
}

// Function to create a new minimax tree node
Node* new_node(Board board, int depth) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->board = board;
    node->depth = depth;
    node->value = 0;
    int i, j, k=0;
    for (i=0; i<BOARD_SIZE; i++) {
        for (j=0; j<BOARD_SIZE; j++) {
            if (board.grid[i][j] == 0) {
                Board new_board = board;
                make_move(&new_board, i, j, (depth%2)+1);
                node->children[k] = new_node(new_board, depth+1);
                k++;
            }
        }
    }
    return node;
}

// Function to free a minimax tree
void free_tree(Node* node) {
    int i;
    for (i=0; i<BOARD_SIZE*BOARD_SIZE; i++) {
        if (node->children[i] != NULL) {
            free_tree(node->children[i]);
        }
    }
    free(node);
}

// Function to calcualte minimax value for node
int minimax(Node* node, int alpha, int beta) {
    if (node->depth == MAX_DEPTH || is_board_full(&node->board) || is_winner(&node->board, 1) || is_winner(&node->board, 2)) {
        if (is_winner(&node->board, 2)) {
            return 1;
        } else if (is_winner(&node->board, 1)) {
            return -1;
        } else {
            return 0;
        }
    } else {
        int i;
        if (node->depth%2 == 0) {
            node->value = alpha;
            for (i=0; i<BOARD_SIZE*BOARD_SIZE; i++) {
                if (node->children[i] != NULL) {
                    node->value = (node->value > minimax(node->children[i], node->value, beta)) ? node->value : minimax(node->children[i], node->value, beta);
                    if (beta <= node->value) {
                        break;
                    }
                }
            }
            return node->value;
        } else {
            node->value = beta;
            for (i=0; i<BOARD_SIZE*BOARD_SIZE; i++) {
                if (node->children[i] != NULL) {
                    node->value = (node->value < minimax(node->children[i], alpha, node->value)) ? node->value : minimax(node->children[i], alpha, node->value);
                    if (node->value <= alpha) {
                        break;
                    }
                }
            }
            return node->value;
        }
    }
}

// Function to find best move for AI
void find_best_move(Board* board) {
    Node* root = new_node(*board, 0);
    int i, j;
    for (i=0; i<BOARD_SIZE; i++) {
        for (j=0; j<BOARD_SIZE; j++) {
            if (board->grid[i][j] == 0) {
                Board new_board = *board;
                make_move(&new_board, i, j, 2);
                Node* node = new_node(new_board, 1);
                node->value = minimax(node, -1, 1);
                root->children[i*BOARD_SIZE+j]->value = node->value;
                free_tree(node);
            }
        }
    }
    int best_row, best_col, best_value=-2;
    for (i=0; i<BOARD_SIZE; i++) {
        for (j=0; j<BOARD_SIZE; j++) {
            if (board->grid[i][j] == 0 && root->children[i*BOARD_SIZE+j]->value > best_value) {
                best_row = i;
                best_col = j;
                best_value = root->children[i*BOARD_SIZE+j]->value;
            }
        }
    }
    printf("AI chooses row %d, column %d\n", best_row, best_col);
    make_move(board, best_row, best_col, 2);
    free_tree(root);
}

// Main function
int main() {
    Board board = new_board();
    int player = 1;
    int row, col;
    while (!is_board_full(&board) && !is_winner(&board, 1) && !is_winner(&board, 2)) {
        printf("Player %d's turn\n", player);
        print_board(&board);
        if (player == 1) {
            printf("Enter row: ");
            scanf("%d", &row);
            printf("Enter column: ");
            scanf("%d", &col);
            while (board.grid[row][col] != 0) {
                printf("Invalid move, try again\n");
                printf("Enter row: ");
                scanf("%d", &row);
                printf("Enter column: ");
                scanf("%d", &col);
            }
            make_move(&board, row, col, player);
        } else {
            find_best_move(&board);
        }
        player = (player%2) + 1;
    }
    print_board(&board);
    if (is_winner(&board, 1)) {
        printf("Player 1 wins!\n");
    } else if (is_winner(&board, 2)) {
        printf("Player 2 wins!\n");
    } else {
        printf("Draw!\n");
    }
    return 0;
}