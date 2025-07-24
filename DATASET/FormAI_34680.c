//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10     // Size of the map
#define START_X 0       // Starting X coordinate
#define START_Y 0       // Starting Y coordinate
#define GOAL_X 9        // Goal X coordinate
#define GOAL_Y 9        // Goal Y coordinate
#define OBSTACLE1_X 3   // Obstacle 1 X coordinate
#define OBSTACLE1_Y 5   // Obstacle 1 Y coordinate
#define OBSTACLE2_X 7   // Obstacle 2 X coordinate
#define OBSTACLE2_Y 2   // Obstacle 2 Y coordinate

int map[MAP_SIZE][MAP_SIZE];

void initializeMap();
void printMap();
int navigate(int x, int y);

int main()
{
    initializeMap();
    printMap();
    navigate(START_X, START_Y);
    printMap();

    return 0;
}

void initializeMap()
{
    srand(time(NULL));
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            if (i == OBSTACLE1_X && j == OBSTACLE1_Y)
            {
                map[i][j] = 1;
            }
            else if (i == OBSTACLE2_X && j == OBSTACLE2_Y)
            {
                map[i][j] = 1;
            }
            else
            {
                map[i][j] = 0;
            }
        }
    }
}

void printMap()
{
    system("cls");
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            if (i == START_X && j == START_Y)
            {
                printf("S ");
            }
            else if (i == GOAL_X && j == GOAL_Y)
            {
                printf("G ");
            }
            else if (map[i][j] == 1)
            {
                printf("O ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int navigate(int x, int y)
{
    int steps = 0;
    while (x != GOAL_X || y != GOAL_Y)
    {
        steps++;
        if (x < GOAL_X)
        {
            x++;
        }
        else if (x > GOAL_X)
        {
            x--;
        }

        if (y < GOAL_Y)
        {
            y++;
        }
        else if (y > GOAL_Y)
        {
            y--;
        }

        if (map[x][y] == 1)
        {
            printf("Obstacle detected at (%d, %d)\n", x, y);
            if ((rand() % 2) == 0)
            {
                printf("Moving left\n");
                y--;
            }
            else
            {
                printf("Moving right\n");
                y++;
            }
        }

        printMap();
    }
    printf("Goal reached in %d steps!\n", steps);
    return steps;
}