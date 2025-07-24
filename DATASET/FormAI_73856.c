//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {1, 1, 0, 1, 1, 0, 1, 0, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 1, 0, 1, 1, 0},
    {1, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
};

struct Node {
    int x, y;
    struct Node *next;
};

void push(struct Node **head, int x, int y) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->x = x;
    new_node->y = y;
    new_node->next = *head;
    *head = new_node;
}

void pop(struct Node **head) {
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void print_stack(struct Node *head) {
    while (head) {
        printf("(%d, %d) ", head->x, head->y);
        head = head->next;
    }
    printf("\n");
}

void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int find_route(int x, int y, struct Node **stack) {
    if (x < 0 || y < 0 || x >= ROWS || y >= COLS) return 0; // out of bounds
    if (maze[x][y] == 0) return 0; // wall
    if (maze[x][y] == 2) return 1; // destination found

    maze[x][y] = 0; // mark as visited

    push(stack, x, y);

    if (find_route(x-1, y, stack)) return 1; // try going up
    if (find_route(x, y+1, stack)) return 1; // try going right
    if (find_route(x+1, y, stack)) return 1; // try going down
    if (find_route(x, y-1, stack)) return 1; // try going left

    pop(stack);

    return 0;
}

int main() {
    struct Node *stack = NULL;

    printf("Maze:\n");
    print_maze();

    if (find_route(0, 1, &stack)) {
        printf("Path found: ");
        print_stack(stack);
    } else {
        printf("No path found.\n");
    }

    return 0;
}