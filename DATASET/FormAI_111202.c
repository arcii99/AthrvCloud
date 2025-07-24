//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

char map[ROWS][COLS] = {
    {'.', '.', '#', '.', '#', '.', '#', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '#', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '#', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '#', '.', '.', '#'},
    {'.', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'.', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'.', '.', '#', '#', '#', '.', '#', '.', '.', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '.', '.', '.'},
};

int distances[ROWS][COLS];

typedef struct node
{
    int x;
    int y;
    struct node *next;
} node;

node *path = NULL;

int find_shortest_path(int start_x, int start_y, int end_x, int end_y)
{
    int i, j;
    node *tmp, *tmp2, *new_node;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            distances[i][j] = -1;
        }
    }

    distances[start_x][start_y] = 0;

    while (distances[end_x][end_y] == -1)
    {
        for (i = 0; i < ROWS; i++)
        {
            for (j = 0; j < COLS; j++)
            {
                if (map[i][j] == '#' || distances[i][j] != -1)
                {
                    continue;
                }

                if (i > 0 && distances[i - 1][j] != -1)
                {
                    distances[i][j] = distances[i - 1][j] + 1;
                }

                if (i < ROWS - 1 && distances[i + 1][j] != -1)
                {
                    distances[i][j] = distances[i + 1][j] + 1;
                }

                if (j > 0 && distances[i][j - 1] != -1)
                {
                    distances[i][j] = distances[i][j - 1] + 1;
                }

                if (j < COLS - 1 && distances[i][j + 1] != -1)
                {
                    distances[i][j] = distances[i][j + 1] + 1;
                }
            }
        }
    }

    i = end_x;
    j = end_y;
    tmp = NULL;

    while (i != start_x || j != start_y)
    {
        new_node = (node *)malloc(sizeof(node));
        new_node->x = i;
        new_node->y = j;
        new_node->next = tmp;
        tmp = new_node;

        if (i > 0 && distances[i - 1][j] == distances[i][j] - 1)
        {
            i--;
        }
        else if (i < ROWS - 1 && distances[i + 1][j] == distances[i][j] - 1)
        {
            i++;
        }
        else if (j > 0 && distances[i][j - 1] == distances[i][j] - 1)
        {
            j--;
        }
        else if (j < COLS - 1 && distances[i][j + 1] == distances[i][j] - 1)
        {
            j++;
        }
    }

    new_node = (node *)malloc(sizeof(node));
    new_node->x = start_x;
    new_node->y = start_y;
    new_node->next = tmp;
    path = new_node;

    tmp = path;
    tmp2 = path->next;
    free(tmp);

    while (tmp2 != NULL)
    {
        tmp = tmp2;
        tmp2 = tmp2->next;
        free(tmp);
    }

    return distances[end_x][end_y];
}

int main()
{
    int start_x = 3;
    int start_y = 3;
    int end_x = 7;
    int end_y = 2;
    int distance;
    int i, j;

    distance = find_shortest_path(start_x, start_y, end_x, end_y);

    if (distance != -1)
    {
        printf("The shortest distance is %d\n", distance);
        printf("The path is:\n");

        for (i = 0; i < ROWS; i++)
        {
            for (j = 0; j < COLS; j++)
            {
                if (i == start_x && j == start_y)
                {
                    printf("S ");
                }
                else if (i == end_x && j == end_y)
                {
                    printf("E ");
                }
                else if (distances[i][j] != -1)
                {
                    printf("%d ", distances[i][j]);
                }
                else
                {
                    printf("  ");
                }
            }

            printf("\n");
        }
        printf("\n");
    }
    else
    {
        printf("No path found!\n");
    }

    return 0;
}