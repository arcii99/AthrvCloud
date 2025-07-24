//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50  // grid size
#define THRESHOLD 0.6  // percolation threshold

int grid[SIZE][SIZE];
int opened[SIZE][SIZE];  // nodes opened during percolation
int top[SIZE * SIZE];  // top virtual node of each component
int bottom[SIZE * SIZE];  // bottom virtual node of each component
int total_nodes;
int component_count = 0;

int find(int *array, int node) {
    if (node == array[node]) {
        return node;
    }
    return array[node] = find(array, array[node]);
}

void union_nodes(int *array, int node1, int node2) {
    int root1 = find(array, node1);
    int root2 = find(array, node2);
    if (root1 != root2) {
        array[root1] = root2;
    }
}

int random_node() {
    return rand() % total_nodes;
}

void init() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            grid[row][col] = 0;
            opened[row][col] = 0;
        }
    }
}

void print_grid() {
    printf("\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%c ", grid[row][col] == 1 ? '*' : '.');
        }
        printf("\n");
    }
}

void open(int row, int col) {
    opened[row][col] = 1;
    grid[row][col] = 1;
    if (row == 0) {
        top[component_count] = row * SIZE + col;
    }
    if (row == SIZE - 1) {
        bottom[component_count] = row * SIZE + col;
    }
    if (row > 0 && opened[row - 1][col]) {
        union_nodes(top, row * SIZE + col, (row - 1) * SIZE + col);
        union_nodes(bottom, row * SIZE + col, (row - 1) * SIZE + col);
    }
    if (row < SIZE - 1 && opened[row + 1][col]) {
        union_nodes(top, row * SIZE + col, (row + 1) * SIZE + col);
        union_nodes(bottom, row * SIZE + col, (row + 1) * SIZE + col);
    }
    if (col > 0 && opened[row][col - 1]) {
        union_nodes(top, row * SIZE + col, row * SIZE + col - 1);
        union_nodes(bottom, row * SIZE + col, row * SIZE + col - 1);
    }
    if (col < SIZE - 1 && opened[row][col + 1]) {
        union_nodes(top, row * SIZE + col, row * SIZE + col + 1);
        union_nodes(bottom, row * SIZE + col, row * SIZE + col + 1);
    }
}

void percolate() {
    init();
    srand(time(NULL));
    total_nodes = SIZE * SIZE;
    for (int i = 0; i < total_nodes; i++) {
        top[i] = i;
        bottom[i] = i;
    }
    while (find(top, top[component_count]) != find(bottom, bottom[component_count])) {
        int node = random_node();
        int row = node / SIZE;
        int col = node % SIZE;
        if (!opened[row][col]) {
            open(row, col);
            component_count++;
        }
    }
    print_grid();
    printf("\n");

    if (find(top, top[component_count - 1]) == find(bottom, bottom[component_count - 1])) {
        printf("Percolation threshold %f\n", (float)component_count / total_nodes);
    } else {
        printf("System did not percolate\n");
    }
}

int main() {
    percolate();
    return 0;
}