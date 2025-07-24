//FormAI DATASET v1.0 Category: Chess AI ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position current_position;
    Position possible_moves[8];
} Piece;

Piece board[BOARD_SIZE][BOARD_SIZE];
int active_player = 1; // Player 1 or 2
int check_flag = 0; // 0 - no check, 1 - check, 2 - checkmate
Position king_positions[2]; // Keep track of both king's positions

// Add a piece to the board at the specified position
void add_piece(int x, int y, int player) {
    Piece new_piece;
    new_piece.current_position.x = x;
    new_piece.current_position.y = y;
    
    // Set possible moves based on piece type
    if (player == 1) {
        new_piece.possible_moves[0] = (Position) {x-1, y+1}; // Top left diagonal
        new_piece.possible_moves[1] = (Position) {x+1, y+1}; // Top right diagonal
        new_piece.possible_moves[2] = (Position) {x-1, y-1}; // Bottom left diagonal
        new_piece.possible_moves[3] = (Position) {x+1, y-1}; // Bottom right diagonal
    } else if (player == 2) {
        new_piece.possible_moves[0] = (Position) {x-1, y}; // Up
        new_piece.possible_moves[1] = (Position) {x, y+1}; // Right
        new_piece.possible_moves[2] = (Position) {x+1, y}; // Down
        new_piece.possible_moves[3] = (Position) {x, y-1}; // Left
    }
    
    board[x][y] = new_piece;
}

// Initialize the board with pieces
void initialize_board() {
    // Add player 1's pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        add_piece(i, 1, 1); // Pawns
    }
    add_piece(0, 0, 1); // Rook
    add_piece(1, 0, 1); // Knight
    add_piece(2, 0, 1); // Bishop
    add_piece(3, 0, 1); // Queen
    add_piece(4, 0, 1); // King
    add_piece(5, 0, 1); // Bishop
    add_piece(6, 0, 1); // Knight
    add_piece(7, 0, 1); // Rook
    
    // Add player 2's pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        add_piece(i, 6, 2); // Pawns
    }
    add_piece(0, 7, 2); // Rook
    add_piece(1, 7, 2); // Knight
    add_piece(2, 7, 2); // Bishop
    add_piece(3, 7, 2); // Queen
    add_piece(4, 7, 2); // King
    add_piece(5, 7, 2); // Bishop
    add_piece(6, 7, 2); // Knight
    add_piece(7, 7, 2); // Rook
}

// Display the board to the console
void display_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].current_position.x == king_positions[0].x && board[i][j].current_position.y == king_positions[0].y) {
                printf(" W ");
            } else if (board[i][j].current_position.x == king_positions[1].x && board[i][j].current_position.y == king_positions[1].y) {
                printf(" B ");
            } else if (board[i][j].current_position.x == 0 || board[i][j].current_position.x == 2 || board[i][j].current_position.x == 4 || board[i][j].current_position.x == 6) {
                printf("\033[40m\033[31m   \033[0m");
            } else {
                printf("\033[40m\033[37m   \033[0m");
            }
        }
        printf("\n");
    }
}

// Move the piece at the specified position to the new position
void move_piece(Position current_position, Position new_position) {
    Piece piece = board[current_position.x][current_position.y];
    board[new_position.x][new_position.y] = piece;
    board[current_position.x][current_position.y].current_position = (Position) {-1, -1}; // Remove piece from old position
    
    // Check if move results in checkmate
    if (check_flag == 1) {
        check_flag = 0;
        if (is_checkmate()) {
            check_flag = 2;
        }
    }
    
    // Switch active player
    if (active_player == 1) {
        active_player = 2;
    } else {
        active_player = 1;
    }
}

// Check if a move is valid for the current player
int is_valid_move(Position current_position, Position new_position) {
    Piece piece = board[current_position.x][current_position.y];
    if (piece.current_position.x == -1 || piece.current_position.y == -1) {
        return 0;
    }
    if (piece.current_position.x == new_position.x && piece.current_position.y == new_position.y) {
        return 0;
    }
    if (piece.current_position.x < 0 || piece.current_position.x >= BOARD_SIZE || piece.current_position.y < 0 || piece.current_position.y >= BOARD_SIZE) {
        return 0;
    }
    if (active_player == 1) {
        if (board[new_position.x][new_position.y].current_position.x != -1 && board[new_position.x][new_position.y].current_position.y != -1) {
            return 0; // Can't move to a position occupied by a piece of the same color
        }
        for (int i = 0; i < 4; i++) {
            if (piece.possible_moves[i].x == new_position.x && piece.possible_moves[i].y == new_position.y) {
                return 1; // Valid move for this piece
            }
        }
        return 0; // Invalid move
    } else if (active_player == 2) {
        if (board[new_position.x][new_position.y].current_position.x != -1 && board[new_position.x][new_position.y].current_position.y != -1) {
            return 0; // Can't move to a position occupied by a piece of the same color
        }
        for (int i = 0; i < 4; i++) {
            if (piece.possible_moves[i].x == new_position.x && piece.possible_moves[i].y == new_position.y) {
                return 1; // Valid move for this piece
            }
        }
        return 0; // Invalid move
    }
}

// Check if the king of the active player is in check or checkmate
int is_checkmate() {
    // TODO: Implement checkmate logic
    return 1;
}

int main() {
    initialize_board();
    king_positions[0] = (Position) {4, 0}; // Player 1's king starting position
    king_positions[1] = (Position) {4, 7}; // Player 2's king starting position
    
    while(1) {
        display_board();
        printf("\n");
        
        // Check status flag and print appropriate message if necessary
        switch (check_flag) {
            case 0:
                printf("No check.\n");
                break;
            case 1:
                printf("Check!\n");
                break;
            case 2:
                printf("Checkmate! Game over.\n");
                return 0;
        }
        
        char input[10];
        printf("Player %d turn. Enter move (ex: a2 a3): ", active_player);
        fgets(input, 10, stdin);
        Position current_position = {input[0]-'a', input[1]-'0'-1};
        Position new_position = {input[3]-'a', input[4]-'0'-1};
        
        // Validate move and move the piece if valid
        if (is_valid_move(current_position, new_position)) {
            move_piece(current_position, new_position);
        } else {
            printf("Invalid move.\n");
        }
    }
    
    return 0;
}