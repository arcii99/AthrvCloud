//FormAI DATASET v1.0 Category: Chess AI ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 4
#define INFINITY 10000
#define NEG_INFINITY -10000

// Piece values
#define PAWN_VALUE 1
#define KNIGHT_VALUE 3
#define BISHOP_VALUE 3
#define ROOK_VALUE 5
#define QUEEN_VALUE 9
#define KING_VALUE INFINITY

// Helper functions
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

// Struct to hold chess board state
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char turn;
    int score;
    int depth;
} ChessBoard;

// Initialize starting board
void initBoard(ChessBoard* board) {
    char rows[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = rows[i][j];
        }
    }
    
    board->turn = 'w';
    board->score = 0;
    board->depth = 0;
}

// Helper functions to print board state
void printBoard(ChessBoard* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE-i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

// Check if a move is valid
int isValidMove(ChessBoard* board, int fromX, int fromY, int toX, int toY) {
    // Check if from and to coords are valid
    if (fromX < 0 || fromY < 0 || toX < 0 || toY < 0 ||
        fromX >= BOARD_SIZE || fromY >= BOARD_SIZE ||
        toX >= BOARD_SIZE || toY >= BOARD_SIZE) {
        return 0;
    }
    
    // Get piece from starting position
    char piece = board->board[fromY][fromX];
    char target = board->board[toY][toX];
    
    // Check if piece belongs to current player
    if ((piece >= 'a' && board->turn == 'w') ||
        (piece >= 'A' && board->turn == 'b')) {
        return 0;
    }
    
    // Check if target is a friendly piece
    if ((piece >= 'a' && target >= 'a') ||
        (piece < 'a' && target < 'a')) {
        return 0;
    }
    
    // Check if move is valid based on piece rules
    switch (piece) {
        case 'p':
        case 'P':
            // TODO: implement pawn rules
            break;
        case 'n':
        case 'N':
            if (abs(toX - fromX) == 2 && abs(toY - fromY) == 1) {
                return 1;
            }
            if (abs(toX - fromX) == 1 && abs(toY - fromY) == 2) {
                return 1;
            }
            break;
        case 'b':
        case 'B':
            if (abs(toX - fromX) == abs(toY - fromY)) {
                int xDir = (toX - fromX > 0) ? 1 : -1;
                int yDir = (toY - fromY > 0) ? 1 : -1;
                int x = fromX + xDir;
                int y = fromY + yDir;
                while (x != toX && y != toY) {
                    if (board->board[y][x] != '.') {
                        return 0;
                    }
                    x += xDir;
                    y += yDir;
                }
                return 1;
            }
            break;
        case 'r':
        case 'R':
            if (fromX == toX || fromY == toY) {
                int dir = (toX == fromX) ? ((toY > fromY) ? 1 : -1) : ((toX > fromX) ? 1 : -1);
                int x = fromX + dir;
                int y = fromY + dir;
                while (x != toX || y != toY) {
                    if (board->board[y][x] != '.') {
                        return 0;
                    }
                    if (toX == fromX) {
                        y += dir;
                    } else {
                        x += dir;
                    }
                }
                return 1;
            }
            break;
        case 'q':
        case 'Q':
            // TODO: implement queen rules
            break;
        case 'k':
        case 'K':
            if (abs(toX - fromX) <= 1 && abs(toY - fromY) <= 1) {
                return 1;
            }
            break;
    }
    
    // Move was not valid
    return 0;
}

// Make a move on the board
void makeMove(ChessBoard* board, int fromX, int fromY, int toX, int toY) {
    char piece = board->board[fromY][fromX];
    char target = board->board[toY][toX];
    board->board[fromY][fromX] = '.';
    board->board[toY][toX] = piece;
    if (target != '.') {
        board->score -= (target >= 'a') ? piece - target : target - piece;
    }
    if (board->turn == 'w') {
        board->turn = 'b';
    } else {
        board->turn = 'w';
    }
}

// Undo a move on the board
void undoMove(ChessBoard* board, int fromX, int fromY, int toX, int toY, char target) {
    char piece = board->board[toY][toX];
    board->board[toY][toX] = target;
    board->board[fromY][fromX] = piece;
    if (target != '.') {
        board->score += (target >= 'a') ? piece - target : target - piece;
    }
    if (board->turn == 'w') {
        board->turn = 'b';
    } else {
        board->turn = 'w';
    }
}

// Recursive minimax function with alpha-beta pruning
int minimax(ChessBoard* board, int depth, int alpha, int beta) {
    if (depth == MAX_DEPTH || board->score <= -INFINITY || board->score >= INFINITY) {
        return board->score;
    }
    
    if (board->turn == 'w') {
        int maxScore = NEG_INFINITY;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board->board[i][j] >= 'a') { // skip black pieces
                    continue;
                }
                for (int k = 0; k < BOARD_SIZE; k++) {
                    for (int l = 0; l < BOARD_SIZE; l++) {
                        if (isValidMove(board, j, i, l, k)) {
                            char target = board->board[k][l];
                            makeMove(board, j, i, l, k);
                            int score = minimax(board, depth+1, alpha, beta);
                            undoMove(board, j, i, l, k, target);
                            maxScore = max(maxScore, score);
                            alpha = max(alpha, score);
                            if (alpha >= beta) {
                                return maxScore;
                            }
                        }
                    }
                }
            }
        }
        return maxScore;
    } else {
        int minScore = INFINITY;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board->board[i][j] < 'a') { // skip white pieces
                    continue;
                }
                for (int k = 0; k < BOARD_SIZE; k++) {
                    for (int l = 0; l < BOARD_SIZE; l++) {
                        if (isValidMove(board, j, i, l, k)) {
                            char target = board->board[k][l];
                            makeMove(board, j, i, l, k);
                            int score = minimax(board, depth+1, alpha, beta);
                            undoMove(board, j, i, l, k, target);
                            minScore = min(minScore, score);
                            beta = min(beta, score);
                            if (alpha >= beta) {
                                return minScore;
                            }
                        }
                    }
                }
            }
        }
        return minScore;
    }
}

// Main function to run game loop
int main() {
    ChessBoard board;
    initBoard(&board);
    printBoard(&board);
    
    while(1) {
        int fromX, fromY, toX, toY;
        printf("%c's turn: ", board.turn);
        scanf("%d %d %d %d", &fromX, &fromY, &toX, &toY);
        
        if (isValidMove(&board, fromX, fromY, toX, toY)) {
            char target = board.board[toY][toX];
            makeMove(&board, fromX, fromY, toX, toY);
            board.score = minimax(&board, 0, NEG_INFINITY, INFINITY);
            printf("Score: %d\n", board.score);
            printBoard(&board);
        } else {
            printf("Invalid move\n");
        }
    }
    
    return 0;
}