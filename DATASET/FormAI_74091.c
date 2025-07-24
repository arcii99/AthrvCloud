//FormAI DATASET v1.0 Category: Checkers Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define BOARD_SIZE 8

// Data Structures
enum player {
    PLAYER_1 = 1,
    PLAYER_2 = 2
};

struct piece {
    enum player player;
    bool king;
};

// Globals
struct piece board[BOARD_SIZE][BOARD_SIZE];
enum player current_player = PLAYER_1;

// Function Prototypes
void print_board();
bool is_move_valid(int x1, int y1, int x2, int y2);
bool is_jump_valid(int x1, int y1, int x2, int y2);
bool check_king(int player, int x);
bool check_win();
void move_piece(int x1, int y1, int x2, int y2);

// Functions
int main() {
    // Initialize the board
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(i < 3 && (i+j)%2 != 0) {
                board[i][j].player = PLAYER_2;
                board[i][j].king = false;
            } else if(i > 4 && (i+j)%2 != 0) {
                board[i][j].player = PLAYER_1;
                board[i][j].king = false;
            } else {
                board[i][j].player = 0;
                board[i][j].king = false;
            }
        }
    }
    
    // Game loop
    while(!check_win()) {
        printf("Current player: %d\n", current_player);
        print_board();
        int x1, y1, x2, y2;
        printf("Enter move coordinates (x1,y1,x2,y2): ");
        scanf("%d,%d,%d,%d", &x1, &y1, &x2, &y2);
        
        if(is_move_valid(x1, y1, x2, y2)) {
            move_piece(x1, y1, x2, y2);
        } else {
            printf("Invalid move!\n");
            continue;
        }
        
        current_player = (current_player == PLAYER_1) ? PLAYER_2 : PLAYER_1;
    }
    
    printf("Player %d wins!\n", current_player);
    
    return 0;
}

void print_board() {
    printf("\n   0 1 2 3 4 5 6 7\n");
    printf("  -----------------\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d| ", i);
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j].player == PLAYER_1) {
                printf("O ");
            } else if(board[i][j].player == PLAYER_2) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("|\n");
    }
    printf("  -----------------\n");
}

bool is_move_valid(int x1, int y1, int x2, int y2) {
    // Check if move is within bounds of the board
    if(x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE ||
       x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
        return false;
    }
    
    // Check if move is diagonal and not more than 2 spaces away
    if(abs(x1 - x2) != abs(y1 - y2) || abs(x1 - x2) > 2) {
        return false;
    }
    
    // Check if destination square is already occupied
    if(board[x2][y2].player != 0) {
        return false;
    }
    
    // Check if player is moving their own piece
    if(board[x1][y1].player != current_player) {
        return false;
    }
    
    // Check if player is moving a king piece correctly
    if(board[x1][y1].king && abs(x1 - x2) == 1) {
        return false;
    }
    
    // Check if move is jumping over another piece
    if(abs(x1 - x2) == 2) {
        return is_jump_valid(x1, y1, x2, y2);
    }
    
    return true;
}

bool is_jump_valid(int x1, int y1, int x2, int y2) {
    int middle_x = (x1 + x2) / 2;
    int middle_y = (y1 + y2) / 2;
    
    // Check if jump is over an opponent's piece
    if(board[middle_x][middle_y].player == current_player ||
       board[middle_x][middle_y].player == 0) {
        return false;
    }
    
    return true;
}

bool check_king(int player, int x) {
    // Check if piece has reached the opposite end of the board
    if((player == PLAYER_1 && x == 0) || (player == PLAYER_2 && x == 7)) {
        return true;
    }
    
    return false;
}

bool check_win() {
    int count_p1 = 0, count_p2 = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j].player == PLAYER_1) {
                count_p1++;
            } else if(board[i][j].player == PLAYER_2) {
                count_p2++;
            }
        }
    }
    
    if(count_p1 == 0 || count_p2 == 0) {
        return true;
    }
    
    return false;
}

void move_piece(int x1, int y1, int x2, int y2) {
    // Move the piece
    board[x2][y2] = board[x1][y1];
    board[x2][y2].king = check_king(current_player, x2);
    board[x1][y1].player = 0;
    
    // Check if player can make another jump
    if(abs(x1 - x2) == 2) {
        printf("Jump successful! Enter next jump coordinates (x1,y1,x2,y2): ");
        int jump_x1, jump_y1, jump_x2, jump_y2;
        scanf("%d,%d,%d,%d", &jump_x1, &jump_y1, &jump_x2, &jump_y2);
        if(is_jump_valid(x2, y2, jump_x2, jump_y2) &&
           is_move_valid(jump_x1, jump_y1, jump_x2, jump_y2)) {
            move_piece(jump_x1, jump_y1, jump_x2, jump_y2);
        } else {
            printf("Invalid jump!\n");
        }
    }
}