//FormAI DATASET v1.0 Category: Game of Life ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 30
#define COLS 80

void print_world(char world[ROWS][COLS]);
void update_world(char world[ROWS][COLS]);

int main()
{
    char world[ROWS][COLS] = {0};

    //Initial setup of the world
    world[5][5] = 1;
    world[6][5] = 1;
    world[6][6] = 1;
    world[5][6] = 1;
    world[14][28] = 1;
    world[14][29] = 1;
    world[15][28] = 1;
    world[15][30] = 1;
    world[16][31] = 1;
    world[16][32] = 1;
    world[16][33] = 1;

    while (1)
    {
        //Clearing the screen and printing the world
        system("clear");
        print_world(world);

        //Updating the world
        update_world(world);

        //Sleeping for 0.1 seconds
        usleep(100000);
    }

    return 0;
}

//Function to print the current world state
void print_world(char world[ROWS][COLS])
{
    printf("The Game of Life - Sherlock Holmes Style\n\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            //Displaying "X" for live cells and "." for dead ones
            if (world[i][j])
                printf("X");
            else
                printf(".");
        }
        printf("\n");
    }
}

//Function to update the world state
void update_world(char world[ROWS][COLS])
{
    char new_world[ROWS][COLS] = {0};

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int n_neighbors = 0;

            //Counting the number of neighbors
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if (k == 0 && l == 0)
                        continue;

                    int row = i + k;
                    int col = j + l;

                    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
                        continue;

                    if (world[row][col])
                        n_neighbors++;
                }
            }

            //Applying the rules of the Game of Life
            if (world[i][j] == 1 && n_neighbors < 2)
                new_world[i][j] = 0;
            else if (world[i][j] == 1 && (n_neighbors == 2 || n_neighbors == 3))
                new_world[i][j] = 1;
            else if (world[i][j] == 1 && n_neighbors > 3)
                new_world[i][j] = 0;
            else if (world[i][j] == 0 && n_neighbors == 3)
                new_world[i][j] = 1;
        }
    }

    //Updating the world with the new state
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            world[i][j] = new_world[i][j];
        }
    }
}