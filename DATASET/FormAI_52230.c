//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: shocked
#define SIZE 10 // Size of the maze

// Function to print the maze
void printMaze(char maze[][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the cell is valid
int isValid(int x, int y, char maze[][SIZE]) {
    if(x>=0 && x<SIZE && y>=0 && y<SIZE && maze[x][y]==' ') {
        return 1;
    }
    return 0;
}

// Function to solve the maze
int solveMazeUtil(int x, int y, char maze[][SIZE], int sol[][SIZE]) {
    if(x == SIZE-1 && y == SIZE-1) { // Base case when we have reached the destination
        sol[x][y] = 1;
        return 1;
    }
    if(isValid(x, y, maze)) { // If the current cell is a valid path
        sol[x][y] = 1; // Mark the cell as visited
        if(solveMazeUtil(x+1, y, maze, sol) == 1) { // Move down
            return 1;
        }
        if(solveMazeUtil(x, y+1, maze, sol) == 1) { // Move right
            return 1;
        }
        if(solveMazeUtil(x-1, y, maze, sol) == 1) { // Move up
            return 1;
        }
        if(solveMazeUtil(x, y-1, maze, sol) == 1) { // Move left
            return 1;
        }
        sol[x][y] = 0; // If none of the above paths lead to the destination, backtrack
    }
    return 0;
}

// Function to solve the maze
void solveMaze(char maze[][SIZE]) {
    int sol[SIZE][SIZE] = {0}; // Create a 2D array to store the solution
    if(solveMazeUtil(0, 0, maze, sol) == 1) { // If there is a solution
        printMaze(maze);
    }
    else {
        printf("No path found!\n"); // Otherwise, print no path found!
    }
}

// Driver function
int main() {
    char maze[SIZE][SIZE] = {
        {' ', '*', ' ', '*', '*', '*', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' '},
        {'*', '*', '*', '*', '*', ' ', '*', '*', '*', ' '},
        {' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' '},
        {'*', '*', '*', ' ', '*', ' ', '*', '*', '*', ' '},
        {' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' '},
        {'*', '*', '*', '*', '*', ' ', '*', '*', '*', ' '},
        {' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' '},
        {'*', '*', '*', '*', '*', ' ', '*', '*', '*', ' '},
        {' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' '}
    };
    solveMaze(maze);
    return 0;
}