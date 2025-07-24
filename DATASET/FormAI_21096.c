//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct Node {
    int x; 
    int y;
    int f;
    int g;
    int h;
    struct Node* parent;
} Node;

Node* grid[ROWS][COLS];
Node* open_set[ROWS * COLS]; 
Node* closed_set[ROWS * COLS];

int open_set_size = 0;
int closed_set_size = 0;

Node* create_node(int x, int y) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->parent = NULL;
    return node;
}

int heuristic(Node* a, Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

void add_open_set(Node* node) {
    open_set[open_set_size] = node;
    open_set_size++;
}

void add_closed_set(Node* node) {
    closed_set[closed_set_size] = node;
    closed_set_size++;
}

void remove_node_from_open_set(Node* node) {
    for (int i = 0; i < open_set_size; i++) {
        if (open_set[i] == node) {
            open_set[i] = NULL;
            open_set_size--;
            return;
        }
    }
}

Node* get_lowest_f_cost() {
    int lowest_f = 100000;
    Node* lowest_node = NULL;
    for (int i = 0; i < open_set_size; i++) {
        Node* node = open_set[i];
        if (node != NULL && node->f < lowest_f) {
            lowest_f = node->f;
            lowest_node = node;
        }
    }
    return lowest_node;
}

void reconstruct_path(Node* current) {
    int size = 0;
    Node* path[ROWS * COLS];
    path[size] = current;
    size++;

    while (current->parent != NULL) {
        current = current->parent;
        path[size] = current;
        size++;
    }

    printf("Path found: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("(%d,%d)", path[i]->x, path[i]->y);
        if (i != 0) {
            printf(" -> ");
        }
    }
    printf("\n");
}

void find_path(Node* start, Node* end) {
    add_open_set(start);

    while (open_set_size > 0) {
        Node* current = get_lowest_f_cost();

        if (current == end) {
            reconstruct_path(end);
            return;
        }

        remove_node_from_open_set(current);
        add_closed_set(current);

        // Check all neighbors of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;

                int x = current->x + i;
                int y = current->y + j;

                // Check if neighbor is out of bounds
                if (x < 0 || y < 0 || x >= ROWS || y >= COLS) continue;

                Node* neighbor = grid[x][y];

                // Check if neighbor is already in the closed set
                if (neighbor == NULL || in_array(neighbor, closed_set, closed_set_size)) continue;

                int tentative_g = current->g + heuristic(current, neighbor);

                // Check if neighbor is not yet in the open set
                if (!in_array(neighbor, open_set, open_set_size) || tentative_g < neighbor->g) {
                    neighbor->parent = current;
                    neighbor->g = tentative_g;
                    neighbor->h = heuristic(neighbor, end);
                    neighbor->f = neighbor->g + neighbor->h;

                    if (!in_array(neighbor, open_set, open_set_size)) {
                        add_open_set(neighbor);
                    }
                }
            }
        }
    }

    printf("Path not found.\n");
}

int in_array(Node* node, Node** array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == node) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Initialize grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = create_node(i, j);
        }
    }

    // Set obstacles
    grid[2][2] = NULL;
    grid[2][3] = NULL;
    grid[2][4] = NULL;
    grid[2][5] = NULL;
    grid[2][6] = NULL;
    grid[3][6] = NULL;
    grid[4][6] = NULL;
    grid[5][6] = NULL;
    grid[6][6] = NULL;

    // Find path
    Node* start = grid[0][0];
    Node* end = grid[8][8];
    find_path(start, end);

    return 0;

}