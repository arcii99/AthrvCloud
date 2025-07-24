//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
#include <stdio.h>

/* Define the maze as a multi-dimensional array, where 0 represents open space and 1 represents a wall */
int maze[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

/* Define a struct to store the position of a point in the maze */
struct point {
    int x;
    int y;
};

/* Function to check if a given point is inside the boundaries of the maze */
int isValid(struct point p) {
    if (p.x < 0 || p.y < 0 || p.x >= 10 || p.y >= 10) {
        return 0;
    }
    return 1;
}

/* Function to check if a given point is a valid move (i.e. not a wall) */
int canMove(struct point p) {
    if (!isValid(p)) {
        return 0;
    }
    if (maze[p.x][p.y] == 1) {
        return 0;
    }
    return 1;
}

/* Recursive function to find the route from the start point to the end point of the maze */
int findRoute(struct point current, struct point end, int visited[][10]) {
    /* If the current point is the end point, return 1 (success) */
    if (current.x == end.x && current.y == end.y) {
        return 1;
    }
    /* If the current point is not valid or has already been visited, return 0 (failure) */
    if (!isValid(current) || visited[current.x][current.y] == 1) {
        return 0;
    }
    /* Mark the current point as visited */
    visited[current.x][current.y] = 1;
    /* Try moving up, down, left, and right from the current point */
    struct point next;
    next.x = current.x - 1;
    next.y = current.y;
    if (canMove(next) && findRoute(next, end, visited)) {
        printf("(%d, %d) -> ", current.x, current.y);
        return 1;
    }
    next.x = current.x + 1;
    next.y = current.y;
    if (canMove(next) && findRoute(next, end, visited)) {
        printf("(%d, %d) -> ", current.x, current.y);
        return 1;
    }
    next.x = current.x;
    next.y = current.y - 1;
    if (canMove(next) && findRoute(next, end, visited)) {
        printf("(%d, %d) -> ", current.x, current.y);
        return 1;
    }
    next.x = current.x;
    next.y = current.y + 1;
    if (canMove(next) && findRoute(next, end, visited)) {
        printf("(%d, %d) -> ", current.x, current.y);
        return 1;
    }
    /* If no valid moves are found, return 0 (failure) */
    return 0;
}

int main() {
    /* Define the start and end points of the maze */
    struct point start, end;
    start.x = 1;
    start.y = 1;
    end.x = 8;
    end.y = 8;
    /* Initialize the visited array to all zeros */
    int visited[10][10] = {0};
    /* Find the route from the start point to the end point of the maze */
    if (findRoute(start, end, visited)) {
        printf("(%d, %d)\n", end.x, end.y);
    } else {
        printf("No route found\n");
    }
    return 0;
}