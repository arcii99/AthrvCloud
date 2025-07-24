//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CARS 50
#define MAX_X 20
#define MAX_Y 20

int x[MAX_CARS], y[MAX_CARS], speed[MAX_CARS];
int num_cars, tick_counter;
char simulation_grid[MAX_X][MAX_Y];

void initialize_simulation()
{
    int i, j;

    num_cars = rand()%MAX_CARS;

    for(i=0; i<num_cars; i++)
    {
        x[i] = rand()%MAX_X;
        y[i] = rand()%MAX_Y;
        speed[i] = rand()%5 + 1;
    }

    for(i=0; i<MAX_X; i++)
    {
        for(j=0; j<MAX_Y; j++)
        {
            simulation_grid[i][j] = ' ';
        }
    }

    for(i=0; i<num_cars; i++)
    {
        simulation_grid[x[i]][y[i]] = 'C';
    }

    tick_counter = 0;
}

void move_cars()
{
    int i, j, new_x, new_y;

    for(i=0; i<num_cars; i++)
    {
        new_x = x[i] + speed[i];
        new_y = y[i];

        if(new_x >= MAX_X)
        {
            new_x = new_x - MAX_X;
        }

        if(simulation_grid[new_x][new_y] == 'C')
        {
            speed[i] = speed[i]/2;
            if(speed[i] == 0)
                speed[i] = 1;
        }
        else
        {
            simulation_grid[x[i]][y[i]] = ' ';
            simulation_grid[new_x][new_y] = 'C';
            x[i] = new_x;
            y[i] = new_y;
        }
    }
}

void print_simulation()
{
    int i, j;

    printf("Tick: %d\n", tick_counter);

    for(i=0; i<MAX_X; i++)
    {
        for(j=0; j<MAX_Y; j++)
        {
            printf("%c", simulation_grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(0));

    initialize_simulation();

    while(1)
    {
        print_simulation();
        move_cars();
        tick_counter++;
        getchar(); // pause for user to view simulation
    }

    return 0;
}