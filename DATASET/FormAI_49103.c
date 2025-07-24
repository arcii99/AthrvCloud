//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 20
#define COL 50

char maze[ROW][COL];

//Function to print the maze
void printMaze()
{
    system("clear");  //clear the terminal in unix based systems 

    for(int i=0; i<ROW; i++)
    {
        printf("%s\n", maze[i]);
    }
}

//Function to generate random maze
void generateMaze()
{
    srand(time(NULL));    //seed the random number generator

    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(i==0 || i==ROW-1 || j==0 || j==COL-1)    //Create boundary walls
            {
                maze[i][j] = '#';
            }
            else    
            {
                int r = rand()%10;   //generate random number between 0 and 9

                if(r<8) //80% of the spaces are empty
                {
                    maze[i][j] = ' ';
                }
                else    //20% of the spaces are walls
                {
                    maze[i][j] = '#';
                }
            }
        }
    }

    maze[1][1] = ' ';   //Entrance point
    maze[ROW-2][COL-2] = ' ';   //Exit point

    printMaze();
}

//Function to find the path in the maze
void findPath(int row, int col)
{
    if(maze[row][col] == '#' || maze[row][col] == '.')   //If the cell is a wall or already visited
    {
        return;
    }

    if(row == ROW-2 && col == COL-2)    //If the exit point is reached
    {
        maze[row][col] = '.';   //Mark this cell as part of the path
        printMaze();
        printf("Path Found!!!\n");
        return;
    }

    maze[row][col] = '.';   //Mark this cell as part of the path
    printMaze();

    findPath(row-1, col);   //Check cell above
    findPath(row+1, col);   //Check cell below
    findPath(row, col-1);   //Check cell to the left
    findPath(row, col+1);   //Check cell to the right

    maze[row][col] = ' ';   //If the current path did not lead to the exit, mark this cell as not visited
}

int main()
{
    generateMaze();
    findPath(1,1);
    return 0;
}