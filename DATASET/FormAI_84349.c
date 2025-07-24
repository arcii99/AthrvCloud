//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// define the size of the map
#define ROWS 10
#define COLS 10

// define the starting and ending point
int start_x = 2, start_y = 2;
int end_x = 8, end_y = 8;

// define the map as a 2D array
int map[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// define the node structure
typedef struct Node {
    int x, y;
    int g, h, f;
    struct Node *parent;
} Node;

// define a function to get the Manhattan distance between two points
int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// define a function to check if a node is in bounds
int in_bounds(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

// define a function to check if a node is walkable
int is_walkable(int x, int y) {
    return !map[x][y];
}

// define a function to get the successors of a node
Node **get_successors(Node *node) {
    Node **successors = malloc(4 * sizeof(Node *));
    int x = node->x, y = node->y;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (in_bounds(nx, ny) && is_walkable(nx, ny)) {
            Node *new_node = malloc(sizeof(Node));
            new_node->x = nx, new_node->y = ny;
            new_node->parent = node;
            successors[i] = new_node;
        }
    }
    return successors;
}

// define the A* algorithm
Node *astar() {
    Node *open_set[ROWS * COLS];
    Node *closed_set[ROWS * COLS];
    int openset_size = 0, closedset_size = 0;
    Node *start_node = malloc(sizeof(Node));
    start_node->x = start_x, start_node->y = start_y;
    start_node->g = 0, start_node->h = manhattan_distance(start_x, start_y, end_x, end_y);
    start_node->f = start_node->g + start_node->h, start_node->parent = NULL;
    open_set[openset_size++] = start_node;
    while (openset_size > 0) {
        // get the node with the lowest f score
        Node *current = open_set[0];
        int current_index = 0;
        for (int i = 1; i < openset_size; i++) {
            if (open_set[i]->f < current->f) {
                current = open_set[i];
                current_index = i;
            }
        }
        // check if we have reached the end node
        if (current->x == end_x && current->y == end_y) {
            return current;
        }
        // remove the current node from the open set
        for (int i = current_index; i < openset_size - 1; i++) {
            open_set[i] = open_set[i + 1];
        }
        openset_size--;
        // add the current node to the closed set
        closed_set[closedset_size++] = current;
        // get the successors of the current node
        Node **successors = get_successors(current);
        for (int i = 0; i < 4; i++) {
            if (successors[i] != NULL) {
                // check if the successor node is in the closed set
                int is_in_closed_set = 0;
                for (int j = 0; j < closedset_size; j++) {
                    if (closed_set[j]->x == successors[i]->x && closed_set[j]->y == successors[i]->y) {
                        is_in_closed_set = 1;
                        break;
                    }
                }
                if (is_in_closed_set) {
                    continue;
                }
                // calculate the g score of the successor node
                int new_g = current->g + 1;
                // check if the successor node is in the open set
                int is_in_open_set = 0;
                for (int j = 0; j < openset_size; j++) {
                    if (open_set[j]->x == successors[i]->x && open_set[j]->y == successors[i]->y) {
                        is_in_open_set = 1;
                        break;
                    }
                }
                if (!is_in_open_set) {
                    // set the f score of the successor node
                    successors[i]->g = new_g;
                    successors[i]->h = manhattan_distance(successors[i]->x, successors[i]->y, end_x, end_y);
                    successors[i]->f = successors[i]->g + successors[i]->h;
                    successors[i]->parent = current;
                    open_set[openset_size++] = successors[i];
                } else {
                    // update the g score of the successor node if it is lower
                    if (new_g < successors[i]->g) {
                        successors[i]->g = new_g;
                        successors[i]->f = successors[i]->g + successors[i]->h;
                        successors[i]->parent = current;
                    }
                }
            }
        }
    }
    // return NULL if no path was found
    return NULL;
}

// define a function to print the path from the start node to the end node
void print_path(Node *end_node) {
    if (end_node == NULL) {
        printf("No path found.\n");
        return;
    }
    Node *path[ROWS * COLS];
    int path_size = 0;
    while (end_node != NULL) {
        path[path_size++] = end_node;
        end_node = end_node->parent;
    }
    printf("Path: ");
    for (int i = path_size - 1; i >= 0; i--) {
        printf("(%d, %d) ", path[i]->x, path[i]->y);
    }
    printf("\n");
}

// define the main function
int main() {
    // print the map
    printf("Map:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // run the A* algorithm
    Node *end_node = astar();
    // print the path
    print_path(end_node);
    return 0;
}