//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 41

// Function to print the maze
void display(char maze[][COLS])  
{  
    for(int i=0;i<ROWS;i++)  
    {  
        for(int j=0;j<COLS;j++)  
        {  
            printf("%c", maze[i][j]);  
        }  
        printf("\n");  
    }  
}  

int main()  
{  
    char maze[ROWS][COLS];  
    int i, j, start_row, start_col;  

    // Setting up boundaries of the maze with walls
    for(i=0; i<ROWS; i++)  
    {  
        for(j=0; j<COLS; j++)  
        {  
            if(i == 0 || i == ROWS-1 || j == 0 || j == COLS-1)  
            {  
                maze[i][j] = '#';  
            }  
            else  
            {  
                maze[i][j] = ' ';  
            }  
        }  
    }  

    // Random seed for different maze each time 
    srand(time(0));  

    // Starting point of the maze
    start_row = 1 + rand()%(ROWS-2);  
    start_col = 1 + rand()%(COLS-2);  
    maze[start_row][start_col] = 'S';  
    
    int current_row = start_row;
    int current_col = start_col;
    int visited[ROWS][COLS]={0};

    // Randomly generates a path until the end is found
    while (maze[current_row][current_col]!= 'E')  
    {  
        visited[current_row][current_col]=1;
        
        // Randomly chooses a direction to move in
        int direction = rand()%4+1;
        
        // Depending on the direction, moves in that direction
        if (direction==1 && (current_row-2)>0 && (!visited[current_row-2][current_col]))
        {
            maze[current_row-1][current_col] = '#';
            maze[current_row-2][current_col] = ' ';
            current_row -=2;
        }
        else if (direction==2 && (current_col+2)<COLS && (!visited[current_row][current_col+2]))
        {
            maze[current_row][current_col+1] = '#';
            maze[current_row][current_col+2] = ' ';
            current_col +=2;
        }
        else if (direction==3 && (current_row+2)<ROWS && (!visited[current_row+2][current_col]))
        {
            maze[current_row+1][current_col] = '#';
            maze[current_row+2][current_col] = ' ';
            current_row +=2;
        }
        else if (direction==4 && (current_col-2)>0 && (!visited[current_row][current_col-2]))
        {
            maze[current_row][current_col-1] = '#';
            maze[current_row][current_col-2] = ' ';
            current_col -=2;
        }
    }

    // End point of the maze
    maze[current_row][current_col] = 'E';
    
    // Display the final maze
    display(maze); 

    return 0;  
}