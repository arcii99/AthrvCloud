//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

struct Node {
    int row, col;
    int f_score, g_score, h_score;
    bool blocked;
    struct Node* parent;
};

void initialize_board(bool board[ROWS][COLS]) {
    // Initializes the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = false;
        }
    }
    
    // Adds some obstacles
    board[2][2] = true;
    board[2][3] = true;
    board[2][4] = true;
    board[2][5] = true;
    board[3][5] = true;
    board[4][5] = true;
    board[5][5] = true;
    board[6][5] = true;
    board[7][5] = true;
    board[7][4] = true;
    board[7][3] = true;
    board[7][2] = true;
}

bool is_valid(int row, int col) {
    // Checks if a given node is within the board boundaries
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

bool is_blocked(bool board[ROWS][COLS], int row, int col) {
    // Checks if a given node is blocked
    return board[row][col];
}

int calculate_h_score(int start_row, int start_col, int end_row, int end_col) {
    // Calculates the heuristic score (simple distance) between two nodes
    return abs(end_row - start_row) + abs(end_col - start_col);
}

bool is_goal(int row, int col, int end_row, int end_col) {
    // Checks if a given node is the goal node
    return row == end_row && col == end_col;
}

void print_path(struct Node* end_node) {
    // Recursively prints the path from the end node to the start node
    if (end_node == NULL) {
        return;
    }
    
    print_path(end_node->parent);
    printf("(%d, %d) ", end_node->row, end_node->col);
}

void find_path(bool board[ROWS][COLS], int start_row, int start_col, int end_row, int end_col) {
    // Implements the A* pathfinding algorithm
    struct Node open_list[ROWS * COLS];
    struct Node closed_list[ROWS * COLS];
    int open_list_size = 0;
    int closed_list_size = 0;
    
    // Initializes the start node
    struct Node start_node = {start_row, start_col, 0, 0, 0, false, NULL};
    start_node.h_score = calculate_h_score(start_row, start_col, end_row, end_col);
    open_list[open_list_size++] = start_node;
    
    while (open_list_size > 0) {
        // Picks the node with the lowest f score from the open list
        struct Node current_node = open_list[0];
        int current_index = 0;
        for (int i = 0; i < open_list_size; i++) {
            if (open_list[i].f_score < current_node.f_score) {
                current_node = open_list[i];
                current_index = i;
            }
        }
        
        // Removes the current node from the open list
        for (int i = current_index; i < open_list_size - 1; i++) {
            open_list[i] = open_list[i + 1];
        }
        open_list_size--;
        
        // Adds the current node to the closed list
        closed_list[closed_list_size++] = current_node;
        
        // Checks if the current node is the goal node
        if (is_goal(current_node.row, current_node.col, end_row, end_col)) {
            printf("Path: ");
            print_path(&current_node);
            printf("\n");
            return;
        }
        
        // Expands the current node's neighbors
        int row_offsets[4] = {-1, 0, 1, 0};
        int col_offsets[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int neighbor_row = current_node.row + row_offsets[i];
            int neighbor_col = current_node.col + col_offsets[i];
            
            // Skips invalid or blocked nodes
            if (!is_valid(neighbor_row, neighbor_col) || is_blocked(board, neighbor_row, neighbor_col)) {
                continue;
            }
            
            // Checks if the neighbor is already in the closed list
            bool is_in_closed_list = false;
            for (int j = 0; j < closed_list_size; j++) {
                if (closed_list[j].row == neighbor_row && closed_list[j].col == neighbor_col) {
                    is_in_closed_list = true;
                    break;
                }
            }
            if (is_in_closed_list) {
                continue;
            }
            
            // Calculates the neighbor's g score, h score, and f score
            int neighbor_g_score = current_node.g_score + 1;
            int neighbor_h_score = calculate_h_score(neighbor_row, neighbor_col, end_row, end_col);
            int neighbor_f_score = neighbor_g_score + neighbor_h_score;
            
            // Checks if the neighbor is already in the open list, and updates it if necessary
            bool is_in_open_list = false;
            for (int j = 0; j < open_list_size; j++) {
                if (open_list[j].row == neighbor_row && open_list[j].col == neighbor_col) {
                    if (neighbor_g_score < open_list[j].g_score) {
                        open_list[j].g_score = neighbor_g_score;
                        open_list[j].f_score = neighbor_f_score;
                        open_list[j].parent = &current_node;
                    }
                    is_in_open_list = true;
                    break;
                }
            }
            if (is_in_open_list) {
                continue;
            }
            
            // Adds the neighbor to the open list
            struct Node neighbor_node = {neighbor_row, neighbor_col, neighbor_f_score, neighbor_g_score, neighbor_h_score, false, &current_node};
            open_list[open_list_size++] = neighbor_node;
        }
    }
    
    printf("No path found.\n");
}

int main() {
    bool board[ROWS][COLS];
    initialize_board(board);
    find_path(board, 0, 0, 9, 9);
    return 0;
}