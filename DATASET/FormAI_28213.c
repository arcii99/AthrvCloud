//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

// Node structure for A* Pathfinding algorithm
typedef struct Node {
    int row, col, f, g, h;
    struct Node* parent;
} Node;

int is_valid(int row, int col) {
    // Returns 1 if row and col are within the matrix boundaries, 0 otherwise
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

int is_unblocked(int matrix[][COL], int row, int col) {
    // Returns 1 if the cell is unblocked, 0 otherwise
    return (matrix[row][col] == 1);
}

int is_destination(int row, int col, Node dest) {
    // Returns 1 if the cell is the destination, 0 otherwise
    return (row == dest.row) && (col == dest.col);
}

int calculate_h_value(int row, int col, Node dest) {
    // Calculate the heuristic value
    return ((row - dest.row)*(row - dest.row) + (col - dest.col)*(col - dest.col));
}

void print_path(Node* current) {
    // Prints the path taken from start to destination
    if (current == NULL) return;
    print_path(current->parent);
    printf("(%d,%d) ", current->row, current->col);
}

void a_star_algorithm(int matrix[][COL], Node start, Node dest) {
    // Create a closed list that contains the nodes already evaluated by the algorithm
    int closed_list[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            closed_list[i][j] = 0;
        }
    }
    
    // Create an open list that contains the nodes to be evaluated by the algorithm
    Node* open_list = (Node*)malloc(sizeof(Node));
    Node* current;
    int open_list_len = 1;
    open_list[0] = start;
    
    // While there are still nodes to be evaluated
    while (open_list_len > 0) {
        // Choose the node with the least f value from the open list
        int min_f_index = 0;
        for (int i = 0; i < open_list_len; i++) {
            if (open_list[i].f < open_list[min_f_index].f) min_f_index = i;
        }
        
        // Set the current node to the node with the least f value
        current = &open_list[min_f_index];
        
        // If the current node is the destination, print the path and return
        if (is_destination(current->row, current->col, dest)) {
            printf("Path taken: ");
            print_path(current);
            printf("\n");
            return;
        }
        
        // Remove the current node from the open list and add it to the closed list
        open_list_len--;
        open_list[min_f_index] = open_list[open_list_len];
        closed_list[current->row][current->col] = 1;
        
        // Explore the neighbors of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // Skip the current node and diagonals
                if (i == 0 && j == 0) continue;
                if (abs(i) + abs(j) == 2) continue;
                
                // Calculate the row and column of the neighbor
                int neighbor_row = current->row + i;
                int neighbor_col = current->col + j;
                
                // Skip neighbor if it is out of bounds or on the closed list or blocked
                if (!is_valid(neighbor_row, neighbor_col)) continue;
                if (closed_list[neighbor_row][neighbor_col] == 1) continue;
                if (!is_unblocked(matrix, neighbor_row, neighbor_col)) continue;
                
                // Calculate the g, h and f values of the neighbor
                int g_value = current->g + 1;
                int h_value = calculate_h_value(neighbor_row, neighbor_col, dest);
                int f_value = g_value + h_value;
                
                // Check if the neighbor is already on the open list
                int neighbor_index = -1;
                for (int k = 0; k < open_list_len; k++) {
                    if ((open_list[k].row == neighbor_row) && (open_list[k].col == neighbor_col)) {
                        neighbor_index = k;
                        break;
                    }
                }
                
                // Add the neighbor to the open list if it is not there or if a better path is found
                if (neighbor_index == -1) {
                    Node neighbor = {neighbor_row, neighbor_col, f_value, g_value, h_value, current};
                    open_list[open_list_len] = neighbor;
                    open_list_len++;
                } else if (g_value < open_list[neighbor_index].g) {
                    open_list[neighbor_index].g = g_value;
                    open_list[neighbor_index].f = f_value;
                    open_list[neighbor_index].parent = current;
                }
            }
        }
    }
    
    // Print "No path found" if the destination is unreachable
    printf("No path found.\n");
}

// Driver program
int main() {
    int matrix[ROW][COL] = 
    {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    
    Node start = {0, 0, 0, 0, 0, NULL};
    Node dest = {ROW-1, COL-1, 0, 0, 0, NULL};
    
    a_star_algorithm(matrix, start, dest);
    
    return 0;
}