//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int heuristic(int row, int col, int end_row, int end_col) {
    // manhattan distance heuristic
    return abs(end_row - row) + abs(end_col - col);
}

typedef struct node {
    int row;
    int col;
    int g_score;
    int f_score;
    struct node* parent;
} Node;

void print_path(Node* node) {
    if (node == NULL) {
        printf("No path found!\n");
        return;
    }

    Node* current = node;
    while (current != NULL) {
        printf("(%d, %d)%s", current->row, current->col, current->parent != NULL ? " -> " : "\n");
        current = current->parent;
    }
}

int main() {
    // initialize the grid
    int grid[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // initialize the start and end points
    int start_row = 1;
    int start_col = 0;
    int end_row = 8;
    int end_col = 9;

    // initialize the open and closed sets
    Node* open_set[ROWS*COLS];
    for (int i = 0; i < ROWS*COLS; i++) {
        open_set[i] = NULL;
    }
    bool closed_set[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            closed_set[i][j] = false;
        }
    }

    // add the starting node to the open set
    Node* start_node = (Node*) malloc(sizeof(Node));
    start_node->row = start_row;
    start_node->col = start_col;
    start_node->g_score = 0;
    start_node->f_score = heuristic(start_row, start_col, end_row, end_col);
    start_node->parent = NULL;
    open_set[0] = start_node;
    int open_set_size = 1;

    // search for the shortest path
    while (open_set_size > 0) {
        // find the node in the open set with the lowest f_score
        int current_index = 0;
        int current_f_score = open_set[0]->f_score;
        for (int i = 0; i < open_set_size; i++) {
            if (open_set[i]->f_score < current_f_score) {
                current_index = i;
                current_f_score = open_set[i]->f_score;
            }
        }
        Node* current_node = open_set[current_index];

        // if we've reached the end, trace back the path and print it
        if (current_node->row == end_row && current_node->col == end_col) {
            print_path(current_node);
            break;
        }

        // remove the current node from the open set and add it to the closed set
        open_set[current_index] = NULL;
        open_set_size--;
        closed_set[current_node->row][current_node->col] = true;

        // check each neighbor of the current node
        int row = current_node->row;
        int col = current_node->col;
        int g_score = current_node->g_score + 1;
        if (row > 0 && grid[row-1][col] == 0 && !closed_set[row-1][col]) {
            // neighbor to the north
            Node* neighbor = (Node*) malloc(sizeof(Node));
            neighbor->row = row-1;
            neighbor->col = col;
            neighbor->g_score = g_score;
            neighbor->f_score = g_score + heuristic(row-1, col, end_row, end_col);
            neighbor->parent = current_node;
            int index = open_set_size;
            for (int i = 0; i < open_set_size; i++) {
                if (open_set[i]->row == neighbor->row && open_set[i]->col == neighbor->col) {
                    index = i;
                    break;
                }
            }
            if (index == open_set_size) {
                open_set[open_set_size] = neighbor;
                open_set_size++;
            } else if (g_score < open_set[index]->g_score) {
                open_set[index]->g_score = g_score;
                open_set[index]->f_score = g_score + heuristic(row-1, col, end_row, end_col);
                open_set[index]->parent = current_node;
            }
        }
        if (row < ROWS-1 && grid[row+1][col] == 0 && !closed_set[row+1][col]) {
            // neighbor to the south
            Node* neighbor = (Node*) malloc(sizeof(Node));
            neighbor->row = row+1;
            neighbor->col = col;
            neighbor->g_score = g_score;
            neighbor->f_score = g_score + heuristic(row+1, col, end_row, end_col);
            neighbor->parent = current_node;
            int index = open_set_size;
            for (int i = 0; i < open_set_size; i++) {
                if (open_set[i]->row == neighbor->row && open_set[i]->col == neighbor->col) {
                    index = i;
                    break;
                }
            }
            if (index == open_set_size) {
                open_set[open_set_size] = neighbor;
                open_set_size++;
            } else if (g_score < open_set[index]->g_score) {
                open_set[index]->g_score = g_score;
                open_set[index]->f_score = g_score + heuristic(row+1, col, end_row, end_col);
                open_set[index]->parent = current_node;
            }
        }
        if (col > 0 && grid[row][col-1] == 0 && !closed_set[row][col-1]) {
            // neighbor to the west
            Node* neighbor = (Node*) malloc(sizeof(Node));
            neighbor->row = row;
            neighbor->col = col-1;
            neighbor->g_score = g_score;
            neighbor->f_score = g_score + heuristic(row, col-1, end_row, end_col);
            neighbor->parent = current_node;
            int index = open_set_size;
            for (int i = 0; i < open_set_size; i++) {
                if (open_set[i]->row == neighbor->row && open_set[i]->col == neighbor->col) {
                    index = i;
                    break;
                }
            }
            if (index == open_set_size) {
                open_set[open_set_size] = neighbor;
                open_set_size++;
            } else if (g_score < open_set[index]->g_score) {
                open_set[index]->g_score = g_score;
                open_set[index]->f_score = g_score + heuristic(row, col-1, end_row, end_col);
                open_set[index]->parent = current_node;
            }
        }
        if (col < COLS-1 && grid[row][col+1] == 0 && !closed_set[row][col+1]) {
            // neighbor to the east
            Node* neighbor = (Node*) malloc(sizeof(Node));
            neighbor->row = row;
            neighbor->col = col+1;
            neighbor->g_score = g_score;
            neighbor->f_score = g_score + heuristic(row, col+1, end_row, end_col);
            neighbor->parent = current_node;
            int index = open_set_size;
            for (int i = 0; i < open_set_size; i++) {
                if (open_set[i]->row == neighbor->row && open_set[i]->col == neighbor->col) {
                    index = i;
                    break;
                }
            }
            if (index == open_set_size) {
                open_set[open_set_size] = neighbor;
                open_set_size++;
            } else if (g_score < open_set[index]->g_score) {
                open_set[index]->g_score = g_score;
                open_set[index]->f_score = g_score + heuristic(row, col+1, end_row, end_col);
                open_set[index]->parent = current_node;
            }
        }
    }

    return 0;
}