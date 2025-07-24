//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: irregular
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define INF 999999999

typedef struct node {
    int row, col, f, g, h;
    bool visited, obstacle;
    struct node *parent;
} node_t;

node_t grid[MAX_ROWS][MAX_COLS];

node_t *open_set[MAX_ROWS * MAX_COLS];
int open_set_size = 0;

node_t *closed_set[MAX_ROWS * MAX_COLS];
int closed_set_size = 0;

node_t *start_node;
node_t *end_node;

void init_grid() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            node_t *node = &grid[i][j];
            node->row = i;
            node->col = j;
            node->visited = false;
            node->obstacle = false;
            node->parent = NULL;
            node->f = node->g = node->h = INF;

            if (i == 0 || i == MAX_ROWS - 1 || j == 0 || j == MAX_COLS - 1) {
                node->obstacle = true;
            }
        }
    }
}

void add_obstacle(int row, int col) {
    grid[row][col].obstacle = true;
}

void print_grid() {
    printf("\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            char c = '.';
            if (grid[i][j].obstacle) {
                c = '#';
            } else if (grid[i][j].visited) {
                c = '*';
            } else if (grid[i][j].parent) {
                c = '+';
            } else if (&grid[i][j] == start_node) {
                c = 'S';
            } else if (&grid[i][j] == end_node) {
                c = 'E';
            }
            printf("%c ", c);
        }
        printf("\n");
    }
}

// calculate the Manhattan distance between two points
int heuristic(node_t *a, node_t *b) {
    return abs(a->row - b->row) + abs(a->col - b->col);
}

// check if a node is in the open set
bool in_open_set(node_t *node) {
    for (int i = 0; i < open_set_size; i++) {
        if (open_set[i] == node) {
            return true;
        }
    }
    return false;
}

// check if a node is in the closed set
bool in_closed_set(node_t *node) {
    for (int i = 0; i < closed_set_size; i++) {
        if (closed_set[i] == node) {
            return true;
        }
    }
    return false;
}

// add a node to the open set
void add_to_open_set(node_t *node) {
    open_set[open_set_size++] = node;
}

// get the node with the lowest f-value from the open set
node_t *get_lowest_f_node() {
    int index = 0;
    int lowest_f = INF;
    for (int i = 0; i < open_set_size; i++) {
        if (open_set[i]->f < lowest_f) {
            lowest_f = open_set[i]->f;
            index = i;
        }
    }
    node_t *node = open_set[index];
    open_set[index] = open_set[--open_set_size];
    return node;
}

// reconstruct the path from the end node to the start node
void reconstruct_path(node_t *node) {
    while (node->parent) {
        node->visited = true;
        node = node->parent;
    }
    node->visited = true;
}

void a_star() {
    add_to_open_set(start_node);
    start_node->f = 0;
    start_node->g = 0;
    start_node->h = heuristic(start_node, end_node);

    while (open_set_size > 0) {
        node_t *current = get_lowest_f_node();
        if (current == end_node) {
            reconstruct_path(current);
            break;
        }

        closed_set[closed_set_size++] = current;

        int row = current->row;
        int col = current->col;

        // check the neighbors
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = col - 1; j <= col + 1; j++) {
                // skip the current node
                if (i == row && j == col) {
                    continue;
                }
                // skip out-of-bounds nodes
                if (i < 0 || i >= MAX_ROWS || j < 0 || j >= MAX_COLS) {
                    continue;
                }
                node_t *neighbor = &grid[i][j];
                // skip obstacles and nodes in the closed set
                if (neighbor->obstacle || in_closed_set(neighbor)) {
                    continue;
                }
                int new_g = current->g + 1;
                if (!in_open_set(neighbor) || new_g < neighbor->g) {
                    neighbor->parent = current;
                    neighbor->g = new_g;
                    neighbor->h = heuristic(neighbor, end_node);
                    neighbor->f = neighbor->g + neighbor->h;
                    if (!in_open_set(neighbor)) {
                        add_to_open_set(neighbor);
                    }
                }
            }
        }
    }
}

int main() {
    init_grid();
    add_obstacle(2, 3);
    add_obstacle(3, 3);
    add_obstacle(4, 3);

    start_node = &grid[1][1];
    end_node = &grid[8][8];

    a_star();

    print_grid();

    return 0;
}