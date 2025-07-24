//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: scalable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int map[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1}
};

typedef struct node {
    int r, c;
    int parent_r, parent_c;
    int distance_from_start;
    int heuristic_distance_to_end;
    int total_distance;
} Node;

// Function to calculate the Manhattan distance heuristic
int calcManhattanDistance(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

// Function to check if a node is valid
bool isValidNode(int r, int c) {
    return r >= 0 && r < ROW && c >= 0 && c < COL && map[r][c] == 1;
}

// Function to find the shortest path using A* algorithm
bool findShortestPath(Node start_node, Node end_node) {
    Node open_set[ROW * COL];
    Node closed_set[ROW * COL];
    int open_set_size = 1;
    int closed_set_size = 0;
    open_set[0] = start_node;
    
    while (open_set_size > 0) {
        // Find node with lowest total distance
        int curr_node_index = 0;
        for (int i = 1; i < open_set_size; i++) {
            if (open_set[i].total_distance < open_set[curr_node_index].total_distance) {
                curr_node_index = i;
            }
        }
        Node curr_node = open_set[curr_node_index];
        
        // Check if we have reached the end node
        if (curr_node.r == end_node.r && curr_node.c == end_node.c) {
            printf("Shortest path found! Distance: %d\n", curr_node.distance_from_start);
            
            // Print out the path by following the parent pointers
            while (curr_node.parent_r != -1 && curr_node.parent_c != -1) {
                printf("(%d, %d) -> ", curr_node.r, curr_node.c);
                curr_node = open_set[curr_node.parent_r * COL + curr_node.parent_c];
            }
            printf("(%d, %d)\n", curr_node.r, curr_node.c);
            
            return true;
        }
        
        // Remove node from open set and add to closed set
        for (int i = curr_node_index; i < open_set_size - 1; i++) {
            open_set[i] = open_set[i+1];
        }
        open_set_size--;
        closed_set[closed_set_size++] = curr_node;
        
        // Generate and evaluate neighbor nodes
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue;
                int neighbor_r = curr_node.r + dr;
                int neighbor_c = curr_node.c + dc;
                if (!isValidNode(neighbor_r, neighbor_c)) continue;
                Node neighbor = {
                    .r = neighbor_r,
                    .c = neighbor_c,
                    .parent_r = curr_node.r,
                    .parent_c = curr_node.c,
                    .distance_from_start = curr_node.distance_from_start + 1,
                    .heuristic_distance_to_end = calcManhattanDistance(neighbor_r, neighbor_c, end_node.r, end_node.c),
                    .total_distance = curr_node.distance_from_start + 1 + calcManhattanDistance(neighbor_r, neighbor_c, end_node.r, end_node.c)
                };
                bool skip_node = false;
                for (int i = 0; i < open_set_size; i++) {
                    if (open_set[i].r == neighbor.r && open_set[i].c == neighbor.c && open_set[i].total_distance <= neighbor.total_distance) {
                        skip_node = true;
                        break;
                    }
                }
                if (skip_node) continue;
                for (int i = 0; i < closed_set_size; i++) {
                    if (closed_set[i].r == neighbor.r && closed_set[i].c == neighbor.c && closed_set[i].total_distance <= neighbor.total_distance) {
                        skip_node = true;
                        break;
                    }
                }
                if (skip_node) continue;
                open_set[open_set_size++] = neighbor;
            }
        }
    }
    
    return false;
}

int main() {
    Node start_node = {
        .r = 0,
        .c = 0,
        .parent_r = -1,
        .parent_c = -1,
        .distance_from_start = 0,
        .heuristic_distance_to_end = calcManhattanDistance(0, 0, 9, 9),
        .total_distance = calcManhattanDistance(0, 0, 9, 9)
    };
    Node end_node = {
        .r = 9,
        .c = 9
    };
    
    if (!findShortestPath(start_node, end_node)) {
        printf("No path found!\n");
    }
    
    return 0;
}