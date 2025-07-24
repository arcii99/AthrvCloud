//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

// create the maze grid
char maze[SIZE][SIZE] = {
        {'S', '#', '#', '#', '#', '#', '#', '#', '#', 'E'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', 'X'}
};

// create the queue structure for BFS
typedef struct Node {
    int row;
    int col;
    struct Node* next;
} Node;

Node* create_node(int row, int col) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->next = NULL;
    return new_node;
}

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

bool is_empty(Queue* queue) {
    return queue->head == NULL;
}

void enqueue(Queue* queue, int row, int col) {
    Node* new_node = create_node(row, col);
    if (queue->head == NULL) {
        queue->head = queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

Node* dequeue(Queue* queue) {
    if (queue->head == NULL) {
        return NULL;
    } else {
        Node* removed_node = queue->head;
        queue->head = queue->head->next;
        if (queue->head == NULL) {
            queue->tail = NULL;
        }
        return removed_node;
    }
}

// create a function to print the maze
void print_maze() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// create a function to find the next possible moves from the current position
void find_possible_moves(int row, int col, Queue* queue) {
    if (row - 1 >= 0 && maze[row-1][col] != '#' && maze[row-1][col] != 'X') {
        enqueue(queue, row-1, col); // move up
    }
    if (col + 1 < SIZE && maze[row][col+1] != '#' && maze[row][col+1] != 'X') {
        enqueue(queue, row, col+1); // move right
    }
    if (row + 1 < SIZE && maze[row+1][col] != '#' && maze[row+1][col] != 'X') {
        enqueue(queue, row+1, col); // move down
    }
    if (col - 1 >= 0 && maze[row][col-1] != '#' && maze[row][col-1] != 'X') {
        enqueue(queue, row, col-1); // move left
    }
}

// create a function to implement Breadth-First Search (BFS) algorithm on the maze
void BFS(int start_row, int start_col) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    enqueue(queue, start_row, start_col);
    while (!is_empty(queue)) {
        Node* current_node = dequeue(queue);
        find_possible_moves(current_node->row, current_node->col, queue);
        maze[current_node->row][current_node->col] = '.';
        free(current_node);
        if (maze[SIZE-1][SIZE-2] == '.') {
            maze[SIZE-1][SIZE-2] = 'X';
            print_maze();
            printf("Path Found!\n");
            break;
        }
    }
    free(queue);
}

int main() {
    printf("Maze: \n");
    print_maze();
    printf("Finding path...\n");
    BFS(0, 0);
    return 0;
}