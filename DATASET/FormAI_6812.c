//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct Node {
    int x, y;
    int f, g, h;
    struct Node* parent;
} Node;

// The grid we'll be working with
int grid[WIDTH][HEIGHT] = {
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

// Heuristic function to calculate distance to end node
int heuristic(Node* a, Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

// Check if a node is within bounds of the grid
bool is_valid_node(int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[x][y] == 0);
}

// Check if a node is in the open set
bool in_open_set(Node* node, Node** open_set, int open_size) {
    for (int i = 0; i < open_size; i++) {
        if (node->x == open_set[i]->x && node->y == open_set[i]->y) {
            return true;
        }
    }
    return false;
}

// Check if a node is in the closed set
bool in_closed_set(Node* node, Node** closed_set, int closed_size) {
    for (int i = 0; i < closed_size; i++) {
        if (node->x == closed_set[i]->x && node->y == closed_set[i]->y) {
            return true;
        }
    }
    return false;
}

// Get the node with the lowest f score in the open set
Node* get_lowest_f_score_node(Node** open_set, int open_size) {
    Node* lowest = open_set[0];
    for (int i = 1; i < open_size; i++) {
        if (open_set[i]->f < lowest->f) {
            lowest = open_set[i];
        }
    }
    return lowest;
}

// Get the path from the start node to the end node
Node** get_path(Node* start, Node* end, Node** closed_set, int closed_size) {
    Node** path = (Node**)malloc(sizeof(Node*) * closed_size);
    int path_size = 0;
    Node* current = end;
    while (current != start) {
        path[path_size] = current;
        path_size++;
        current = current->parent;
    }
    path[path_size] = start;
    return path;
}

Node** find_path(Node* start, Node* end) {
    // Create open and closed sets
    Node* open_set[WIDTH * HEIGHT] = {0};
    Node* closed_set[WIDTH * HEIGHT] = {0};
    int open_size = 0;
    int closed_size = 0;

    open_set[0] = start;
    open_size++;

    while (open_size > 0) {
        // Get the node with the lowest f score
        Node* current = get_lowest_f_score_node(open_set, open_size);

        // If we've reached the end, return the path
        if (current->x == end->x && current->y == end->y) {
            return get_path(start, end, closed_set, closed_size);
        }

        // Move current node from open set to closed set
        open_set[current->f] = NULL;
        open_size--;
        closed_set[closed_size] = current;
        closed_size++;

        // Check neighbors
        int neighbors[8][2] = {
            { -1, -1 }, { -1, 0 }, { -1, 1 },
            { 0, -1 }, { 0, 1 },
            { 1, -1 }, { 1, 0 }, { 1, 1 }
        };
        for (int i = 0; i < 8; i++) {
            int neighbor_x = current->x + neighbors[i][0];
            int neighbor_y = current->y + neighbors[i][1];

            // Check if neighbor is within bounds and not in closed set
            if (!is_valid_node(neighbor_x, neighbor_y) || in_closed_set(&(Node) { neighbor_x, neighbor_y }, closed_set, closed_size)) {
                continue;
            }

            // If neighbor is in open set, calculate new scores
            int tentative_g_score = current->g + 1;
            Node* neighbor = &(Node) { neighbor_x, neighbor_y };
            if (!in_open_set(neighbor, open_set, open_size)) {
                open_set[open_size] = neighbor;
                open_size++;
                neighbor->h = heuristic(neighbor, end);
            }
            else if (tentative_g_score >= neighbor->g) {
                continue;
            }

            // Update neighbor scores
            neighbor->parent = current;
            neighbor->g = tentative_g_score;
            neighbor->f = neighbor->g + neighbor->h;
        }
    }

    // No path found
    return NULL;
}

int main() {
    Node* start = &(Node) { 0, 0 };
    Node* end = &(Node) { 9, 9 };
    Node** path = find_path(start, end);
    if (path == NULL) {
        printf("No path found.\n");
    }
    else {
        printf("Path found:\n");
        for (int i = 0; path[i] != NULL; i++) {
            printf("(%d, %d)\n", path[i]->x, path[i]->y);
        }
    }

    return 0;
}