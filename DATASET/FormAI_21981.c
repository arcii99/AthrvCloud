//FormAI DATASET v1.0 Category: Checkers Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Board data structure
typedef struct {
    int x, y;
} Position;

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    bool player1Turn; // True if player1's turn, false otherwise
} Board;

// Prints the current state of the board
void printBoard(Board board) {
    printf("   A B C D E F G H\n");
    printf("  +----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board.board[i][j]);
        }
        printf("|\n");
    }
    printf("  +----------------+\n");
}

// Checks if a given move is legal
bool isLegalMove(Board board, Position origin, Position dest) {
    char player = board.board[origin.y][origin.x];
    // Check that the destination is a valid spot on the board
    if (dest.x < 0 || dest.x >= BOARD_SIZE || dest.y < 0 || dest.y >= BOARD_SIZE) {
        return false;
    }
    // Check that the destination is empty
    if (board.board[dest.y][dest.x] != ' ') {
        return false;
    }
    // Check that the move is diagonal
    int xDiff = abs(dest.x - origin.x);
    int yDiff = abs(dest.y - origin.y);
    if (xDiff != yDiff) {
        return false;
    }
    // Check that the move is not more than 2 spaces away
    if (xDiff > 2) {
        return false;
    }
    // Check that if the move is 2 spaces away, the jumped piece is an enemy piece
    if (xDiff == 2) {
        int xJump = (origin.x + dest.x) / 2;
        int yJump = (origin.y + dest.y) / 2;
        char jumpedPiece = board.board[yJump][xJump];
        char playerCode = board.player1Turn ? 'X' : 'O';
        if (jumpedPiece == ' ' || jumpedPiece == playerCode) {
            return false;
        }
    }
    // Check that regular pieces are only moving forwards
    if (player == 'X' && dest.y <= origin.y) {
        return false;
    }
    if (player == 'O' && dest.y >= origin.y) {
        return false;
    }
    // All checks passed, move is legal
    return true;
}

// Promote a piece to a king
void promote(Board* board, Position pos) {
    char player = board->board[pos.y][pos.x];
    if (player == 'X' && pos.y == BOARD_SIZE - 1) {
        board->board[pos.y][pos.x] = 'K';
    } else if (player == 'O' && pos.y == 0) {
        board->board[pos.y][pos.x] = 'K';
    }
}

// Apply the given move to the board
void applyMove(Board* board, Position origin, Position dest) {
    char player = board->board[origin.y][origin.x];
    // Update the board state
    board->board[origin.y][origin.x] = ' ';
    board->board[dest.y][dest.x] = player;
    // Promote the piece if needed
    promote(board, dest);
    // Check for multiple jumps
    Position jumps[4] = {{origin.x-2, origin.y-2}, {origin.x+2, origin.y-2},
    {origin.x-2, origin.y+2}, {origin.x+2, origin.y+2}};
    bool jumpFound = false;
    for (int i = 0; i < 4; i++) {
        if (isLegalMove(*board, origin, jumps[i])) {
            jumpFound = true;
            Position jumpedPos = {(origin.x + jumps[i].x) / 2, (origin.y + jumps[i].y) / 2};
            board->board[jumpedPos.y][jumpedPos.x] = ' ';
            applyMove(board, origin, jumps[i]);
        }
    }
    // If no jumps were taken, switch turns
    if (!jumpFound) {
        board->player1Turn = !board->player1Turn;
    }
}

// Get a position from the user
Position getPosition() {
    char buffer[5];
    printf("Enter position (i.e. A1): ");
    scanf("%s", buffer);
    int x = buffer[0] - 'A';
    int y = buffer[1] - '1';
    return (Position) {x, y};
}

// Main game loop
void playGame() {
    Board board = {{{' ','O',' ','O',' ','O',' ','O'},
                    {'O',' ','O',' ','O',' ','O',' '},
                    {' ','O',' ','O',' ','O',' ','O'},
                    {' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' '},
                    {'X',' ','X',' ','X',' ','X',' '},
                    {' ','X',' ','X',' ','X',' ','X'},
                    {'X',' ','X',' ','X',' ','X',' '}},
                    true};
    while (true) {
        printBoard(board);
        char playerCode = board.player1Turn ? 'X' : 'O';
        printf("Player %c's turn.\n", playerCode);
        Position origin = getPosition();
        Position dest = getPosition();
        if (isLegalMove(board, origin, dest)) {
            applyMove(&board, origin, dest);
        } else {
            printf("Invalid move.\n");
        }
    }
}

int main() {
    playGame();
    return 0;
}