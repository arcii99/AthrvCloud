//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Cryptic
//Breaking the labyrinth code: K-Riddler's Way

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

//Function to check if the location is within the maze
bool within_maze(int row, int col)
{
    if(row>=0 && row < ROW && col>=0 && col<COL) return true;
    else return false;
}

//Function to check if the location is open or blocked
bool is_open(char maze[][COL], int row, int col)
{
    if(maze[row][col] == '.') return true;
    else return false;
}

//Find the shortest path to the finish line
bool solve_maze(char maze[][COL], int start_row, int start_col, int finish_row, int finish_col)
{
    //Create a solution grid with all paths marked as unexplored
    int solution[ROW][COL];
    int i,j;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            solution[i][j] = -1;
        }
    }

    //Define possible movements: up, down, left, right
    int row_move[] = {-1,0,1,0};
    int col_move[] = {0,1,0,-1};

    //Start by marking the initial position as the starting point with zero steps
    solution[start_row][start_col] = 0;

    //Declare the queue for the graph
    int queue[ROW*COL];
    int q_front = 0, q_rear = 0;

    //Enqueue the starting point
    queue[q_rear++] = start_row*COL + start_col;

    int current_row, current_col, next_row, next_col;

    //Main loop to find the shortest path
    while(q_front!=q_rear)
    {
        //Get the current position
        int current_pos = queue[q_front++];
        current_row = current_pos / COL;
        current_col = current_pos % COL;

        //Check if finish has been reached
        if(current_row==finish_row && current_col==finish_col) break;

        //Visit each neighbor
        for(i=0;i<4;i++)
        {
            next_row = current_row + row_move[i];
            next_col = current_col + col_move[i];

            //Check if the neighbor is within bounds and is a valid move
            if(within_maze(next_row,next_col) && is_open(maze,next_row,next_col) && solution[next_row][next_col]==-1)
            {
                //Mark the current step
                solution[next_row][next_col] = solution[current_row][current_col] + 1;
                //Enqueue the next position
                queue[q_rear++] = next_row*COL + next_col;
            }
        }
    }

    //Print the solution
    if(solution[finish_row][finish_col] == -1)
    {
        printf("No solution found.");
        return false;
    }
    else
    {
        printf("Shortest path: %d steps\n",solution[finish_row][finish_col]);
        int step = solution[finish_row][finish_col];

        //Backtrack the path until start is reached
        printf("Path: ");
        while(step>0)
        {
            printf("(%d,%d) ",current_row,current_col);
            for(i=0;i<4;i++)
            {
                next_row = current_row + row_move[i];
                next_col = current_col + col_move[i];

                if(within_maze(next_row,next_col) && solution[next_row][next_col]==step-1)
                {
                    current_row = next_row;
                    current_col = next_col;
                    step--;
                    break;
                }
            }
        }
        printf("(%d,%d)\n",current_row,current_col);
        return true;
    }
}

//Driver code
int main(void)
{
    //Input the maze
    char maze[ROW][COL] = { {'#','.','#','.','#'},
                            {'#','.','.','.','#'},
                            {'#','.','#','.','#'},
                            {'#','.','#','.','.'},
                            {'#','#','#','#','#'} };

    //Input the starting and ending positions
    int start_row = 0, start_col = 1, finish_row = 4, finish_col = 3;

    //Solve the maze
    solve_maze(maze,start_row,start_col,finish_row,finish_col);

    return 0;
}