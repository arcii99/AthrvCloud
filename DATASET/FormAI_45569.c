//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define WIDTH 80
#define HEIGHT 24
#define BRICK_ROWS 4
#define BRICK_COLS 15
#define PADDLE_WIDTH 5
#define BALL_INIT_POS_X (WIDTH / 2)
#define BALL_INIT_POS_Y (HEIGHT - 2)
#define BALL_INIT_VEL_X 1
#define BALL_INIT_VEL_Y -1
#define MAX_LEVEL 3
#define GAME_SPEED 80000

// Define some escape sequence constants to use for color
#define ANSI_BLACK "\033[0;30m"
#define ANSI_RED "\033[0;31m"
#define ANSI_GREEN "\033[0;32m"
#define ANSI_YELLOW "\033[0;33m"
#define ANSI_BLUE "\033[0;34m"
#define ANSI_MAGENTA "\033[0;35m"
#define ANSI_CYAN "\033[0;36m"
#define ANSI_WHITE "\033[0;37m"
#define ANSI_DEFAULT "\033[0;0m"

// Define the brick and ball structs
typedef struct {
    bool destroyed;
    char color[10];
} Brick;

typedef struct {
    int pos_x, pos_y;
    int vel_x, vel_y;
    char color[10];
} Ball;

// Define the paddle with its width, height, position, and color
typedef struct {
    int width, height;
    int pos_x, pos_y;
    char color[10];
} Paddle;

// Clear the screen using an escape sequence
void clear_screen() {
    printf("\033[2J");
}

// Move the cursor to the specified row and column
void move_cursor(int row, int col) {
    printf("\033[%d;%df", row, col);
}

// Hide the cursor so it doesn't blink on the screen
void hide_cursor() {
    printf("\033[?25l");
}

// Restore the cursor so it's visible again after the game is over
void show_cursor() {
    printf("\033[?25h");
}

// Set a termios struct with some custom input settings
void custom_input() {
    struct termios new;
    tcgetattr(0, &new);
    new.c_lflag &= ~ICANON;
    new.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new);
}

// Reset the input settings once the game is over
void reset_input() {
    struct termios old;
    tcgetattr(0, &old);
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    tcsetattr(0, TCSANOW, &old);
}

// Initialize the bricks for the game
void init_bricks(Brick bricks[BRICK_ROWS][BRICK_COLS]) {
    int i, j;
    for (i = 0; i < BRICK_ROWS; i++) {
        for (j = 0; j < BRICK_COLS; j++) {
            bricks[i][j].destroyed = false;
            if (i == 0) {
                strcpy(bricks[i][j].color, ANSI_RED);
            } else if (i == 1) {
                strcpy(bricks[i][j].color, ANSI_YELLOW);
            } else if (i == 2) {
                strcpy(bricks[i][j].color, ANSI_BLUE);
            } else {
                strcpy(bricks[i][j].color, ANSI_GREEN);
            }
        }
    }
}

// Draw the bricks on the screen
void draw_bricks(Brick bricks[BRICK_ROWS][BRICK_COLS]) {
    int i, j, x, y;
    for (i = 0; i < BRICK_ROWS; i++) {
        y = i + 2;
        for (j = 0; j < BRICK_COLS; j++) {
            x = j * 5;
            if (!bricks[i][j].destroyed) {
                move_cursor(y, x+1);
                printf("%s=====%s", bricks[i][j].color, ANSI_DEFAULT);
                move_cursor(y+1, x+1);
                printf("%s=====%s", bricks[i][j].color, ANSI_DEFAULT);
            }
        }
    }
}

// Determine if the ball collided with a brick and destroy it
void check_brick_collision(Ball *ball, Brick bricks[BRICK_ROWS][BRICK_COLS]) {
    int i, j, x, y;
    for (i = 0; i < BRICK_ROWS; i++) {
        y = i + 2;
        for (j = 0; j < BRICK_COLS; j++) {
            x = j * 5;
            if (!bricks[i][j].destroyed && ball->pos_x >= x && ball->pos_x < x+5 && ball->pos_y == y+1) {
                ball->vel_y = -ball->vel_y;
                bricks[i][j].destroyed = true;
                move_cursor(y, x+1);
                printf("     ");
                move_cursor(y+1, x+1);
                printf("     ");
            }
        }
    }
}

// Initialize the ball with its position, velocity, and color
void init_ball(Ball *ball) {
    ball->pos_x = BALL_INIT_POS_X;
    ball->pos_y = BALL_INIT_POS_Y;
    ball->vel_x = BALL_INIT_VEL_X;
    ball->vel_y = BALL_INIT_VEL_Y;
    strcpy(ball->color, ANSI_CYAN);
}

// Draw the ball on the screen
void draw_ball(Ball *ball) {
    move_cursor(ball->pos_y, ball->pos_x);
    printf("%sO%s", ball->color, ANSI_DEFAULT);
}

// Determine if the ball collided with the paddle and bounce it
void check_paddle_collision(Ball *ball, Paddle *paddle) {
    if (ball->pos_y == paddle->pos_y-1 && ball->pos_x >= paddle->pos_x && ball->pos_x < paddle->pos_x+paddle->width) {
        ball->vel_y = -ball->vel_y;
    }
}

// Move the ball based on its velocity
void move_ball(Ball *ball) {
    ball->pos_x += ball->vel_x;
    ball->pos_y += ball->vel_y;

    // Bounce the ball off the walls
    if (ball->pos_x <= 0 || ball->pos_x >= WIDTH-1) {
        ball->vel_x = -ball->vel_x;
    }
    if (ball->pos_y <= 0) {
        ball->vel_y = -ball->vel_y;
    }
}

// Initialize the paddle with its position, width, height, and color
void init_paddle(Paddle *paddle) {
    paddle->width = PADDLE_WIDTH;
    paddle->height = 1;
    paddle->pos_x = WIDTH / 2 - paddle->width / 2;
    paddle->pos_y = HEIGHT - 2;
    strcpy(paddle->color, ANSI_MAGENTA);
}

// Draw the paddle on the screen
void draw_paddle(Paddle *paddle) {
    int i, j;
    for (i = 0; i < paddle->height; i++) {
        move_cursor(paddle->pos_y+i, paddle->pos_x);
        for (j = 0; j < paddle->width; j++) {
            printf("%s=%s", paddle->color, ANSI_DEFAULT);
        }
    }
}

// Move the paddle based on user input
void move_paddle(Paddle *paddle, int input) {
    if (input == 'a' && paddle->pos_x > 0) {
        paddle->pos_x--;
    }
    if (input == 'd' && paddle->pos_x < WIDTH-paddle->width) {
        paddle->pos_x++;
    }
}

// Check if the ball hit the bottom of the screen and end the game if it did
bool check_game_over(Ball *ball) {
    if (ball->pos_y >= HEIGHT-1) {
        return true;
    } else {
        return false;
    }
}

// Print the game over screen and ask the user if they want to play again
bool game_over_screen(int level) {
    move_cursor(HEIGHT/2-2, WIDTH/2-12);
    printf(" --------- GAME OVER ---------");
    move_cursor(HEIGHT/2, WIDTH/2-10);
    printf(" You made it to level %d", level);
    move_cursor(HEIGHT/2+2, WIDTH/2-14);
    printf(" Press 'y' if you want to play again");

    int input = getchar();
    while (input != 'y' && input != 'q') {
        input = getchar();
    }
    if (input == 'y') {
        return true;
    } else {
        return false;
    }
}

// Print the screen for the next level
void next_level_screen(int level) {
    move_cursor(HEIGHT/2, WIDTH/2-18);
    printf(" --------- CONGRATS, LEVEL %d COMPLETE! ---------", level);
    move_cursor(HEIGHT/2+2, WIDTH/2-15);
    printf(" Press any key to move on to the next level");

    getchar();
}

int main() {
    srand(time(NULL));

    // Initialize the game variables and input settings
    Brick bricks[BRICK_ROWS][BRICK_COLS];
    Ball ball;
    Paddle paddle;
    int level = 1;
    bool game_over = false;
    custom_input();

    // Main game loop
    while (1) {
        // Initialize the current level
        init_bricks(bricks);
        init_ball(&ball);
        init_paddle(&paddle);

        // Play the current level
        while (1) {
            clear_screen();
            hide_cursor();

            // Draw the game objects on the screen
            draw_bricks(bricks);
            draw_ball(&ball);
            draw_paddle(&paddle);
            
            // Check for collisions and move the objects
            check_brick_collision(&ball, bricks);
            check_paddle_collision(&ball, &paddle);
            move_ball(&ball);

            // Check for user input and move the paddle
            int input = getchar();
            if (input == 'q') {
                game_over = true;
                break;
            }
            move_paddle(&paddle, input);

            // End the game if the ball hits the bottom
            if (check_game_over(&ball)) {
                break;
            }

            // Move to the next level if all the bricks are destroyed
            bool bricks_remaining = false;
            int i, j;
            for (i = 0; i < BRICK_ROWS; i++) {
                for (j = 0; j < BRICK_COLS; j++) {
                    if (!bricks[i][j].destroyed) {
                        bricks_remaining = true;
                    }
                }
            }
            if (!bricks_remaining) {
                if (level == MAX_LEVEL) {
                    game_over = true;
                    break;
                } else {
                    next_level_screen(level);
                    level++;
                    break;
                }
            }

            // Wait for some time before refreshing the screen
            usleep(GAME_SPEED);
        }

        // Show the game over screen and exit or play again
        if (game_over_screen(level)) {
            level = 1;
        } else {
            break;
        }
    }

    // Clear the screen, restore input settings, and show the cursor
    clear_screen();
    reset_input();
    show_cursor();

    return 0;
}