//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAP_SIZE 20
#define MAX_COMMANDS 10

typedef struct
{
    int x;
    int y;
} Position;

typedef enum
{
    UP,
    RIGHT,
    DOWN,
    LEFT
} Direction;

void printMap(char map[][MAP_SIZE])
{
    system("clear");
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

char getRandomObstacle()
{
    int rnd = rand() % 100 + 1;
    if (rnd <= 30)
        return 'T'; // Tree
    else if (rnd <= 60)
        return 'R'; // Rock
    else
        return '.'; // Empty space
}

bool isValidMovement(char map[][MAP_SIZE], Position newPos)
{
    if (newPos.x < 0 || newPos.y < 0 || newPos.x >= MAP_SIZE || newPos.y >= MAP_SIZE)
        return false;
    if (map[newPos.y][newPos.x] == 'T' || map[newPos.y][newPos.x] == 'R')
        return false;
    return true;
}

int main()
{
    char map[MAP_SIZE][MAP_SIZE];
    srand(time(NULL));

    // Fill map with random obstacles
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            map[i][j] = getRandomObstacle();
        }
    }

    // Create the vehicle
    Position vehiclePos = {0, 0};
    map[0][0] = 'V';

    // Main loop
    char command[MAX_COMMANDS + 1];
    while (true)
    {
        printMap(map);
        printf("Enter command (up, down, left, right):\n");
        fgets(command, MAX_COMMANDS + 1, stdin);

        // Remove newline character from command
        int len = strlen(command);
        if (command[len - 1] == '\n')
            command[len - 1] = '\0';

        // Parse command
        Direction dir;
        if (strcmp(command, "up") == 0)
            dir = UP;
        else if (strcmp(command, "right") == 0)
            dir = RIGHT;
        else if (strcmp(command, "down") == 0)
            dir = DOWN;
        else if (strcmp(command, "left") == 0)
            dir = LEFT;
        else
            printf("Invalid command\n");

        // Move vehicle
        Position newPos;
        switch (dir)
        {
            case UP:
                newPos.x = vehiclePos.x;
                newPos.y = vehiclePos.y - 1;
                break;
            case RIGHT:
                newPos.x = vehiclePos.x + 1;
                newPos.y = vehiclePos.y;
                break;
            case DOWN:
                newPos.x = vehiclePos.x;
                newPos.y = vehiclePos.y + 1;
                break;
            case LEFT:
                newPos.x = vehiclePos.x - 1;
                newPos.y = vehiclePos.y;
                break;
        }
        if (isValidMovement(map, newPos))
        {
            // Clear old vehicle position
            map[vehiclePos.y][vehiclePos.x] = getRandomObstacle();

            // Update vehicle position
            vehiclePos = newPos;
            map[vehiclePos.y][vehiclePos.x] = 'V';
        }
        else
        {
            printf("Invalid movement\n");
        }
    }

    return 0;
}