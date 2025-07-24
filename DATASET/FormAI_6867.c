//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 25
#define COL 50
#define BARRIER_RATE 0.6
#define PERCOLATION_RATE 0.5

int system_grid[ROW][COL];
int number_of_sites[ROW][COL] = {0};
int open_check[ROW][COL] = {0};

void initialise_system_grid(void)
{
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if((rand()/(float)RAND_MAX) < BARRIER_RATE) system_grid[i][j] = 1;
            else system_grid[i][j] = 0;
        }
    }
}

void check_percolation(void)
{
    for(int i=0;i<ROW;i++)
    {
        if(open_check[0][i] && open_check[ROW-1][i])
        {
            printf("Percolation achieved!\n");
            exit(1);
        }
    }
}

void print_system_grid(void)
{
    printf("\n\n\n\n\n");
    printf("**********************************************************\n");
    for(int i=0;i<ROW;i++)
    {
        printf("*");
        for(int j=0;j<COL;j++)
        {
            if(system_grid[i][j] == 1) printf(" ");
            else if(open_check[i][j] == 1) printf("#");
            else printf(".");
        }
        printf("*\n");
    }
    printf("**********************************************************\n\n\n\n\n\n\n");
}

void update_number_of_sites(int row, int col)
{
    number_of_sites[row][col] = 1;
    if(row > 0 && open_check[row-1][col] == 1)
    {
        number_of_sites[row][col] += number_of_sites[row-1][col];
    }
    if(row < ROW-1 && open_check[row+1][col] == 1)
    {
        number_of_sites[row][col] += number_of_sites[row+1][col];
    }
    if(col > 0 && open_check[row][col-1] == 1)
    {
        number_of_sites[row][col] += number_of_sites[row][col-1];
    }
    if(col < COL-1 && open_check[row][col+1] == 1)
    {
        number_of_sites[row][col] += number_of_sites[row][col+1];
    }
}

void open_site(int row, int col)
{
    if(open_check[row][col] == 1) return; // Site is already open

    open_check[row][col] = 1;

    if(system_grid[row][col] == 1)
    {
        return; // Site is impassable
    }

    update_number_of_sites(row, col);

    if(row == 0) 
    {
        number_of_sites[row][col] = -1;
    }
    if(row == ROW-1)
    {
        number_of_sites[row][col] = -2;
    }

    if(row > 0 && open_check[row-1][col] == 1)
    {
        if(number_of_sites[row][col] < number_of_sites[row-1][col])
        {
            number_of_sites[row-1][col] = number_of_sites[row][col];
            update_number_of_sites(row-1, col);
        }
        else
        {
            number_of_sites[row][col] = number_of_sites[row-1][col];
            update_number_of_sites(row, col);
        }
    }

    if(row < ROW-1 && open_check[row+1][col] == 1)
    {
        if(number_of_sites[row][col] < number_of_sites[row+1][col])
        {
            number_of_sites[row+1][col] = number_of_sites[row][col];
            update_number_of_sites(row+1, col);
        }
        else
        {
            number_of_sites[row][col] = number_of_sites[row+1][col];
            update_number_of_sites(row, col);
        }
    }

    if(col > 0 && open_check[row][col-1] == 1)
    {
        if(number_of_sites[row][col] < number_of_sites[row][col-1])
        {
            number_of_sites[row][col-1] = number_of_sites[row][col];
            update_number_of_sites(row, col-1);
        }
        else
        {
            number_of_sites[row][col] = number_of_sites[row][col-1];
            update_number_of_sites(row, col);
        }
    }

    if(col < COL-1 && open_check[row][col+1] == 1)
    {
        if(number_of_sites[row][col] < number_of_sites[row][col+1])
        {
            number_of_sites[row][col+1] = number_of_sites[row][col];
            update_number_of_sites(row, col+1);
        }
        else
        {
            number_of_sites[row][col] = number_of_sites[row][col+1];
            update_number_of_sites(row, col);
        }
    }

    check_percolation();

}

int main()
{
    srand(time(NULL));

    initialise_system_grid();

    for(int i=0;i<ROW;i++)
    {
        open_site(i,0);
        print_system_grid();
        open_site(i,COL-1);
        print_system_grid();
    }
    return 0;
}