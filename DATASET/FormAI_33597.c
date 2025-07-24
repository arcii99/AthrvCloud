//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/select.h>

#define ROWS 20
#define COLS 40

char screen[ROWS][COLS];
int paddle_x;
int ball_x, ball_y;
int vel_x, vel_y;
int score;

int kbhit(void)
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

void init_game()
{
    // Initialize the screen buffer
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            screen[i][j] = ' ';
        }
    }

    // Initialize the paddle
    paddle_x = COLS/2 - 3;
    for(int i=paddle_x; i<=paddle_x+6; i++) {
        screen[ROWS-1][i] = '=';
    }

    // Initialize the ball
    ball_x = COLS/2;
    ball_y = ROWS/2;
    screen[ball_y][ball_x] = '*';
    vel_x = 1;
    vel_y = -1;

    // Initialize the score
    score = 0;
}

void draw_screen()
{
    printf("\x1b[2J"); // Clear the screen

    printf("Score: %d\n", score);

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void move_ball()
{
    // Save the old ball position
    int old_x = ball_x;
    int old_y = ball_y;

    // Update the ball position
    ball_x += vel_x;
    ball_y += vel_y;

    // Check for collision with walls
    if(ball_x <= 0 || ball_x >= COLS-1) {
        vel_x = -vel_x;
    }

    if(ball_y <= 0) {
        vel_y = -vel_y;
    }

    if(ball_y >= ROWS-1) {
        // Ball hit the floor, Game Over!
        printf("Game Over!\n");
        exit(0);
    }

    // Check for collision with paddle
    if(ball_y == ROWS-2 && ball_x >= paddle_x && ball_x <= paddle_x + 6) {
        vel_y = -vel_y;
        score++;
    }

    // Erase the old ball position
    screen[old_y][old_x] = ' ';

    // Draw the new ball position
    screen[ball_y][ball_x] = '*';
}

void move_paddle()
{
    if(!kbhit())
        return;

    char c=getchar();

    if(c=='a' && paddle_x > 0) {
        // Move paddle to the left
        for(int i=paddle_x+6; i>=paddle_x; i--) {
            screen[ROWS-1][i] = ' ';
            screen[ROWS-1][i-1] = '=';
        }
        paddle_x--;
    }
    else if(c=='d' && paddle_x < COLS-7) {
        // Move paddle to the right
        for(int i=paddle_x; i<=paddle_x+6; i++) {
            screen[ROWS-1][i] = ' ';
            screen[ROWS-1][i+1] = '=';
        }
        paddle_x++;
    }
}

int main()
{
    // Set the random seed
    srand(time(NULL));

    // Set the terminal to non-canonical mode
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Initialize the game
    init_game();

    // Game loop
    while(true) {
        // Move the ball
        move_ball();

        // Move the paddle
        move_paddle();

        // Draw the screen
        draw_screen();

        // Slow down the game
        usleep(50000);
    }

    // Reset the terminal to canonical mode
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return 0;
}