//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define sizes
#define WIDTH 40
#define HEIGHT 20

// Define cells
char cells[WIDTH][HEIGHT];

// Define start and end coordinates
int sx = 2, sy = 2;
int ex = 37, ey = 17;

// Define node
typedef struct node {
    int x, y, g, h, f;
    struct node *parent;
} node;

// Define open and closed lists
node *open_list[WIDTH*HEIGHT];
int open_size = 0;
node *closed_list[WIDTH*HEIGHT];
int closed_size = 0;

// Define distance function
int distance(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

// Define check if node is in list function
int in_list(node *current, node **list, int size) {
    for (int i = 0; i < size; i++) {
        if (current->x == list[i]->x && current->y == list[i]->y) {
            return i;
        }
    }
    return -1;
}

// Define get lowest f score function
node *get_lowest_f() {
    node *lowest = open_list[0];
    for (int i = 1; i < open_size; i++) {
        if (open_list[i]->f < lowest->f) {
            lowest = open_list[i];
        }
    }
    return lowest;
}

// Define get adjacent nodes function
node **get_adjacent_nodes(node *current) {
    node **adjacent_nodes = malloc(sizeof(node*)*8);
    int x = current->x;
    int y = current->y;
    int index = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            int cx = x+dx;
            int cy = y+dy;
            if (cx < 0 || cy < 0 || cx >= WIDTH || cy >= HEIGHT) {
                continue;
            }
            if (cells[cx][cy] == '#') {
                continue;
            }
            node *adjacent_node = malloc(sizeof(node));
            adjacent_node->x = cx;
            adjacent_node->y = cy;
            adjacent_node->g = current->g + distance(x, y, cx, cy);
            adjacent_node->h = distance(cx, cy, ex, ey);
            adjacent_node->f = adjacent_node->g + adjacent_node->h;
            adjacent_node->parent = current;
            adjacent_nodes[index++] = adjacent_node;
        }
    }
    return adjacent_nodes;
}

// Define print path function
void print_path(node *current) {
    while (current != NULL) {
        printf("[%d, %d] ", current->x, current->y);
        current = current->parent;
    }
    printf("\n");
}

// Define main function
int main() {
    // Initialize cells
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0 || x == WIDTH-1 || y == 0 || y == HEIGHT-1) {
                cells[x][y] = '#';
            } else {
                cells[x][y] = ' ';
            }
        }
    }
    
    // Set start and end cells
    cells[sx][sy] = 'S';
    cells[ex][ey] = 'E';
    
    // Initialize first node
    node *start = malloc(sizeof(node));
    start->x = sx;
    start->y = sy;
    start->g = 0;
    start->h = distance(sx, sy, ex, ey);
    start->f = start->g + start->h;
    start->parent = NULL;
    
    // Add start node to open list
    open_list[open_size++] = start;
    
    // Loop until end node is found or open list is empty
    while (open_size > 0) {
        // Get node with lowest f score from open list
        node *current = get_lowest_f();
        // Remove current node from open list
        for (int i = 0; i < open_size; i++) {
            if (open_list[i] == current) {
                open_list[i] = open_list[--open_size];
                break;
            }
        }
        // Add current node to closed list
        closed_list[closed_size++] = current;
        // Check if current node is the end node
        if (current->x == ex && current->y == ey) {
            print_path(current);
            return 0;
        }
        // Get adjacent nodes of current node
        node **adjacent_nodes = get_adjacent_nodes(current);
        // Loop through adjacent nodes
        for (int i = 0; i < 8; i++) {
            node *adjacent_node = adjacent_nodes[i];
            // Check if adjacent node is already in closed list
            int closed_index = in_list(adjacent_node, closed_list, closed_size);
            if (closed_index != -1) {
                continue;
            }
            // Check if adjacent node is already in open list
            int open_index = in_list(adjacent_node, open_list, open_size);
            if (open_index != -1) {
                if (adjacent_node->g < open_list[open_index]->g) {
                    open_list[open_index]->g = adjacent_node->g;
                    open_list[open_index]->f = open_list[open_index]->g + open_list[open_index]->h;
                    open_list[open_index]->parent = current;
                }
                continue;
            }
            // Add adjacent node to open list
            open_list[open_size++] = adjacent_node;
        }
    }
    
    return 0;
}