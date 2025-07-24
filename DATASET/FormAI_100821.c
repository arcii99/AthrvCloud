//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// A node struct to keep track of node data
typedef struct Node {
  int row, col; // Current node position
  int fScore, gScore, hScore; // Node scores
  bool isOpen, isClosed; // Node state
  struct Node* parent; // Node's parent
} Node;

// Global variable to store the grid
Node grid[ROWS][COLS];

// Function to initialize grid nodes
void initializeGrid() {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      grid[row][col].row = row;
      grid[row][col].col = col;
      grid[row][col].fScore = 0;
      grid[row][col].gScore = 0;
      grid[row][col].hScore = 0;
      grid[row][col].isOpen = true;
      grid[row][col].isClosed = false;
      grid[row][col].parent = NULL;
    }
  }
}

// Function to calculate Manhattan distance heuristic
int getManhattanDistance(int r1, int c1, int r2, int c2) {
  return abs(r1 - r2) + abs(c1 - c2);
}

// Function to calculate the node's fScore
void calculateFScore(Node* node, int startRow, int startCol, int endRow, int endCol) {
  node->gScore = getManhattanDistance(startRow, startCol, node->row, node->col);
  node->hScore = getManhattanDistance(node->row, node->col, endRow, endCol);
  node->fScore = node->gScore + node->hScore;
}

// Function to check if node is a valid neighbor
bool isValidNeighbor(Node* node, int row, int col) {
  return (row >= 0 && row < ROWS && col >= 0 && col < COLS && grid[row][col].isOpen);
}

// Function to get the neighbors of a node
void getNeighbors(Node* node, Node* neighbors[8]) {
  int row = node->row;
  int col = node->col;

  // Get the 8 neighbors of the current node
  neighbors[0] = isValidNeighbor(node, row - 1, col - 1) ? &grid[row - 1][col - 1] : NULL;
  neighbors[1] = isValidNeighbor(node, row - 1, col) ? &grid[row - 1][col] : NULL;
  neighbors[2] = isValidNeighbor(node, row - 1, col + 1) ? &grid[row - 1][col + 1] : NULL;
  neighbors[3] = isValidNeighbor(node, row, col - 1) ? &grid[row][col - 1] : NULL;
  neighbors[4] = isValidNeighbor(node, row, col + 1) ? &grid[row][col + 1] : NULL;
  neighbors[5] = isValidNeighbor(node, row + 1, col - 1) ? &grid[row + 1][col - 1] : NULL;
  neighbors[6] = isValidNeighbor(node, row + 1, col) ? &grid[row + 1][col] : NULL;
  neighbors[7] = isValidNeighbor(node, row + 1, col + 1) ? &grid[row + 1][col + 1] : NULL;
}

// Function to find the node with the lowest fScore
Node* getLowestFScoreNode(Node* openSet[]) {
  Node* lowestFScoreNode = openSet[0];
  for (int i = 1; i < ROWS * COLS; i++) {
    if (openSet[i] && (openSet[i]->fScore < lowestFScoreNode->fScore)) {
      lowestFScoreNode = openSet[i];
    }
  }
  return lowestFScoreNode;
}

// Function to find the shortest path using the A* algorithm
void findShortestPath(int startRow, int startCol, int endRow, int endCol) {
  // Initialize the grid
  initializeGrid();

  // Add start node to open set
  Node* openSet[ROWS * COLS] = {&grid[startRow][startCol]};
  int openSetSize = 1;
  grid[startRow][startCol].isOpen = false;

  // Loop until the open set is empty
  while (openSetSize > 0) {
    // Get the node with the lowest fScore
    Node* current = getLowestFScoreNode(openSet);

    // Check if current node is the end node
    if (current->row == endRow && current->col == endCol) {
      printf("Shortest path found!\n");
      return;
    }

    // Remove current node from open set
    current->isOpen = false;
    current->isClosed = true;
    for (int i = 0; i < openSetSize; i++) {
      if (openSet[i] == current) {
        openSet[i] = NULL;
        break;
      }
    }
    openSetSize--;

    // Get neighbors of current node
    Node* neighbors[8];
    getNeighbors(current, neighbors);

    // Loop through neighbors
    for (int i = 0; i < 8; i++) {
      Node* neighbor = neighbors[i];

      if (neighbor && !neighbor->isClosed) {
        // Calculate neighbor's fScore
        calculateFScore(neighbor, startRow, startCol, endRow, endCol);

        if (!neighbor->isOpen) {
          // Add neighbor to open set
          neighbor->isOpen = true;
          openSet[openSetSize] = neighbor;
          openSetSize++;
        } else {
          // Check if new path to neighbor is better than previous
          if (neighbor->gScore > current->gScore + getManhattanDistance(current->row, current->col, neighbor->row, neighbor->col)) {
            neighbor->parent = current;
            neighbor->gScore = current->gScore + getManhattanDistance(current->row, current->col, neighbor->row, neighbor->col);
            neighbor->fScore = neighbor->gScore + neighbor->hScore;
          }
        }
      }
    }
  }

  // No path found
  printf("No path found!\n");
}

int main() {
  // Find the shortest path
  findShortestPath(2, 2, 8, 8);

  return 0;
}