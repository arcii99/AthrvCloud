//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: scalable
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Define the board size and the number of pellets
#define BOARD_HEIGHT 15
#define BOARD_WIDTH 20
#define NUM_PELLETS 5

// Define constants for game objects
#define EMPTY_SPACE ' '
#define WALL '|'
#define PELLET '.'
#define PACMAN 'C'
#define BLINKY 'B'

// Define struct for game objects
typedef struct object {
    int pos_x;
    int pos_y;
    char symbol;
} object;

// Define global variables for game objects
object board[BOARD_HEIGHT][BOARD_WIDTH];
object pacman;
object blinky;

// Define function to initialize the board
void initialize_board() {
    // Fill the board with empty spaces
    for(int i = 0; i < BOARD_HEIGHT; i++) {
        for(int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j].symbol = EMPTY_SPACE;
        }
    }
    
    // Fill the borders with walls
    for(int i = 0; i < BOARD_HEIGHT; i++) {
        board[i][0].symbol = WALL;
        board[i][BOARD_WIDTH-1].symbol = WALL;
    }
    for(int j = 0; j < BOARD_WIDTH; j++) {
        board[0][j].symbol = WALL;
        board[BOARD_HEIGHT-1][j].symbol = WALL;
    }
    
    // Place the pellets randomly
    for(int i = 0; i < NUM_PELLETS; i++) {
        int pellet_x = rand() % (BOARD_WIDTH-2) + 1;
        int pellet_y = rand() % (BOARD_HEIGHT-2) + 1;
        if(board[pellet_y][pellet_x].symbol == EMPTY_SPACE) {
            board[pellet_y][pellet_x].symbol = PELLET;
        } else {
            i--;
        }
    }
    
    // Place Pac-Man and Blinky
    pacman.pos_x = BOARD_WIDTH / 2;
    pacman.pos_y = BOARD_HEIGHT / 2;
    pacman.symbol = PACMAN;
    board[pacman.pos_y][pacman.pos_x].symbol = pacman.symbol;
    
    blinky.pos_x = pacman.pos_x + 5;
    blinky.pos_y = pacman.pos_y - 3;
    blinky.symbol = BLINKY;
    board[blinky.pos_y][blinky.pos_x].symbol = blinky.symbol;
}

// Define function to draw the board
void draw_board() {
    system("clear"); // Clear the console
    for(int i = 0; i < BOARD_HEIGHT; i++) {
        for(int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board[i][j].symbol);
        }
        printf("\n");
    }
}

// Define function to move Pac-Man
void move_pacman(char direction) {
    board[pacman.pos_y][pacman.pos_x].symbol = EMPTY_SPACE;
    
    switch(direction) {
        case 'W':
            if(board[pacman.pos_y-1][pacman.pos_x].symbol != WALL) {
                pacman.pos_y--;
            }
            break;
        case 'A':
            if(board[pacman.pos_y][pacman.pos_x-1].symbol != WALL) {
                pacman.pos_x--;
            }
            break;
        case 'S':
            if(board[pacman.pos_y+1][pacman.pos_x].symbol != WALL) {
                pacman.pos_y++;
            }
            break;
        case 'D':
            if(board[pacman.pos_y][pacman.pos_x+1].symbol != WALL) {
                pacman.pos_x++;
            }
            break;
    }
    
    if(board[pacman.pos_y][pacman.pos_x].symbol == PELLET) {
        board[pacman.pos_y][pacman.pos_x].symbol = EMPTY_SPACE;
    }
    
    board[pacman.pos_y][pacman.pos_x].symbol = PACMAN;
}

// Define function to move Blinky
void move_blinky() {
    int dx = pacman.pos_x - blinky.pos_x;
    int dy = pacman.pos_y - blinky.pos_y;
    
    char direction = 'N';
    
    if(dx > 0) {
        if(board[blinky.pos_y][blinky.pos_x+1].symbol != WALL) {
            direction = 'D';
        }
    } else if(dx < 0) {
        if(board[blinky.pos_y][blinky.pos_x-1].symbol != WALL) {
            direction = 'A';
        }
    } else if(dy > 0) {
        if(board[blinky.pos_y+1][blinky.pos_x].symbol != WALL) {
            direction = 'S';
        }
    } else if(dy < 0) {
        if(board[blinky.pos_y-1][blinky.pos_x].symbol != WALL) {
            direction = 'W';
        }
    }
    
    board[blinky.pos_y][blinky.pos_x].symbol = EMPTY_SPACE;
    
    if(direction != 'N') {
        switch(direction) {
            case 'W':
                blinky.pos_y--;
                break;
            case 'A':
                blinky.pos_x--;
                break;
            case 'S':
                blinky.pos_y++;
                break;
            case 'D':
                blinky.pos_x++;
                break;
        }
    }
    
    board[blinky.pos_y][blinky.pos_x].symbol = BLINKY;
}

// Define main function
int main() {
    initialize_board();
    draw_board();
    while(true) {
        char input = getchar();
        move_pacman(input);
        move_blinky();
        draw_board();
    }
    return 0; // End the program
}