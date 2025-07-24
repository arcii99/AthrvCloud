//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,1,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,1,0,1,0,0,1,0,1,1},
    {1,1,0,0,0,1,1,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0}
};

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void push(int x, int y) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void pop() {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
    }
    free(temp);
}

void print_maze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }
}

void print_path() {
    Node* current = head;
    printf("Path: ");
    while (current != NULL) {
        printf("(%d,%d) ", current->x, current->y);
        current = current->next;
    }
    printf("\n");
}

void find_path() {
    push(1, 1);
    maze[1][1] = 2;

    while (head != NULL) {
        int x = head->x;
        int y = head->y;

        if (x == ROW - 2 && y == COL - 2) {
            print_path();
            return;
        }

        if (maze[x-1][y] == 0) {
            push(x-1, y);
            maze[x-1][y] = 2;
        }

        if (maze[x+1][y] == 0) {
            push(x+1, y);
            maze[x+1][y] = 2;
        }

        if (maze[x][y-1] == 0) {
            push(x, y-1);
            maze[x][y-1] = 2;
        }

        if (maze[x][y+1] == 0) {
            push(x, y+1);
            maze[x][y+1] = 2;
        }

        pop();
    }

    printf("No path found.\n");
}

int main() {
    printf("Welcome to the Maze Route Finder!\n\n");
    printf("Maze:\n");
    print_maze();

    printf("\nFinding path...\n\n");
    find_path();

    return 0;
}