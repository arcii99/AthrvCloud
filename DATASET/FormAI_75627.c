//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the size of the map
#define ROW 8
#define COL 8

// Define the start and end points
#define START_ROW 0
#define START_COL 0
#define END_ROW 7
#define END_COL 7

// Define the heuristic function
#define HEURISTIC(row, col) ((ROW - row) + (COL - col))

// Define a struct for the node in the map
typedef struct Node {
    int row, col;
    int g_score, f_score;
    struct Node* parent;
    struct Node* next;
} Node;

// Define an array to store the open and closed nodes
Node* open_nodes = NULL;
Node* closed_nodes = NULL;

// Define a function to create a new node
Node* create_node(int row, int col, int g_score, int f_score, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->g_score = g_score;
    node->f_score = f_score;
    node->parent = parent;
    node->next = NULL;
    return node;
}

// Define a function to insert a node into a list
void insert_node(Node** list, Node* node) {
    if (*list == NULL) {
        *list = node;
    } else {
        Node* current_node = *list;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = node;
    }
}

// Define a function to remove a node from a list
void remove_node(Node** list, Node* node) {
    Node* current_node = *list;
    if (current_node == node) {
        *list = node->next;
    } else {
        while (current_node->next != node) {
            current_node = current_node->next;
        }
        current_node->next = node->next;
    }
}

// Define a function to check if a node is in a list
int is_in_list(Node* list, Node* node) {
    Node* current_node = list;
    while (current_node != NULL) {
        if (current_node == node) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

// Define the A* pathfinding algorithm
void pathfinding() {
    // Initialize the start node
    Node* start_node = create_node(START_ROW, START_COL, 0, HEURISTIC(START_ROW, START_COL), NULL);
    insert_node(&open_nodes, start_node);

    // Loop until the end node is found or there are no more open nodes
    while (open_nodes != NULL) {
        // Find the node with the lowest f score in the open list
        Node* current_node = open_nodes;
        Node* lowest_f_node = open_nodes;
        while (current_node != NULL) {
            if (current_node->f_score < lowest_f_node->f_score) {
                lowest_f_node = current_node;
            }
            current_node = current_node->next;
        }

        // If the lowest f score is the end node, stop searching
        if (lowest_f_node->row == END_ROW && lowest_f_node->col == END_COL) {
            return;
        }

        // Move the lowest f score node from the open list to the closed list
        remove_node(&open_nodes, lowest_f_node);
        insert_node(&closed_nodes, lowest_f_node);

        // Generate the neighbors of the lowest f score node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // Skip the current node and diagonal neighbors
                if ((i == 0 && j == 0) || (i != 0 && j != 0)) {
                    continue;
                }
                // Determine the row and column of the neighbor node
                int neighbor_row = lowest_f_node->row + i;
                int neighbor_col = lowest_f_node->col + j;
                // Skip the neighbor node if it is out of bounds or already in the closed list
                if (neighbor_row < 0 || neighbor_row >= ROW || neighbor_col < 0 || neighbor_col >= COL || is_in_list(closed_nodes, create_node(neighbor_row, neighbor_col, 0, 0, NULL))) {
                    continue;
                }
                // Calculate the tentative g score and f score of the neighbor node
                int tentative_g_score = lowest_f_node->g_score + abs(i) + abs(j); // 1 if horizontal or vertical, 2 if diagonal
                int tentative_f_score = tentative_g_score + HEURISTIC(neighbor_row, neighbor_col);
                // Add the neighbor node to the open list or update it if it is already in the open list
                Node* neighbor_node = create_node(neighbor_row, neighbor_col, tentative_g_score, tentative_f_score, lowest_f_node);
                if (!is_in_list(open_nodes, neighbor_node)) {
                    insert_node(&open_nodes, neighbor_node);
                } else {
                    Node* current_node = open_nodes;
                    while (current_node != NULL) {
                        if (current_node->row == neighbor_row && current_node->col == neighbor_col) {
                            if (tentative_g_score < current_node->g_score) {
                                current_node->g_score = tentative_g_score;
                                current_node->f_score = tentative_f_score;
                                current_node->parent = lowest_f_node;
                            }
                            break;
                        }
                        current_node = current_node->next;
                    }
                }
            }
        }
    }
}

// Define a function to print the path from the start node to the end node
void print_path() {
    // Find the end node in the closed list
    Node* end_node = closed_nodes;
    while (!(end_node->row == END_ROW && end_node->col == END_COL)) {
        end_node = end_node->next;
    }
    // Print the path from the end node to the start node
    Node* current_node = end_node;
    int path_length = 0;
    while (current_node != NULL) {
        path_length++;
        current_node = current_node->parent;
    }
    printf("Path length: %d\n", path_length);
    printf("Path:\n");
    current_node = end_node;
    while (current_node != NULL) {
        printf("(%d, %d)\n", current_node->row, current_node->col);
        current_node = current_node->parent;
    }
}

// Define the main function
int main() {
    // Define the map
    int map[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 1, 1, 0},
        {0, 0, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };

    // Print the map
    printf("Map:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    // Find the path
    pathfinding();

    // Print the path
    print_path();

    // Free the memory allocated for the nodes
    Node* current_node = open_nodes;
    while (current_node != NULL) {
        Node* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    current_node = closed_nodes;
    while (current_node != NULL) {
        Node* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    return 0;
}