//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COLUMN 10

// Structure for each node
struct node {
    int row_val, column_val, f_val, g_val, h_val, visited, obstacle;
    struct node* parent;
};

// Create a grid of nodes
void create_grid(struct node grid[ROW][COLUMN]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COLUMN; j++) {
            grid[i][j].row_val = i;
            grid[i][j].column_val = j;
            grid[i][j].f_val = 0;
            grid[i][j].g_val = 0;
            grid[i][j].h_val = 0;
            grid[i][j].visited = 0;
            grid[i][j].obstacle = 0;
            grid[i][j].parent = NULL;
        }
    }
}

// Assign obstacles in the grid
void assign_obstacles(struct node grid[ROW][COLUMN], int numOfObs) {
    int i=0;
    while(i<numOfObs) {
        int rand_row = rand() % ROW;
        int rand_column = rand() % COLUMN;
        if(grid[rand_row][rand_column].obstacle == 0) {
            grid[rand_row][rand_column].obstacle = 1;
            i++;
        }
    }
}

// Calculate manhattan distance
int manhattan_distance(int current_row, int current_column, int goal_row, int goal_column) {
    return abs(current_row - goal_row) + abs(current_column - goal_column);
}

// Find the node with the minimum f value
struct node* find_min_f(struct node open[ROW*COLUMN], int* numOfOpenNodes) {
    int min_f = 1000;
    int min_index = -1;
    for(int i=0; i<*numOfOpenNodes; i++) {
        if(open[i].f_val < min_f) {
            min_f = open[i].f_val;
            min_index = i;
        }
    }
    if(min_index != -1) {
        struct node* min_node = &open[min_index];
        for(int j=min_index; j<*numOfOpenNodes-1; j++) {
            open[j] = open[j+1];
        }
        (*numOfOpenNodes)--;
        return min_node;
    }
    return NULL;
}

// Check if the node is in closed list
int in_closed_list(struct node closed[ROW*COLUMN], int numOfClosedNodes, int row, int column) {
    for(int i=0; i<numOfClosedNodes; i++) {
        if(closed[i].row_val == row && closed[i].column_val == column) {
            return 1;
        }
    }
    return 0;
}

// Check if the node is in open list
int in_open_list(struct node open[ROW*COLUMN], int numOfOpenNodes, int row, int column) {
    for(int i=0; i<numOfOpenNodes; i++) {
        if(open[i].row_val == row && open[i].column_val == column) {
            return 1;
        }
    }
    return 0;
}

// Update the node values
void update_node(struct node* current_node, struct node* neighbour_node, int row, int column, int goal_row, int goal_column) {
    int g_value = current_node->g_val + 1;
    if(g_value < neighbour_node->g_val || neighbour_node->visited == 0) {
        neighbour_node->g_val = g_value;
        neighbour_node->h_val = manhattan_distance(row, column, goal_row, goal_column);
        neighbour_node->f_val = neighbour_node->g_val + neighbour_node->h_val;
        neighbour_node->parent = current_node;
        if(neighbour_node->visited == 0) {
            neighbour_node->visited = 1;
        }
    }
}

// Find the path
void find_path(struct node grid[ROW][COLUMN], int start_row, int start_column, int goal_row, int goal_column) {
    int numOfOpenNodes = 0;
    int numOfClosedNodes = 0;
    struct node open[ROW*COLUMN];
    struct node closed[ROW*COLUMN];
    struct node* current_node = &grid[start_row][start_column];

    current_node->visited = 1;
    current_node->g_val = 0;
    current_node->h_val = manhattan_distance(start_row, start_column, goal_row, goal_column);
    current_node->f_val = current_node->g_val + current_node->h_val;
    open[numOfOpenNodes] = *current_node;
    numOfOpenNodes++;

    while(numOfOpenNodes > 0) {
        current_node = find_min_f(open, &numOfOpenNodes);
        closed[numOfClosedNodes] = *current_node;
        numOfClosedNodes++;

        if(current_node->row_val == goal_row && current_node->column_val == goal_column) {
            return;
        }

        struct node* neighbour_node;

        // Check left
        if(current_node->column_val > 0) {
            neighbour_node = &grid[current_node->row_val][current_node->column_val-1];
            if(neighbour_node->obstacle == 0 && in_closed_list(closed, numOfClosedNodes, neighbour_node->row_val, neighbour_node->column_val) == 0) {
                if(in_open_list(open, numOfOpenNodes, neighbour_node->row_val, neighbour_node->column_val) == 0) {
                    open[numOfOpenNodes] = *neighbour_node;
                    numOfOpenNodes++;
                }
                update_node(current_node, neighbour_node, neighbour_node->row_val, neighbour_node->column_val, goal_row, goal_column);
            }
        }

        // Check right
        if(current_node->column_val < COLUMN-1) {
            neighbour_node = &grid[current_node->row_val][current_node->column_val+1];
            if(neighbour_node->obstacle == 0 && in_closed_list(closed, numOfClosedNodes, neighbour_node->row_val, neighbour_node->column_val) == 0) {
                if(in_open_list(open, numOfOpenNodes, neighbour_node->row_val, neighbour_node->column_val) == 0) {
                    open[numOfOpenNodes] = *neighbour_node;
                    numOfOpenNodes++;
                }
                update_node(current_node, neighbour_node, neighbour_node->row_val, neighbour_node->column_val, goal_row, goal_column);
            }
        }

        // Check up
        if(current_node->row_val > 0) {
            neighbour_node = &grid[current_node->row_val-1][current_node->column_val];
            if(neighbour_node->obstacle == 0 && in_closed_list(closed, numOfClosedNodes, neighbour_node->row_val, neighbour_node->column_val) == 0) {
                if(in_open_list(open, numOfOpenNodes, neighbour_node->row_val, neighbour_node->column_val) == 0) {
                    open[numOfOpenNodes] = *neighbour_node;
                    numOfOpenNodes++;
                }
                update_node(current_node, neighbour_node, neighbour_node->row_val, neighbour_node->column_val, goal_row, goal_column);
            }
        }

        // Check down
        if(current_node->row_val < ROW-1) {
            neighbour_node = &grid[current_node->row_val+1][current_node->column_val];
            if(neighbour_node->obstacle == 0 && in_closed_list(closed, numOfClosedNodes, neighbour_node->row_val, neighbour_node->column_val) == 0) {
                if(in_open_list(open, numOfOpenNodes, neighbour_node->row_val, neighbour_node->column_val) == 0) {
                    open[numOfOpenNodes] = *neighbour_node;
                    numOfOpenNodes++;
                }
                update_node(current_node, neighbour_node, neighbour_node->row_val, neighbour_node->column_val, goal_row, goal_column);
            }
        }
    }
}

// Print path
void print_path(struct node grid[ROW][COLUMN], int start_row, int start_column, int goal_row, int goal_column) {
    struct node* current_node = &grid[goal_row][goal_column];
    while(current_node->row_val != start_row || current_node->column_val != start_column) {
        printf("(%d,%d) -> ", current_node->row_val, current_node->column_val);
        current_node = current_node->parent;
    }
    printf("(%d,%d)\n", start_row, start_column);
}

int main() {
    struct node grid[ROW][COLUMN];

    create_grid(grid);

    int start_row = 0;
    int start_column = 0;
    int goal_row = 9;
    int goal_column = 9;

    assign_obstacles(grid, 15);

    printf("Grid: \n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COLUMN; j++) {
            printf("%d ", grid[i][j].obstacle);
        }
        printf("\n");
    }
    printf("\n");

    find_path(grid, start_row, start_column, goal_row, goal_column);

    printf("Path: ");
    print_path(grid, start_row, start_column, goal_row, goal_column);

    return 0;
}