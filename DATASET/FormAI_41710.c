//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20

char map[MAP_SIZE][MAP_SIZE];

void generateMap()
{
    srand(time(NULL)); //Seed the random number generator
    
    //Fill the map with random blocks
    for(int i=0; i<MAP_SIZE; i++)
    {
        for(int j=0; j<MAP_SIZE; j++)
        {
            int blockType = rand()%3;
            if(blockType == 0)
            {
                map[i][j] = '#'; //Wall
            }
            else if(blockType == 1)
            {
                map[i][j] = '.'; //Floor
            }
            else
            {
                map[i][j] = '+'; //Chest
            }
        }
    }
    
    //Place the player at a random location
    int playerX = rand()%MAP_SIZE;
    int playerY = rand()%MAP_SIZE;
    map[playerX][playerY] = '@';
    
    //Place the exit at a random location
    int exitX = rand()%MAP_SIZE;
    int exitY = rand()%MAP_SIZE;
    map[exitX][exitY] = '!';
}

void printMap()
{
    printf("##########\n"); //Print top border
    
    //Print the map
    for(int i=0; i<MAP_SIZE; i++)
    {
        printf("#");
        for(int j=0; j<MAP_SIZE; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("#\n");
    }
    
    printf("##########\n"); //Print bottom border
}

int main()
{
    generateMap();
    printMap();
    
    return 0;
}