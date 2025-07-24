//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define HEIGHT 20
#define WIDTH 50

#define BRICK_CHAR '#'
#define BALL_CHAR 'o'
#define PADDLE_CHAR '='

struct termios orig_termios;
static void reset_terminal_mode()
{
    tcsetattr(0, TCSANOW, &orig_termios);
}
static void set_conio_terminal_mode()
{
    struct termios new_termios;

    /* take two copies - one for now, one for later */
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));

    /* register cleanup handler, and set the new terminal mode */
    atexit(reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
}
static int kbhit()
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

int main()
{
    srand(time(NULL));
    set_conio_terminal_mode();
    int score = 0;
    int lives = 3;

    char screen[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            screen[i][j] = ' ';
        }
    }

    int paddle_pos = WIDTH / 2 - 5;
    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT - 2;
    int ball_dir_x = 1;
    int ball_dir_y = -1;

    while (1)
    {
        usleep(10000);

        // Handle input
        if (kbhit())
        {
            char c = getchar();
            if (c == 'a' && paddle_pos > 0)
            {
                paddle_pos--;
            }
            if (c == 'd' && paddle_pos < WIDTH - 10)
            {
                paddle_pos++;
            }
        }

        // Move ball
        if (ball_x + ball_dir_x == 0 || ball_x + ball_dir_x == WIDTH - 1)
        {
            ball_dir_x = -ball_dir_x;
        }
        if (ball_y + ball_dir_y == 0)
        {
            ball_dir_y = -ball_dir_y;
        }
        if (ball_y + ball_dir_y == HEIGHT - 1)
        {
            lives--;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT - 2;
            ball_dir_x = 1;
            ball_dir_y = -1;
            if (lives == 0)
            {
                printf("Game Over!\n");
                exit(0);
            }
        }
        if (ball_y + ball_dir_y == HEIGHT - 2 && ball_x + ball_dir_x >= paddle_pos && ball_x + ball_dir_x < paddle_pos + 10)
        {
            ball_dir_y = -ball_dir_y;
            score++;
        }
        ball_x += ball_dir_x;
        ball_y += ball_dir_y;

        // Draw screen
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if (i == ball_y && j == ball_x)
                {
                    screen[i][j] = BALL_CHAR;
                }
                else if (i == HEIGHT - 1)
                {
                    if (j >= paddle_pos && j < paddle_pos + 10)
                    {
                        screen[i][j] = PADDLE_CHAR;
                    }
                    else
                    {
                        screen[i][j] = ' ';
                    }
                }
                else if (i < 5 && j % 5 == 0)
                {
                    screen[i][j] = BRICK_CHAR;
                }
                else
                {
                    screen[i][j] = ' ';
                }
                printf("%c", screen[i][j]);
            }
            printf("\n");
        }
        printf("Score: %d\tLives: %d\n", score, lives);
        printf("Use arrow keys to move paddle left and right\n");
        printf("Press Ctrl+C to quit\n");

        // Clear screen
        printf("\033[2J");

        // Check for win
        int bricks_left = 0;
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if (screen[i][j] == BRICK_CHAR)
                {
                    bricks_left = 1;
                    break;
                }
            }
            if (bricks_left)
            {
                break;
            }
        }
        if (!bricks_left)
        {
            printf("You win!\n");
            exit(0);
        }
    }
    return 0;
}