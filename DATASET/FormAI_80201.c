//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: retro
// Retro Style Maze Route Finder

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define maze dimensions
#define ROW 10
#define COL 10

// Define maze structure
struct maze {
    int x;
    int y;
    char val;
    bool visited;
};

// Define the maze
struct maze maze[ROW][COL] = {
    {{0, 0, 'O', false}, {0, 1, 'X', false}, {0, 2, 'O', false}, {0, 3, 'O', false}, {0, 4, 'X', false}, {0, 5, 'O', false}, {0, 6, 'X', false}, {0, 7, 'O', false}, {0, 8, 'O', false}, {0, 9, 'X', false}},
    {{1, 0, 'O', false}, {1, 1, 'X', false}, {1, 2, 'O', false}, {1, 3, 'O', false}, {1, 4, 'O', false}, {1, 5, 'X', false}, {1, 6, 'O', false}, {1, 7, 'X', false}, {1, 8, 'X', false}, {1, 9, 'O', false}},
    {{2, 0, 'O', false}, {2, 1, 'X', false}, {2, 2, 'O', false}, {2, 3, 'O', false}, {2, 4, 'O', false}, {2, 5, 'O', false}, {2, 6, 'O', false}, {2, 7, 'X', false}, {2, 8, 'O', false}, {2, 9, 'O', false}},
    {{3, 0, 'O', false}, {3, 1, 'O', false}, {3, 2, 'O', false}, {3, 3, 'O', false}, {3, 4, 'O', false}, {3, 5, 'O', false}, {3, 6, 'O', false}, {3, 7, 'X', false}, {3, 8, 'O', false}, {3, 9, 'X', false}},
    {{4, 0, 'O', false}, {4, 1, 'X', false}, {4, 2, 'X', false}, {4, 3, 'O', false}, {4, 4, 'X', false}, {4, 5, 'O', false}, {4, 6, 'O', false}, {4, 7, 'X', false}, {4, 8, 'O', false}, {4, 9, 'O', false}},
    {{5, 0, 'O', false}, {5, 1, 'X', false}, {5, 2, 'O', false}, {5, 3, 'O', false}, {5, 4, 'O', false}, {5, 5, 'X', false}, {5, 6, 'O', false}, {5, 7, 'X', false}, {5, 8, 'X', false}, {5, 9, 'O', false}},
    {{6, 0, 'O', false}, {6, 1, 'X', false}, {6, 2, 'O', false}, {6, 3, 'O', false}, {6, 4, 'O', false}, {6, 5, 'O', false}, {6, 6, 'O', false}, {6, 7, 'X', false}, {6, 8, 'O', false}, {6, 9, 'O', false}},
    {{7, 0, 'O', false}, {7, 1, 'O', false}, {7, 2, 'O', false}, {7, 3, 'O', false}, {7, 4, 'O', false}, {7, 5, 'O', false}, {7, 6, 'O', false}, {7, 7, 'X', false}, {7, 8, 'O', false}, {7, 9, 'X', false}},
    {{8, 0, 'O', false}, {8, 1, 'X', false}, {8, 2, 'X', false}, {8, 3, 'O', false}, {8, 4, 'X', false}, {8, 5, 'O', false}, {8, 6, 'O', false}, {8, 7, 'X', false}, {8, 8, 'O', false}, {8, 9, 'O', false}},
    {{9, 0, 'O', false}, {9, 1, 'O', false}, {9, 2, 'O', false}, {9, 3, 'O', false}, {9, 4, 'O', false}, {9, 5, 'O', false}, {9, 6, 'O', false}, {9, 7, 'O', false}, {9, 8, 'O', false}, {9, 9, 'X', false}},
};

// Define the start and end points
struct maze start_point = {0, 0, 'O', false};
struct maze end_point = {9, 9, 'X', false};

// Define the stack data structure
struct stack {
    struct maze data;
    struct stack *next;
};

// Define the start and end nodes for the stack
struct stack *start = NULL;
struct stack *end = NULL;

// Function to check if the stack is empty
bool isEmpty() {
    return start == NULL;
}

// Function to push a node to the stack
void push(struct maze data) {
    struct stack *new_node = (struct stack*)malloc(sizeof(struct stack));
    new_node->data = data;
    new_node->next = NULL;
    if (isEmpty()) {
        start = new_node;
        end = new_node;
        return;
    }
    end->next = new_node;
    end = new_node;
}

// Function to pop a node from the stack
struct maze pop() {
    struct maze popped_val;
    struct stack *temp = start;
    if (isEmpty()) {
        return start_point;
    }
    if (start == end) {
        start = NULL;
        end = NULL;
    } else {
        while (temp->next != end) {
            temp = temp->next;
        }
        end = temp;
        temp = temp->next;
        end->next = NULL;
    }
    popped_val = temp->data;
    free(temp);
    return popped_val;
}

// Function to find the solution to the maze
void find_route() {
    // Push the start point to the stack
    push(start_point);

    // Loop until the stack is empty
    while (!isEmpty()) {
        // Pop the top node from the stack
        struct maze current_node = pop();

        // Check if the node is the end node
        if (current_node.x == end_point.x && current_node.y == end_point.y) {
            printf("End point found!\n");
            return;
        }

        // Check if the node is marked as visited
        if (maze[current_node.x][current_node.y].visited) {
            continue;
        }
        maze[current_node.x][current_node.y].visited = true;

        // Check the neighbors of the node
        int x = current_node.x;
        int y = current_node.y;
        if (x > 0 && maze[x-1][y].val == 'O' && !maze[x-1][y].visited) {
            push(maze[x-1][y]);
        }
        if (y > 0 && maze[x][y-1].val == 'O' && !maze[x][y-1].visited) {
            push(maze[x][y-1]);
        }
        if (x < ROW-1 && maze[x+1][y].val == 'O' && !maze[x+1][y].visited) {
            push(maze[x+1][y]);
        }
        if (y < COL-1 && maze[x][y+1].val == 'O' && !maze[x][y+1].visited) {
            push(maze[x][y+1]);
        }
    }

    printf("End point not found.\n");
}

int main() {
    printf("Retro Style Maze Route Finder\n");

    // Print the maze
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", maze[i][j].val);
        }
        printf("\n");
    }

    // Find the solution to the maze
    find_route();

    return 0;
}