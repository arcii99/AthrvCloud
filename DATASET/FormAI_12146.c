//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define ROWS 21
#define COLS 41
#define PLAYER_ROW 19
#define PLAYER_COL 20
#define MAX_BULLETS 5
#define BULLET_SPEED 100000
#define ENEMY_SPEED 200000

int score = 0;
int lives = 3;

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void clear(void)
{
    printf("\033[2J");
}

void draw_board(char board[ROWS][COLS])
{
    int i, j;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d    Lives: %d\n", score, lives);
}

void move_player(char board[ROWS][COLS], int direction)
{
    if(direction == 0 && PLAYER_COL > 1)
    {
        board[PLAYER_ROW][PLAYER_COL] = ' ';
        board[PLAYER_ROW][PLAYER_COL-1] = 'A';
    }
    else if(direction == 1 && PLAYER_COL < COLS-2)
    {
        board[PLAYER_ROW][PLAYER_COL] = ' ';
        board[PLAYER_ROW][PLAYER_COL+1] = 'A';
    }
}

void shoot_bullet(char board[ROWS][COLS], int bullet_row, int bullet_col)
{
    int i;
    for(i=bullet_row;i>0;i--)
    {
        board[i][bullet_col] = ' ';
        if(board[i-1][bullet_col] == 'E')
        {
            score += 10;
            board[i-1][bullet_col] = ' ';
            break;
        }
        else if(board[i-1][bullet_col] == '|')
        {
            break;
        }
        else
        {
            board[i-1][bullet_col] = '|';
            draw_board(board);
            usleep(BULLET_SPEED);
        }
    }
}

void move_enemy(char board[ROWS][COLS], int enemy_row, int enemy_col)
{
    board[enemy_row][enemy_col] = ' ';
    board[enemy_row+1][enemy_col] = 'E';

    draw_board(board);
    usleep(ENEMY_SPEED);
}

int main(void)
{
    char board[ROWS][COLS] = {0};
    int i, j;
    int direction = 0; /* 0 for left, 1 for right */
    int bullet_count = 0;
    int bullets[MAX_BULLETS][2] = {0};
    int enemy_row = 0, enemy_col = 0;
    int enemy_direction = 0; /* 0 for left, 1 for right */

    /* Initialize board with spaces */
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            board[i][j] = ' ';
        }
    }

    /* Draw player */
    board[PLAYER_ROW][PLAYER_COL] = 'A';

    /* Draw enemy */
    enemy_row = 1;
    enemy_col = COLS / 2;
    board[enemy_row][enemy_col] = 'E';

    clear();

    while(lives > 0)
    {
        if(kbhit())
        {
            char c = getchar();
            if(c == 'a')
            {
                direction = 0;
            }
            else if(c == 'd')
            {
                direction = 1;
            }
            else if(c == ' ')
            {
                if(bullet_count < MAX_BULLETS)
                {
                    bullets[bullet_count][0] = PLAYER_ROW - 1;
                    bullets[bullet_count][1] = PLAYER_COL;
                    bullet_count++;
                }
            }
        }

        move_player(board, direction);

        if(enemy_direction == 0 && enemy_col > 1)
        {
            move_enemy(board, enemy_row, enemy_col);
            enemy_col--;
        }
        else if(enemy_direction == 1 && enemy_col < COLS-2)
        {
            move_enemy(board, enemy_row, enemy_col);
            enemy_col++;
        }
        else
        {
            enemy_direction = !enemy_direction;
            enemy_row++;
        }

        for(i=0;i<MAX_BULLETS;i++)
        {
            if(bullets[i][0] != 0)
            {
                shoot_bullet(board, bullets[i][0], bullets[i][1]);
                bullets[i][0] = 0;
                bullets[i][1] = 0;
                bullet_count--;
            }
        }

        /* Check for collision between player and enemy */
        if(board[PLAYER_ROW-1][PLAYER_COL] == 'E' ||
           board[PLAYER_ROW][PLAYER_COL-1] == 'E' ||
           board[PLAYER_ROW][PLAYER_COL+1] == 'E')
        {
            lives--;
            clear();
            printf("You have %d lives remaining.\n", lives);
            usleep(3000000);

            /* Reset board */
            for(i=0;i<ROWS;i++)
            {
                for(j=0;j<COLS;j++)
                {
                    board[i][j] = ' ';
                }
            }
            board[PLAYER_ROW][PLAYER_COL] = 'A';
            enemy_row = 1;
            enemy_col = COLS / 2;
            board[enemy_row][enemy_col] = 'E';
            continue;
        }

        /* Check for game over */
        for(i=0;i<COLS;i++)
        {
            if(board[ROWS-2][i] == 'E')
            {
                clear();
                printf("Game Over.\nFinal Score: %d\n", score);
                return 0;
            }
        }

        clear();
        draw_board(board);
    }

    return 0;
}