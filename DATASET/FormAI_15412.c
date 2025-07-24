//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 10
#define COLS 10

typedef struct node {
    int row;
    int col;
    int g_score;
    int h_score;
    int f_score;
    struct node *parent;
} Node;

Node open_set[ROWS * COLS];
int open_set_size = 0;

Node closed_set[ROWS * COLS];
int closed_set_size = 0;

int start_row = 0;
int start_col = 0;

int end_row = ROWS - 1;
int end_col = COLS - 1;

int grid[ROWS][COLS] = {
    {0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

bool is_valid(int row, int col) {
    if (row < 0 || row >= ROWS) {
        return false;
    }
    if (col < 0 || col >= COLS) {
        return false;
    }
    if (grid[row][col] == 1) {
        return false;
    }
    return true;
}

int heuristic(int row, int col) {
    int d1 = abs(row - end_row);
    int d2 = abs(col - end_col);
    return d1 + d2;
}

void add_to_open_set(Node *n) {
    open_set[open_set_size++] = *n;
}

bool is_in_open_set(int row, int col) {
    for (int i = 0; i < open_set_size; i++) {
        if (open_set[i].row == row && open_set[i].col == col) {
            return true;
        }
    }
    return false;
}

bool is_in_closed_set(int row, int col) {
    for (int i = 0; i < closed_set_size; i++) {
        if (closed_set[i].row == row && closed_set[i].col == col) {
            return true;
        }
    }
    return false;
}

Node* lowest_f_score_node() {
    Node *lowest_node = &open_set[0];
    for (int i = 1; i < open_set_size; i++) {
        if (open_set[i].f_score < lowest_node->f_score) {
            lowest_node = &open_set[i];
        }
    }
    return lowest_node;
}

void remove_node_from_open_set(Node *n) {
    for (int i = 0; i < open_set_size; i++) {
        if (open_set[i].row == n->row && open_set[i].col == n->col) {
            open_set[i] = open_set[--open_set_size];
            return;
        }
    }
}

void reconstruct_path(Node *n) {
    if (n->parent != NULL) {
        reconstruct_path(n->parent);
    }
    printf("(%d, %d) -> ", n->row, n->col);
}

int main() {
    Node start = {start_row, start_col, 0, heuristic(start_row, start_col), heuristic(start_row, start_col), NULL};
    add_to_open_set(&start);

    while (open_set_size > 0) {
        Node *current = lowest_f_score_node();

        if (current->row == end_row && current->col == end_col) {
            printf("Shortest path found: ");
            reconstruct_path(current);
            printf("done.");
            return 0;
        }

        remove_node_from_open_set(current);
        closed_set[closed_set_size++] = *current;

        for (int d_row = -1; d_row <= 1; d_row++) {
            for (int d_col = -1; d_col <= 1; d_col++) {
                if (d_row == 0 && d_col == 0) {
                    continue;
                }

                int neighbor_row = current->row + d_row;
                int neighbor_col = current->col + d_col;

                if (!is_valid(neighbor_row, neighbor_col)) {
                    continue;
                }

                if (is_in_closed_set(neighbor_row, neighbor_col)) {
                    continue;
                }

                int tentative_g_score = current->g_score + 1;
                Node *neighbor;

                if (!is_in_open_set(neighbor_row, neighbor_col)) {
                    int h_score = heuristic(neighbor_row, neighbor_col);
                    neighbor = (Node*) malloc(sizeof(Node));
                    neighbor->row = neighbor_row;
                    neighbor->col = neighbor_col;
                    neighbor->g_score = tentative_g_score;
                    neighbor->h_score = h_score;
                    neighbor->f_score = tentative_g_score + h_score;
                    neighbor->parent = current;
                    add_to_open_set(neighbor);
                } else {
                    for (int i = 0; i < open_set_size; i++) {
                        if (open_set[i].row == neighbor_row && open_set[i].col == neighbor_col) {
                            neighbor = &open_set[i];
                            break;
                        }
                    }
                    if (tentative_g_score < neighbor->g_score) {
                        neighbor->g_score = tentative_g_score;
                        neighbor->f_score = tentative_g_score + neighbor->h_score;
                        neighbor->parent = current;
                    }
                }
            }
        }
    }

    printf("Unable to find shortest path.");
    return 0;
}