//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multiplayer
// Multiplayer Pathfinding Algorithm
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int map[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Node structure for A* algorithm
struct Node {
    int x, y, distance, heuristic, visited, parentX, parentY;
};

// Function to check if a given location is a valid move
int is_valid(int x, int y) {
    if (x >= 0 && x < ROW && y >= 0 && y < COL && map[x][y] == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to calculate manhattan distance
int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Function to check if a given node is the destination
int is_destination(int x, int y, int dest_x, int dest_y) {
    if (x == dest_x && y == dest_y) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the path taken from source to destination
void print_path(struct Node nodes[ROW][COL], int src_x, int src_y, int dest_x, int dest_y) {
    int curr_x = dest_x, curr_y = dest_y;
    printf("Path: (%d, %d)", curr_x, curr_y);
    while (curr_x != src_x || curr_y != src_y) {
        int temp_x = curr_x;
        curr_x = nodes[curr_x][curr_y].parentX;
        curr_y = nodes[temp_x][curr_y].parentY;
        printf(" <- (%d, %d)", curr_x, curr_y);
    }
    printf("\n");
}

// Function to perform A* algorithm
void a_star(int src_x, int src_y, int dest_x, int dest_y) {
    // Initialize the nodes
    struct Node nodes[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            nodes[i][j].x = i;
            nodes[i][j].y = j;
            nodes[i][j].distance = -1;
            nodes[i][j].heuristic = -1;
            nodes[i][j].visited = 0;
            nodes[i][j].parentX = -1;
            nodes[i][j].parentY = -1;
        }
    }

    // Initialize the source node
    nodes[src_x][src_y].distance = 0;
    nodes[src_x][src_y].heuristic = manhattan_distance(src_x, src_y, dest_x, dest_y);

    // Initialize the open and closed lists
    struct Node *open_list[ROW * COL];
    int open_count = 0;
    struct Node *closed_list[ROW * COL];
    int closed_count = 0;
    open_list[open_count++] = &nodes[src_x][src_y];

    // Loop until destination is found
    while (open_count > 0) {
        // Get the node with the lowest cost
        int lowest_cost = 99999;
        int current_node_index = 0;
        for (int i = 0; i < open_count; i++) {
            if (open_list[i]->distance + open_list[i]->heuristic < lowest_cost) {
                lowest_cost = open_list[i]->distance + open_list[i]->heuristic;
                current_node_index = i;
            }
        }
        struct Node *current_node = open_list[current_node_index];

        // Remove the current node from the open list
        for (int i = current_node_index; i < open_count - 1; i++) {
            open_list[i] = open_list[i + 1];
        }
        open_count--;

        // Add the current node to the closed list
        closed_list[closed_count++] = current_node;

        // Check if the current node is the destination
        if (is_destination(current_node->x, current_node->y, dest_x, dest_y)) {
            print_path(nodes, src_x, src_y, dest_x, dest_y);
            return;
        }

        // Get the valid neighbors of the current node
        int neighbors[8][2] = {
            {-1, 0},
            {0, -1},
            {1, 0},
            {0, 1},
            {-1, -1},
            {-1, 1},
            {1, -1},
            {1, 1}
        };
        for (int i = 0; i < 8; i++) {
            int neighbor_x = current_node->x + neighbors[i][0];
            int neighbor_y = current_node->y + neighbors[i][1];

            if (is_valid(neighbor_x, neighbor_y)) {
                int new_distance = current_node->distance + 1;
                int new_heuristic = manhattan_distance(neighbor_x, neighbor_y, dest_x, dest_y);
                struct Node *neighbor_node = &nodes[neighbor_x][neighbor_y];

                // Check if the neighbor node is already in the closed list
                int found_in_closed = 0;
                for (int j = 0; j < closed_count; j++) {
                    if (neighbor_node == closed_list[j]) {
                        found_in_closed = 1;
                        break;
                    }
                }
                if (found_in_closed) {
                    continue;
                }

                // Check if the neighbor node is already in the open list
                int found_in_open = 0;
                for (int j = 0; j < open_count; j++) {
                    if (neighbor_node == open_list[j]) {
                        found_in_open = 1;
                        break;
                    }
                }
                if (!found_in_open) {
                    open_list[open_count++] = neighbor_node;
                } else if (new_distance >= neighbor_node->distance) {
                    continue;
                }

                // Update the neighbor node
                neighbor_node->distance = new_distance;
                neighbor_node->heuristic = new_heuristic;
                neighbor_node->parentX = current_node->x;
                neighbor_node->parentY = current_node->y;
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    // Starting coordinates of 2 players
    int player1_x = 1, player1_y = 1;
    int player2_x = 8, player2_y = 8;

    // Print the map
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == player1_x && j == player1_y) {
                printf("1 ");
            } else if (i == player2_x && j == player2_y) {
                printf("2 ");
            } else {
                printf("%d ", map[i][j]);
            }
        }
        printf("\n");
    }

    // Get the destination coordinates from player1
    int player1_dest_x, player1_dest_y;
    printf("Enter Player 1's destination coordinates: ");
    scanf("%d %d", &player1_dest_x, &player1_dest_y);

    // Find the path from player1's current location to destination
    a_star(player1_x, player1_y, player1_dest_x, player1_dest_y);

    // Get the destination coordinates from player2
    int player2_dest_x, player2_dest_y;
    printf("Enter Player 2's destination coordinates: ");
    scanf("%d %d", &player2_dest_x, &player2_dest_y);

    // Find the path from player2's current location to destination
    a_star(player2_x, player2_y, player2_dest_x, player2_dest_y);

    return 0;
}