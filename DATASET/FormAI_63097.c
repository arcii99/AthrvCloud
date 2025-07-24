//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>

#define ROWS 8
#define COLUMNS 8

// Define the maze with start and end positions
char maze[ROWS][COLUMNS] = {
    {'S', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', 'E'}
};

// Define movement directions
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// Define a queue structure for BFS
struct queue {
    int x;
    int y;
    int distance;
} q[ROWS * COLUMNS];

int head = 0;
int tail = 0;

// Check if the given position is valid
bool is_valid(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLUMNS && maze[x][y] != '#' && maze[x][y] != 'V';
}

// Perform BFS to find the shortest path to the end
void bfs(int start_x, int start_y) {
    struct queue start = {start_x, start_y, 0};
    q[tail++] = start;
    
    while (head != tail) {
        struct queue current = q[head++];
        int x = current.x;
        int y = current.y;
        int distance = current.distance;
        
        if (maze[x][y] == 'E') {
            printf("Shortest distance to end: %d\n", distance);
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            if (is_valid(new_x, new_y)) {
                maze[new_x][new_y] = 'V';
                struct queue next = {new_x, new_y, distance + 1};
                q[tail++] = next;
            }
        }
    }
}

// Print the maze with the shortest path
void print_maze() {
    printf("The shortest path through the maze:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (maze[i][j] == 'S' || maze[i][j] == 'E' || maze[i][j] == '.' || maze[i][j] == '*') {
                printf("%c ", maze[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Main program execution
int main() {
    bfs(0, 0);
    
    int x = ROWS - 1;
    int y = COLUMNS - 1;
    int shortest_distance = ROWS * COLUMNS;
    while (x != 0 || y != 0) {
        if (maze[x][y - 1] == '*' && maze[x][y - 2] < shortest_distance) {
            maze[x][y - 1] = '.';
            maze[x][y - 2] = '*';
            shortest_distance = maze[x][y - 2];
            y -= 2;
        } else if (maze[x - 1][y] == '*' && maze[x - 2][y] < shortest_distance) {
            maze[x - 1][y] = '.';
            maze[x - 2][y] = '*';
            shortest_distance = maze[x - 2][y];
            x -= 2;
        } else if (maze[x][y + 1] == '*' && maze[x][y + 2] < shortest_distance) {
            maze[x][y + 1] = '.';
            maze[x][y + 2] = '*';
            shortest_distance = maze[x][y + 2];
            y += 2;
        } else if (maze[x + 1][y] == '*' && maze[x + 2][y] < shortest_distance) {
            maze[x + 1][y] = '.';
            maze[x + 2][y] = '*';
            shortest_distance = maze[x + 2][y];
            x += 2;
        } else {
            break;
        }
    }

    // Print the maze with the shortest path
    print_maze();
    
    return 0;
}