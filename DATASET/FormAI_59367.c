//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>

// Function to print the maze
void print_maze(char maze[][10], int row, int col) {
    printf("\n");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c", maze[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

// Function to find the route
void find_route(char maze[][10], int row, int col, int x, int y, int stop_x, int stop_y) {
    // Check if we reached the stop point
    if (x == stop_x && y == stop_y) {
        // Print the maze with the route
        print_maze(maze, row, col);
        return;
    }

    if (maze[x][y] == 'X') {
        // Path already explored
        return;
    }

    // Mark the current position as visited
    maze[x][y] = 'X';

    // Move to the top
    if (x - 1 >= 0 && maze[x - 1][y] != '#') {
        find_route(maze, row, col, x - 1, y, stop_x, stop_y);
        maze[x - 1][y] = ' ';
    }

    // Move to the bottom
    if (x + 1 < row && maze[x + 1][y] != '#') {
        find_route(maze, row, col, x + 1, y, stop_x, stop_y);
        maze[x + 1][y] = ' ';
    }

    // Move to the left
    if (y - 1 >= 0 && maze[x][y - 1] != '#') {
        find_route(maze, row, col, x, y - 1, stop_x, stop_y);
        maze[x][y - 1] = ' ';
    }

    // Move to the right
    if (y + 1 < col && maze[x][y + 1] != '#') {
        find_route(maze, row, col, x, y + 1, stop_x, stop_y);
        maze[x][y + 1] = ' ';
    }
}

// Main function
int main() {
    // Define the maze
    char maze[10][10] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', '#', '#', 'E', ' ', '#'}
    };

    // Find the route
    find_route(maze, 10, 10, 1, 1, 9, 7);

    return 0;
}