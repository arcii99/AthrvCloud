//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10 //number of rows in the maze
#define COLS 10 //number of columns in the maze
#define START_ROW 0 //starting row index
#define START_COL 0 //starting column index
#define END_ROW 9 //ending row index
#define END_COL 9 //ending column index

char maze[ROWS][COLS] = { //initialize the maze
    {'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'E'},
};

void printMaze() { //function to print the maze
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int findRoute(int row, int col) { //recursive function to find the route
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS) { //if out of bounds
        return 0;
    }
    if(maze[row][col] == '#') { //if hitting a wall
        return 0;
    }
    if(maze[row][col] == 'X') { //if already visited
        return 0;
    }
    if(row == END_ROW && col == END_COL) { //if reaching the end
        maze[row][col] = 'X';
        printMaze();
        printf("You found the exit!\n");
        return 1;
    }
    maze[row][col] = 'X'; //mark current position as visited
    printMaze();
    if(findRoute(row-1, col) || findRoute(row, col+1) || findRoute(row+1, col) || findRoute(row, col-1)) { //try all directions recursively
        return 1;
    }
    return 0; //if no route found
}

int main() { //main function
    printf("You are trapped in a maze! Find your way out.\n");
    printf("S is the starting point, E is the exit, # is a wall, X is the path you have taken.\n\n");
    printMaze();
    findRoute(START_ROW, START_COL);
    printf("Game over!\n");
    return 0;
}