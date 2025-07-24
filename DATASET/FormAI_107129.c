//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 8
#define COL 8

void findRoute(int, int);
int isSafe(int, int);
int maze[ROW][COL];

int main()
{
    int i, j;
    srand(time(0));     //seeding rand function with time to get random values

    //Initialising the maze with 0's and 1's randomly
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            maze[i][j] = rand()%2;
        }
    }

    //Printing the maze
    printf("Here is the randomly generated maze:\n");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    //Starting position of robot
    printf("Enter the starting position i and j (less than 8) separated by space: ");
    int si, sj;
    scanf("%d%d", &si, &sj);

    //Checking if starting position is valid or not
    if(si<0 || si>=ROW || sj<0 || sj>=COL)
    {
        printf("Error: Invalid starting position.\n");
        exit(0);
    }

    //Destination position of robot
    printf("Enter the destination position i and j (less than 8) separated by space: ");
    int di, dj;
    scanf("%d%d", &di, &dj);

    //Checking if destination position is valid or not
    if(di<0 || di>=ROW || dj<0 || dj>=COL)
    {
        printf("Error: Invalid destination position.\n");
        exit(0);
    }

    //If starting position and destination position are same
    if(si==di && sj==dj)
    {
        printf("You have reached your destination.\n");
        exit(0);
    }

    //Finding the route
    findRoute(si, sj);

    //Checking if route is found or not
    if(maze[di][dj]==2)
    {
        printf("Route found.\n");
    }
    else
    {
        printf("Route not found.\n");
    }

    //Printing the maze with route
    printf("Here is the maze with route:\n");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//Finding the route
void findRoute(int i, int j)
{
    //Base condition
    if(i<0 || i>=ROW || j<0 || j>=COL || maze[i][j]==1 || maze[i][j]==2)
    {
        return;
    }

    //Marking visited positions with 2
    maze[i][j] = 2;

    //Going in all directions to find the route
    findRoute(i-1, j);  //up
    findRoute(i+1, j);  //down
    findRoute(i, j-1);  //left
    findRoute(i, j+1);  //right
}

//Checking if position is safe or not
int isSafe(int i, int j)
{
    if(i<0 || i>=ROW || j<0 || j>=COL || maze[i][j]==1)
    {
        return 0;
    }
    return 1;
}