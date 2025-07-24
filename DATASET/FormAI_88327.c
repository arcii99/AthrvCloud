//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define COLORS 3

int graph[SIZE][SIZE] = {
                        {0, 1, 0, 1, 0},
                        {1, 0, 1, 0, 0},
                        {0, 1, 0, 1, 1},
                        {1, 0, 1, 0, 1},
                        {0, 0, 1, 1, 0}
                       };
int color[SIZE];

void printGraph()
{
    printf("   ");
    for(int i=0; i<SIZE; i++)
        printf("%d ", i+1);
    printf("\n");
    for(int i=0; i<SIZE; i++)
    {
        printf("%d: ", i+1);
        for(int j=0; j<SIZE; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int isColorSafe(int nodeIndex, int c)
{
    for(int i=0; i<SIZE; i++)
    {
        if(graph[nodeIndex][i] == 1 && color[i] == c)
            return 0;
    }
    return 1;
}

int getMinColor(int nodeIndex)
{
    int c, flag = 0;
    for(c=1; c<=COLORS; c++)
    {
        if(isColorSafe(nodeIndex, c))
        {
            flag = 1;
            break;
        }
    }
    if(flag)
        return c;
    else
        return -1;
}

void colorGraph(int nodeIndex)
{
    if(nodeIndex == SIZE)
    {
        printf("Coloring of the given graph:\n");
        for(int i=0; i<SIZE; i++)
        {
            printf("Node %d -> Color %d\n", i+1, color[i]);
        }
        exit(0);
    }

    for(int c=1; c<=COLORS; c++)
    {
        if(isColorSafe(nodeIndex, c))
        {
            color[nodeIndex] = c;
            colorGraph(nodeIndex+1);
            color[nodeIndex] = 0;
        }
    }
}

int main()
{
    srand(time(NULL));
    printf("Welcome to the futuristic world of Cyberpunk graph coloring!\n");
    printf("Here is the given graph:\n");
    printGraph();
    for(int i=0; i<SIZE; i++)
    {
        color[i] = rand()%COLORS + 1;
    }
    printf("Initial random colors:\n");
    for(int i=0; i<SIZE; i++)
    {
        printf("Node %d -> Color %d\n", i+1, color[i]);
    }
    printf("Computing safe colors...\n");
    colorGraph(0);
    return 0;
}