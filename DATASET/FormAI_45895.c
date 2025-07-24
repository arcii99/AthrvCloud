//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define ROWS 20
#define COLS 15

// Global variables
int bricks[ROWS][COLS]; // 2D array to hold the bricks
int score = 0; // Global variable to hold the score
int lives = 3; // Global variable to hold the lives
int gameover = 0; // Global variable to hold the gameover state
int ball_position_x = 7, ball_position_y = 7; // Ball position
int board_position = 6; // Board position
int direction_x = 1, direction_y = -1; // Ball movement direction

// Function to initialize the bricks
void init_bricks()
{
    // Set all bricks to 1
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bricks[i][j] = 1;
        }
    }
}

// Function to draw the board
void draw_board()
{
    printf("\033[2J"); // Clear the console
    printf("\033[%d;%dH", 22, board_position-2); // Move cursor to board position
    printf("==========\n"); // Draw board
    printf("\033[%d;%dH", 23, board_position-2);
    printf("==========\n"); // Draw board
}

// Function to draw the ball
void draw_ball()
{
    printf("\033[%d;%dH", ball_position_x, ball_position_y); // Move cursor to ball position
    printf("O\n"); // Draw ball
}

// Function to check if a collision has occured and update direction
void check_collision()
{
    // Collision with board
    if (ball_position_x == 22 && ball_position_y >= board_position-2 && ball_position_y <= board_position+2) {
        direction_y = -1; // Reverse vertical direction
        score++; // Increase score
    }
    
    // Collision with bricks
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bricks[i][j] == 1) {
                int brick_x = i+2;
                int brick_y = j*5+2;
                if (ball_position_x == brick_x && ball_position_y >= brick_y && ball_position_y <= brick_y+4) {
                    direction_y = 1; // Reverse vertical direction
                    bricks[i][j] = 0; // Mark brick as destroyed
                    score += 10; // Increase score
                }
            }
        }
    }
    
    // Collision with walls
    if (ball_position_x == 1) {
        direction_y = 1; // Reverse vertical direction
    }
    if (ball_position_y == 1 || ball_position_y == 75) {
        direction_x = -direction_x; // Reverse horizontal direction
    }
}

// Function to update ball position
void update_ball_position()
{
    ball_position_x += direction_x; // Update horizontal position
    ball_position_y += direction_y; // Update vertical position
}

// Function to draw the bricks
void draw_bricks()
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bricks[i][j] == 1) {
                int brick_x = i+2;
                int brick_y = j*5+2;
                printf("\033[%d;%dH", brick_x, brick_y);
                printf("====="); // Draw brick
            }
        }
    }
}

// Function to draw scores and lives
void draw_scores_and_lives()
{
    printf("\033[%d;%dH", 1, 1);
    printf("Score: %d", score); // Draw score
    printf("\033[%d;%dH", 1, 75);
    printf("Lives: %d", lives); // Draw lives
}

// Function to update lives and gameover state
void check_lives()
{
    if (ball_position_x == 23) {
        lives--;
        if (lives == 0) {
            gameover = 1;
        }
        else {
            ball_position_x = 7;
            ball_position_y = 7;
            direction_x = 1;
            direction_y = -1;
        }
    }
}

// Function to create a delay
void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

// Main function
int main()
{
    init_bricks(); // Initialize bricks
    draw_board(); // Draw board
    draw_ball(); // Draw ball
    draw_bricks(); // Draw bricks
    draw_scores_and_lives(); // Draw scores and lives
    
    while (!gameover) { // While game is not over
        check_collision(); // Check for collisions
        update_ball_position(); // Update ball position
        check_lives(); // Check lives
        
        draw_board(); // Draw board        
        draw_bricks(); // Draw bricks
        draw_ball(); // Draw ball
        draw_scores_and_lives(); // Draw scores and lives
        
        delay(50); // Delay
    }
    
    printf("\033[2J"); // Clear the console
    printf("\033[%d;%dH", 12, 30);
    printf("GAME OVER\n"); // Print game over message
    printf("\033[%d;%dH", 13, 30);
    printf("SCORE: %d\n", score); // Print final score
    
    return 0;
}