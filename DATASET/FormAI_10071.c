//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

//Define the size of the maze
#define ROW 10
#define COL 10

// Function prototypes
void print_maze(int maze[ROW][COL], int start_row, int start_col, int end_row, int end_col);
void find_route(int maze[ROW][COL], int start_row, int start_col, int end_row, int end_col);

int main()
{
    int maze[ROW][COL] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 1, 0, 0, 0, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 2}
    };
    
    //Define starting and ending points
    int start_row = 1, start_col = 0;
    int end_row = 9, end_col = 9;

    //call the function
    find_route(maze, start_row, start_col, end_row, end_col);

    return 0;
}

void find_route(int maze[ROW][COL], int start_row, int start_col, int end_row, int end_col)
{
    // Define direction - Right, Down, Left, Up
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};

    int queue[ROW*COL]; // Define queue to keep track of the path
    int queue_front = 0, queue_rear = 0;
    queue[queue_rear++] = start_row*COL + start_col;
    maze[start_row][start_col] = 2; //Mark as visited

    while(queue_front != queue_rear)
    {
        int idx = queue[queue_front++];
        int row = idx / COL, col = idx % COL;

        if(row == end_row && col == end_col)
        {
            print_maze(maze, start_row, start_col, end_row, end_col); // Print maze with path
            return;
        }

        // Move in all four directions
        for(int d=0; d<4; d++)
        {
            int r = row + dr[d], c = col + dc[d];

            //Check if point is within the boundaries and unvisited
            if(r >= 0 && r < ROW && c >= 0 && c < COL && maze[r][c] == 0)
            {
                queue[queue_rear++] = r*COL + c;
                maze[r][c] = maze[row][col] + 1;
            }
        }
    }

    //Exit if there's no path
    printf("No path found to reach the end point.");
}

void print_maze(int maze[ROW][COL], int start_row, int start_col, int end_row, int end_col)
{
    printf("\nPath:\n");
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(i == start_row && j == start_col)
                printf("S ");
            else if(i == end_row && j == end_col)
                printf("E ");
            else if(maze[i][j] == 2)
                printf("P ");
            else if(maze[i][j] == 1)
                printf("# ");
            else if(maze[i][j] == 0)
                printf(". ");
        }
        printf("\n");
    }
}