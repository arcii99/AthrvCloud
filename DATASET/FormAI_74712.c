//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to represent a point in the maze
typedef struct {
    int x;
    int y;
    int dist;
    char prevDir;
} Point;

// Helper function to create a new point
Point newPoint(int x, int y, int dist, char prevDir) {
    Point p;
    p.x = x;
    p.y = y;
    p.dist = dist;
    p.prevDir = prevDir;
    return p;
}

// Function to read the maze from a file
char** readMaze(char* filename, int* rows, int* cols) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file!");
        exit(1);
    }
    // Read the first line to get the number of columns
    char firstLine[100];
    fgets(firstLine, 100, fp);
    *cols = strlen(firstLine) - 1;
    // Count the number of rows
    int lineCount = 1;
    while (fgets(firstLine, 100, fp) != NULL) {
        lineCount++;
    }
    *rows = lineCount;
    // Allocate memory for the maze
    char** maze = (char**) malloc(*rows * sizeof(char*));
    for (int i = 0; i < *rows; i++) {
        maze[i] = (char*) malloc((*cols + 1) * sizeof(char));
        memset(maze[i], '\0', (*cols + 1) * sizeof(char));
    }
    rewind(fp);
    lineCount = 0;
    while (fgets(maze[lineCount], (*cols + 1), fp) != NULL) {
        lineCount++;
    }
    fclose(fp);
    return maze;
}

// Helper function to check if a point is valid and not a wall or already visited
int isValid(char** maze, int rows, int cols, int x, int y, int visited[][cols]) {
    if (x < 0 || y < 0 || x >= rows || y >= cols) return 0;
    if (maze[x][y] == '#' || visited[x][y]) return 0;
    return 1;
}

// Function to find the shortest route through a maze
char* findRoute(char** maze, int rows, int cols, Point src, Point dest) {
    // Allocate memory for the visited matrix and initialize it to 0
    int visited[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }
    // Initialize the queue and enqueue the source point
    Point queue[rows * cols];
    int front = 0, rear = 0;
    queue[rear++] = src;
    visited[src.x][src.y] = 1;
    // Loop until the queue is empty or the destination is found
    while (front < rear) {
        Point cur = queue[front++];
        // If the destination is found, backtrack to construct the path
        if (cur.x == dest.x && cur.y == dest.y) {
            char* path = (char*) malloc((cur.dist + 1) * sizeof(char));
            int idx = cur.dist - 1;
            while (cur.x != src.x || cur.y != src.y) {
                path[idx--] = cur.prevDir;
                switch (cur.prevDir) {
                    case 'U': cur.x++; break;
                    case 'D': cur.x--; break;
                    case 'L': cur.y++; break;
                    case 'R': cur.y--; break;
                }
            }
            path[cur.dist] = '\0';
            return path;
        }
        // Enqueue neighboring points that are valid
        if (isValid(maze, rows, cols, cur.x - 1, cur.y, visited)) {
            queue[rear++] = newPoint(cur.x - 1, cur.y, cur.dist + 1, 'U');
            visited[cur.x - 1][cur.y] = 1;
        }
        if (isValid(maze, rows, cols, cur.x + 1, cur.y, visited)) {
            queue[rear++] = newPoint(cur.x + 1, cur.y, cur.dist + 1, 'D');
            visited[cur.x + 1][cur.y] = 1;
        }
        if (isValid(maze, rows, cols, cur.x, cur.y - 1, visited)) {
            queue[rear++] = newPoint(cur.x, cur.y - 1, cur.dist + 1, 'L');
            visited[cur.x][cur.y - 1] = 1;
        }
        if (isValid(maze, rows, cols, cur.x, cur.y + 1, visited)) {
            queue[rear++] = newPoint(cur.x, cur.y + 1, cur.dist + 1, 'R');
            visited[cur.x][cur.y + 1] = 1;
        }
    }
    // If the destination is not found, return NULL
    return NULL;
}

int main() {
    // Read the maze from file
    char** maze;
    int rows, cols;
    maze = readMaze("maze.txt", &rows, &cols);

    // Find the shortest route through the maze
    Point src = newPoint(0, 1, 0, '\0');
    Point dest = newPoint(rows - 1, cols - 2, 0, '\0');
    char* route = findRoute(maze, rows, cols, src, dest);

    // Print the maze and the shortest route
    if (route == NULL) {
        printf("No route found!");
    } else {
        printf("Shortest route length: %d\n", strlen(route));
        for (int i = 0; i < rows; i++) {
            printf("%s", maze[i]);
        }
        printf("Shortest route: %s\n", route);
        free(route);
    }
    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(maze[i]);
    }
    free(maze);
    return 0;
}