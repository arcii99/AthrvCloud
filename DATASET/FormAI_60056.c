//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROW 5
#define COL 5

typedef struct node {
    int x;
    int y;
    struct node* link;
}node;

node* front = NULL;
node* rear = NULL;

// A structure to hold the coordinates of a cell and its distance from the source
typedef struct {
    int row;
    int col;
    int dist;
} cell;

// A function to check if a given cell (row, col) is valid or not.
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// A function to check if the destination has been reached or not
bool isDestination(cell current, cell dest) {
    return (current.row == dest.row) && (current.col == dest.col);
}

// A function to calculate the heuristic value of a given cell
int calculateHeuristic(cell current, cell dest) {
    return abs(current.row - dest.row) + abs(current.col - dest.col);
}

// A function to print the path found from source to destination
void printPath(cell parent[], cell dest) {
    int row = dest.row;
    int col = dest.col;
    node* temp = (node*)malloc(sizeof(node));
    temp->link = NULL;

    while (!(parent[row * COL + col].row == row && parent[row * COL + col].col == col)) {
        temp->x = row;
        temp->y = col;
        temp->link = front;
        front = temp;
        temp = (node*)malloc(sizeof(node));
        temp->link = NULL;
        int temp_row = parent[row * COL + col].row;
        int temp_col = parent[row * COL + col].col;
        row = temp_row;
        col = temp_col;
    }

    temp->x = row;
    temp->y = col;
    temp->link = front;
    front = temp;

    printf("\nThe shortest path is: ");
    while (front != NULL) {
        printf("(%d,%d)", front->x, front->y);
        front = front->link;
        free(rear);
        rear = front;
    }
    printf("\n");
}

// A function to implement A* algorithm to find the shortest path between source and destination
void aStarSearch(int maze[][COL], cell start, cell dest) {
    // If the start is an obstacle
    if (maze[start.row][start.col] != 0) {
        printf("Start is an obstacle\n");
        return;
    }

    // If the destination is an obstacle
    if (maze[dest.row][dest.col] != 0) {
        printf("Destination is an obstacle\n");
        return;
    }

    // If the source and destination are the same
    if (isDestination(start, dest)) {
        printf("Source and destination are the same\n");
        return;
    }

    // Create a closed list to store the cells which have already been visited
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    // Create a cell structure to hold the coordinates of the parent of each cell
    cell parent[ROW * COL];
    memset(parent, -1, sizeof(parent));

    // Create a priority queue to hold the cells to be explored next
    int queueSize = ROW * COL;
    cell queue[queueSize];

    // Initialize the queue with the start cell
    int front = -1, rear = -1;
    queue[++rear] = start;

    // Loop until the queue is empty or the destination has been reached
    while (front != rear) {
        // Remove the cell with the highest priority (lowest cost)
        cell current = queue[++front];

        // Print the current cell
        printf("(%d,%d) -> ", current.row, current.col);

        // If the destination has been reached
        if (isDestination(current, dest)) {
            printf("\nThe destination has been reached\n");
            printPath(parent, dest);
            return;
        }

        // Mark the current cell as visited
        closedList[current.row][current.col] = true;

        // Calculate the heuristic value of each neighbor and add it to the queue
        int row = current.row;
        int col = current.col;
        int dist = current.dist + 1;

        // Check the neighbor above
        if (isValid(row - 1, col) && !closedList[row - 1][col] && maze[row - 1][col] == 0) {
            cell neighbor = { row - 1, col, dist + calculateHeuristic((cell){row - 1, col}, dest)};
            parent[(row - 1) * COL + col] = current;
            queue[++rear] = neighbor;
        }

        // Check the neighbor below
        if (isValid(row + 1, col) && !closedList[row + 1][col] && maze[row + 1][col] == 0) {
            cell neighbor = { row + 1, col, dist + calculateHeuristic((cell){row + 1, col}, dest)};
            parent[(row + 1) * COL + col] = current;
            queue[++rear] = neighbor;
        }

        // Check the neighbor to the left
        if (isValid(row, col - 1) && !closedList[row][col - 1] && maze[row][col - 1] == 0) {
            cell neighbor = { row, col - 1, dist + calculateHeuristic((cell){row, col - 1}, dest)};
            parent[row * COL + col - 1] = current;
            queue[++rear] = neighbor;
        }

        // Check the neighbor to the right
        if (isValid(row, col + 1) && !closedList[row][col + 1] && maze[row][col + 1] == 0) {
            cell neighbor = { row, col + 1, dist + calculateHeuristic((cell){row, col + 1}, dest)};
            parent[row * COL + col + 1] = current;
            queue[++rear] = neighbor;
        }
    }

    // If the destination cannot be reached
    printf("\n\nThe destination cannot be reached\n");
}

int main() {
    int maze[ROW][COL] =
    {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    cell start = { 0, 0, 0 };
    cell dest = { 4, 4, 0 };

    aStarSearch(maze, start, dest);

    return 0;
}