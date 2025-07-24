//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20

char map[MAP_SIZE][MAP_SIZE];

void generate_map() 
{
        int i, j;
        for(i=0;i<MAP_SIZE;i++) 
        {
                for(j=0;j<MAP_SIZE;j++) 
                {
                        if(rand() % 10 == 0) 
                        {
                                map[i][j] = '#';
                        }
                        else 
                        {
                                map[i][j] = '.';
                        }
                }
        }
}

void print_map() 
{
        int i, j;
        for(i=0;i<MAP_SIZE;i++) 
        {
                for(j=0;j<MAP_SIZE;j++) 
                {
                        printf("%c", map[i][j]);
                }
                printf("\n");
        }
}

int main() 
{
        srand(time(0));
        generate_map();
        print_map();
        return 0;
}