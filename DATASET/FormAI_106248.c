//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10
#define COL 20

int map[ROW][COL];

void initializeMap()
{
    int i, j;
    srand(time(NULL));
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            if((i==0 && j==0) || (i==ROW-1 && j==COL-1))
                map[i][j] = 0;
            else
                map[i][j] = rand()%2;
        }
    }
}

void printMap()
{
    int i, j;
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            if(map[i][j] == 0)
                printf(" S ");
            else if(map[i][j] == 1)
                printf(" X ");
        }
        printf("\n");
    }
}

int findPath(int r, int c)
{
    if((r<0 || r>=ROW || c<0 || c>=COL) || (map[r][c] == 1))
        return 0;
    else if(r == ROW-1 && c == COL-1)
        return 1;
    map[r][c] = 1;
    if(findPath(r-1,c) == 1)
        return 1;
    if(findPath(r+1,c) == 1)
        return 1;
    if(findPath(r,c-1) == 1)
        return 1;
    if(findPath(r,c+1) == 1)
        return 1;
    return 0;
}

int main()
{
    initializeMap();
    printf("Initial Map:\n");
    printMap();
    printf("\n");
    if(findPath(0,0) == 1)
    {
        printf("Path Found! Final Map:\n");
        printMap();
    }
    else
        printf("Path Not Found!\n");
    return 0;
}