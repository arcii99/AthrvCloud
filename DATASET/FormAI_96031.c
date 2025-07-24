//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: automated
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_ROWS 20
#define SCREEN_COLS 30

// Paddle - the player controlled object
typedef struct {
    int row;      // the y position of the top of the paddle
    int col;      // the x position of the left side of the paddle
    int length;   // the length of the paddle in characters
} Paddle;

// Ball - the object that bounces around the screen
typedef struct {
    int row;      // the y position of the ball
    int col;      // the x position of the ball
    int direction; // the direction of the ball, in degrees
    int speed;    // the speed of the ball, in characters per second
} Ball;

// Screen - the container for everything on the screen
typedef struct {
    Paddle paddle;     // the player controlled paddle
    Ball ball;         // the bouncing ball
    char screen[SCREEN_ROWS][SCREEN_COLS]; // the actual screen 
} Screen;

/**
 * Initialize the game screen with the paddle and ball
 * @param screen The screen to initialize
 * @param paddle_length The length of the paddle
 */
void init_screen(Screen* screen, int paddle_length) {
    // initialize the paddle
    screen->paddle.row = SCREEN_ROWS-2;
    screen->paddle.col = SCREEN_COLS/2 - paddle_length/2;
    screen->paddle.length = paddle_length;
    
    // initialize the ball
    screen->ball.row = 5;
    screen->ball.col = 15;
    screen->ball.direction = 45;
    screen->ball.speed = 10;
    
    // initialize the screen with spaces
    for (int r = 0; r < SCREEN_ROWS; r++) {
        for (int c = 0; c < SCREEN_COLS; c++) {
            screen->screen[r][c] = ' ';
        }
    }
}

/**
 * Draw the paddle onto the screen
 * @param screen The screen to draw on
 */
void draw_paddle(Screen* screen) {
    for (int c = screen->paddle.col; c < screen->paddle.col+screen->paddle.length; c++) {
        screen->screen[screen->paddle.row][c] = '=';
    }
}

/**
 * Draw the ball onto the screen
 * @param screen The screen to draw on
 */
void draw_ball(Screen* screen) {
    screen->screen[screen->ball.row][screen->ball.col] = 'O';
}

/**
 * Update the position of the ball based on its direction and speed
 * @param screen The screen containing the ball
 */
void update_ball_position(Screen* screen) {
    // calculate the new position of the ball
    int new_row = screen->ball.row + screen->ball.speed * sin(screen->ball.direction * 3.14159 / 180);
    int new_col = screen->ball.col + screen->ball.speed * cos(screen->ball.direction * 3.14159 / 180);
    
    // check for collisions with the screen edges
    if (new_row < 0) {
        screen->ball.direction = 360 - screen->ball.direction;
        new_row = -new_row;
    }
    if (new_col < 0 || new_col >= SCREEN_COLS) {
        screen->ball.direction = (540 - screen->ball.direction) % 360;
        new_col = new_col < 0 ? -new_col : 2*SCREEN_COLS - new_col - 2;
    }
    
    // check for collisions with the paddle
    for (int c = screen->paddle.col; c < screen->paddle.col+screen->paddle.length; c++) {
        if (new_row == screen->paddle.row-1 && new_col == c) {
            screen->ball.direction = 360 - screen->ball.direction;
            new_row -= 2;
        }
    }
    
    // update the position of the ball
    screen->ball.row = new_row;
    screen->ball.col = new_col;
}

/**
 * Move the paddle to the left by one character
 * @param screen The screen containing the paddle
 */
void move_paddle_left(Screen* screen) {
    if (screen->paddle.col > 0) {
        screen->paddle.col--;
    }
}

/**
 * Move the paddle to the right by one character
 * @param screen The screen containing the paddle
 */
void move_paddle_right(Screen* screen) {
    if (screen->paddle.col + screen->paddle.length < SCREEN_COLS) {
        screen->paddle.col++;
    }
}

/**
 * Update the position of the AI paddle based the movement of the ball
 * @param screen The screen containing the paddle
 */
void update_ai_paddle(Screen* screen) {
    int ball_col = screen->ball.col;
    int paddle_center = screen->paddle.col + screen->paddle.length / 2;
    
    if (ball_col < paddle_center && screen->paddle.col > 0) {
        move_paddle_left(screen);
    }
    else if (ball_col > paddle_center && screen->paddle.col + screen->paddle.length < SCREEN_COLS) {
        move_paddle_right(screen);
    }
}

/**
 * Draw the screen
 * @param screen The screen to draw
 */
void draw_screen(Screen* screen) {
    // clear the screen
    system("clear");
    
    // draw the paddle and ball
    draw_ball(screen);
    draw_paddle(screen);
    
    // draw the screen
    for (int r = 0; r < SCREEN_ROWS; r++) {
        for (int c = 0; c < SCREEN_COLS; c++) {
            printf("%c", screen->screen[r][c]);
        }
        printf("\n");
    }
}

/**
 * Check if the ball has hit the bottom of the screen
 * @param screen The screen containing the ball
 * @return Whether the ball has hit the bottom of the screen
 */
bool is_game_over(Screen* screen) {
    return screen->ball.row >= SCREEN_ROWS - 1;
}

int main() {
    Screen screen;
    int paddle_length = 7;
    init_screen(&screen, paddle_length);
    
    srand(time(NULL));
    
    while (!is_game_over(&screen)) {
        // update the ball's position
        update_ball_position(&screen);
        
        // update the AI paddle's position
        update_ai_paddle(&screen);
        
        // draw the screen
        draw_screen(&screen);
        
        // wait for a bit to control game speed
        usleep(100000);
    }
    
    printf("Game Over!\n");
    
    return 0;
}