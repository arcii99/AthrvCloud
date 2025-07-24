//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define BOARD_WIDTH 50
#define BOARD_HEIGHT 20
#define BALL_SYMBOL 'O'
#define PADDLE_SYMBOL '='
#define BRICK_SYMBOL '+'

// Initialize game board
void init_game_board(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int col = 0; col < BOARD_WIDTH; col++) {
            board[row][col] = ' ';
        }
    }
}

// Draw game board
void draw_game_board(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int col = 0; col < BOARD_WIDTH; col++) {
            putchar(board[row][col]);
        }
        putchar('\n');
    }
}

// Set ball position
void set_ball_position(char board[BOARD_HEIGHT][BOARD_WIDTH], int ball_position[2]) {
    board[ball_position[0]][ball_position[1]] = BALL_SYMBOL;
}

// Set paddle position
void set_paddle_position(char board[BOARD_HEIGHT][BOARD_WIDTH], int paddle_position) {
    for (int row = BOARD_HEIGHT - 1; row > BOARD_HEIGHT - 3; row--) {
        for (int col = paddle_position - 4; col <= paddle_position + 4; col++) {
            board[row][col] = PADDLE_SYMBOL;
        }
    }
}

// Update ball position
void update_ball_position(char board[BOARD_HEIGHT][BOARD_WIDTH], int ball_position[2], int ball_direction[2], int paddle_position) {
    int next_position[2] = {ball_position[0] + ball_direction[0], ball_position[1] + ball_direction[1]};
    
    // Check for collision with paddle
    if (next_position[0] == BOARD_HEIGHT - 3 && next_position[1] >= paddle_position - 4 && next_position[1] <= paddle_position + 4) {
        ball_direction[0] = -ball_direction[0];
    }
    
    // Check for collision with top wall
    if (next_position[0] == 0) {
        ball_direction[0] = -ball_direction[0];
    }
    
    // Check for collision with left or right wall
    if (next_position[1] == 0 || next_position[1] == BOARD_WIDTH - 1) {
        ball_direction[1] = -ball_direction[1];
    }
    
    // Check for collision with bricks
    if (next_position[0] < BOARD_HEIGHT - 3) {
        if (board[next_position[0]][next_position[1]] != ' ') {
            board[next_position[0]][next_position[1]] = ' ';
            ball_direction[0] = -ball_direction[0];
        }
    }
    
    // Clear current ball position and update ball position
    board[ball_position[0]][ball_position[1]] = ' ';
    ball_position[0] += ball_direction[0];
    ball_position[1] += ball_direction[1];
    set_ball_position(board, ball_position);
}

int main() {
    // Initialize game board and ball position
    char game_board[BOARD_HEIGHT][BOARD_WIDTH];
    init_game_board(game_board);
    int ball_position[2] = {3, BOARD_WIDTH / 2};
    int ball_direction[2] = {1, 1};
    set_ball_position(game_board, ball_position);
    
    // Set paddle position
    int paddle_position = BOARD_WIDTH / 2;
    set_paddle_position(game_board, paddle_position);
    
    // Draw game board
    draw_game_board(game_board);
    
    // Set up keyboard input
    struct termios old_term;
    tcgetattr(STDIN_FILENO, &old_term);
    struct termios new_term = old_term;
    new_term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
    
    // Run game loop
    while (1) {
        // Update ball position
        update_ball_position(game_board, ball_position, ball_direction, paddle_position);
        
        // Check for game over
        if (ball_position[0] == BOARD_HEIGHT - 1) {
            printf("\nGame over!\n");
            break;
        }
        
        // Draw game board
        printf("\033[2J\033[1;1H");
        draw_game_board(game_board);
        printf("Controls: A = left, D = right, Q = quit\n");
        
        // Get keyboard input
        char key;
        if (read(STDIN_FILENO, &key, 1) == -1) {
            continue;
        }
        
        // Update paddle position
        switch (key) {
            case 'a':
                if (paddle_position > 4) {
                    set_paddle_position(game_board, --paddle_position);
                }
                break;
            case 'd':
                if (paddle_position < BOARD_WIDTH - 5) {
                    set_paddle_position(game_board, ++paddle_position);
                }
                break;
            case 'q':
                printf("\nExiting game...\n");
                goto end;
            default:
                break;
        }
    }
    
    end:
    // Reset terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
    
    return 0;
}