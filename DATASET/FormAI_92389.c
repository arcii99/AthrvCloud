//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 40
#define HEIGHT 20

void print_board(char board[HEIGHT][WIDTH]) {
    system("cls"); // Clear screen
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[HEIGHT][WIDTH]; // Game board
    
    // Initialize board with empty spaces
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
    
    // Initialize player position
    int player_x = WIDTH/2;
    int player_y = HEIGHT - 1;
    board[player_y][player_x] = '^';
    
    // Initialize enemy positions
    char enemy = '*';
    for (int i = 0; i < HEIGHT/2; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = enemy;
        }
    }
    
    // Game loop
    bool game_over = false;
    while (!game_over) {
        print_board(board);
        
        // Player movement
        char move = getchar();
        if (move == 'a' && player_x > 0) {
            board[player_y][player_x] = ' ';
            player_x--;
            board[player_y][player_x] = '^';
        }
        else if (move == 'd' && player_x < WIDTH-1) {
            board[player_y][player_x] = ' ';
            player_x++;
            board[player_y][player_x] = '^';
        }
        else if (move == 'q') {
            game_over = true;
        }
        
        // Enemy movement
        for (int i = 0; i < HEIGHT/2; i++) {
            bool move_left = true;
            for (int j = 0; j < WIDTH; j++) {
                if (board[i][j] == enemy) {
                    board[i][j] = ' ';
                    if (move_left && j > 0) {
                        board[i][j-1] = enemy;
                    }
                    else if (!move_left && j < WIDTH-1) {
                        board[i][j+1] = enemy;
                    }
                    else if (j == 0) {
                        move_left = false;
                        board[i+1][j] = enemy;
                    }
                    else if (j == WIDTH-1) {
                        move_left = true;
                        board[i+1][j] = enemy;
                    }
                }
            }
        }
        
        // Check for collision
        for (int i = 0; i < HEIGHT/2; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (board[i][j] == enemy && i+1 == player_y && j == player_x) {
                    game_over = true;
                }
            }
        }
    }
    
    printf("Game Over\n");
    return 0;
}