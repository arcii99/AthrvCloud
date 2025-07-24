//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define ROWS 25
#define COLUMNS 80

#define BOARD_TOP 1
#define BOARD_BOTTOM ROWS-2
#define BOARD_LEFT 1
#define BOARD_RIGHT COLUMNS-2

#define BALL_SPEED 100000

// Function to set STDIN in noncanonical mode
void set_terminal_mode()
{
    struct termios ttystate;

    tcgetattr(STDIN_FILENO, &ttystate);

    ttystate.c_lflag &= ~(ICANON | ECHO); // Turn off canoncial mode and echo
    ttystate.c_cc[VMIN] = 0;
    ttystate.c_cc[VTIME] = 1;

    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

// Function to read keystrokes
int get_key()
{
    int c = 0;

    if (read(STDIN_FILENO, &c, 1) == -1)
    {
        return 0;
    }

    return c;
}

// Function to clear the screen
void clear_screen()
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

// Function to draw the game board
void draw_board(int x, int y)
{
    clear_screen();

    for (int j = BOARD_LEFT; j <= BOARD_RIGHT; j++)
    {
        printf("#");
    }

    for (int i = BOARD_TOP; i <= BOARD_BOTTOM; i++)
    {
        printf("#");

        for (int j = BOARD_LEFT + 1; j <= BOARD_RIGHT - 1; j++)
        {
            if (i == y && j == x)
            {
                printf("O");
            }
            else
            {
                printf(" ");
            }
        }

        printf("#\n");
    }

    for (int j = BOARD_LEFT; j <= BOARD_RIGHT; j++)
    {
        printf("#");
    }

    printf("\n");
}


int main()
{
    int ball_x = (BOARD_LEFT + BOARD_RIGHT) / 2;
    int ball_y = (BOARD_TOP + BOARD_BOTTOM) / 2;
    int dx = 1;
    int dy = 1;
    int score = 0;
    int paddle_x = (BOARD_LEFT + BOARD_RIGHT) / 2;

    set_terminal_mode();

    while (1)
    {
        // Draw the board
        draw_board(ball_x, ball_y);

        // Move the paddle based on user input
        int key = get_key();

        if (key == 'a' && paddle_x > BOARD_LEFT + 1)
        {
            paddle_x--;
        }

        if (key == 'd' && paddle_x < BOARD_RIGHT - 1)
        {
            paddle_x++;
        }

        // Move the ball
        ball_x += dx;
        ball_y += dy;

        // Check if the ball has hit the paddle
        if (ball_y == BOARD_BOTTOM && ball_x >= paddle_x - 1 && ball_x <= paddle_x + 1)
        {
            dy = -dy;
            score++;
        }

        // Check if the ball has hit a wall
        if (ball_x == BOARD_LEFT || ball_x == BOARD_RIGHT)
        {
            dx = -dx;
        }

        if (ball_y == BOARD_TOP)
        {
            dy = -dy;
        }

        // Check if the game is over
        if (ball_y == BOARD_BOTTOM + 1)
        {
            printf("Game over! Score: %d\n", score);
            break;
        }

        // Wait for a little bit so the ball doesn't move too fast
        usleep(BALL_SPEED);
    }

    return 0;
}