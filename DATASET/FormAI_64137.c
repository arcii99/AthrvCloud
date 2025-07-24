//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COLUMN 10
#define MAX_COST 1000

// Define a node structure
typedef struct node {
    int row;
    int col;
    int g_score;
    int h_score;
    int f_score;
} node;

// Define the start and end positions
int start_row = 0;
int start_col = 0;
int end_row = 9;
int end_col = 9;

// Define the heuristic function - Manhattan distance
int heuristic(node n) {
    return abs(end_row - n.row) + abs(end_col - n.col);
}

// Define a function to check if a node is valid
int is_valid(int row, int col) {
    if (row < 0 || col < 0 || row >= ROW || col >= COLUMN) {
        return 0;
    }
    return 1;
}

// Define a function to check if a node is an obstacle
int is_obstacle(int row, int col) {
    if (row == 2 && col == 4) {
        return 1;
    }
    if (row == 5 && col == 7) {
        return 1;
    }
    return 0;
}

// Define a function to get the successors of a node
void get_successors(node current_node, node successors[]) {
    int row = current_node.row;
    int col = current_node.col;
    int g_score = current_node.g_score + 1;
    int h_score;
    int f_score;

    // Get the upper neighbor
    if (is_valid(row - 1, col) && !is_obstacle(row - 1, col)) {
        h_score = heuristic((node) {row - 1, col, 0, 0, 0});
        f_score = g_score + h_score;
        successors[0] = (node) {row - 1, col, g_score, h_score, f_score};
    }

    // Get the lower neighbor
    if (is_valid(row + 1, col) && !is_obstacle(row + 1, col)) {
        h_score = heuristic((node) {row + 1, col, 0, 0, 0});
        f_score = g_score + h_score;
        successors[1] = (node) {row + 1, col, g_score, h_score, f_score};
    }

    // Get the left neighbor
    if (is_valid(row, col - 1) && !is_obstacle(row, col - 1)) {
        h_score = heuristic((node) {row, col - 1, 0, 0, 0});
        f_score = g_score + h_score;
        successors[2] = (node) {row, col - 1, g_score, h_score, f_score};
    }

    // Get the right neighbor
    if (is_valid(row, col + 1) && !is_obstacle(row, col + 1)) {
        h_score = heuristic((node) {row, col + 1, 0, 0, 0});
        f_score = g_score + h_score;
        successors[3] = (node) {row, col + 1, g_score, h_score, f_score};
    }
}

// Define a function to print the path
void print_path(node final_node, node closed_list[]) {
    printf("The path is: \n");
    int path[ROW*COLUMN][2];
    int i = 0;
    int j = 0;
    while (final_node.row != start_row || final_node.col != start_col) {
        path[i][0] = final_node.row;
        path[i][1] = final_node.col;
        i++;
        for (int k = 0; k < ROW*COLUMN; k++) {
            if (closed_list[k].row == final_node.row && closed_list[k].col == final_node.col) {
                final_node = closed_list[k];
                break;
            }
        }
    }
    path[i][0] = start_row;
    path[i][1] = start_col;
    for (int k = i; k >= 0; k--) {
        printf("(%d, %d) ", path[k][0], path[k][1]);
    }
    printf("\n");
}

// Define the main function
int main() {
    // Initialize the open and closed lists
    node open_list[ROW*COLUMN];
    node closed_list[ROW*COLUMN];
    for (int i = 0; i < ROW*COLUMN; i++) {
        open_list[i].row = -1;
        open_list[i].col = -1;
        open_list[i].g_score = MAX_COST;
        open_list[i].h_score = 0;
        open_list[i].f_score = MAX_COST;
        closed_list[i].row = -1;
        closed_list[i].col = -1;
        closed_list[i].g_score = MAX_COST;
        closed_list[i].h_score = 0;
        closed_list[i].f_score = MAX_COST;
    }
    open_list[0] = (node) {start_row, start_col, 0, 0, 0};
    int open_list_size = 1;

    // Initialize the current and final nodes
    node current_node;
    node final_node;

    // Start the A* algorithm
    while (open_list_size > 0) {
        // Get the node with the lowest f score from the open list
        int lowest_f_score = open_list[0].f_score;
        int lowest_f_score_index = 0;
        for (int i = 1; i < ROW*COLUMN; i++) {
            if (open_list[i].f_score < lowest_f_score) {
                lowest_f_score = open_list[i].f_score;
                lowest_f_score_index = i;
            }
        }
        current_node = open_list[lowest_f_score_index];

        // If the current node is the final node, print the path and exit
        if (current_node.row == end_row && current_node.col == end_col) {
            final_node = current_node;
            print_path(final_node, closed_list);
            exit(0);
        }

        // Remove the current node from the open list and add it to the closed list
        open_list[lowest_f_score_index] = (node) {-1, -1, MAX_COST, 0, MAX_COST};
        open_list_size--;
        for (int i = 0; i < ROW*COLUMN; i++) {
            if (closed_list[i].row == -1 && closed_list[i].col == -1) {
                closed_list[i] = current_node;
                break;
            }
        }

        // Get the successors of the current node and add them to the open list
        node successors[4];
        get_successors(current_node, successors);
        for (int i = 0; i < 4; i++) {
            if (successors[i].row != -1 && successors[i].col != -1) {
                int already_in_open_list = 0;
                int already_in_closed_list = 0;
                for (int j = 0; j < ROW*COLUMN; j++) {
                    if (open_list[j].row == successors[i].row && open_list[j].col == successors[i].col) {
                        already_in_open_list = 1;
                        if (successors[i].g_score < open_list[j].g_score) {
                            open_list[j] = successors[i];
                        }
                        break;
                    }
                    if (closed_list[j].row == successors[i].row && closed_list[j].col == successors[i].col) {
                        already_in_closed_list = 1;
                        break;
                    }
                }
                if (!already_in_open_list && !already_in_closed_list) {
                    open_list[open_list_size] = successors[i];
                    open_list_size++;
                }
            }
        }
    }
}