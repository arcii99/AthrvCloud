//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>

#define HEIGHT 20
#define WIDTH 40
#define PADDLE_WIDTH 5
#define BALL_DELAY 200000
#define BLOCKS_ROW 5
#define BLOCKS_COL 10
#define BLOCK_HEIGHT 2
#define BLOCK_WIDTH 4

int rand_int(int l, int r)
{
    return rand() % (r - l + 1) + l;
}

int kbhit()
{
    struct termios oldt, newt;
    int fd = 0;
    int ch = 0;
    int oldf = 0;

    tcgetattr(fd, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(fd, TCSANOW, &newt);
    oldf = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(fd, TCSANOW, &oldt);
    fcntl(fd, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void move_paddle(char key, int *paddle_x)
{
    if(key == 'a' && *paddle_x > 0)
    {
        *paddle_x -= 1;
    }
    else if(key == 'd' && *paddle_x + PADDLE_WIDTH < WIDTH)
    {
        *paddle_x += 1;
    }
}

void draw_paddle(int paddle_x)
{
    for(int i = 0; i < PADDLE_WIDTH; i++)
    {
        putchar(' ');
    }
    putchar('\r');

    for(int i = 0; i < PADDLE_WIDTH; i++)
    {
        if(i + paddle_x == WIDTH)
        {
            break;
        }
        putchar('=');
    }

    putchar('\r');
}

void draw_ball(int ball_x, int ball_y)
{
    printf(" ");
    printf("\033[%d;%dH", ball_y, ball_x);
    printf("*");
    printf("\033[1;1H");
}

void draw_blocks(int blocks[BLOCKS_ROW][BLOCKS_COL])
{
    for(int i = 0; i < BLOCKS_ROW; i++)
    {
        for(int j = 0; j < BLOCKS_COL; j++)
        {
            int block_x = j * (BLOCK_WIDTH + 1) + 1;
            int block_y = i * (BLOCK_HEIGHT + 1) + 1;

            if(blocks[i][j] > 0)
            {
                printf("\033[%d;%dH", block_y, block_x);
                printf("+---+\n|   |\n|   |\n+---+");
            }
            else
            {
                printf("\033[%d;%dH", block_y, block_x);
                printf("     ");
            }

            printf("\033[1;1H");
        }
    }
}

void move_ball(int *ball_x, int *ball_y, int *dir_x, int *dir_y, int paddle_x, int *gameover, int blocks[BLOCKS_ROW][BLOCKS_COL])
{
    *ball_x += *dir_x;
    *ball_y += *dir_y;

    if(*ball_x < 0 || *ball_x >= WIDTH)
    {
        *dir_x = -(*dir_x);
    }
    if(*ball_y < 0)
    {
        *dir_y = -(*dir_y);
    }
    if(*ball_y >= HEIGHT)
    {
        *gameover = 1;
    }

    if(*ball_y == HEIGHT - 2 && *dir_y == 1)
    {
        if(*ball_x >= paddle_x && *ball_x < paddle_x + PADDLE_WIDTH)
        {
            *dir_y = -(*dir_y);
        }
    }

    int row = *ball_y / (BLOCK_HEIGHT + 1);
    int col = -1;
    if(*ball_x >= 1 && *ball_x <= WIDTH - 2)
    {
        col = (*ball_x - 1) / (BLOCK_WIDTH + 1);
    }

    if(row >= 0 && row < BLOCKS_ROW && col >= 0 && col < BLOCKS_COL && blocks[row][col] > 0)
    {
        blocks[row][col]--;

        if(*ball_x % (BLOCK_WIDTH + 1) == 1)
        {
            *dir_x = -(*dir_x);
        }
        else
        {
            *dir_y = -(*dir_y);
        }
    }
}

void init_blocks(int blocks[BLOCKS_ROW][BLOCKS_COL])
{
    for(int i = 0; i < BLOCKS_ROW; i++)
    {
        for(int j = 0; j < BLOCKS_COL; j++)
        {
            blocks[i][j] = 1;
        }
    }
}

int main()
{
    srand(time(NULL));

    int paddle_x = WIDTH / 2 - PADDLE_WIDTH / 2;
    int ball_x = rand_int(1, WIDTH - 2);
    int ball_y = HEIGHT / 2;
    int dir_x = rand_int(0, 1) ? 1 : -1;
    int dir_y = -1;
    int gameover = 0;

    int blocks[BLOCKS_ROW][BLOCKS_COL];
    init_blocks(blocks);

    while(!gameover)
    {
        if(kbhit())
        {
            char key = getchar();
            move_paddle(key, &paddle_x);
        }

        move_ball(&ball_x, &ball_y, &dir_x, &dir_y, paddle_x, &gameover, blocks);

        printf("\033[2J");
        printf("\033[H");
        draw_paddle(paddle_x);
        draw_ball(ball_x, ball_y);
        draw_blocks(blocks);

        usleep(BALL_DELAY);
    }

    printf("\033[2J");
    printf("\033[H");
    printf("Game Over!\n");

    return 0;
}