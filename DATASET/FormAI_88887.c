//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 11
#define COLS 11

void generate_maze(char maze[ROWS][COLS]);
void print_maze(char maze[ROWS][COLS]);

int main(void)
{
    char maze[ROWS][COLS];
    generate_maze(maze);
    print_maze(maze);
    return 0;
}

void generate_maze(char maze[ROWS][COLS])
{
    srand(time(NULL));

    // Set all cells to wall initially
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            maze[i][j] = '#';
        }
    }

    // Choose a random starting cell
    int current_row = rand() % ROWS;
    int current_col = rand() % COLS;

    // Mark the starting cell as visited
    maze[current_row][current_col] = ' ';

    // Create a list of unvisited cells
    int unvisited_count = (ROWS - 1) / 2 * (COLS - 1) / 2 - 1;
    int unvisited[unvisited_count][2];
    int count = 0;
    for (int i = 1; i < ROWS; i += 2)
    {
        for (int j = 1; j < COLS; j += 2)
        {
            if (maze[i][j] == '#')
            {
                unvisited[count][0] = i;
                unvisited[count][1] = j;
                count++;
            }
        }
    }

    // Generate the maze using a depth first search algorithm
    while (unvisited_count > 0)
    {
        // Choose a random unvisited neighbor
        int neighbors[4][2] = {{-2, 0}, {0, 2}, {2, 0}, {0, -2}};
        int neighbor_count = 0;
        int neighbor_index = 0;
        for (int i = 0; i < 4; i++)
        {
            int row = current_row + neighbors[i][0];
            int col = current_col + neighbors[i][1];
            if (row >= 1 && row < ROWS - 1 && col >= 1 && col < COLS - 1)
            {
                if (maze[row][col] == '#')
                {
                    neighbor_count++;
                    neighbor_index = i;
                }
            }
        }
        if (neighbor_count > 0)
        {
            // Break down the wall between the current cell and the chosen neighbor
            int wall_row = current_row + neighbors[neighbor_index][0] / 2;
            int wall_col = current_col + neighbors[neighbor_index][1] / 2;
            maze[wall_row][wall_col] = ' ';

            // Move to the chosen neighbor and mark it as visited
            current_row += neighbors[neighbor_index][0];
            current_col += neighbors[neighbor_index][1];
            maze[current_row][current_col] = ' ';

            // Remove the chosen neighbor from the unvisited list
            for (int i = 0; i < unvisited_count; i++)
            {
                if (unvisited[i][0] == current_row && unvisited[i][1] == current_col)
                {
                    unvisited[i][0] = unvisited[unvisited_count-1][0];
                    unvisited[i][1] = unvisited[unvisited_count-1][1];
                    unvisited_count--;
                    break;
                }
            }
        }
        else
        {
            // Backtrack to the previous cell
            current_row -= neighbors[neighbor_index][0];
            current_col -= neighbors[neighbor_index][1];
        }
    }
}

void print_maze(char maze[ROWS][COLS])
{
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}