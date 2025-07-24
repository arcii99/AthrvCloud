//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define COLS 20
#define ROWS 20

typedef struct Node {
    int x;
    int y;
    bool visited;
    bool is_wall;
    struct Node *parent;
} Node;

void init_node(Node *node, int x, int y) {
    node->x = x;
    node->y = y;
    node->visited = false;
    node->is_wall = false;
    node->parent = NULL;
}

void print_grid(Node grid[COLS][ROWS]) {
    printf("\n");
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            if (grid[i][j].visited) {
                printf("•");
            } else if (grid[i][j].is_wall) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

bool is_valid_point(int x, int y) {
    if (x < 0 || y < 0 || x >= COLS || y >= ROWS) {
        return false;
    }
    return true;
}

void shuffle_int_array(int *array, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void make_path(Node *end_node, char path[COLS][ROWS]) {
    Node current_node = *end_node;
    while (current_node.parent != NULL) {
        char dir = ' ';
        if (current_node.x - current_node.parent->x > 0) {
            dir = 'r';
        } else if (current_node.x - current_node.parent->x < 0) {
            dir = 'l';
        } else if (current_node.y - current_node.parent->y > 0) {
            dir = 'd';
        } else if (current_node.y - current_node.parent->y < 0) {
            dir = 'u';
        }
        path[current_node.x][current_node.y] = dir;
        current_node = *(current_node.parent);
    }
}

void dfs(Node grid[COLS][ROWS], Node *current_node, Node *end_node,
        char path[COLS][ROWS], int *path_length) {
    if (current_node == end_node) {
        (*path_length)++;
        make_path(current_node, path);
        return;
    }

    current_node->visited = true;
    int adj_x[] = {0, 1, 0, -1};
    int adj_y[] = {1, 0, -1, 0};
    int shuffled_indexes[] = {0, 1, 2, 3};
    shuffle_int_array(shuffled_indexes, 4);
    for (int i = 0; i < 4; i++) {
        int index = shuffled_indexes[i];
        int x = current_node->x + adj_x[index];
        int y = current_node->y + adj_y[index];

        if (!is_valid_point(x, y)) {
            continue;
        }

        Node *adj_node = &grid[x][y];
        if (adj_node == current_node->parent || adj_node->visited || adj_node->is_wall) {
            continue;
        }

        adj_node->parent = current_node;
        dfs(grid, adj_node, end_node, path, path_length);
        adj_node->parent = NULL;
    }
    current_node->visited = false;
}

int main(void) {
    Node grid[COLS][ROWS];
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            init_node(&grid[i][j], i, j);
        }
    }

    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            if (i == 0 || i == COLS - 1 || j == 0 || j == ROWS - 1) {
                grid[i][j].is_wall = true;
            }
        }
    }

    Node *start_node = &grid[1][1];
    Node *end_node = &grid[COLS - 2][ROWS - 2];

    int wall_count = COLS * ROWS / 4;
    for (int i = 0; i < wall_count; i++) {
        int x, y;
        do {
            x = rand() % (COLS - 2) + 1;
            y = rand() % (ROWS - 2) + 1;
        } while (grid[x][y].is_wall || x == start_node->x || x == end_node->x);
        grid[x][y].is_wall = true;
    }

    char path[COLS][ROWS] = {0};
    int path_length = 0;
    dfs(grid, start_node, end_node, path, &path_length);
    printf("Path: (%d) ", path_length);
    for (int i = path_length - 1; i >= 0; i--) {
        printf("%c", path[end_node->x][end_node->y]);
    }
    printf("\n");
    print_grid(grid);

    return 0;
}