//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLS 10

#define START_ROW 0
#define START_COL 0

#define END_ROW 9
#define END_COL 9

#define BLOCK_ROW 5
#define BLOCK_COL 5

// Define a boolean data type
typedef enum { false, true } bool;

// Define a node structure for A* algorithm
typedef struct {
    int row;
    int col;
    double f_score;
    double g_score;
    double h_score;
    struct Node* came_from;
} Node;

// Define a 2D array to represent the grid
int grid[ROWS][COLS];

// Declare functions
bool is_valid(int, int);
bool is_blocked(int, int);
double euclidean_distance(int, int, int, int);
Node* get_lowest_f_score(Node**);
void reconstruct_path(Node*);

int main() {
    // Initialize the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
    grid[START_ROW][START_COL] = 1; // Mark start node
    grid[END_ROW][END_COL] = 1; // Mark end node
    grid[BLOCK_ROW][BLOCK_COL] = -1; // Mark a blockage

    // Initialize the open and closed sets
    Node* open_set[ROWS * COLS];
    Node* closed_set[ROWS * COLS];
    Node* start = malloc(sizeof(Node));
    start->row = START_ROW;
    start->col = START_COL;
    start->f_score = euclidean_distance(start->row, start->col, END_ROW, END_COL);
    start->g_score = 0.0;
    start->h_score = euclidean_distance(start->row, start->col, END_ROW, END_COL);
    start->came_from = NULL;
    open_set[0] = start;
    int open_set_size = 1;
    int closed_set_size = 0;

    // Begin A* algorithm
    while (open_set_size > 0) {
        // Get the node in open set with lowest f score
        Node* current = get_lowest_f_score(open_set);
        if (current->row == END_ROW && current->col == END_COL) {
            // Path found, reconstruct and print it
            reconstruct_path(current);
            break;
        }

        // Move current from open set to closed set
        for (int i = 0; i < open_set_size; i++) {
            if (open_set[i] == current) {
                open_set[i] = open_set[open_set_size - 1];
                open_set_size--;
                break;
            }
        }
        closed_set[closed_set_size] = current;
        closed_set_size++;

        // Explore neighbors of current
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0)
                    continue; // Skip current node
                int neighbor_row = current->row + i;
                int neighbor_col = current->col + j;
                if (is_valid(neighbor_row, neighbor_col) && !is_blocked(neighbor_row, neighbor_col)) {
                    Node* neighbor = malloc(sizeof(Node));
                    neighbor->row = neighbor_row;
                    neighbor->col = neighbor_col;
                    neighbor->g_score = current->g_score + euclidean_distance(current->row, current->col, neighbor_row, neighbor_col);
                    neighbor->h_score = euclidean_distance(neighbor->row, neighbor->col, END_ROW, END_COL);
                    neighbor->f_score = neighbor->g_score + neighbor->h_score;
                    neighbor->came_from = current;
                    bool in_closed_set = false;
                    for (int i = 0; i < closed_set_size; i++) {
                        if (closed_set[i]->row == neighbor->row && closed_set[i]->col == neighbor->col) {
                            in_closed_set = true;
                            break;
                        }
                    }
                    if (in_closed_set)
                        continue;
                    bool in_open_set = false;
                    for (int i = 0; i < open_set_size; i++) {
                        if (open_set[i]->row == neighbor->row && open_set[i]->col == neighbor->col) {
                            in_open_set = true;
                            if (neighbor->g_score < open_set[i]->g_score) {
                                open_set[i]->g_score = neighbor->g_score;
                                open_set[i]->f_score = neighbor->f_score;
                                open_set[i]->came_from = neighbor->came_from;
                            }
                            break;
                        }
                    }
                    if (!in_open_set) {
                        open_set[open_set_size] = neighbor;
                        open_set_size++;
                    }
                }
            }
        }
    }

    // Free memory
    for (int i = 0; i < open_set_size; i++) {
        free(open_set[i]);
    }
    for (int i = 0; i < closed_set_size; i++) {
        free(closed_set[i]);
    }

    return 0;
}

// Check if node is within the grid
bool is_valid(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

// Check if node is blocked by obstacle
bool is_blocked(int row, int col) {
    return grid[row][col] == -1;
}

// Calculate Euclidean distance between two nodes
double euclidean_distance(int row1, int col1, int row2, int col2) {
    return sqrt(pow(row1 - row2, 2) + pow(col1 - col2, 2));
}

// Get node with lowest f score from open set
Node* get_lowest_f_score(Node** set) {
    Node* current = set[0];
    int lowest_index = 0;
    for (int i = 1; i < ROWS * COLS; i++) {
        if (!set[i])
            break;
        if (set[i]->f_score < current->f_score) {
            current = set[i];
            lowest_index = i;
        }
    }
    return current;
}

// Reconstruct path from end node to start node
void reconstruct_path(Node* current) {
    int count = 0;
    Node* path[ROWS * COLS];
    while (current != NULL) {
        path[count] = current;
        count++;
        current = current->came_from;
    }
    printf("Shortest path from start to end:\n");
    for (int i = count - 1; i >= 0; i--) {
        printf("(%d, %d) ", path[i]->row, path[i]->col);
    }
}