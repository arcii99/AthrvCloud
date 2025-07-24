//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10 // Define number of rows in maze
#define COLUMNS 20 // Define number of columns in maze
#define MAXSTACK 1000 // Define maximum size of stack

typedef struct Stack{ // Define structure for a stack
    int row;
    int column;
} Stack;

Stack stack[MAXSTACK]; // Create an array stack of type Stack
int top = -1; // Initialize top of stack to -1

char maze[ROWS][COLUMNS] = { // Create a 2D array for the maze
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '.', '#', '.', '#', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '#', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
}; 

void push(int row, int column){ // Define push function for the stack
    top++;
    stack[top].row = row;
    stack[top].column = column;
}

void pop(){ // Define pop function for the stack
    top--;
}

bool isStackEmpty(){ // Define function to check if stack is empty
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

void printMaze(){ // Define function to print the maze
    
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

bool isExit(int row, int column){ // Define function to check if current position is the exit position
    
    if(row == 0 || row == ROWS-1 || column == 0 || column == COLUMNS-1){
        return true;
    }
    else{
        return false;
    }
}

void findRoute(){ // Define function to find the route through the maze
    
    int row = 1; // Initialize starting position
    int column = 1;
    
    while(!isExit(row, column)){ // Loop until exit is found
        if(maze[row][column+1] == '.'){ // Check if path to right is clear
            push(row, column); // Push current position onto the stack
            maze[row][column] = '+'; // Mark current position as visited
            column++; // Move to next position
        }
        else if(maze[row+1][column] == '.'){ // Check if path below is clear
            push(row, column); // Push current position onto the stack
            maze[row][column] = '+'; // Mark current position as visited
            row++; // Move to next position
        }
        else if(maze[row][column-1] == '.'){ // Check if path to left is clear
            push(row, column); // Push current position onto the stack
            maze[row][column] = '+'; // Mark current position as visited
            column--; // Move to next position
        }
        else if(maze[row-1][column] == '.'){ // Check if path above is clear
            push(row, column); // Push current position onto the stack
            maze[row][column] = '+'; // Mark current position as visited
            row--; // Move to next position
        }
        else{ // If there is no clear path, backtrack
            maze[row][column] = '*'; // Mark current position as a dead end
            if(isStackEmpty()){ // If stack is empty, there is no route
                printf("No route found\n");
                return;
            }
            row = stack[top].row; // Move back to previous position
            column = stack[top].column;
            pop(); // Pop previous position off the stack
        }
        printMaze(); // Print maze after each move
        printf("\n");
    }
    printf("Route found!\n"); // Print message when route is found
}

int main(){
    
    findRoute(); // Call function to find the route
    
    return 0;
}