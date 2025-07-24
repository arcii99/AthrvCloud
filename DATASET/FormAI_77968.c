//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: safe
#include <stdio.h>
#define ROWS 10
#define COLS 10

int queue[ROWS*COLS][2]; // array to act as a queue data structure
int front = 0, rear = 0;
int visited[ROWS][COLS] = {0}; // initialize visited array with zeros

void enqueue(int x, int y) {
    queue[rear][0] = x;
    queue[rear][1] = y;
    rear++;
}

void dequeue() {
    front++;
}

int is_empty() {
    return front == rear ? 1 : 0;
}

int is_valid_move(int x, int y, int maze[ROWS][COLS]) {
    // check if the given cell is within the maze and unvisited
    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 1 && visited[x][y] != 1) {
        return 1;
    }
    return 0;
}

void print_path(int path[ROWS][COLS], int start_x, int start_y, int end_x, int end_y) {
    int curr_x = end_x, curr_y = end_y;
    while (curr_x != start_x || curr_y != start_y) {
        printf("(%d,%d) ", curr_x, curr_y);
        int temp_x = curr_x, temp_y = curr_y;
        curr_x = path[temp_x][temp_y]/10; // get the x-coordinate of previous cell from path matrix
        curr_y = path[temp_x][temp_y]%10; // get the y-coordinate of previous cell from path matrix
    }
    printf("(%d,%d)\n", start_x, start_y);
}

void bfs(int maze[ROWS][COLS], int start_x, int start_y, int end_x, int end_y) {
    int path[ROWS][COLS] = {0}; // initialize path array with zeros
    visited[start_x][start_y] = 1;
    enqueue(start_x, start_y);
    while (!is_empty()) {
        int curr_x = queue[front][0], curr_y = queue[front][1];
        dequeue();
        if (curr_x == end_x && curr_y == end_y) { // we have reached the destination
            printf("Path found: ");
            print_path(path, start_x, start_y, end_x, end_y);
            break;
        }
        // explore all possible moves from current cell
        if (is_valid_move(curr_x-1, curr_y, maze)) { // up
            visited[curr_x-1][curr_y] = 1;
            enqueue(curr_x-1, curr_y);
            path[curr_x-1][curr_y] = curr_x*10 + curr_y; // store the previous cell coordinates in path matrix
        }
        if (is_valid_move(curr_x, curr_y+1, maze)) { // right
            visited[curr_x][curr_y+1] = 1;
            enqueue(curr_x, curr_y+1);
            path[curr_x][curr_y+1] = curr_x*10 + curr_y;
        }
        if (is_valid_move(curr_x+1, curr_y, maze)) { // down
            visited[curr_x+1][curr_y] = 1;
            enqueue(curr_x+1, curr_y);
            path[curr_x+1][curr_y] = curr_x*10 + curr_y;
        }
        if (is_valid_move(curr_x, curr_y-1, maze)) { // left
            visited[curr_x][curr_y-1] = 1;
            enqueue(curr_x, curr_y-1);
            path[curr_x][curr_y-1] = curr_x*10 + curr_y;
        }
    }
}

int main() {
    int maze[ROWS][COLS] = {{1,1,1,1,1,1,1,1,1,1},
                            {1,0,0,0,0,0,0,0,0,1},
                            {1,0,1,1,1,1,1,1,0,1},
                            {1,0,0,0,0,0,0,0,0,1},
                            {1,1,1,1,0,1,1,1,1,1},
                            {1,0,0,1,0,0,0,0,0,1},
                            {1,1,1,1,1,1,1,1,0,1},
                            {1,0,0,0,0,0,0,0,0,1},
                            {1,1,1,1,1,1,1,1,0,1},
                            {1,0,0,0,0,0,0,0,0,1}};
    bfs(maze, 1, 1, 8, 8); // find path from (1,1) to (8,8)
    return 0;
}