//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Function to print maze
void print_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a position is valid in the maze
bool is_valid_position(int row, int col, char maze[ROWS][COLS]) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return false;
    }
    if (maze[row][col] == '#') {
        return false;
    }
    return true;
}

// Function to find a path through the maze
bool find_path(char maze[ROWS][COLS], int start_row, int start_col, int end_row, int end_col) {
    if (!is_valid_position(start_row, start_col, maze)) {
        return false;
    }
    if (start_row == end_row && start_col == end_col) {
        maze[start_row][start_col] = 'X';
        return true;
    }
    
    maze[start_row][start_col] = 'o';
    
    if (find_path(maze, start_row - 1, start_col, end_row, end_col)) {
        maze[start_row][start_col] = 'X';
        return true;
    }
    if (find_path(maze, start_row + 1, start_col, end_row, end_col)) {
        maze[start_row][start_col] = 'X';
        return true;
    }
    if (find_path(maze, start_row, start_col - 1, end_row, end_col)) {
        maze[start_row][start_col] = 'X';
        return true;
    }
    if (find_path(maze, start_row, start_col + 1, end_row, end_col)) {
        maze[start_row][start_col] = 'X';
        return true;
    }
    
    maze[start_row][start_col] = '.';
    
    return false;
}

int main() {
    char maze[ROWS][COLS] = {
        "#S........",
        "#########.",
        "........#.",
        ".########.",
        ".#......#.",
        ".#.####.#.",
        ".#.#..#.#.",
        ".###.#.#.#",
        "....#...#.",
        ".#######E#"
    };
    
    printf("Maze:\n");
    print_maze(maze);
    
    int start_row = 0;
    int start_col = 1;
    int end_row = 9;
    int end_col = 9;
    
    printf("Finding path...\n");
    bool path_found = find_path(maze, start_row, start_col, end_row, end_col);
    
    if (path_found) {
        printf("Path found!\n");
        print_maze(maze);
    } else {
        printf("No path found.\n");
    }
    
    return 0;
}