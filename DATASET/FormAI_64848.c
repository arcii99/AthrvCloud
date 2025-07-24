//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = { // our maze
    {0, 1, 0, 0, 1, 0, 1, 1, 0, 1},
    {0, 0, 1, 0, 1, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
    {1, 1, 0, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 0, 1, 1, 1},
    {1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
    {1, 1, 0, 0, 0, 1, 0, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 0}
};

int visitedCells[ROWS][COLS] = {{0}}; // by default all cells are unvisited

typedef struct Node { // our node struct to store coordinates
    int x;
    int y;
} Node;

Node queue[ROWS * COLS]; // we will use BFS algorithm to find a way through the maze
int front = 0, rear = 0; // our BFS queue indices

void enqueue(Node elem) { // push new element into the queue
    queue[rear] = elem;
    rear++;
}

Node dequeue() { // get the next element in queue
    Node elem = queue[front];
    front++;
    return elem;
}

int isQueueEmpty() { // check if queue is empty
    return front == rear;
}

int main() {
    srand(time(NULL)); // initialize random seed
    Node current = {0, 0}; // start from top-left corner
    visitedCells[current.x][current.y] = 1; // mark current cell as visited
    enqueue(current); // put current cell into BFS queue
        
    while (!isQueueEmpty()) { // BFS algorithm
        current = dequeue(); // get next node from queue
        
        if (current.x == ROWS - 1 && current.y == COLS - 1) { // we have reached the bottom-right corner of maze
            printf("Congratulations! You have completed the maze!\n");
            break;
        }
            
        // look for valid neighbors (i.e. not outside the maze, not blocked, not already visited)
        Node neighbors[4];
        int numNeighbors = 0;
        if (current.x > 0 && maze[current.x - 1][current.y] == 0 && visitedCells[current.x - 1][current.y] == 0) {
            neighbors[numNeighbors++] = (Node){current.x - 1, current.y};
        }
        if (current.x < ROWS - 1 && maze[current.x + 1][current.y] == 0 && visitedCells[current.x + 1][current.y] == 0) {
            neighbors[numNeighbors++] = (Node){current.x + 1, current.y};
        }
        if (current.y > 0 && maze[current.x][current.y - 1] == 0 && visitedCells[current.x][current.y - 1] == 0) {
            neighbors[numNeighbors++] = (Node){current.x, current.y - 1};
        }
        if (current.y < COLS - 1 && maze[current.x][current.y + 1] == 0 && visitedCells[current.x][current.y + 1] == 0) {
            neighbors[numNeighbors++] = (Node){current.x, current.y + 1};
        }
        
        if (numNeighbors > 0) { // if we have valid neighbors, randomly choose one and enqueue it
            int randomNeighbor = rand() % numNeighbors;
            visitedCells[neighbors[randomNeighbor].x][neighbors[randomNeighbor].y] = 1; // mark neighbor as visited
            enqueue(neighbors[randomNeighbor]); // push neighbor to BFS queue
        }
    }
    
    return 0;
}