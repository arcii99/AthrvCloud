//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROW 20
#define COL 20

// Initialize the game board
void init_board(char board[ROW][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(i==0 || i==ROW-1 || j==0 || j==COL-1) {
                board[i][j] = '#';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Print the game board
void print_board(char board[ROW][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Place the Pac-Man on the board
void place_pacman(char board[ROW][COL], int pacman_x, int pacman_y) {
    board[pacman_x][pacman_y] = '@';
}

// Move the Pac-Man on the board
void move_pacman(char board[ROW][COL], int curr_x, int curr_y, int new_x, int new_y) {
    board[curr_x][curr_y] = ' ';
    board[new_x][new_y] = '@';
}

// Place the ghosts on the board
void place_ghosts(char board[ROW][COL], int ghost_x[], int ghost_y[], int num_ghosts) {
    for(int i=0; i<num_ghosts; i++) {
        board[ghost_x[i]][ghost_y[i]] = 'G';
    }
}

// Move the ghosts on the board
void move_ghosts(char board[ROW][COL], int ghost_x[], int ghost_y[], int num_ghosts) {
    for(int i=0; i<num_ghosts; i++) {
        // Generate a random direction to move the ghost
        int rand_dir = rand() % 4;
        int new_x = ghost_x[i];
        int new_y = ghost_y[i];
        if(rand_dir == 0) {
            new_x++;
        } else if(rand_dir == 1) {
            new_x--;
        } else if(rand_dir == 2) {
            new_y++;
        } else if(rand_dir == 3) {
            new_y--;
        }
        if(board[new_x][new_y] == '#') {
            continue;
        }
        board[ghost_x[i]][ghost_y[i]] = ' ';
        ghost_x[i] = new_x;
        ghost_y[i] = new_y;
        board[ghost_x[i]][ghost_y[i]] = 'G';
    }
}

int main() {
    char board[ROW][COL];
    int pacman_x = ROW/2;
    int pacman_y = COL/2;
    int ghost_x[] = {1, ROW-2, ROW/2};
    int ghost_y[] = {COL/3, 2*COL/3, COL/2};
    int num_ghosts = 3;
    int score = 0;
    init_board(board);
    place_pacman(board, pacman_x, pacman_y);
    place_ghosts(board, ghost_x, ghost_y, num_ghosts);
    print_board(board);
    while(true) {
        // Move the Pac-Man
        char move;
        printf("Enter a move (w=up, s=down, a=left, d=right): ");
        scanf(" %c", &move);
        int curr_x = pacman_x;
        int curr_y = pacman_y;
        int new_x = pacman_x;
        int new_y = pacman_y;
        if(move == 'w') {
            new_x--;
        } else if(move == 's') {
            new_x++;
        } else if(move == 'a') {
            new_y--;
        } else if(move == 'd') {
            new_y++;
        }
        if(board[new_x][new_y] == '#') {
            continue;
        } else if(board[new_x][new_y] == 'G') {
            printf("You were caught by a ghost!\n");
            break;
        }
        move_pacman(board, curr_x, curr_y, new_x, new_y);
        pacman_x = new_x;
        pacman_y = new_y;
        print_board(board);
        // Move the ghosts
        move_ghosts(board, ghost_x, ghost_y, num_ghosts);
        print_board(board);
        // Increase the score if Pac-Man eats a dot
        if(board[pacman_x][pacman_y] == '.') {
            score += 10;
        }
        printf("Score: %d\n", score);
    }
    printf("Game over!\n");
    return 0;
}