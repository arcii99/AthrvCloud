//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define WIDTH 10
#define HEIGHT 10

char map[WIDTH][HEIGHT];
int pos_x = 0, pos_y = 0;
int exit_x = 0, exit_y = 0;

int main()
{
    srand(time(NULL));

    // Initialize map
    for(int i=0; i<WIDTH; i++)
    {
        for(int j=0; j<HEIGHT; j++)
        {
            if(i == 0 || i == WIDTH-1 || j == 0 || j == HEIGHT-1)
            {
                map[i][j] = '#';
            }
            else
            {
                map[i][j] = '.';
            }
        }
    }

    // Generate walls
    for(int i=0; i<WIDTH*HEIGHT/3; i++)
    {
        int rand_x = rand() % (WIDTH-2) + 1;
        int rand_y = rand() % (HEIGHT-2) + 1;

        map[rand_x][rand_y] = '#';
    }

    // Generate player position
    while(1)
    {
        int rand_x = rand() % (WIDTH-2) + 1;
        int rand_y = rand() % (HEIGHT-2) + 1;

        if(map[rand_x][rand_y] == '.')
        {
            pos_x = rand_x;
            pos_y = rand_y;
            map[pos_x][pos_y] = '@';
            break;
        }
    }

    // Generate exit position
    while(1)
    {
        int rand_x = rand() % (WIDTH-2) + 1;
        int rand_y = rand() % (HEIGHT-2) + 1;

        if(map[rand_x][rand_y] == '.')
        {
            exit_x = rand_x;
            exit_y = rand_y;
            map[exit_x][exit_y] = 'O';
            break;
        }
    }

    // Print map
    for(int i=0; i<WIDTH; i++)
    {
        for(int j=0; j<HEIGHT; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}