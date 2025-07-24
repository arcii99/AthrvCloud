//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10
#define UNVISITED 0

int maze[ROW][COL];

// Function to check if the adjacent cells of (i,j) are valid and unvisited
int is_valid(int i, int j)
{
    if (i >= 0 && i < ROW && j >= 0 && j < COL && maze[i][j] == UNVISITED)
        return 1;
    else
        return 0;
}

// Function to generate a random order of directions to be checked
void shuffle(int *array, int n)
{
    if (n > 1)
    {
        int i;
        for (i = 0; i < n - 1; i++)
        {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

// Recursive function to generate the maze
void generate_maze(int i, int j)
{
    int directions[] = {1, 2, 3, 4}; // 1 for up, 2 for down, 3 for left, 4 for right
    shuffle(directions, 4);

    int d;
    for (d = 0; d < 4; d++)
    {
        int ni, nj;
        if (directions[d] == 1) // up
        {
            ni = i - 1;
            nj = j;
        }
        else if (directions[d] == 2) // down
        {
            ni = i + 1;
            nj = j;
        }
        else if (directions[d] == 3) // left
        {
            ni = i;
            nj = j - 1;
        }
        else if (directions[d] == 4) // right
        {
            ni = i;
            nj = j + 1;
        }

        if (is_valid(ni, nj))
        {
            maze[ni][nj] = maze[i][j] + 1;
            generate_maze(ni, nj);
        }
    }
}

int main()
{
    srand(time(NULL));

    // Initialize all maze cells as UNVISITED
    int i, j;
    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            maze[i][j] = UNVISITED;

    // Choose a random starting cell and mark it as visited
    int si = rand() % ROW;
    int sj = rand() % COL;
    maze[si][sj] = 1;

    // Generate the maze starting from (si,sj)
    generate_maze(si, sj);

    // Print the maze
    printf("Maze:\n");
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
            printf("%d ", maze[i][j]);
        printf("\n");
    }

    return 0;
}