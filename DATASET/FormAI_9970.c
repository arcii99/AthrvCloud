//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 20

void generate_maze(int maze[HEIGHT][WIDTH]);
void print_maze(int maze[HEIGHT][WIDTH]);

int main()
{
    srand(time(NULL));

    int maze[HEIGHT][WIDTH];
    generate_maze(maze);
    print_maze(maze);

    return 0;
}

void generate_maze(int maze[HEIGHT][WIDTH])
{
    // Fill the maze with walls
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            maze[i][j] = 1;
        }
    }

    // Carve out the maze using a depth-first search algorithm
    int stack[HEIGHT * WIDTH][2];
    int top = 0;

    int visited[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            visited[i][j] = 0;
        }
    }

    int start_i = rand() % HEIGHT;
    int start_j = rand() % WIDTH;
    stack[top][0] = start_i;
    stack[top][1] = start_j;
    top++;
    visited[start_i][start_j] = 1;

    while (top > 0)
    {
        int current_i = stack[top-1][0];
        int current_j = stack[top-1][1];

        // Check if we're at a dead end or if we've already visited this cell
        int num_neighbors = 0;
        int neighbors[4][2] = {
            {current_i-1, current_j},
            {current_i+1, current_j},
            {current_i, current_j-1},
            {current_i, current_j+1}
        };

        for (int k = 0; k < 4; k++)
        {
            int ni = neighbors[k][0];
            int nj = neighbors[k][1];

            if (ni >= 0 && ni < HEIGHT && nj >= 0 && nj < WIDTH && visited[ni][nj])
            {
                num_neighbors++;
            }
        }

        if (num_neighbors >= 3)
        {
            top--;
            continue;
        }

        // Carve out the passage and mark the cell as visited
        maze[current_i][current_j] = 0;
        visited[current_i][current_j] = 1;

        // Add the unvisited neighboring cells to the stack
        int unvisited[4][2];
        int num_unvisited = 0;

        for (int k = 0; k < 4; k++)
        {
            int ni = neighbors[k][0];
            int nj = neighbors[k][1];

            if (ni >= 0 && ni < HEIGHT && nj >= 0 && nj < WIDTH && !visited[ni][nj])
            {
                unvisited[num_unvisited][0] = ni;
                unvisited[num_unvisited][1] = nj;
                num_unvisited++;
            }
        }

        if (num_unvisited > 0)
        {
            int chosen = rand() % num_unvisited;
            int ni = unvisited[chosen][0];
            int nj = unvisited[chosen][1];
            stack[top][0] = ni;
            stack[top][1] = nj;
            top++;
        }
        else
        {
            top--;
        }
    }
}

void print_maze(int maze[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (maze[i][j] == 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}