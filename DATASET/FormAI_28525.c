//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: introspective
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ROWS 7
#define COLS 10

char maze[ROWS][COLS] = {
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
    { '#', '.', '.', '.', '#', '.', '.', '.', '.', '#' },
    { '#', '.', '#', '.', '#', '.', '#', '#', '#', '#' },
    { '#', '.', '#', '.', '.', '.', '.', '.', '.', '#' },
    { '#', '.', '#', '#', '#', '#', '.', '#', '#', '#' },
    { '#', '.', '.', '.', '.', '#', '.', '.', '.', '#' },
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
};

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void add_to_path(int x, int y) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    if (tail == NULL) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void print_path() {
    Node* current = head;
    while (current != NULL) {
        printf("(%d, %d) ", current->x, current->y);
        current = current->next;
    }
}

bool find_path(int x, int y) {
    if (x < 0 || y < 0 || x >= ROWS || y >= COLS || maze[x][y] == '#' || maze[x][y] == '*') {
        return false;
    }
    add_to_path(x, y);
    if (x == ROWS - 1 && y == COLS - 1) {
        return true;
    }
    maze[x][y] = '*';
    if (find_path(x, y + 1) || find_path(x + 1, y) ||
        find_path(x, y - 1) || find_path(x - 1, y)) {
        return true;
    }
    free(head);
    head = NULL;
    tail = NULL;
    return false;
}

int main() {
    printf("Maze:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    if (find_path(0, 0)) {
        printf("Path found!\n");
        printf("Path: ");
        print_path();
        printf("\n");
    } else {
        printf("Path not found.\n");
    }

    return 0;
}