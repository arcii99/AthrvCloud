//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 10
#define COL 10

// Structure to hold the location and cost of a node
typedef struct
{
    int row;
    int col;
    int cost;
} Node;

// Utility function to create a new Node
Node* createNode(int row, int col, int cost)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->cost = cost;
    return node;
}

// Variables to hold the start and end locations
int startRow, startCol, endRow, endCol;

// Variable to hold the map
int map[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Utility function to check if a location is valid
bool isValid(int row, int col)
{
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

// Utility function to check if a location is blocked
bool isBlocked(int row, int col)
{
    return (map[row][col] == 1);
}

// Utility function to check if a location is the goal
bool isGoal(int row, int col)
{
    return (row == endRow && col == endCol);
}

// Utility function to calculate heuristic cost between two nodes
int heuristicCost(Node* current, Node* goal)
{
    int dx = abs(current->col - goal->col);
    int dy = abs(current->row - goal->row);
    return dx + dy;
}

// Function to implement A* pathfinding algorithm
void aStar()
{
    // Create a two-dimensional array to hold the cost of each node
    int costs[ROW][COL];

    // Initialize all costs to infinity
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            costs[i][j] = INT_MAX;
        }
    }

    // Create a two-dimensional array to hold the parent node of each node
    Node* parents[ROW][COL];

    // Create a priority queue to hold the nodes to be expanded
    Node* queue[ROW * COL];
    int front = 0;
    int rear = 0;

    // Create the starting node and set its cost to zero
    Node* start = createNode(startRow, startCol, 0);
    costs[startRow][startCol] = 0;

    // Add the starting node to the queue
    queue[rear++] = start;

    // Loop until the queue is empty or the goal is found
    while (front != rear)
    {
        // Get the node at the front of the queue
        Node* current = queue[front++];

        // Check if the current node is the goal
        if (isGoal(current->row, current->col))
        {
            // Print the path
            Node* node = current;
            while (node != NULL)
            {
                printf("(%d, %d)\n", node->row, node->col);
                node = parents[node->row][node->col];
            }
            return;
        }

        // Loop through the neighbors of the current node
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                // Skip the current node
                if (i == 0 && j == 0)
                    continue;

                // Calculate the row and column of the neighbor
                int row = current->row + i;
                int col = current->col + j;

                // Check if the neighbor is valid and not blocked
                if (isValid(row, col) && !isBlocked(row, col))
                {
                    // Calculate the cost of moving to the neighbor
                    int cost = current->cost + 1;

                    // Calculate the heuristic cost of the neighbor
                    Node* goal = createNode(endRow, endCol, 0);
                    int heuristic = heuristicCost(createNode(row, col, 0), goal);

                    // Calculate the total cost of the neighbor
                    int totalCost = cost + heuristic;

                    // Check if the total cost is less than the current cost
                    if (totalCost < costs[row][col])
                    {
                        // Update the cost and parent of the neighbor
                        costs[row][col] = totalCost;
                        parents[row][col] = current;

                        // Create a new node for the neighbor and add it to the queue
                        Node* neighbor = createNode(row, col, cost);
                        queue[rear++] = neighbor;
                    }
                }
            }
        }
    }

    // If the goal was not found, print an error message
    printf("No path found\n");
}

// Main function to test the algorithm
int main()
{
    // Set the start and end locations
    startRow = 0;
    startCol = 0;
    endRow = 9;
    endCol = 9;

    // Set the map
    map[1][0] = 1;
    map[1][1] = 1;
    map[2][1] = 1;
    map[3][1] = 1;
    map[3][2] = 1;
    map[3][3] = 1;
    map[2][3] = 1;
    map[1][3] = 1;
    map[4][4] = 1;
    map[5][4] = 1;
    map[6][4] = 1;
    map[7][4] = 1;
    map[7][5] = 1;
    map[7][6] = 1;
    map[6][6] = 1;
    map[5][6] = 1;
    map[8][8] = 1;
    map[8][9] = 1;
    map[9][8] = 1;
    map[9][9] = 1;

    // Run the algorithm and print the path
    aStar();

    return 0;
}