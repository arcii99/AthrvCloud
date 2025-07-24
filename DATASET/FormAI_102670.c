//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

struct node {
    int x;
    int y;
    struct node *next;
};

typedef struct node Node;

Node *stack = NULL;

int maze[ROWS][COLS] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                         {1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
                         {1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
                         {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                         {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                         {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
                         {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
                         {1, 0, 0, 0, 1, 1, 0, 1, 0, 1},
                         {1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
                         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

void push(int x, int y) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->next = stack;
    stack = new_node;
}

void pop(int *x, int *y) {
    if(stack) {
        *x = stack->x;
        *y = stack->y;
        Node *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

void print_path(int path[][COLS], int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

int find_path(int x, int y, int path[][COLS]) {
    if(x==ROWS-1 && y==COLS-1) {
        path[x][y] = 1;
        return 1;
    }

    if(maze[x][y] || path[x][y]) {
        return 0;
    }

    path[x][y] = 1;

    int found_path = 0;
    push(x+1, y); // go down
    found_path = find_path(x+1, y, path);
    if(!found_path) {
        pop(&x, &y);
        push(x, y+1); // go right
        found_path = find_path(x, y+1, path);
        if(!found_path) {
            pop(&x, &y);
            push(x-1, y); // go up
            found_path = find_path(x-1, y, path);
            if(!found_path) {
                pop(&x, &y);
                push(x, y-1); // go left
                found_path = find_path(x, y-1, path);
                if(!found_path) {
                    pop(&x, &y);
                }
            }
        }
    }

    if(found_path) {
        path[x][y] = 1;
    }

    return found_path;
}

int main() {
    int path[ROWS][COLS] = {0};
    int start_x = 0;
    int start_y = 0;

    printf("Maze:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    printf("\nFinding path...\n\n");
    int found_path = find_path(start_x, start_y, path);

    if(!found_path) {
        printf("No path found.\n");
    } else {
        printf("Path:\n");
        print_path(path, ROWS, COLS);
    }

    return 0;
}