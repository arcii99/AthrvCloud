//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define WIDTH 10
#define HEIGHT 10

// Function declarations
void init_board(char board[][WIDTH], int width, int height);
void draw_board(char board[][WIDTH], int width, int height);
void update_board(char board[][WIDTH], int width, int height, int x, int y);
int getch();
void handle_input(char board[][WIDTH], int width, int height, int *x, int *y);

int main() {

    // Initialize board
    char board[HEIGHT][WIDTH];
    init_board(board, WIDTH, HEIGHT);

    // Initialize Pac-Man position
    int x = WIDTH/2;
    int y = HEIGHT/2;

    // Game loop
    while (1) {

        // Clear the terminal
        printf("\033[2J\033[1;1H");

        // Handle input
        handle_input(board, WIDTH, HEIGHT, &x, &y);

        // Update the board with the new position
        update_board(board, WIDTH, HEIGHT, x, y);

        // Draw the board
        draw_board(board, WIDTH, HEIGHT);

        // Sleep for a short time
        usleep(100000);
    }

    return 0;
}

// Initialize board with walls and dots
void init_board(char board[][WIDTH], int width, int height) {

    // Add walls to edges of board
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (i == 0 || i == height-1 || j == 0 || j == width-1) {
                board[i][j] = '#';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    // Add dots to board
    for (int i=1; i<height-1; i++) {
        for (int j=1; j<width-1; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                board[i][j] = '.';
            }
        }
    }

    // Add Pac-Man to board
    board[height/2][width/2] = 'C';
}

// Draw board to terminal
void draw_board(char board[][WIDTH], int width, int height) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Update board with new Pac-Man position
void update_board(char board[][WIDTH], int width, int height, int x, int y) {

    // Remove Pac-Man from old position
    board[y][x] = ' ';

    // Update Pac-Man's position
    board[y][x+1] = 'C';

    // Check if Pac-Man has eaten a dot
    if (board[y][x+2] == '.') {
        board[y][x+2] = ' ';
    }
}

// Get single character input from user
int getch() {
    struct termios old_tio, new_tio;
    int ch;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    return ch;
}

// Handle user input
void handle_input(char board[][WIDTH], int width, int height, int *x, int *y) {
    int input = getch();
    switch (input) {
        case 'w':
            if (*y > 1) {
                *y -= 1;
            }
            break;
        case 'a':
            if (*x > 1) {
                *x -= 1;
            }
            break;
        case 's':
            if (*y < height-2) {
                *y += 1;
            }
            break;
        case 'd':
            if (*x < width-3) {
                *x += 1;
            }
            break;
    }
}