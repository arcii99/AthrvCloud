//FormAI DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int cell[WIDTH][HEIGHT];

void clear_screen()
{
    printf("\033[2J\033[1;1H");
}

void print_board()
{
    int i,j;
    for(i=0;i<WIDTH;i++)
    {
        for(j=0;j<HEIGHT;j++)
        {
            if(cell[i][j])
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

void init_board()
{
    srand(time(NULL));
    int i,j;
    for(i=0;i<WIDTH;i++)
    {
        for(j=0;j<HEIGHT;j++)
        {
            cell[i][j] = rand() % 2;
        }
    }
}

int count_neighbors(int x, int y)
{
    int count = 0;
    int i,j;
    for(i=-1;i<=1;i++)
    {
        for(j=-1;j<=1;j++)
        {
            int nx = x+i;
            int ny = y+j;
            if(nx<0 || nx>=WIDTH || ny<0 || ny>=HEIGHT)
                continue;
            if(i==0 && j==0)
                continue;
            if(cell[nx][ny])
                count++;
        }
    }
    return count;
}

void update_board()
{
    int new_cell[WIDTH][HEIGHT];
    int i,j;
    for(i=0;i<WIDTH;i++)
    {
        for(j=0;j<HEIGHT;j++)
        {
            int neighbors = count_neighbors(i,j);
            if(cell[i][j])
            {
                if(neighbors < 2 || neighbors > 3)
                    new_cell[i][j] = 0;
                else
                    new_cell[i][j] = 1;
            }
            else
            {
                if(neighbors == 3)
                    new_cell[i][j] = 1;
                else
                    new_cell[i][j] = 0;
            }
        }
    }
    for(i=0;i<WIDTH;i++)
    {
        for(j=0;j<HEIGHT;j++)
        {
            cell[i][j] = new_cell[i][j];
        }
    }
}

int main()
{
    init_board();
    while(1)
    {
        clear_screen();
        print_board();
        update_board();
        sleep(1);
    }
    return 0;
}