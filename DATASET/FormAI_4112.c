//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the map
#define ROW 10
#define COL 10

// Define the starting and ending point
#define START_ROW 0
#define START_COL 0
#define END_ROW 9
#define END_COL 9

// Define an array to store the map
char map[ROW][COL] = {
    {'S', '.', '.', '#', '.', '.', '.', '.', '.', '.'},
    {'.', '#', '.', '.', '.', '#', '.', '.', '.', '.'},
    {'.', '#', '.', '.', '.', '#', '.', '.', '.', '.'},
    {'.', '.', '#', '#', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '#', '.', '.', '#', '.', '.'},
    {'.', '.', '.', '.', '#', '.', '.', '#', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '#', '.', '.', '.'},
    {'.', '#', '#', '#', '.', '#', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'E'}
};

// Define a structure to represent a point on the map
typedef struct {
    int row;
    int col;
} Point;

// Define a structure to represent a node in the priority queue
typedef struct {
    Point point;
    int priority;
} PQNode;

// Define a function to check if the given point is a valid point on the map
bool is_valid_point(Point point) {
    if (point.row < 0 || point.col < 0 || point.row >= ROW || point.col >= COL) {
        return false;
    }
    if (map[point.row][point.col] == '#') {
        return false;
    }
    return true;
}

// Define a function to calculate the heuristic value of the given point
int heuristic(Point point) {
    return abs(point.row - END_ROW) + abs(point.col - END_COL);
}

// Define a function to add a node to the priority queue
void add_to_pq(PQNode pq[], int *pq_size, PQNode node) {
    int i;
    for (i = *pq_size - 1; i >= 0; i--) {
        if (pq[i].priority < node.priority) {
            break;
        }
        pq[i + 1] = pq[i];
    }
    pq[i + 1] = node;
    (*pq_size)++;
}

// Define a function to remove the node with the highest priority from the priority queue
PQNode pop_from_pq(PQNode pq[], int *pq_size) {
    PQNode node = pq[0];
    (*pq_size)--;
    int i;
    for (i = 0; i < *pq_size; i++) {
        pq[i] = pq[i + 1];
    }
    return node;
}

// Define the A* search algorithm
void astar_search() {
    // Define the priority queue
    PQNode pq[ROW * COL];
    int pq_size = 0;

    // Define the visited array to mark which points have been visited
    bool visited[ROW][COL] = {false};

    // Define the parent array to store the parent of each point
    Point parent[ROW][COL] = {0};

    // Define the cost array to store the cost of each point
    int cost[ROW][COL] = {0};

    // Add the starting point to the priority queue
    PQNode start_node = { {START_ROW, START_COL}, 0 };
    add_to_pq(pq, &pq_size, start_node);

    // Loop until the priority queue is empty
    while (pq_size > 0) {
        // Pop the node with the highest priority from the priority queue
        PQNode current_node = pop_from_pq(pq, &pq_size);
        Point current_point = current_node.point;
        visited[current_point.row][current_point.col] = true;

        // If we have reached the end point, exit the loop
        if (current_point.row == END_ROW && current_point.col == END_COL) {
            break;
        }

        // Check the neighbors of the current point
        Point neighbors[4] = {
            {current_point.row - 1, current_point.col},
            {current_point.row + 1, current_point.col},
            {current_point.row, current_point.col - 1},
            {current_point.row, current_point.col + 1}
        };
        int i;
        for (i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];

            // Make sure the neighbor is a valid point on the map
            if (!is_valid_point(neighbor)) {
                continue;
            }

            // If the neighbor has not been visited, or there is a shorter path to it, update its cost and add it to the priority queue
            int neighbor_cost = cost[current_point.row][current_point.col] + 1;
            if (!visited[neighbor.row][neighbor.col] || neighbor_cost < cost[neighbor.row][neighbor.col]) {
                cost[neighbor.row][neighbor.col] = neighbor_cost;
                parent[neighbor.row][neighbor.col] = current_point;
                int priority = neighbor_cost + heuristic(neighbor);
                PQNode neighbor_node = { neighbor, priority };
                add_to_pq(pq, &pq_size, neighbor_node);
            }
        }
    }

    // Print the path from the start point to the end point
    Point current_point = {END_ROW, END_COL};
    while (current_point.row != START_ROW || current_point.col != START_COL) {
        printf("(%d,%d) -> ", current_point.row, current_point.col);
        current_point = parent[current_point.row][current_point.col];
    }
    printf("(%d,%d)\n", START_ROW, START_COL);
}

// Define the main function
int main() {
    astar_search();
    return 0;
}