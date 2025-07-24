//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define the size of the grid
#define ROW 6
#define COL 6

// define the Start and End coordinates
#define START_ROW 0
#define START_COL 0
#define END_ROW 5
#define END_COL 5

// define the structure of each node in the grid
struct Node {
    int row, col;
    int g, h, f;
    bool is_obstacle, is_visited;
    struct Node *parent;
};

typedef struct Node node;

// initialise the grid with coordinates and obstacle status
node grid[ROW][COL] = {
    { {0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0}, {0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0} },
    { {0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0} },
    { {0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0}, {0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0} },
    { {0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0} },
    { {0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0}, {0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0} },
    { {0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0} }
};

// print out the grid with obstacle status and path
void print_grid() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == START_ROW && j == START_COL) {
                printf("S ");
            } else if (i == END_ROW && j == END_COL) {
                printf("E ");
            } else if (grid[i][j].is_obstacle) {
                printf("X ");
            } else if (grid[i][j].is_visited) {
                printf(". ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// calculate the manhattan distance from current node to end node
int calc_h(node current) {
    return abs(current.row - END_ROW) + abs(current.col - END_COL);
}

// initialise the start node and add it to the open list
void init_start(node *open_list) {
    grid[START_ROW][START_COL].g = 0;
    grid[START_ROW][START_COL].h = calc_h(grid[START_ROW][START_COL]);
    grid[START_ROW][START_COL].f = grid[START_ROW][START_COL].g + grid[START_ROW][START_COL].h;
    grid[START_ROW][START_COL].is_visited = true;
    open_list[0] = grid[START_ROW][START_COL];
}

// check if the current node is the end node
bool is_end(node current) {
    return current.row == END_ROW && current.col == END_COL;
}

// check if the coordinates of the next node is within the grid boundaries
bool is_within_bounds(int row, int col) {
    return row >= 0 && row < ROW && col >= 0 && col < COL;
}

// check if the next node is not an obstacle and has not been visited before
bool is_valid_neighbour(node current, int next_row, int next_col) {
    if (is_within_bounds(next_row, next_col) &&
        !grid[next_row][next_col].is_obstacle &&
        !grid[next_row][next_col].is_visited) {
            return true;
        }
    return false;
}

// add the next node to the open list
void add_neighbour(node *open_list, int *count, node current, int next_row, int next_col) {
    node neighbour = grid[next_row][next_col];
    int g_cost = current.g + 1;
    if (g_cost < neighbour.g || !neighbour.is_visited) {
        neighbour.g = g_cost;
        neighbour.h = calc_h(neighbour);
        neighbour.f = neighbour.g + neighbour.h;
        neighbour.parent = &current;
        neighbour.is_visited = true;
        open_list[*count] = neighbour;
        *count += 1;
    }
}

// search for the path from the start node to the end node
void search_path() {
    // initialise open and closed lists
    node open_list[ROW * COL];
    int open_count = 1;
    node closed_list[ROW * COL];
    int closed_count = 0;
    
    // initialise the start node and add it to the open list
    init_start(open_list);
    
    // search for the path
    while (open_count > 0) {
        // sort the open list in ascending order of f value
        for (int i = 0; i < open_count - 1; i++) {
            for (int j = 0; j < open_count - i - 1; j++) {
                if (open_list[j].f > open_list[j+1].f) {
                    node temp = open_list[j];
                    open_list[j] = open_list[j+1];
                    open_list[j+1] = temp;
                }
            }
        }
        
        // get the node with the smallest f value
        node current = open_list[0];
        
        // remove the current node from the open list and add it to the closed list
        for (int i = 0; i < open_count - 1; i++) {
            open_list[i] = open_list[i+1];
        }
        open_count -= 1;
        closed_list[closed_count] = current;
        closed_count += 1;
        
        // check if the current node is the end node
        if (is_end(current)) {
            printf("\nPath found!\n");
            node *p = &current;
            while (p->parent != NULL) {
                p = p->parent;
                grid[p->row][p->col].is_visited = true;
            }
            return;
        }
        
        // add the valid neighbours to the open list
        int row = current.row;
        int col = current.col;
        if (is_valid_neighbour(current, row-1, col)) {
            add_neighbour(open_list, &open_count, current, row-1, col);
        }
        if (is_valid_neighbour(current, row, col+1)) {
            add_neighbour(open_list, &open_count, current, row, col+1);
        }
        if (is_valid_neighbour(current, row+1, col)) {
            add_neighbour(open_list, &open_count, current, row+1, col);
        }
        if (is_valid_neighbour(current, row, col-1)) {
            add_neighbour(open_list, &open_count, current, row, col-1);
        }
    }
    
    // no path was found if the open list is empty
    printf("\nNo path found.\n");
}

int main() {
    // print the initialised grid with obstacle status
    printf("Initial grid:\n");
    print_grid();
    
    // search for the path
    search_path();
    
    // print the final grid with obstacle status and path
    printf("\nFinal grid:\n");
    print_grid();
    
    return 0;
}