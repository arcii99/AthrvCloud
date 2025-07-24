//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10

/*
    This program implements the Dijkstra's algorithm for finding the shortest path
    between nodes in a graph. In this case, the graph is represented as a 2D array
    of integers.

    The program prompts the user to input a starting and ending point, then
    calculates the shortest path between them.

    The algorithm keeps track of the shortest distances found so far to all nodes,
    as well as the nodes that are still unvisited.

    The code below uses a priority queue to keep track of the unvisited nodes.
*/

// Define the graph as a global variable
int graph[ROWS][COLUMNS];

// Define a struct for a node
typedef struct {
    int row;
    int column;
} node;

// Define a struct for a priority queue
typedef struct {
    node data[ROWS*COLUMNS];
    int priority[ROWS*COLUMNS];
    int size;
} priority_queue;

// Define functions for working with the priority queue
void init_priority_queue(priority_queue *q);
void enqueue(priority_queue *q, node n, int priority);
node dequeue(priority_queue *q);
bool is_empty(priority_queue *q);

// Define the main function
int main() {
    // Initialize the graph
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLUMNS; j++) {
            graph[i][j] = rand() % 10;
        }
    }

    // Print the graph
    printf("Graph:\n");
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLUMNS; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Prompt the user to input a starting and ending point
    node start, end;
    printf("Enter the starting row and column: ");
    scanf("%d %d", &start.row, &start.column);
    printf("Enter the ending row and column: ");
    scanf("%d %d", &end.row, &end.column);

    // Initialize the distance and visited matrices
    int distances[ROWS][COLUMNS];
    bool visited[ROWS][COLUMNS];

    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLUMNS; j++) {
            distances[i][j] = 999; // Initialize to a high value
            visited[i][j] = false;
        }
    }

    distances[start.row][start.column] = 0;

    // Initialize the priority queue and enqueue the start node
    priority_queue q;
    init_priority_queue(&q);
    enqueue(&q, start, 0);

    // Main loop
    while (!is_empty(&q)) {
        node current = dequeue(&q);

        // Check for the end node
        if (current.row == end.row && current.column == end.column) {
            printf("Shortest path found: %d\n", distances[current.row][current.column]);
            break;
        }

        visited[current.row][current.column] = true;

        // Check the distance to the neighbors
        int row = current.row;
        int column = current.column;

        if (row > 0 && !visited[row-1][column]) {
            int d = distances[row][column] + graph[row-1][column];
            if (d < distances[row-1][column]) {
                distances[row-1][column] = d;
                enqueue(&q, (node){row-1, column}, d);
            }
        }

        if (row < ROWS-1 && !visited[row+1][column]) {
            int d = distances[row][column] + graph[row+1][column];
            if (d < distances[row+1][column]) {
                distances[row+1][column] = d;
                enqueue(&q, (node){row+1, column}, d);
            }
        }

        if (column > 0 && !visited[row][column-1]) {
            int d = distances[row][column] + graph[row][column-1];
            if (d < distances[row][column-1]) {
                distances[row][column-1] = d;
                enqueue(&q, (node){row, column-1}, d);
            }
        }

        if (column < COLUMNS-1 && !visited[row][column+1]) {
            int d = distances[row][column] + graph[row][column+1];
            if (d < distances[row][column+1]) {
                distances[row][column+1] = d;
                enqueue(&q, (node){row, column+1}, d);
            }
        }
    }

    return 0;
}

void init_priority_queue(priority_queue *q) {
    q->size = 0;
}

void enqueue(priority_queue *q, node n, int priority) {
    q->data[q->size] = n;
    q->priority[q->size] = priority;
    q->size++;

    // Bubble up the new element to its correct position in the queue
    int i = q->size - 1;
    while (i > 0 && q->priority[i] < q->priority[(i-1)/2]) {
        // Swap the parent and child nodes
        node temp_node = q->data[(i-1)/2];
        int temp_priority = q->priority[(i-1)/2];
        q->data[(i-1)/2] = q->data[i];
        q->priority[(i-1)/2] = q->priority[i];
        q->data[i] = temp_node;
        q->priority[i] = temp_priority;

        i = (i-1)/2;
    }
}

node dequeue(priority_queue *q) {
    // Save the top element
    node result = q->data[0];

    // Move the last element to the top
    q->size--;
    q->data[0] = q->data[q->size];
    q->priority[0] = q->priority[q->size];

    // Bubble down the new top element to its correct position in the queue
    int i = 0;
    while (2*i+1 < q->size) {
        // Check which child has the smaller priority
        int j = 2*i+1; // Left child
        if (j+1 < q->size && q->priority[j+1] < q->priority[j]) {
            j = j+1; // Right child
        }

        // Swap the parent and child nodes if necessary
        if (q->priority[i] > q->priority[j]) {
            node temp_node = q->data[j];
            int temp_priority = q->priority[j];
            q->data[j] = q->data[i];
            q->priority[j] = q->priority[i];
            q->data[i] = temp_node;
            q->priority[i] = temp_priority;
        }

        i = j;
    }

    return result;
}

bool is_empty(priority_queue *q) {
    return q->size == 0;
}