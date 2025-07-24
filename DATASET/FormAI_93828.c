//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 20
#define COLS 20

// Medieval-style map with walls and obstacles
char map[ROWS][COLS] = {
    "###################",
    "#                 #",
    "# ####     ###### #",
    "#    #     #       #",
    "#### #     # ######",
    "#    #           ##",
    "#    ######     ## ",
    "#        #     ##  ",
    "##########     #   ",
    "#        #     #   ",
    "# ###### #     #   ",
    "# #          # #   ",
    "# # ########## #   ",
    "# #      #       ##",
    "# ####   #      ## ",
    "#        #######   ",
    "#### #     #       ",
    "#    #     # ###   ",
    "# ####     #   #   ",
    "###################",
};

// Struct to represent nodes in the map
typedef struct Node {
    int row, col;
    int g_score, f_score;
    struct Node* parent;
} Node;

Node* create_node(int r, int c) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = r;
    node->col = c;
    node->g_score = 0;
    node->f_score = 0;
    node->parent = NULL;
    return node;
}

// Heuristic function to calculate the estimated distance between two nodes
int heuristic(Node* current, Node* goal) {
    int dx = abs(current->col - goal->col);
    int dy = abs(current->row - goal->row);
    return sqrt(dx*dx + dy*dy);
}

// Utility function to check if a node is inside the map
bool is_inside_map(int r, int c) {
    return r >= 0 && r < ROWS && c >= 0 && c < COLS;
}

// Utility function to check if a node is not a wall or obstacle
bool is_walkable(int r, int c) {
    return map[r][c] != '#' && map[r][c] != '%';
}

// Utility function to check if two nodes are neighbors (i.e. are adjacent or diagonal)
bool are_neighbors(Node* node1, Node* node2) {
    int dx = abs(node1->col - node2->col);
    int dy = abs(node1->row - node2->row);
    return (dx == 1 && dy == 0) || (dx == 0 && dy == 1) || (dx == 1 && dy == 1);
}

// Utility function to print the map with the path found by A*
void print_map(Node* start, Node* goal) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (start->row == r && start->col == c) {
                printf("S");
            } else if (goal->row == r && goal->col == c) {
                printf("G");
            } else if (map[r][c] == '#') {
                printf("#");
            } else if (map[r][c] == '%') {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Main function to perform A* pathfinding algorithm
bool a_star(Node* start, Node* goal, Node** path, int* path_length) {
    // Create an open set and add the start node to it
    Node* open_set[ROWS*COLS];
    int open_set_size = 0;
    open_set[open_set_size++] = start;

    // Create a closed set
    bool closed_set[ROWS][COLS] = {false};

    // Loop until the open set is empty
    while (open_set_size > 0) {
        // Find the node in the open set with the lowest f_score
        int lowest_f_score = open_set[0]->f_score;
        int lowest_f_score_index = 0;
        for (int i = 1; i < open_set_size; i++) {
            if (open_set[i]->f_score < lowest_f_score) {
                lowest_f_score = open_set[i]->f_score;
                lowest_f_score_index = i;
            }
        }
        Node* current = open_set[lowest_f_score_index];

        // If the current node is the goal, reconstruct the path and return true
        if (current->row == goal->row && current->col == goal->col) {
            *path_length = 0;
            Node* node = current;
            while (node) {
                (*path)[(*path_length)++] = *node;
                node = node->parent;
            }
            return true;
        }

        // Remove the current node from the open set and add it to the closed set
        open_set[lowest_f_score_index] = open_set[--open_set_size];
        closed_set[current->row][current->col] = true;

        // Loop over the neighbors of the current node
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                // Ignore the current node and diagonal neighbors
                if (dr == 0 && dc == 0 || abs(dr) == abs(dc)) {
                    continue;
                }
                int r = current->row + dr;
                int c = current->col + dc;
                // Ignore nodes outside the map
                if (!is_inside_map(r, c)) {
                    continue;
                }
                // Ignore nodes that are walls or obstacles
                if (!is_walkable(r, c)) {
                    continue;
                }
                Node* neighbor = create_node(r, c);
                // Ignore nodes that are already in the closed set
                if (closed_set[r][c]) {
                    continue;
                }
                // Calculate the tentative g_score for the neighbor
                int tentative_g_score = current->g_score + heuristic(current, neighbor);
                // If the neighbor is not in the open set, add it and calculate its f_score
                bool neighbor_in_open_set = false;
                for (int i = 0; i < open_set_size; i++) {
                    if (open_set[i]->row == neighbor->row && open_set[i]->col == neighbor->col) {
                        neighbor_in_open_set = true;
                        if (tentative_g_score < open_set[i]->g_score) {
                            open_set[i]->g_score = tentative_g_score;
                            open_set[i]->f_score = tentative_g_score + heuristic(neighbor, goal);
                            open_set[i]->parent = current;
                        }
                        break;
                    }
                }
                if (!neighbor_in_open_set) {
                    neighbor->g_score = tentative_g_score;
                    neighbor->f_score = tentative_g_score + heuristic(neighbor, goal);
                    neighbor->parent = current;
                    open_set[open_set_size++] = neighbor;
                }
            }
        }
    }
    // If the open set is empty and no path was found, return false
    return false;
}

int main() {
    // Find the start and goal nodes in the map
    Node* start = NULL;
    Node* goal = NULL;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (map[r][c] == 'S') {
                start = create_node(r, c);
            } else if (map[r][c] == 'G') {
                goal = create_node(r, c);
            }
        }
    }

    // Find the path from the start to the goal using A*
    Node* path = (Node*)malloc(ROWS*COLS*sizeof(Node));
    int path_length = 0;
    bool success = a_star(start, goal, &path, &path_length);

    // Print the map with the path found by A*
    if (success) {
        for (int i = path_length-1; i >= 0; i--) {
            map[path[i].row][path[i].col] = '%';
        }
    }
    print_map(start, goal);

    return 0;
}