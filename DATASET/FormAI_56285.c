//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10 // number of rows
#define COLS 10 // number of columns

// struct node to hold data for each cell
struct node {
    int x, y; // coordinates of the cell
    bool obstacle; // whether the cell is an obstacle or not
    bool visited; // whether the cell has been visited or not
};

// function to initialize the grid with nodes
void init_grid(struct node grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].obstacle = false;
            grid[i][j].visited = false;
        }
    }
    // mark some cells as obstacles
    grid[2][3].obstacle = true;
    grid[3][3].obstacle = true;
    grid[4][3].obstacle = true;
    grid[5][3].obstacle = true;
    grid[6][3].obstacle = true;
    grid[7][3].obstacle = true;
    grid[7][4].obstacle = true;
    grid[7][5].obstacle = true;
    grid[7][6].obstacle = true;
    grid[7][7].obstacle = true;
}

// function to print the grid with the path
void print_grid(struct node grid[ROWS][COLS], int path[ROWS*COLS][2], int path_len) {
    printf("Final Grid:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j].obstacle == true) {
                printf("X ");
            }
            else if (grid[i][j].visited == true) {
                bool is_path = false;
                for (int k = 0; k < path_len; k++) {
                    if (path[k][0] == i && path[k][1] == j) {
                        is_path = true;
                        break;
                    }
                }
                if (is_path == true) {
                    printf("* ");
                }
                else {
                    printf(". ");
                }
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// function to find the shortest path using breadth-first search algorithm
bool find_shortest_path(struct node grid[ROWS][COLS], int path[ROWS*COLS][2], int* path_len) {
    // initialize queue for breadth-first search
    struct node queue[ROWS*COLS];
    int front = 0;
    int rear = 0;
    // add start node to the queue
    grid[0][0].visited = true;
    queue[rear++] = grid[0][0];
    // loop through the queue until destination is reached or queue is empty
    while (front != rear) {
        // get the next node from the queue
        struct node curr_node = queue[front++];
        // check if destination is reached
        if (curr_node.x == ROWS-1 && curr_node.y == COLS-1) {
            // trace back the path from destination to start
            int i = 0;
            path[i][0] = curr_node.x;
            path[i][1] = curr_node.y;
            while (!(curr_node.x == 0 && curr_node.y == 0)) {
                for (int j = 0; j < rear; j++) {
                    if (queue[j].visited == true && abs(queue[j].x - curr_node.x) + abs(queue[j].y - curr_node.y) == 1) {
                        curr_node = queue[j];
                        path[++i][0] = curr_node.x;
                        path[i][1] = curr_node.y;
                        break;
                    }
                }
            }
            *path_len = i+1;
            return true;
        }
        // add neighboring nodes to the queue
        if (curr_node.x > 0 && grid[curr_node.x-1][curr_node.y].visited == false && grid[curr_node.x-1][curr_node.y].obstacle == false) {
            grid[curr_node.x-1][curr_node.y].visited = true;
            queue[rear++] = grid[curr_node.x-1][curr_node.y];
        }
        if (curr_node.x < ROWS-1 && grid[curr_node.x+1][curr_node.y].visited == false && grid[curr_node.x+1][curr_node.y].obstacle == false) {
            grid[curr_node.x+1][curr_node.y].visited = true;
            queue[rear++] = grid[curr_node.x+1][curr_node.y];
        }
        if (curr_node.y > 0 && grid[curr_node.x][curr_node.y-1].visited == false && grid[curr_node.x][curr_node.y-1].obstacle == false) {
            grid[curr_node.x][curr_node.y-1].visited = true;
            queue[rear++] = grid[curr_node.x][curr_node.y-1];
        }
        if (curr_node.y < COLS-1 && grid[curr_node.x][curr_node.y+1].visited == false && grid[curr_node.x][curr_node.y+1].obstacle == false) {
            grid[curr_node.x][curr_node.y+1].visited = true;
            queue[rear++] = grid[curr_node.x][curr_node.y+1];
        }
    }
    // destination could not be reached
    return false;
}

int main() {
    struct node grid[ROWS][COLS];
    init_grid(grid);
    printf("Initial Grid:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf(". ");
        }
        printf("\n");
    }
    int path[ROWS*COLS][2];
    int path_len = 0;
    if (find_shortest_path(grid, path, &path_len) == true) {
        print_grid(grid, path, path_len);
        printf("Shortest Path Length: %d\n", path_len);
    }
    else {
        printf("No Path Found.\n");
    }
    return 0;
}