//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

#define V 4

int graph[V][V] = { {0, 1, 1, 1},
                    {1, 0, 1, 0},
                    {1, 1, 0, 1},
                    {1, 0, 1, 0} };
int color[V];

/* Function to check if the given color is valid at position v */
int isValid(int v, int c)
{
    int i;
    for(i=0;i<V;i++)
    {
        if(graph[v][i] && color[i] == c)
        {
            return 0;
        }
    }
    return 1;
}

/* Function to print colors assigned */
void printColors()
{
    int i;
    printf("Colors Assigned:\n");
    for(i=0;i<V;i++)
    {
        printf("%d ", color[i]);
    }
    printf("\n");
}

/* Function to check if all vertices have been assigned a color */
int isAllColored()
{
    int i;
    for(i=0;i<V;i++)
    {
        if(color[i] == -1)
        {
            return 0;
        }
    }
    return 1;
}

/* Recursive function to assign colors to vertices */
void assignColorsRecursive(int v)
{
    int c;
    
    /* Base condition */
    if(isAllColored())
    {
        printColors();
        return;
    }
    
    for(c=1;c<=V;c++)
    {
        if(isValid(v,c))
        {
            color[v] = c;
            assignColorsRecursive(v+1);
            color[v] = -1;
        }
    }
}

/* Driver Function */
int main()
{
    int i;
    for(i=0;i<V;i++)
    {
        color[i] = -1;
    }
    assignColorsRecursive(0);
    return 0;
}