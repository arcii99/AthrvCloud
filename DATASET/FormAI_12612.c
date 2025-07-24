//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

char field[WIDTH][HEIGHT];
int pacman_x;
int pacman_y;

void initField()
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            field[i][j] = '.';
        }
    }
    for (int i = 0; i < WIDTH; i++)
    {
        field[i][0] = 'X';
        field[i][HEIGHT-1] = 'X';
    }
    for (int j = 0; j < HEIGHT; j++)
    {
        field[0][j] = 'X';
        field[WIDTH-1][j] = 'X';
    }
    pacman_x = WIDTH/2;
    pacman_y = HEIGHT/2;
    field[pacman_x][pacman_y] = 'O';
}

void printField()
{
    for (int j = 0; j < HEIGHT; j++)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }
}

void movePacman(char direction)
{
    int new_x = pacman_x;
    int new_y = pacman_y;
    if (direction == 'w')
    {
        new_y--;
    }
    else if (direction == 's')
    {
        new_y++;
    }
    else if (direction == 'a')
    {
        new_x--;
    }
    else if (direction == 'd')
    {
        new_x++;
    }
    if (field[new_x][new_y] == '.')
    {
        field[pacman_x][pacman_y] = '.';
        pacman_x = new_x;
        pacman_y = new_y;
        field[pacman_x][pacman_y] = 'O';
    }
}

int main()
{
    initField();
    printField();
    while (1)
    {
        char direction;
        printf("Enter direction (w/a/s/d): ");
        scanf("%c", &direction);
        movePacman(direction);
        printField();
    }
    return 0;
}