//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include<stdio.h>

// Maze dimensions
#define N 6
#define M 6

// Maze array
char maze[N][M] = {
    {'#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', '#'},
    {'#', '#', '#', ' ', '#', '#'},
    {'#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', '#'},
    {'#', '#', '#', '#', '#', '#'}
};

// Stack data structure implementation
typedef struct {
    int x;
    int y;
} point;

point stack[N*M];
int top = -1;

void push(int x, int y) {
    top++;
    stack[top].x = x;
    stack[top].y = y;
}

point pop() {
    point p = stack[top];
    top--;
    return p;
}

int is_empty() {
    return top == -1;
}

// Depth-first search algorithm for maze route finding
void dfs(int x, int y) {
    if (maze[x][y] == ' ') {
        push(x, y);
        maze[x][y] = '*';
    }
    while (!is_empty()) {
        point p = pop();
        x = p.x;
        y = p.y;
        if (maze[x-1][y] == ' ') {
            push(x-1, y);
            maze[x-1][y] = '*';
        }
        if (maze[x+1][y] == ' ') {
            push(x+1, y);
            maze[x+1][y] = '*';
        }
        if (maze[x][y-1] == ' ') {
            push(x, y-1);
            maze[x][y-1] = '*';
        }
        if (maze[x][y+1] == ' ') {
            push(x, y+1);
            maze[x][y+1] = '*';
        }
    }
}

int main() {
    // Print the original maze
    printf("Original Maze:\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    // Call dfs function to find the route
    dfs(1, 1);
    // Print the maze with the found route
    printf("\nMaze with Route:\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}