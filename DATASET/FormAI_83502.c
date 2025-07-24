//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// Constants for game grid
#define ROWS 25
#define COLS 60
#define BALL_CHAR 'O'
#define PADDLE_CHAR '='
#define WALL_CHAR '|'
#define BRICK_CHAR '#'

// Constants for ball and paddle movement
#define DEFAULT_X_SPEED 1
#define DEFAULT_Y_SPEED -1
#define PADDLE_SPEED 2

// Global variables
char grid[ROWS][COLS]; // This is the game grid
int paddle_pos = COLS/2 - 2; // Starting position of paddle
int ball_x, ball_y; // Current position of ball
int x_speed = DEFAULT_X_SPEED; // X-direction of ball movement
int y_speed = DEFAULT_Y_SPEED; // Y-direction of ball movement
int is_running = 1; // Flag to keep game running
int score = 0; // Player's score

// Function to read a character from keyboard without blocking
char getkey() {
    struct termios oldt, newt;
    char ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    while(1) {
        ch = getchar();
        if(ch != EOF) {
            break;
        }
        usleep(1000);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    return ch;
}

// Function to update position of ball every frame
void* ball_thread(void* arg) {
    while(is_running) {
        // Update ball position
        ball_x += x_speed;
        ball_y += y_speed;

        // Check for collision with walls
        if(ball_x <= 0 || ball_x >= COLS - 1) {
            x_speed = -x_speed;
        }
        if(ball_y <= 0) {
            y_speed = -y_speed;
        }

        // Check for collision with paddle or bricks
        if(ball_y == ROWS - 2) {
            if(ball_x >= paddle_pos && ball_x <= paddle_pos + 3) {
                y_speed = -y_speed;
                score += 10;
            } else if(grid[ball_y][ball_x] == BRICK_CHAR) {
                y_speed = -y_speed;
                grid[ball_y][ball_x] = ' ';
                score += 20;
            }
        }

        // Check for game over
        if(ball_y >= ROWS - 1) {
            is_running = 0;
        }

        usleep(50000); // Wait for 50ms before next update
    }
    pthread_exit(NULL);
}

// Function to update position of paddle based on user input
void* paddle_thread(void* arg) {
    while(is_running) {
        char key = getkey(); // Read input from keyboard
        if(key == 'a' && paddle_pos > 0) {
            paddle_pos -= PADDLE_SPEED;
        } else if(key == 'd' && paddle_pos < COLS - 4) {
            paddle_pos += PADDLE_SPEED;
        }
        usleep(10000); // Wait for 10ms before next update
    }
    pthread_exit(NULL);
}

// Function to initialize game grid with walls and bricks
void init_grid() {
    // Fill grid with empty spaces
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            grid[i][j] = ' ';
        }
    }

    // Create left and right walls
    for(int i = 0; i < ROWS; ++i) {
        grid[i][0] = WALL_CHAR;
        grid[i][COLS - 1] = WALL_CHAR;
    }

    // Create top wall
    for(int i = 0; i < COLS; ++i) {
        grid[0][i] = WALL_CHAR;
    }

    // Create bricks
    for(int i = 3; i <= 43; i += 10) {
        for(int j = 3; j <= 23; j += 5) {
            grid[j][i] = BRICK_CHAR;
        }
    }
}

// Function to print game grid to console
void print_grid() {
    system("clear"); // Clear console screen
    printf("Score: %d\n", score); // Display player's score

    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            if(i == ROWS - 1 && (j >= paddle_pos && j < paddle_pos + 4)) {
                putchar(PADDLE_CHAR);
            } else if(i == ball_y && j == ball_x) {
                putchar(BALL_CHAR);
            } else {
                putchar(grid[i][j]);
            }
        }
        putchar('\n');
    }
}

int main() {
    init_grid(); // Initialize game grid

    // Set starting position of ball
    ball_x = COLS/2;
    ball_y = ROWS/2;

    // Create threads for ball and paddle movement
    pthread_t ball_t, paddle_t;
    pthread_create(&ball_t, NULL, ball_thread, NULL);
    pthread_create(&paddle_t, NULL, paddle_thread, NULL);

    // Main game loop
    while(is_running) {
        print_grid(); // Display game grid
        usleep(50000); // Wait for 50ms before next frame
    }

    // Display game over message
    system("clear");
    printf("Game Over! Final score: %d\n", score);

    // Join threads and exit
    pthread_join(ball_t, NULL);
    pthread_join(paddle_t, NULL);
    return 0;
}