//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROW_COUNT 10
#define COL_COUNT 10

typedef struct {
    int row, col;
} Square;

bool maze[ROW_COUNT][COL_COUNT] = {
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}
};

Square queue[ROW_COUNT * COL_COUNT];
int front = 0, rear = 0;

void push(int row, int col) {
    queue[rear].row = row;
    queue[rear].col = col;
    rear++;
}

Square pop() {
    front++;
    return queue[front - 1];
}

bool is_empty() {
    return front == rear;
}

void print_path(Square path[], int size) {
    printf("Path: ");
    for(int i=0; i<size; i++) {
        printf("(%d, %d) ", path[i].row, path[i].col);
    }
    printf("\n");
}

void find_path(int start_row, int start_col, int end_row, int end_col) {
    Square path[ROW_COUNT * COL_COUNT];
    int path_size = 0;
    push(start_row, start_col);
    while(!is_empty()) {
        Square current_square = pop();
        int current_row = current_square.row;
        int current_col = current_square.col;
        if(current_row == end_row && current_col == end_col) {
            path[path_size] = current_square;
            path_size++;
            print_path(path, path_size);
            path_size--;
        } else {
            if(maze[current_row][current_col]) {
                maze[current_row][current_col] = false;
                path[path_size] = current_square;
                path_size++;
                if(current_row > 0) push(current_row - 1, current_col);
                if(current_row < ROW_COUNT - 1) push(current_row + 1, current_col);
                if(current_col > 0) push(current_row, current_col - 1);
                if(current_col < COL_COUNT - 1) push(current_row, current_col + 1);
                path_size--;
            }
        }
    }
}

int main() {
    int start_row = 0, start_col = 0, end_row = 9, end_col = 9;
    find_path(start_row, start_col, end_row, end_col);
    return 0;
}