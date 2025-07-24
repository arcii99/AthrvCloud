//FormAI DATASET v1.0 Category: Chess AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPTH 4 // Set the maximum depth for the AI search algorithm

typedef struct chessboard {
    char board[8][8];
} Chessboard;

// Initialize a new chessboard with starting positions
void init_board(Chessboard *cb) {
    char p[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    
    for (int i = 0; i < 8; i++) {
        cb->board[0][i] = p[i];
        cb->board[1][i] = 'p';
        cb->board[6][i] = 'P';
        cb->board[7][i] = p[i] - 32;
    }
    
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            cb->board[i][j] = ' ';
        }
    }
}

// Print the current chessboard state
void print_board(Chessboard *cb) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < 8; j++) {
            printf("%c ", cb->board[i][j]);
        }
        printf("%d\n", i+1);
    }
    printf("  A B C D E F G H\n");
}

// Check if the given move is valid for the current chessboard state
int is_valid_move(Chessboard *cb, char *from, char *to) {
    int from_x = from[0] - 'a';
    int from_y = from[1] - '1';
    int to_x = to[0] - 'a';
    int to_y = to[1] - '1';
    char piece = cb->board[from_y][from_x];
    
    if (cb->board[to_y][to_x] != ' ') {
        return 0; // Cannot capture own piece
    }
    
    switch (piece) {
        case 'p':
            if (from_x == to_x && from_y - to_y == 1 &&
                cb->board[to_y][to_x] == ' ') {
                return 1; // Move one step forward
            } else if (from_x == to_x && from_y - to_y == 2 &&
                       from_y == 6 && cb->board[to_y][to_x] == ' ') {
                return 1; // Move two steps forward from starting position
            } else if (abs(from_x - to_x) == 1 && from_y - to_y == 1 &&
                       cb->board[to_y][to_x] != ' ') {
                return 1; // Capture opponent's piece diagonally
            } else {
                return 0; // Invalid move for pawn
            }
            break;
        case 'P':
            if (from_x == to_x && to_y - from_y == 1 &&
                cb->board[to_y][to_x] == ' ') {
                return 1; // Move one step forward
            } else if (from_x == to_x && to_y - from_y == 2 &&
                       from_y == 1 && cb->board[to_y][to_x] == ' ') {
                return 1; // Move two steps forward from starting position
            } else if (abs(from_x - to_x) == 1 && to_y - from_y == 1 &&
                       cb->board[to_y][to_x] != ' ') {
                return 1; // Capture opponent's piece diagonally
            } else {
                return 0; // Invalid move for pawn
            }
            break;
        case 'r':
        case 'R':
            if (from_x == to_x) {
                for (int i = from_y + 1; i < to_y; i++) {
                    if (cb->board[i][from_x] != ' ') {
                        return 0; // Path blocked
                    }
                }
                return 1; // Move vertically
            } else if (from_y == to_y) {
                for (int i = from_x + 1; i < to_x; i++) {
                    if (cb->board[from_y][i] != ' ') {
                        return 0; // Path blocked
                    }
                }
                return 1; // Move horizontally
            } else {
                return 0; // Invalid move for rook
            }
            break;
        case 'n':
        case 'N':
            if ((abs(from_x - to_x) == 2 && abs(from_y - to_y) == 1) ||
                (abs(from_x - to_x) == 1 && abs(from_y - to_y) == 2)) {
                return 1; // Move in L shape
            } else {
                return 0; // Invalid move for knight
            }
            break;
        case 'b':
        case 'B':
            if (abs(from_x - to_x) == abs(from_y - to_y)) {
                int dx = (from_x < to_x) ? 1 : -1; // Determine direction
                int dy = (from_y < to_y) ? 1 : -1;
                
                for (int i = from_x+dx, j = from_y+dy;
                     i != to_x && j != to_y; i+=dx, j+=dy) {
                    if (cb->board[j][i] != ' ') {
                        return 0; // Path blocked
                    }
                }
                return 1; // Move diagonally
            } else {
                return 0; // Invalid move for bishop
            }
            break;
        case 'q':
        case 'Q':
            if (from_x == to_x) {
                for (int i = from_y + 1; i < to_y; i++) {
                    if (cb->board[i][from_x] != ' ') {
                        return 0; // Path blocked
                    }
                }
                return 1; // Move vertically
            } else if (from_y == to_y) {
                for (int i = from_x + 1; i < to_x; i++) {
                    if (cb->board[from_y][i] != ' ') {
                        return 0; // Path blocked
                    }
                }
                return 1; // Move horizontally
            } else if (abs(from_x - to_x) == abs(from_y - to_y)) {
                int dx = (from_x < to_x) ? 1 : -1; // Determine direction
                int dy = (from_y < to_y) ? 1 : -1;
                
                for (int i = from_x+dx, j = from_y+dy;
                     i != to_x && j != to_y; i+=dx, j+=dy) {
                    if (cb->board[j][i] != ' ') {
                        return 0; // Path blocked
                    }
                }
                return 1; // Move diagonally
            } else {
                return 0; // Invalid move for queen
            }
            break;
        case 'k':
        case 'K':
            if ((abs(from_x - to_x) == 1 && abs(from_y - to_y) == 0) ||
                (abs(from_x - to_x) == 0 && abs(from_y - to_y) == 1) ||
                (abs(from_x - to_x) == 1 && abs(from_y - to_y) == 1)) {
                return 1; // Move one step in any direction
            } else {
                return 0; // Invalid move for king
            }
            break;
        default:
            return 0; // Invalid piece type
    }
}

// Make a move on the given chessboard
void make_move(Chessboard *cb, char *from, char *to) {
    int from_x = from[0] - 'a';
    int from_y = from[1] - '1';
    int to_x = to[0] - 'a';
    int to_y = to[1] - '1';
    char piece = cb->board[from_y][from_x];
    
    cb->board[to_y][to_x] = piece;
    cb->board[from_y][from_x] = ' ';
}

// Undo a move on the given chessboard
void undo_move(Chessboard *cb, char *from, char *to, char captured) {
    int from_x = from[0] - 'a';
    int from_y = from[1] - '1';
    int to_x = to[0] - 'a';
    int to_y = to[1] - '1';
    char piece = cb->board[to_y][to_x];
    
    cb->board[from_y][from_x] = piece;
    cb->board[to_y][to_x] = captured;
}

// Check if the current player is in check
int is_in_check(Chessboard *cb, char player) {
    // Determine position of player's king
    int kx, ky;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (cb->board[i][j] == (player == 'w' ? 'k' : 'K')) {
                kx = j;
                ky = i;
                break;
            }
        }
    }
    
    // Check if any of the opponent's pieces can capture the king
    char opponent = (player == 'w' ? 'b' : 'w');
    char captured;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (cb->board[i][j] != ' ' && cb->board[i][j] != player) {
                char from[3] = {(char)(j+'a'), (char)(i+'1'), '\0'};
                char to[3] = {(char)(kx+'a'), (char)(ky+'1'), '\0'};
                if (is_valid_move(cb, from, to)) {
                    // Temporarily make the move to see if it puts the king in check
                    captured = cb->board[ky][kx];
                    make_move(cb, from, to);
                    int in_check = is_in_check(cb, player);
                    undo_move(cb, from, to, captured);
                    if (!in_check) {
                        return 0;
                    }
                }
            }
        }
    }
    
    return 1;
}

// Evaluate the current chessboard state for the given player
int evaluate(Chessboard *cb, char player) {
    int value = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char piece = cb->board[i][j];
            if (piece != ' ') {
                if (piece == player || (piece >= 'a' && piece <= 'z' && player == 'b') ||
                    (piece >= 'A' && piece <= 'Z' && player == 'w')) {
                    switch (piece) {
                        case 'p':
                            value += 1;
                            break;
                        case 'P':
                            value -= 1;
                            break;
                        case 'n':
                        case 'N':
                            value += 3;
                            break;
                        case 'b':
                        case 'B':
                            value += 3;
                            break;
                        case 'r':
                        case 'R':
                            value += 5;
                            break;
                        case 'q':
                        case 'Q':
                            value += 9;
                            break;
                        default:
                            break;
                    }
                } else {
                    switch (piece) {
                        case 'p':
                            value -= 1;
                            break;
                        case 'P':
                            value += 1;
                            break;
                        case 'n':
                        case 'N':
                            value -= 3;
                            break;
                        case 'b':
                        case 'B':
                            value -= 3;
                            break;
                        case 'r':
                        case 'R':
                            value -= 5;
                            break;
                        case 'q':
                        case 'Q':
                            value -= 9;
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    return value;
}

// The AI function that chooses the best move for the given player
int ai_move(Chessboard *cb, int depth, char player, char *best_move, int alpha, int beta) {
    if (depth == 0) {
        return evaluate(cb, player);
    }
    
    char move[6];
    int value;
    int best = (player == 'w' ? -9999 : 9999);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (cb->board[i][j] != ' ' && cb->board[i][j] != (player == 'w' ? 'b' : 'w')) {
                char from[3] = {(char)(j+'a'), (char)(i+'1'), '\0'};
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        char to[3] = {(char)(l+'a'), (char)(k+'1'), '\0'};
                        if (is_valid_move(cb, from, to)) {
                            char captured = cb->board[k][l];
                            make_move(cb, from, to);
                            value = ai_move(cb, depth-1, player, NULL, alpha, beta);
                            undo_move(cb, from, to, captured);
                            
                            if (player == 'w') {
                                if (value > best) {
                                    best = value;
                                    sprintf(best_move, "%s-%s", from, to);
                                }
                                alpha = (best > alpha) ? best : alpha;
                            } else {
                                if (value < best) {
                                    best = value;
                                    sprintf(best_move, "%s-%s", from, to);
                                }
                                beta = (best < beta) ? best : beta;
                            }
                            
                            if (beta <= alpha) {
                                return best;
                            }
                        }
                    }
                }
            }
        }
    }
    return best;
}

int main() {
    Chessboard cb;
    init_board(&cb);
    print_board(&cb);
    
    char from[3];
    char to[3];
    char best_move[6];
    int value;
    
    while (1) {
        printf("Enter move (e.g. a2-a4): ");
        scanf("%s-%s", from, to);
        while (!is_valid_move(&cb, from, to)) {
            printf("Invalid move. Enter move (e.g. a2-a4): ");
            scanf("%s-%s", from, to);
        }
        make_move(&cb, from, to);
        if (is_in_check(&cb, 'b')) {
            printf("Black is in check.\n");
        }
        print_board(&cb);
        
        if (is_in_check(&cb, 'w')) {
            printf("Checkmate! Black wins.\n");
            break;
        }
        
        printf("AI thinking...\n");
        value = ai_move(&cb, MAX_DEPTH, 'w', best_move, -9999, 9999);
        printf("AI move: %s (%d)\n", best_move, value);
        make_move(&cb, best_move, best_move+3);
        if (is_in_check(&cb, 'w')) {
            printf("White is in check.\n");
        }
        print_board(&cb);
        
        if (is_in_check(&cb, 'b')) {
            printf("Checkmate! White wins.\n");
            break;
        }
    }
    return 0;
}