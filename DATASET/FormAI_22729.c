//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i=0, j=0, k=0, l=0;
    int car_count = 0;
    int cars[10];
    int current_pos = -1;
    int next_pos = 0;
    char sim_grid[4][10];

    srand(time(NULL)); // to get different random values each time

    // Initializing simulation grid for the traffic flow simulation
    for(i=0; i<4; i++)
    {
        for(j=0; j<10; j++)
        {
            sim_grid[i][j] = '-';
        }
    }

    // Creating the initial traffic flow by randomly placing cars on the grid
    for(i=0; i<5; i++)
    {
        current_pos = rand() % 4;
        next_pos = rand() % 10;
        if(sim_grid[current_pos][next_pos] != 'C')
        {
            sim_grid[current_pos][next_pos] = 'C';
            cars[car_count] = current_pos*10 + next_pos; // storing car position as single integer
            car_count++;
        }
        else
        {
            i--; // if position already occupied by a car, try again with new random values
        }
    }

    // Printing the initial traffic flow configuration
    printf("Initial Traffic Flow Configuration\n");
    for(i=0; i<4; i++)
    {
        for(j=0; j<10; j++)
        {
            printf("%c ", sim_grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Moving the cars on the simulation grid based on traffic rules
    for(k=0; k<30; k++)
    {
        for(l=0; l<car_count; l++)
        {
            current_pos = cars[l] / 10;
            next_pos = cars[l] % 10;
            sim_grid[current_pos][next_pos] = '-'; // emptying the current position

            // Checking traffic rules for moving the car to next position
            if(current_pos == 0 && next_pos == 9)
            {
                sim_grid[3][0] = 'C';
                cars[l] = 30;
            }
            else if(current_pos == 3 && next_pos == 0)
            {
                sim_grid[0][9] = 'C';
                cars[l] = 9;
            }
            else if(next_pos == 9)
            {
                if(sim_grid[current_pos+1][0] != 'C')
                {
                    sim_grid[current_pos+1][0] = 'C';
                    cars[l] = (current_pos+1)*10;
                }
                else
                {
                    sim_grid[current_pos][next_pos] = 'C';
                    cars[l] = current_pos*10 + next_pos;
                }
            }
            else
            {
                if(sim_grid[current_pos][next_pos+1] != 'C')
                {
                    sim_grid[current_pos][next_pos+1] = 'C';
                    cars[l] = current_pos*10 + next_pos+1;
                }
                else
                {
                    sim_grid[current_pos][next_pos] = 'C';
                    cars[l] = current_pos*10 + next_pos;
                }
            }
        }

        // Printing the updated traffic flow configuration
        printf("Traffic Flow Configuration after Step %d\n", k+1);
        for(i=0; i<4; i++)
        {
            for(j=0; j<10; j++)
            {
                printf("%c ", sim_grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}