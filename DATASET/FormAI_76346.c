//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define the size of the grid
#define ROW 10
#define COL 15
 
// define the structure of a node
typedef struct node {
    int x;
    int y;
    // the f value is the sum of g and h
    int f;
    // the g value is the cost to move from the starting node to this node
    int g;
    // the h value is the estimated cost to move from this node to the goal node
    int h;
    struct node* parent;
} Node;

// define the functions to create and free a node
Node* create_node(int x, int y) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->f = 0;
    new_node->g = 0;
    new_node->h = 0;
    new_node->parent = NULL;
    return new_node;
}
 
void free_node(Node* node) {
    free(node);
}

// define the function to calculate the Manhattan distance between two points
int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// define the function to check if a node is a wall or not
int is_wall(int grid[][COL], int x, int y) {
    if (grid[x][y] == 1) {
        return 1;
    } else {
        return 0;
    }
}

// define the function to check if a node is within the grid
int is_within_grid(int x, int y) {
    if (x >= 0 && x < ROW && y >= 0 && y < COL) {
        return 1;
    } else {
        return 0;
    }
}

// define the function to check if a node is valid or not
int is_valid_node(int grid[][COL], int closed[][COL], int x, int y) {
    if (is_within_grid(x, y) && !is_wall(grid, x, y) && closed[x][y] == 0) {
        return 1;
    } else {
        return 0;
    }
}

// define the function to trace the path from the goal node back to the starting node
void trace_path(Node* goal_node, int grid[][COL]) {
    printf("Path:\n");
    Node* current_node = goal_node;
    while (current_node != NULL) {
        printf("(%d,%d)\n", current_node->x, current_node->y);
        grid[current_node->x][current_node->y] = 2;
        current_node = current_node->parent;
    }
}

// define the function to perform the A* pathfinding algorithm
void a_star(int grid[][COL], int start_x, int start_y, int goal_x, int goal_y) {
    // define the arrays for the open and closed lists
    Node* open_list[ROW * COL];
    int closed_list[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            closed_list[i][j] = 0;
        }
    }
    // create the starting node and add it to the open list
    Node* start_node = create_node(start_x, start_y);
    start_node->f = 0;
    start_node->g = 0;
    start_node->h = manhattan_distance(start_x, start_y, goal_x, goal_y);
    open_list[0] = start_node;
    int open_size = 1;
    while (open_size > 0) {
        // find the node with the lowest f value in the open list
        Node* current_node = open_list[0];
        int current_index = 0;
        for (int i = 1; i < open_size; i++) {
            if (open_list[i]->f < current_node->f) {
                current_node = open_list[i];
                current_index = i;
            }
        }
        // remove the current node from the open list and add it to the closed list
        open_list[current_index] = open_list[open_size - 1];
        open_size--;
        closed_list[current_node->x][current_node->y] = 1;
        // check if the current node is the goal node
        if (current_node->x == goal_x && current_node->y == goal_y) {
            trace_path(current_node, grid);
            free_node(start_node);
            return;
        }
        // generate the adjacent nodes and add them to the open list if they are valid
        Node* adjacent_nodes[8];
        int adjacent_size = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int x = current_node->x + i;
                int y = current_node->y + j;
                if (is_valid_node(grid, closed_list, x, y)) {
                    Node* new_node = create_node(x, y);
                    new_node->g = current_node->g + 1;
                    new_node->h = manhattan_distance(x, y, goal_x, goal_y);
                    new_node->f = new_node->g + new_node->h;
                    new_node->parent = current_node;
                    adjacent_nodes[adjacent_size++] = new_node;
                }
            }
        }
        // add the adjacent nodes to the open list
        for (int i = 0; i < adjacent_size; i++) {
            open_list[open_size++] = adjacent_nodes[i];
        }
    }
    printf("Path not found!\n");
    free_node(start_node);
}

int main() {
    // create the grid
    int grid[ROW][COL] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    // perform the A* pathfinding algorithm
    a_star(grid, 0, 0, 9, 14);
    return 0;
}