//FormAI DATASET v1.0 Category: Checkers Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void initialize_board(char board[][BOARD_SIZE]);
void print_board(char board[][BOARD_SIZE]);
int move_piece(char board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y);
int is_valid_move(char board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y);
int is_valid_jump(char board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y);
int check_win(char board[][BOARD_SIZE]);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn = 0;
    
    initialize_board(board);
    
    while (check_win(board) == 0) {
        printf("Current board:\n");
        print_board(board);
        
        int from_x, from_y, to_x, to_y;
        printf("Player %d, enter piece to move (x, y): ", turn + 1);
        scanf("%d %d", &from_x, &from_y);
        printf("Player %d, enter destination (x, y): ", turn + 1);
        scanf("%d %d", &to_x, &to_y);
        
        if (move_piece(board, from_x, from_y, to_x, to_y)) {
            if (turn == 0) turn = 1;
            else turn = 0;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
    
    printf("Player %d wins!\n", check_win(board));
    
    return 0;
}

void initialize_board(char board[][BOARD_SIZE]) {
    // initialize all spaces to blank
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    
    // set initial pieces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i+j) % 2 == 0) board[i][j] = 'B';
        }
    }
    
    for (int i = 5; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i+j) % 2 == 0) board[i][j] = 'R';
        }
    }
}

void print_board(char board[][BOARD_SIZE]) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int move_piece(char board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y) {
    // check if move is valid
    if (!is_valid_move(board, from_x, from_y, to_x, to_y)) return 0;
    
    // move piece
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = ' ';
    
    // check if jump is possible
    if (abs(to_x - from_x) == 2 && abs(to_y - from_y) == 2) {
        int middle_x = (to_x + from_x) / 2;
        int middle_y = (to_y + from_y) / 2;
        
        // remove jumped piece
        board[middle_x][middle_y] = ' ';
    }
    
    return 1;
}

int is_valid_move(char board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y) {
    char piece = board[from_x][from_y];
    
    // check if piece is in bounds
    if (from_x < 0 || from_x >= BOARD_SIZE || from_y < 0 || from_y >= BOARD_SIZE || 
        to_x < 0 || to_x >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE) {
        return 0;
    }
    
    // check if destination is empty
    if (board[to_x][to_y] != ' ') return 0;
    
    // check if move is diagonal
    if (abs(to_x - from_x) != abs(to_y - from_y)) return 0;
    
    // check if regular move or jump
    if (abs(to_x - from_x) == 1) {
        // regular move
        if (piece == 'R' && to_x > from_x) return 0; // red can only move up
        if (piece == 'B' && to_x < from_x) return 0; // black can only move down
        
    } else if (abs(to_x - from_x) == 2) {
        // jump move
        if (!is_valid_jump(board, from_x, from_y, to_x, to_y)) return 0;
    } else {
        return 0;
    }
    
    return 1;
}

int is_valid_jump(char board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y) {
    // check if jumped piece is valid
    int middle_x = (to_x + from_x) / 2;
    int middle_y = (to_y + from_y) / 2;
    char middle_piece = board[middle_x][middle_y];
    if ((middle_piece == 'R' && board[from_x][from_y] != 'B') ||
        (middle_piece == 'B' && board[from_x][from_y] != 'R')) {
        return 0;
    }
    
    return 1;
}

int check_win(char board[][BOARD_SIZE]) {
    int red_count = 0;
    int black_count = 0;
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'R') red_count++;
            if (board[i][j] == 'B') black_count++;
        }
    }
    
    if (red_count == 0) return 2; // black wins
    if (black_count == 0) return 1; // red wins
    
    return 0; // game not over yet
}