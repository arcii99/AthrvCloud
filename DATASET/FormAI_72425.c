//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: multivariable
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <fcntl.h>

#define ROWS 20
#define COLS 30
#define ALIENROWS 4
#define ALIENCOLS 8
#define BULLETROWS 2
#define BULLETCOLS 1

char grid[ROWS][COLS];
char bullets[BULLETROWS][BULLETCOLS];

char aliens[ALIENROWS][ALIENCOLS] =
    {{"<0 0 0 0>"},
     {"< 0 0 0 0"},
     {"<0 0 0 0>"},
     {"< 0 0 0 0"}};

int spaceship_pos = COLS / 2;
int score = 0;

int getch(void)
{
    int ch;
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void drawSpaceship(int lpos, int rpos)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == ROWS - 1 && j >= lpos && j <= rpos)
            {
                grid[i][j] = '|';
            }
            else
            {
                grid[i][j] = ' ';
            }
        }
    }
}

void drawBullets()
{
    for (int i = 0; i < BULLETROWS; i++)
    {
        for (int j = 0; j < BULLETCOLS; j++)
        {
            if (grid[i][j] == '|' && grid[i - 1][j] == '-')
            {
                grid[i - 1][j] = ' ';
            }
            else if (bullets[i][j] == '|')
            {
                grid[i][j + spaceship_pos] = '|';
            }
        }
    }
}

void drawAliens(int offset)
{
    for (int i = 0; i < ALIENROWS; i++)
    {
        for (int j = 0; j < ALIENCOLS; j++)
        {
            if (aliens[i][j] != ' ')
            {
                grid[i + offset][j + 1 + ((COLS - ALIENCOLS - 2) / 2)] = aliens[i][j];
            }
        }
    }
}

void initGame()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = ' ';
        }
    }
    for (int i = 0; i < BULLETROWS; i++)
    {
        for (int j = 0; j < BULLETCOLS; j++)
        {
            bullets[i][j] = '|';
        }
    }
}

void startGame()
{
    int move = 1;
    int bulletspeed = 0;
    int bulletpos = ROWS - 2;
    int spaceship_lpos = spaceship_pos - 1;
    int spaceship_rpos = spaceship_pos + 1;
    int alienpos = 0;

    while (true)
    {
        drawAliens(alienpos);
        drawSpaceship(spaceship_lpos, spaceship_rpos);
        drawBullets();
        for (int i = 0; i < ROWS; i++)
        {
            printf("%s\n", grid[i]);
        }
        printf("Score: %d\n", score);
        printf("Use arrow keys to move, spacebar to shoot, q to quit\n");

        int ch = getch();
        if (ch == 'q')
        {
            break;
        }
        else if (ch == ' ')
        {
            grid[bulletpos][spaceship_pos] = '-';
            bulletspeed = 1;
        }
        else if (ch == 27)
        {
            ch = getch();
            if (ch == 91)
            {
                ch = getch();
                if (ch == 68 && spaceship_lpos > 0)
                {
                    spaceship_pos--;
                    spaceship_lpos--;
                    spaceship_rpos--;
                }
                else if (ch == 67 && spaceship_rpos < COLS - 1)
                {
                    spaceship_pos++;
                    spaceship_lpos++;
                    spaceship_rpos++;
                }
            }
        }

        if (bulletspeed == 1)
        {
            bulletpos--;
        }

        if (bulletpos == 0)
        {
            bulletspeed = 0;
            grid[bulletpos][spaceship_pos] = ' ';
            bulletpos = ROWS - 2;
        }

        if (move % 10 == 0)
        {
            alienpos++;
            if (alienpos >= ROWS - ALIENROWS - 5)
            {
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("GAME OVER! Your score: %d\n", score);
                return;
            }
        }

        if (move % 20 == 0)
        {
            for (int i = 0; i < ALIENROWS; i++)
            {
                for (int j = 0; j < ALIENCOLS; j++)
                {
                    if (aliens[i][j] != ' ')
                    {
                        if ((bulletpos == alienpos + i || bulletpos == alienpos + i - 1) && (spaceship_pos == j + 1 + ((COLS - ALIENCOLS - 2) / 2)))
                        {
                            score++;
                            grid[bulletpos][spaceship_pos] = ' ';
                            bulletspeed = 0;
                            bulletpos = ROWS - 2;
                            aliens[i][j] = ' ';
                        }
                    }
                }
            }
        }

        move++;
        usleep(10000);
        printf("\033[2J\033[1;1H");
    }
}

int main()
{
    initGame();
    startGame();
    return 0;
}