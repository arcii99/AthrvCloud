//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int map[ROW][COL];
bool visited[ROW][COL];
int start_row, start_col, end_row, end_col;

// function to print the map
void print_map() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

// function to initialize the map
void initialize_map() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            map[i][j] = rand() % 2;
        }
    }
    // randomly generate starting and ending points
    start_row = rand() % ROW;
    start_col = rand() % COL;
    end_row = rand() % ROW;
    end_col = rand() % COL;
    map[start_row][start_col] = 0;
    map[end_row][end_col] = 0;
}

// function to check if the current position is valid
bool is_valid(int row, int col) {
    if (row < 0 || row >= ROW || col < 0 || col >= COL) {
        return false;
    }
    if (visited[row][col] || map[row][col] == 1) {
        return false;
    }
    return true;
}

// function to find the shortest path using BFS algorithm
void find_shortest_path() {
    visited[start_row][start_col] = true;

    int queue_row[ROW * COL];
    int queue_col[ROW * COL];
    int front = 0, rear = 0;
    queue_row[rear] = start_row;
    queue_col[rear] = start_col;
    rear++;

    bool path_found = false;
    while (front != rear) {
        int current_row = queue_row[front];
        int current_col = queue_col[front];
        front++;

        if (current_row == end_row && current_col == end_col) {
            path_found = true;
            break;
        }

        if (is_valid(current_row - 1, current_col)) { // up
            visited[current_row - 1][current_col] = true;
            queue_row[rear] = current_row - 1;
            queue_col[rear] = current_col;
            rear++;
        }

        if (is_valid(current_row, current_col + 1)) { // right
            visited[current_row][current_col + 1] = true;
            queue_row[rear] = current_row;
            queue_col[rear] = current_col + 1;
            rear++;
        }

        if (is_valid(current_row + 1, current_col)) { // down
            visited[current_row + 1][current_col] = true;
            queue_row[rear] = current_row + 1;
            queue_col[rear] = current_col;
            rear++;
        }

        if (is_valid(current_row, current_col - 1)) { // left
            visited[current_row][current_col - 1] = true;
            queue_row[rear] = current_row;
            queue_col[rear] = current_col - 1;
            rear++;
        }
    }

    if (path_found) {
        // mark the path with 2
        int current_row = end_row;
        int current_col = end_col;
        while (current_row != start_row || current_col != start_col) {
            if (current_row > 0 && visited[current_row - 1][current_col]) { // up
                current_row--;
            } else if (current_col < COL - 1 && visited[current_row][current_col + 1]) { // right
                current_col++;
            } else if (current_row < ROW - 1 && visited[current_row + 1][current_col]) { // down
                current_row++;
            } else if (current_col > 0 && visited[current_row][current_col - 1]) { // left
                current_col--;
            }
            map[current_row][current_col] = 2;
        }
    }
}

int main() {
    initialize_map();
    printf("Initial Map:\n");
    print_map();

    find_shortest_path();

    printf("Shortest Path:\n");
    print_map();

    return 0;
}