//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>

#define WIDTH 40
#define HEIGHT 20
#define ENEMY_SPEED 1
#define MISSILE_SPEED 2

int kbhit(void);
void display(char grid[][WIDTH]);
void update(char grid[][WIDTH], int *score);
void move_enemy(char grid[][WIDTH], int *enemy_pos, int dir);
void fire_missile(char grid[][WIDTH], int *missile_pos, int *ship_pos, int *score);

int main()
{
    char grid[HEIGHT][WIDTH] = {0};
    int ship_pos = WIDTH / 2;
    int missile_pos[2] = {-1, -1};
    int enemy_pos = (rand() % (WIDTH - 2)) + 1;
    int dir = 1;
    int score = 0;
    
    while(1)
    {
        if(kbhit())
        {
            char c = getchar();
            switch(c)
            {
                case 'a':
                    if(ship_pos > 0)
                        ship_pos--;
                    break;
                case 'd':
                    if(ship_pos < WIDTH - 1)
                        ship_pos++;
                    break;
                case ' ':
                    if(missile_pos[0] == -1)
                    {
                        missile_pos[0] = HEIGHT - 2;
                        missile_pos[1] = ship_pos;
                    }
                    break;
            }
        }
        update(grid, &score);
        move_enemy(grid, &enemy_pos, &dir);
        fire_missile(grid, missile_pos, &ship_pos, &score);
        display(grid);
        usleep(10000);
    }
    return 0;
}

void display(char grid[][WIDTH])
{
    system("clear");
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            if(grid[i][j] == 1)
                printf("O");
            else if(i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void update(char grid[][WIDTH], int *score)
{
    for(int i=0; i<HEIGHT-1; i++)
    {
        for(int j=1; j<WIDTH-1; j++)
        {
            if(grid[i][j] == 1 && grid[i+1][j] != 1)
            {
                grid[i][j] = 0;
                grid[i+1][j] = 1;
            }
            else if(grid[i][j] == 1 && grid[i+1][j] == 1)
            {
                grid[i][j] = 0;
                grid[i+1][j] = 0;
            }
        }
    }
    for(int j=1; j<WIDTH-1; j++)
    {
        if(grid[HEIGHT-2][j] == 1)
        {
            *score += 1;
            grid[HEIGHT-2][j] = 0;
        }
    }
}

void move_enemy(char grid[][WIDTH], int *enemy_pos, int dir)
{
    if(*enemy_pos == 1)
        dir = 1;
    else if(*enemy_pos == WIDTH-2)
        dir = -1;
    *enemy_pos += dir * ENEMY_SPEED;
    grid[1][*enemy_pos] = 1;
}

void fire_missile(char grid[][WIDTH], int *missile_pos, int *ship_pos, int *score)
{
    if(missile_pos[0] == -1)
        return;
    if(grid[missile_pos[0]][missile_pos[1]] == 1)
    {
        missile_pos[0] = -1;
        missile_pos[1] = -1;
        return;
    }
    grid[missile_pos[0]][missile_pos[1]] = 1;
    if(missile_pos[0] == 1)
    {
        missile_pos[0] = -1;
        missile_pos[1] = -1;
        return;
    }
    missile_pos[0] -= MISSILE_SPEED;
}

int kbhit(void)
{
    static struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}