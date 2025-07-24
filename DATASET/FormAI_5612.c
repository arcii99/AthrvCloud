//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

typedef struct node {
    int x, y;
    struct node* parent;
    struct node* next;
} node_t;

node_t* start = NULL;
node_t* end = NULL;
node_t* open = NULL;
node_t* closed = NULL;
int maze[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void print_maze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void add_node(node_t* node) {
    if (open == NULL) {
        open = node;
    } else if (node->x + node->y < open->x + open->y) {
        node->next = open;
        open = node;
    } else {
        node_t* current = open;
        while (current->next != NULL && current->next->x + current->next->y <= node->x + node->y) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

node_t* pop_node() {
    if (open == NULL) {
        return NULL;
    }
    node_t* node = open;
    open = open->next;
    node->next = NULL;
    return node;
}

void add_closed(node_t* node) {
    node->next = closed;
    closed = node;
}

void add_start(int x, int y) {
    start = malloc(sizeof(node_t));
    start->x = x;
    start->y = y;
    start->parent = NULL;
    start->next = NULL;
    add_node(start);
}

void add_end(int x, int y) {
    end = malloc(sizeof(node_t));
    end->x = x;
    end->y = y;
    end->parent = NULL;
    end->next = NULL;
}

void add_to_path(node_t* node) {
    if (node->parent != NULL) {
        add_to_path(node->parent);
    }
    maze[node->y][node->x] = 2;
}

int is_in_list(node_t* list, int x, int y) {
    node_t* current = list;
    while (current != NULL) {
        if (current->x == x && current->y == y) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int is_valid(int x, int y) {
    return x >= 0 && x < COL
        && y >= 0 && y < ROW
        && maze[y][x] != 1
        && !is_in_list(closed, x, y);
}

void add_child(node_t* current, int x, int y) {
    if (is_valid(x, y)) {
        node_t* child = malloc(sizeof(node_t));
        child->x = x;
        child->y = y;
        child->parent = current;
        child->next = NULL;
        add_node(child);
    }
}

void expand_node(node_t* current) {
    add_child(current, current->x + 1, current->y);
    add_child(current, current->x - 1, current->y);
    add_child(current, current->x, current->y + 1);
    add_child(current, current->x, current->y - 1);
}

void find_path() {
    while (open != NULL) {
        node_t* current = pop_node();
        if (current->x == end->x && current->y == end->y) {
            add_to_path(current);
            return;
        }
        add_closed(current);
        expand_node(current);
    }
}

int main() {
    print_maze();
    add_start(3, 0);
    add_end(3, 9);
    find_path();
    print_maze();
    return 0;
}