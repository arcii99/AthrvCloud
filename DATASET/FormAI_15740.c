//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the map size
#define ROWS 6
#define COLS 7

// Define the starting and ending points
#define START_ROW 3
#define START_COL 4
#define END_ROW 0
#define END_COL 5

// Define the heuristic function: Manhattan distance
int heuristic(int row, int col) {
    int dx = abs(row - END_ROW);
    int dy = abs(col - END_COL);
    return dx + dy;
}

// Define the main function: A* algorithm
void a_star(char map[ROWS][COLS]) {
    // Define the Node data structure
    typedef struct Node {
        int row;
        int col;
        int f;
        int g;
        struct Node* parent;
    } Node;

    // Initialize the starting point
    Node* start = (Node*)malloc(sizeof(Node));
    start->row = START_ROW;
    start->col = START_COL;
    start->f = heuristic(START_ROW, START_COL);
    start->g = 0;
    start->parent = NULL;

    // Initialize the open and closed lists
    Node* open_list[ROWS*COLS];
    int open_list_size = 1;
    open_list[0] = start;
    Node* closed_list[ROWS*COLS];
    int closed_list_size = 0;

    while (open_list_size > 0) {
        // Find the Node with the lowest f value
        Node* current = open_list[0];
        int index = 0;
        for (int i = 1; i < open_list_size; i++) {
            if (open_list[i]->f < current->f) {
                current = open_list[i];
                index = i;
            }
        }

        // Remove the current Node from the open list
        open_list[index] = open_list[open_list_size - 1];
        open_list_size--;

        // Add the current Node to the closed list
        closed_list[closed_list_size++] = current;

        // Check if the current Node is the goal Node
        if (current->row == END_ROW && current->col == END_COL) {
            // Print the shortest path
            printf("Shortest path:\n");
            while (current) {
                map[current->row][current->col] = '*';
                current = current->parent;
            }
            printf("\n");
            break;
        }

        // Generate the neighbors of the current Node
        Node* neighbors[8];
        int neighbors_size = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // Skip the current Node and out-of-bounds nodes
                if (i == 0 && j == 0 ||
                    current->row+i < 0 || current->row+i >= ROWS ||
                    current->col+j < 0 || current->col+j >= COLS) {
                    continue;
                }
                // Skip the obstacles
                if (map[current->row+i][current->col+j] == '#') {
                    continue;
                }
                // Create a new Node
                Node* neighbor = (Node*)malloc(sizeof(Node));
                neighbor->row = current->row+i;
                neighbor->col = current->col+j;
                neighbor->g = current->g + 1;
                neighbor->f = neighbor->g + heuristic(neighbor->row, neighbor->col);
                neighbor->parent = current;
                neighbors[neighbors_size++] = neighbor;
            }
        }

        // Check the neighbors
        for (int i = 0; i < neighbors_size; i++) {
            // Skip the neighbors in the closed list
            for (int j = 0; j < closed_list_size; j++) {
                if (neighbors[i]->row == closed_list[j]->row &&
                    neighbors[i]->col == closed_list[j]->col) {
                    goto skip;
                }
            }
            // Check if the neighbor is already in the open list
            for (int j = 0; j < open_list_size; j++) {
                if (neighbors[i]->row == open_list[j]->row &&
                    neighbors[i]->col == open_list[j]->col) {
                    // Calculate the new g value
                    int new_g = current->g + 1;
                    if (new_g < open_list[j]->g) {
                        open_list[j]->g = new_g;
                        open_list[j]->f = new_g + heuristic(open_list[j]->row, open_list[j]->col);
                        open_list[j]->parent = current;
                    }
                    goto skip;
                }
            }
            // Add the neighbor to the open list
            open_list[open_list_size++] = neighbors[i];
            skip:;
        }
    }
}

// Define the main function: create the map and call A*
int main() {
    char map[ROWS][COLS] = {
        ".######",
        "......#",
        ".####.#",
        ".#..###",
        ".#....#",
        "######.",
    };

    printf("Map:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    a_star(map);

    printf("Shortest path on the map:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}