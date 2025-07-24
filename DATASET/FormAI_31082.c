//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 6
#define COL 6
#define START_ROW 0
#define START_COL 0
#define END_ROW 5
#define END_COL 5

// struct to represent each cell in the grid
typedef struct {
    int row, col;
    double f, g, h;
    int obstacle;
    struct node* parent;
} node;

node grid[ROW][COL];  // the grid of nodes
node* open_list[ROW*COL];
int open_list_len = 0;

// function to calculate the Euclidean distance between 2 cells
double distance(int row1, int col1, int row2, int col2) {
    double dx = row1 - row2;
    double dy = col1 - col2;
    return sqrt(dx*dx + dy*dy);
}

// function to add a node to the open list
void add_to_open_list(node* n) {
    open_list[open_list_len++] = n;
}

// function to check if a node is in the open list
int is_in_open_list(int row, int col) {
    int i;
    for (i = 0; i < open_list_len; i++) {
        if (open_list[i]->row == row && open_list[i]->col == col)
            return 1;
    }
    return 0;
}

// function to remove a node from the open list
void remove_from_open_list(node* n) {
    int i, j;
    for (i = 0; i < open_list_len; i++) {
        if (open_list[i] == n) {
            for (j = i; j < open_list_len-1; j++) {
                open_list[j] = open_list[j+1];
            }
            open_list_len--;
            break;
        }
    }
}

// A* algorithm
void A_star() {
    node* current = &grid[START_ROW][START_COL];
    current->g = 0;
    current->h = distance(START_ROW, START_COL, END_ROW, END_COL);
    current->f = current->g + current->h;
    add_to_open_list(current);
    
    while (open_list_len > 0) {
        int i;
        // find the node with the lowest f value in the open list
        double lowest_f = open_list[0]->f;
        int lowest_f_index = 0;
        for (i = 1; i < open_list_len; i++) {
            if (open_list[i]->f < lowest_f) {
                lowest_f = open_list[i]->f;
                lowest_f_index = i;
            }
        }
        current = open_list[lowest_f_index];
        
        // if the current node is the end node, stop
        if (current->row == END_ROW && current->col == END_COL)
            break;
        
        // remove the current node from the open list
        remove_from_open_list(current);
        
        // for each neighbor of the current node
        for (i = -1; i <= 1; i++) {
            int j;
            for (j = -1; j <= 1; j++) {
                if (i == 0 && j == 0)
                    continue;
                int neighbor_row = current->row + i;
                int neighbor_col = current->col + j;
                
                // if the neighbor is out of bounds, skip it
                if (neighbor_row < 0 || neighbor_row >= ROW ||
                    neighbor_col < 0 || neighbor_col >= COL)
                    continue;
                
                // if the neighbor is an obstacle, skip it
                if (grid[neighbor_row][neighbor_col].obstacle)
                    continue;
                
                double tentative_g = current->g + distance(current->row, current->col, neighbor_row, neighbor_col);
                node* neighbor = &grid[neighbor_row][neighbor_col];
                
                // if the neighbor is not in the open list, add it
                if (!is_in_open_list(neighbor_row, neighbor_col))
                    add_to_open_list(neighbor);
                else if (tentative_g >= neighbor->g)
                    continue;  // this is not a better path
                
                // this path is the best until now. Record it!
                neighbor->parent = current;
                neighbor->g = tentative_g;
                neighbor->h = distance(neighbor_row, neighbor_col, END_ROW, END_COL);
                neighbor->f = neighbor->g + neighbor->h;
            }
        }
    }
    
    if (current->row == END_ROW && current->col == END_COL) {
        // print the path
        while (current) {
            printf("(%d,%d) ", current->row, current->col);
            current = current->parent;
        }
    } else {
        printf("No path found.");
    }
}

// main function
int main() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].obstacle = (rand() % 100 < 20);  // 20% chance of obstacle
        }
    }
    
    // set the start and end points
    grid[START_ROW][START_COL].obstacle = 0;
    grid[END_ROW][END_COL].obstacle = 0;
    
    printf("Obstacle grid:\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c", grid[i][j].obstacle ? 'X' : '.');
        }
        printf("\n");
    }
    printf("\n");
    
    printf("Path: ");
    A_star();
    printf("\n");
    
    return 0;
}