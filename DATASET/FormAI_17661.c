//FormAI DATASET v1.0 Category: Chess engine ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE] = {
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1, 0, 1,-1,-1,-1},
    {-1,-1,-1, 1, 0,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1}
};

int current_player = 1;

bool valid_move(int x1, int y1, int x2, int y2) {
    // Check if move is within the board
    if (x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
        return false;
    }
    
    // Check if move is valid based on player's current position
    if (board[x1][y1] != current_player) {
        return false;
    }
    
    // Check if move is empty
    if (board[x2][y2] != -1) {
        return false;
    }
    
    // Check if move is adjacent to opponent's piece
    bool adjacent_to_opponent = false;
    int i, j;
    int xdiff = abs(x1 - x2);
    int ydiff = abs(y1 - y2);
    
    if (xdiff <= 1 && ydiff <= 1) {
        return true;
    }
    
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            int x = x2+i;
            int y = y2+j;
            if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
                if (board[x][y] == 1 - current_player) {
                    adjacent_to_opponent = true;
                    
                    // Check if a line is formed from (x1,y1) to (x,y)
                    while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE &&
                           board[x][y] == 1 - current_player) {
                        x += i;
                        y += j;
                    }
                    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE &&
                        board[x][y] == current_player) {
                        return true;
                    }
                }
            }
        }
    }
    
    return adjacent_to_opponent;
}

void apply_move(int x1, int y1, int x2, int y2) {
    // Make move
    board[x2][y2] = current_player;
    board[x1][y1] = -1;
    
    // Flip opponent's pieces as necessary
    int i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            int x = x2+i;
            int y = y2+j;
            if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
                if (board[x][y] == 1 - current_player) {
                    // Check if a line is formed from (x1,y1) to (x,y)
                    bool valid_line = false;
                    int cx = x+i;
                    int cy = y+j;
                    while (cx >= 0 && cx < BOARD_SIZE && cy >= 0 && cy < BOARD_SIZE &&
                           board[cx][cy] == 1 - current_player) {
                        cx += i;
                        cy += j;
                    }
                    if (cx >= 0 && cx < BOARD_SIZE && cy >= 0 && cy < BOARD_SIZE &&
                        board[cx][cy] == current_player) {
                        valid_line = true;
                    }
                    
                    if (valid_line) {
                        cx = x+i;
                        cy = y+j;
                        while (cx >= 0 && cx < BOARD_SIZE && cy >= 0 && cy < BOARD_SIZE &&
                               board[cx][cy] == 1 - current_player) {
                            board[cx][cy] = current_player;
                            cx += i;
                            cy += j;
                        }
                    }
                }
            }
        }
    }
}

int count_tiles(int player) {
    int count = 0;
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                count++;
            }
        }
    }
    return count;
}

void print_board() {
    printf("  0 1 2 3 4 5 6 7\n");
    printf("-----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|",i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1) {
                printf(" |");
            } else if (board[i][j] == 0) {
                printf("O|");
            } else {
                printf("X|");
            }
        }
        printf("%d\n",i);
    }
    printf("-----------------\n");
    printf("  0 1 2 3 4 5 6 7\n");
}

void play_game() {
    int x1, y1, x2, y2;
    bool valid;
    
    while (true) {
        print_board();
        printf("Player %d's turn\n", current_player);
        printf("Enter move in format x1 y1 x2 y2: ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        valid = valid_move(x1,y1,x2,y2);
        if (valid) {
            apply_move(x1,y1,x2,y2);
            int p1_tiles = count_tiles(0);
            int p2_tiles = count_tiles(1);
            if (p1_tiles == 0 || p2_tiles == 0) {
                break;
            }
            current_player = 1 - current_player;
        } else {
            printf("Invalid move, try again.\n");
        }
    }
    
    print_board();
    int p1_tiles = count_tiles(0);
    int p2_tiles = count_tiles(1);
    if (p1_tiles > p2_tiles) {
        printf("Player 0 wins!\n");
    } else if (p2_tiles > p1_tiles) {
        printf("Player 1 wins!\n");
    } else {
        printf("Tie game!\n");
    }
}

int main() {
    printf("Welcome to my Othello game!\n");
    play_game();
    return 0;
}